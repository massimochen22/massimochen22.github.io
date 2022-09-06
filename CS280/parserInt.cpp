/* Implementation of Recursive-Descent Parser
 * parse.cpp
 * Programming Assignment 2
 * Spring 2021
*/

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include "parserInt.h"

static int error_count = 0;
string currentId;

map<string, bool> defVar;
map<string, Token> SymTable;
LexItem temporaryTok;


map<string,Value>TempsResults;
queue<Value>*ValQue;

namespace Parser {
	bool pushed_back = false;
	LexItem	pushed_token;

	static LexItem GetNextToken(istream& in, int& line) {
		if( pushed_back ) {
			pushed_back = false;
			return pushed_token;
		}
		return getNextToken(in, line);
	}

	static void PushBackToken(LexItem & t) {
		if( pushed_back ) {
			abort();
		}
		pushed_back = true;
		pushed_token = t;	
	}

}

int ErrCount()
{
    return error_count;
}

void ParseError(int line, string msg)
{
	++error_count;
	cout << line << ": " << msg << endl;
    
}



//Program is: Prog = PROGRAM IDENT {Decl} {Stmt} END PROGRAM IDENT
bool Prog(istream& in, int& line)
{
	bool dl = false, sl = false;
	LexItem tok = Parser::GetNextToken(in, line);
	string nameProg; 
	
	if (tok.GetToken() == PROGRAM) {
		tok = Parser::GetNextToken(in, line);
		if (tok.GetToken() == IDENT) {
			nameProg = tok.GetLexeme();
			dl = Decl(in, line);
			if( !dl  )
			{
				ParseError(line, "Incorrect Declaration in Program");
				return false;
			}
			sl = Stmt(in, line);
			//-----------------------------------debug start


			// for (auto it = TempsResults.cbegin(); it != TempsResults.cend(); ++it) {
        	// 	std::cout << "{" << (*it).first << ": " << (*it).second << "}\n";
    		// }
			
			//-----------------------------------debug end
			if( !sl  )
			{
				ParseError(line, "Incorrect Statement in program");
				return false;
			}	
			tok = Parser::GetNextToken(in, line);
			
			if (tok.GetToken() == END) {
				tok = Parser::GetNextToken(in, line);
				
				if (tok.GetToken() == PROGRAM) {
					tok = Parser::GetNextToken(in, line);
					
					if (tok.GetToken() == IDENT && tok.GetLexeme()==nameProg) {
						return true;
					}
					else
					{
						ParseError(line, "Incorrect Program Name");
						return false;
					}	
				}
				else
				{
					ParseError(line, "Missing PROGRAM at the End");
					return false;
				}	
			}
			else
			{
				ParseError(line, "Missing END of Program");
				return false;
			}	
		}
	}
	else if(tok.GetToken() == ERR){
		ParseError(line, "Unrecognized Input Pattern");
		cout << "(" << tok.GetLexeme() << ")" << endl;
		return false;
	}
	
	return false;
}

//Decl = Type : VarList 
//Type = INTEGER | REAL | CHAR
bool Decl(istream& in, int& line) {
	bool status = false;
	LexItem tok;
	
	LexItem t = Parser::GetNextToken(in, line);
	
	if(t == INTEGER || t == REAL || t == CHAR) {
		temporaryTok = t; 
		tok = t;
		tok = Parser::GetNextToken(in, line);
		if (tok.GetToken() == COLON) {
			status = IdList(in, line, t);
			//cout<< tok.GetLexeme() << " " << (status? 1: 0) << endl;
			if (status)
			{
				status = Decl(in, line);
				return status;
			}
		}
		else{
			ParseError(line, "Missing Colon");
			return false;
		}
	}
		
	Parser::PushBackToken(t);
	return true;
}

//Stmt is either a PrintStmt, ReadStmt, IfStmt, or an AssigStmt
//Stmt = AssigStmt | IfStmt | PrintStmt | ReadStmt
bool Stmt(istream& in, int& line) {
	bool status;
	LexItem t = Parser::GetNextToken(in, line);
	
	switch( t.GetToken() ) {

	case PRINT:
		status = PrintStmt(in, line);
		
		if(status)
			status = Stmt(in, line);
		break;

	case IF:
		status = IfStmt(in, line);
		if(status)
			status = Stmt(in, line);
		break;

	case IDENT:
		currentId = t.GetLexeme(); //debug
		Parser::PushBackToken(t);
        status = AssignStmt(in, line);
		if(status)
			status = Stmt(in, line);
		break;

	default:
		Parser::PushBackToken(t);
		return true;
	}

	return status;
}

