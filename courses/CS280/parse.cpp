#include "parse.h"
#include <iostream>
#include "lex.h"
#include "lex2.cpp"

using namespace std;
static int error_count = 0;
static LexItem t;
map<string, bool> defVar;
map<string, Token> SymTable;
static bool checkIF = true;
int tokCount =  0;
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
//--------------------------------------------------------------------------------------------------------------------------------------------------------
int ErrCount()
{
    return error_count;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
void ParseError(int line, string msg)
{
	++error_count;
	cout << line << ": " << msg << endl;
    
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool Prog(istream& in, int& line)
{
	cout<<"Step 1"<<endl; //debug
	t = Parser::GetNextToken(in,line);
	cout<<tokenPrint.find(t.GetToken())->second<<endl; //debug
	if (t.GetToken() != PROGRAM ){
		return false;
	}

	t = Parser::GetNextToken(in,line);
	cout<<tokenPrint.find(t.GetToken())->second<<endl; //debug

	if (t.GetToken() != IDENT){
		return false;
	}
	

	t = Parser::GetNextToken(in,line);
	cout<<tokenPrint.find(t.GetToken())->second<<endl; //debug
	int count = 0; // temporary for debugging

	while (Decl(in, line)){
		//t = Parser::GetNextToken(in,line);
		cout<<"t in prog(0): "<<t.GetLexeme()<<" "<<t.GetLinenum()<<endl; //debug
		count++;
		continue;
	}

	int count2 = 0; // temporary for debugging
	
	while (Stmt(in,line)){
		cout<<"t in prog(0.5): "<<t.GetLexeme()<<" "<<t.GetLinenum()<<endl; //debug
		continue;
	}

	cout<<checkIF<<endl;
	if (!checkIF){
		return false;
	}

	//print out the variables
	for(std::map<string,bool>::iterator it = defVar.begin(); it!=defVar.end();it++){
		
		string key = it->first;
		cout<<key<<endl; //for debug

    }
	//cout<<defVar.size()<<endl; //for debug

	cout<<"t in prog(1): "<<tokenPrint.find(t.GetToken())->second<<" "<<t.GetLinenum()<<endl; //debug
	if (t.GetToken() != END){
		return false;
	}

	t = Parser::GetNextToken(in,line);
	cout<<"t in prog(0): "<<t.GetLexeme()<<" "<<t.GetLinenum()<<endl; //debug
	if (t.GetToken() != PROGRAM){
		return false;
	}
	
	t = Parser::GetNextToken(in,line);
	cout<<"t in prog(0): "<<t.GetLexeme()<<" "<<t.GetLinenum()<<endl; //debug

	if (t.GetToken() != IDENT){
		return false;
	}
	
    return true;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool Stmt(istream& in, int& line){
	//cout<<"Step 2: "<<"inStmt"<<endl; //debug
	bool status;
	//t = Parser::GetNextToken(in,line);
	cout<<"STATM(0): "<<t.GetLexeme()<<" "<<t.GetLinenum()<<endl; //debug
	switch(t.GetToken()){
		case PRINT:
			cout<<"Passing STMT (PRINT)?"<<endl;
			t = Parser::GetNextToken(in,line);
			status = PrintStmt(in,line);
			if(status)
				status=Stmt(in,line);
		break;

		case IF:
			cout<<"if stmt in stmt: "<<t.GetLexeme()<<" line: "<<t.GetLinenum()<<endl;
			t = Parser::GetNextToken(in,line);
			t = Parser::GetNextToken(in,line);
			cout<<"if stmt in stmt2: "<<t.GetLexeme()<<endl;
			status = IfStmt(in,line);

			// if(status)
			// 	status=Stmt(in,line);
		break;

		case IDENT:
			cout<<"Passing STMT (IDENT)?"<<endl;
			status = AssignStmt(in,line);
			// if(status){
			// 	t = Parser::GetNextToken(in,line);
			// 	status=Stmt(in,line);
			// }
		break;

		case READ:
			cout<<"Passing STMT (READ)?"<<endl;
			t = Parser::GetNextToken(in,line);
			status = ReadStmt(in,line);
			if(status)
				status=Stmt(in,line);
		break;

		default:
			//Parser::PushBackToken(t); //REMEMBERRRRRR
			//t = Parser::GetNextToken(in,line);
			return false;
	}

	return status;
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool Decl(istream& in, int& line) {
	//cout<<"Step 3"<<endl;
	bool status = false;
	
	cout<<"t in Decl(0): "<<t.GetLexeme()<<" "<<t.GetLinenum()<<endl; //debug
	if(t == INTEGER || t == REAL || t == CHAR) {
		cout<<"passing?(0) "<<endl; //debug
		t = Parser::GetNextToken(in, line);
		if (t.GetToken() == COLON) {
			cout<<"passing?(1) "<<endl; //debug
			t = Parser::GetNextToken(in, line);
			cout<<"t in Decl(1): "<<"("<<t.GetLexeme()<<" line: "<<t.GetLinenum()<<")"<<endl;//" | "<<"tok in Decl(1): "<<"("<<tok.GetLexeme()<<" line: "<<tok.GetLinenum()<<")"<<endl; //debug
			status = IdList(in, line, t);
			if (status){
				cout<<"passing?(2) "<<"t: "<<t.GetLexeme()<<endl; //debug
				status = Decl(in, line);
				cout<< "Decl function in passing (2) status: "<<status<<endl;
				return status;
			}
		}

		else {
			t = Parser::GetNextToken(in, line);
			ParseError(line, "Missing Colon");
			return false;
		}
	
	}

	else{
		//Parser::PushBackToken(t);
		//t = Parser::GetNextToken(in, line);
		return false;
	}

	return status;	
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool PrintStmt(istream& in, int& line)
{
    if (t.GetToken()== COMA){
		t = Parser::GetNextToken(in, line);
		if (ExprList(in,line))
		{
			t = Parser::GetNextToken(in, line);
			return true;
		}
		else{ //there is a COMA but there is no VarList
			return false;
		}
	}

	else{
		return false; //COMMA is missing
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool IfStmt(istream& in, int& line)
{
	cout<<"entering ifstmt?"<<endl;
	cout<<t.GetLexeme()<<endl;
	if (t.GetToken()==LPAREN){
		cout<<"got Lparent"<<endl;
		t = Parser::GetNextToken(in, line);
		if(LogicExpr(in,line)){
			t = Parser::GetNextToken(in, line);
			if (t.GetToken()==RPAREN){
				cout<<"got Rparent"<<endl;
				t = Parser::GetNextToken(in, line);
				if (t.GetToken()==THEN){
					cout<<"got THEN"<<endl;
					t = Parser::GetNextToken(in, line);
					cout<<t.GetLexeme()<<endl;
					if (!Stmt(in,line)){
						cout<<"IFstmt: false?"<<endl;
						return false; //no statement 
					}
					
					t = Parser::GetNextToken(in, line);
					cout<<t.GetLexeme()<<endl;
					while (Stmt(in,line))
					{
						continue;
					}

					if (t.GetToken()==END){
						cout<<"got END"<<endl;
						t = Parser::GetNextToken(in, line);
						if (t.GetToken()==IF){
							cout<<"got IF"<<endl;
							t = Parser::GetNextToken(in, line);
							return true;
						}
						else{
							cout<<"happening the no IF?"<<endl;
							checkIF = false;
							return false; //no IF
						}
					}
					else{
						return false; //no END
					}
					t = Parser::GetNextToken(in, line);
					if (t.GetToken()==END){
						t = Parser::GetNextToken(in, line);

					}
					else{
						return false; //missing THEN
					}
				}
				else{
					return false; //missing THEN
				}
			}
			else{
				return false; //missing right parenthesis )
			}

		}
		else{
			return false; //missing valid logic expression
		}
	}
	else{
		return false; //missing left parenthesis
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool ReadStmt(istream& in, int& line)
{
	if (t.GetToken()== COMA){
		t = Parser::GetNextToken(in, line);
		if (VarList(in,line))
		{
			return true;
		}
		else{ //there is a COMA but there is no VarList
			return false;
		}
	}

	else{
		return false; //COMMA is missing
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool IdList(istream& in, int& line, LexItem tok2)
{

	LexItem tok;
	tok = Parser::GetNextToken(in, line);
	
	cout<<"t in IdList(0): "<<"("<<t.GetLexeme()<<" line: "<<t.GetLinenum()<<")"<<" | "<<"tok in IdList(0): "<<"("<<tok.GetLexeme()<<" line: "<<tok.GetLinenum()<<")"<<endl; //debug
	if (tok.GetToken()== COMA && t.GetToken()==IDENT && t.GetLinenum()==tok.GetLinenum()){
		if(!(defVar.find(t.GetLexeme())->second)){
	 		defVar[t.GetLexeme()] = true;
	 	}
		else{
			return false;
		}
		t = tok;
		return IdList(in, line,t);
	}

	else if (tok.GetToken() == IDENT && t.GetToken()==COMA && t.GetLinenum()==tok.GetLinenum()){
		t = tok;
		return IdList(in, line,t); //the first thing is not a variable
	}

	if (t.GetLinenum()!=tok.GetLinenum()){
		if(!(defVar.find(t.GetLexeme())->second)){
	 		defVar[t.GetLexeme()] = true;
	 	}
		cout<<"IdList: 1"<<endl; //debug
		t = tok;
		return true;
	}

	else{
		cout<<"IdList: 0"<<endl; //debug
		return false;
	}


    return true;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool VarList(istream& in, int& line)
{
    if (Var(in, line)){
		t = Parser::GetNextToken(in, line);
		if (t.GetToken()==COMA){
			t = Parser::GetNextToken(in, line);
			return VarList(in, line);
		}
		else{
			return true;
		}
	}

	else{
		return false;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool Var(istream& in, int& line)
{
	if(defVar.find(t.GetLexeme())->second){
		return true;
	}
	else{
		return false;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool AssignStmt(istream& in, int& line)
{
	cout<<"AssignSTMT(start)"<<endl;
	cout<<t.GetLexeme()<<endl;
	if (Var(in, line)){
		cout<<"AssignSTMT(Var)"<<endl;
		t = Parser::GetNextToken(in, line);
		cout<<"AssignSTMT: "<<t.GetLexeme()<<" "<<t.GetLinenum()<<endl;
		if (t.GetToken()==ASSOP){
			cout<<"AssignSTMT(at ASSOP) Arrives?"<<endl;
			t = Parser::GetNextToken(in, line);
			cout<<t.GetLexeme()<<endl;
			if (Expr(in,line)){
				cout<<"AssignStmt: Expression true?"<<endl;
				return true;
			}
			else{
				cout<<"AssignStmt: Expression false?"<<endl;
				return false;
			}
		}
		else{
			return false;
		}

	}
	else{
		return false;
	}

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool ExprList(istream& in, int& line)
{
    if (Expr(in, line)){
		t = Parser::GetNextToken(in, line);
		if (t.GetToken()==COMA){
			t = Parser::GetNextToken(in, line);
			return ExprList(in, line);
		}
		else{
			Parser::PushBackToken(t);
			return true;
		}
	}

	else{
		return false;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool LogicExpr(istream& in, int& line)
{
	cout<<"entering logic expression?"<<endl;
	if(Expr(in, line)){
		t = Parser::GetNextToken(in, line);
		if (t.GetToken()==EQUAL||t.GetToken()==LTHAN){
			t = Parser::GetNextToken(in, line);
			if (Expr(in, line)){
				return true;
			}
			else{
				return false; //there is expression and == or < but no second expression
			}
		}
		else{
			return false; //there is an expression but there is not equal or lthan
		}
	}
	else{
		return false;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool Expr(istream& in, int& line)
{
    if (Term(in, line)){
		t = Parser::GetNextToken(in, line);
		if (t.GetToken()==MINUS||t.GetToken()== PLUS){
			t = Parser::GetNextToken(in, line);
			return Expr(in, line);
		}
		else{
			Parser::PushBackToken(t);
			return true;
		}
	}

	else{
		return false;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool Term(istream& in, int& line)
{
	if (SFactor(in, line)){
		t = Parser::GetNextToken(in, line);
		if (t.GetToken()==DIV||t.GetToken()== MULT){
			t = Parser::GetNextToken(in, line);
			return Term(in, line);
		}
		else{
			Parser::PushBackToken(t);
			return true;
		}
	}

	else{
		return false;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool SFactor(istream& in, int& line)
{
	if (t.GetToken()==PLUS||t.GetToken()==MINUS){
		t = Parser::GetNextToken(in, line);
		if(Factor(in, line, 1)){
			//t = Parser::GetNextToken(in, line);
			return true;
		}
		else{ //there is a sign with no factor
			return false;
		}
	}
	else if (Factor(in, line, 1)){ //it is just a factor with no sign
		//t = Parser::GetNextToken(in, line);
		return true;
	}

    else{
		return false;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
bool Factor(istream& in, int& line, int sign)
{
	if(t.GetToken()==IDENT ||t.GetToken()==ICONST ||t.GetToken()==RCONST||t.GetToken()==SCONST){ 
		//t = Parser::GetNextToken(in, line);
		if(t.GetToken()==IDENT){
			if(!(defVar.find(t.GetLexeme())->second)){
				return false; // undeclared variable
			}
	 	}

		return true;
	}
	else if (t.GetToken()==LPAREN){ //if it is a left parenthesis
		t = Parser::GetNextToken(in, line);
		if(Expr(in,line)){ //check if it is an expression
			t = Parser::GetNextToken(in, line);
			if(t.GetToken()==RPAREN){
				//t = Parser::GetNextToken(in, line);
				return true;
			}
			else{
				cout<<"missing right parenthesis"<<endl;
				return false;
			}
		}
		else{ // it is not an expression but there is a left parenthesis so it is wrong
			return false;
		}
	}
	else{ // if it is non of IDENT || ICONST ||RCONST||SCONST||LPAREN
		return false;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------