//PrintStmt:= print, ExpreList 
bool PrintStmt(istream& in, int& line) { 
    LexItem t;
    /*createanemptyqueueofValueobjects.*/
    ValQue = new queue<Value>;

    if( (t=Parser::GetNextToken(in,line)) != COMA){
        ParseError(line,"Missing a Comma");
        return false;
    }

    bool ex=ExprList(in,line);
    
    if(!ex){
        ParseError(line,"Missing expression after print");
        while( !(*ValQue).empty() ){
            ValQue->pop();
        }
        delete ValQue;
        return false;
    }

    //Evaluate:print out the list of expressions' values
    while( !(*ValQue).empty() ){
        Value nextVal=(*ValQue).front();
        cout<<nextVal;ValQue->pop();
    }
    cout<<endl;
    return ex;
}//PrintStmt


//IfStmt:= if (Expr) then {Stmt} END IF
bool IfStmt(istream& in, int& line) {
	bool ex=false ; 
	LexItem t;
    Value retVal;
	
	if( (t=Parser::GetNextToken(in, line)) != LPAREN ) {
		
		ParseError(line, "Missing Left Parenthesis");
		return false;
	}
	//cout<<"retVal1: "<<retVal.GetBool()<<endl;
	ex = LogicExpr(in, line, retVal);


	if( !ex ) {
		ParseError(line, "Missing if statement Logic Expression");
		return false;
	}

	if((t=Parser::GetNextToken(in, line)) != RPAREN ) {
		
		ParseError(line, "Missing Right Parenthesis");
		return false;
	}
	
	if((t=Parser::GetNextToken(in, line)) != THEN ) {
		
		ParseError(line, "Missing THEN");
		return false;
	}

	if (retVal.GetBool()==true){

		bool st = Stmt(in, line);
		if( !st ) {
			ParseError(line, "Missing statement for IF");
			return false;
		}
	}

	else{
		while((t=Parser::GetNextToken(in, line))!=END){
			;
		}

		Parser::PushBackToken(t);
	}
	
	
	
	if((t=Parser::GetNextToken(in, line)) != END ) {
		//cout<<"Here is the prob: "<<t.GetLexeme()<<endl;
		ParseError(line, "Missing END of IF");
		return false;
	}
	if((t=Parser::GetNextToken(in, line)) != IF ) {
		
		ParseError(line, "Missing IF at End of IF statement");
		return false;
	}
	
	return true;
}

//IdList:= IDENT {,IDENT}
bool IdList(istream& in, int& line, LexItem& type) {
	bool status = false;
	string identstr;
	
	LexItem tok = Parser::GetNextToken(in, line);
	if(tok == IDENT)
	{
		//set IDENT lexeme to the type tok value
		identstr = tok.GetLexeme();
		if (!(defVar.find(identstr)->second))
		{
			defVar[identstr] = true;
			SymTable[identstr] = temporaryTok.GetToken();
		}	
		else
		{
			ParseError(line, "Variable Redefinition");
			return false;
		}
		
	}
	else
	{
		ParseError(line, "Missing Variable");
		return false;
	}
	
	tok = Parser::GetNextToken(in, line);
	
	if (tok == COMA) {
		status = IdList(in, line, tok);
	}
	else if(tok.GetToken() == ERR){
		ParseError(line, "Unrecognized Input Pattern");
		cout << "(" << tok.GetLexeme() << ")" << endl;
		return false;
	}
	else{
		Parser::PushBackToken(tok);
		return true;
	}
	return status;
}


//Var:= ident
bool Var(istream& in, int& line, LexItem& type)
{
	//called only from the AssignStmt function
	string identstr;
	
	LexItem tok = Parser::GetNextToken(in, line);
	
	if (tok == IDENT){
		identstr = tok.GetLexeme();
		if (!(defVar.find(identstr)->second))
		{
			ParseError(line, "Undeclared Variable");
			return false;
			
		}

		Parser::PushBackToken(tok);	

		return true;
	}
	else if(tok.GetToken() == ERR){
		ParseError(line, "Unrecognized Input Pattern");
		cout << "(" << tok.GetLexeme() << ")" << endl;
		return false;
	}
	return false;
}

//AssignStmt:= Var = Expr
bool AssignStmt(istream& in, int& line) {

	bool varstatus = false, status = false;
	LexItem t;
    Value retVal;
	
	varstatus = Var( in, line, t);
	
	
	if (varstatus){
		t = Parser::GetNextToken(in, line);
		string varname = t.GetLexeme();
		t = Parser::GetNextToken(in, line);
		//cout<<varname<<endl;
//--------------debug----------
		// cout<<"Symtable map: "<<tokenPrint.find(SymTable[varname])->second<<endl;
		// for (auto it = SymTable.cbegin(); it != SymTable.cend(); ++it) {
        // 		std::cout << "{" << (*it).first << ": " << tokenPrint.find((*it).second)->second << "}\n";
    	// }
//--------------debug----------


		if (t == ASSOP){
			
			status = Expr(in, line,retVal);

			if(!status) {
				ParseError(line, "Missing Expression in Assignment Statment");
				return status;
			}

			if (SymTable[varname]==INTEGER &&retVal.GetType()==VREAL){
				//cout<<"ever entering???"<<endl;
				float temp1 = retVal.GetReal();
				retVal.SetType(VINT);
				retVal.SetInt((int)temp1);
				TempsResults[varname] = retVal;
			}

			else{
				//cout<<"else? "<<t.GetLexeme()<<endl;
				TempsResults[varname] = retVal;
			}
			
		}
		else if(t.GetToken() == ERR){
			ParseError(line, "Unrecognized Input Pattern");
			cout << "(" << t.GetLexeme() << ")" << endl;
			return false;
		}
		else {
			ParseError(line, "Missing Assignment Operator =");
			return false;
		}
	}
	else {
		ParseError(line, "Missing Left-Hand Side Variable in Assignment statement");
		return false;
	}
	return status;	
}

//ExprList:= Expr {,Expr}
bool ExprList(istream& in, int& line) {
	bool status = false;
    Value retVal;

	status = Expr(in, line, retVal);
	//debuggg

	ValQue->push(retVal);


	
	if(!status){
		ParseError(line, "Missing Expression");
		return false;
	}
	
	LexItem tok = Parser::GetNextToken(in, line);
	
	if (tok == COMA) {
		status = ExprList(in, line);

	}
	else if(tok.GetToken() == ERR){
		ParseError(line, "Unrecognized Input Pattern");
		cout << "(" << tok.GetLexeme() << ")" << endl;
		return false;
	}
	else{
		Parser::PushBackToken(tok);
		return true;
	}
	return status;
}


//Expr:= Term {(+|-) Term}
bool Expr(istream& in, int& line, Value & retVal) {
    Value val1, val2;
    bool t1 = Term(in, line, retVal);

    LexItem tok;
    
    if( !t1 ) {
        return false;
    }
    
    tok = Parser::GetNextToken(in, line);
    if(tok.GetToken() == ERR){
        ParseError(line, "Unrecognized Input Pattern");
        cout << "(" << tok.GetLexeme() << ")" << endl;
        return false;
    }
    while ( tok == PLUS || tok == MINUS ) {
        t1 = Term(in, line, val2);
        if( !t1 ) 
        {
            ParseError(line, "Missing operand after operator");
            return false;
        }
		//evaluate the expression for addition or subtraction
		//and update the retVal object
		//check if the operation of PLUS/MINUS is legal for the
		//type of operands
        if(retVal.GetType()==VCHAR || val2.GetType()==VCHAR){
            ParseError(line,"Run-Time Error-Illegal Mixed Type Operands");
            return false;
        }

        else{
            if(tok == PLUS){
                retVal = retVal + val2;
            }
            else if(tok == MINUS){
                retVal = retVal - val2;
            }
        }

        tok=Parser::GetNextToken(in,line);
        if(tok.GetToken() == ERR){
            ParseError(line,"Unrecognized Input Pattern");
            cout<< "(" << tok.GetLexeme() << ")" << endl;
            return false;
        }
    }
    Parser::PushBackToken(tok);
    return true;
}



//Term:= SFactor {(*|/) SFactor}
//Expr:= Term {(+|-) Term}
bool Term(istream& in, int& line, Value & retVal) {
    Value val1, val2;
    bool t1 = SFactor(in, line, retVal);
    LexItem tok;
    

    if( !t1 ) {
        return false;
    }
    
    tok = Parser::GetNextToken(in, line);
    if(tok.GetToken() == ERR){
        ParseError(line, "Unrecognized Input Pattern");
        cout << "(" << tok.GetLexeme() << ")" << endl;
        return false;
    }
    while ( tok == MULT || tok == DIV ) {
        t1 = SFactor(in, line, val2);
        if( !t1 ) 
        {
            ParseError(line, "Missing operand after operator");
            return false;
        }
    //evaluate the expression for addition or subtraction
    //and update the retVal object
    //check if the operation of PLUS/MINUS is legal for the
    //type of operands
        if(retVal.GetType()==VCHAR || val2.GetType()==VCHAR){
            ParseError(line,"Run-Time Error-Illegal Mixed Type Operands");
            return false;
        }
        else{
            if(tok == MULT){
                retVal = retVal * val2;
            }
            else if(tok == DIV){
				if(val2.GetInt()==0){
					return false;
				}
                retVal = retVal / val2;
            }
        }

        tok=Parser::GetNextToken(in,line);
        if(tok.GetToken() == ERR){
            ParseError(line,"Unrecognized Input Pattern");
            cout<< "(" << tok.GetLexeme() << ")" << endl;
            return false;
        }
    }
    Parser::PushBackToken(tok);
    return true;
}

//SFactor = Sign Factor | Factor
bool SFactor(istream& in, int& line,Value& retVal)
{
	LexItem t = Parser::GetNextToken(in, line);
	bool status;
	int sign = 0;
	if(t == MINUS )
	{
		sign = -1;
	}
	else if(t == PLUS)
	{
		sign = 1;
	}
	else
		Parser::PushBackToken(t);
		
	status = Factor(in, line, sign,retVal);
	return status;
}
//LogicExpr = Expr (== | <) Expr
bool LogicExpr(istream& in, int& line,Value& retVal)
{
	Value val1, val2;

	bool t1 = Expr(in, line, val1);
	LexItem tok;
	
	if( !t1 ) {
		return false;
	}
	
	tok = Parser::GetNextToken(in, line);
	if(tok.GetToken() == ERR){
		ParseError(line, "Unrecognized Input Pattern");
		cout << "(" << tok.GetLexeme() << ")" << endl;
		return false;
	}
	if ( tok == LTHAN  || tok == EQUAL) 
	{
		LexItem tempTok = tok;
		t1 = Expr(in, line,val2);
		if( !t1 ) 
		{
			ParseError(line, "Missing expression after relational operator");
			return false;
		}

		if(val1.GetType()!=val2.GetType()){
			ParseError(line, "Run-Time Error-Illegal Mixed Type operation");
			return false;
		}

		if (tempTok == LTHAN){
			retVal = (val1 < val2);
		}

		else{

			retVal = (val1 == val2);

		}


		return true;
	}
	Parser::PushBackToken(tok);
	return true;
}

//Factor := ident | iconst | rconst | sconst | (Expr)
bool Factor(istream& in, int& line, int sign,Value& retVal) {
	
	LexItem tok = Parser::GetNextToken(in, line);
	

	if( tok == IDENT ) {
		//check if the var is defined 
		string lexeme = tok.GetLexeme();
		if (!(defVar.find(lexeme)->second))
		{
			ParseError(line, "Undefined Variable");
			return false;	
		}

		if (TempsResults.count(lexeme) == 0){
			return false;
		}


		retVal = TempsResults.find(lexeme)->second; 

		if (sign == -1){
			retVal = retVal*-1; 
		}


		return true;
	}

	else if( tok == ICONST ) {

		//cout<<"arrive ICONST???"<<endl;
		int toNumber = stoi(tok.GetLexeme());
		//cout<<"toNumber: "<<toNumber<<endl;
		retVal.SetType(VINT);
		
		if (sign == -1){
			toNumber = toNumber * -1;
			retVal.SetInt(toNumber);
		}
		retVal.SetInt(toNumber);
		

		return true;
	}

	else if( tok == SCONST ) {

		//cout<<"arrive SCONST???"<<endl;
		retVal.SetType(VCHAR);
		retVal.SetChar(tok.GetLexeme());

		
		return true;
	}
	else if( tok == RCONST ) {
		//cout<<"arrive RCONST???"<<endl;
		float toNumber = std::stof(tok.GetLexeme());
		//cout<<"toNumber: "<<toNumber<<endl;
		retVal.SetType(VREAL);
		retVal.SetReal(toNumber);
		
		return true;
	}
	else if( tok == LPAREN ) {
		bool ex = Expr(in, line,retVal);
		if( !ex ) {
			ParseError(line, "Missing expression after (");
			return false;
		}
		if( Parser::GetNextToken(in, line) == RPAREN )
			return ex;

		ParseError(line, "Missing ) after expression");
		return false;
	}
	else if(tok.GetToken() == ERR){
		ParseError(line, "Unrecognized Input Pattern");
		cout << "(" << tok.GetLexeme() << ")" << endl;
		return false;
	}

	ParseError(line, "Unrecognized input");
	return 0;
}



