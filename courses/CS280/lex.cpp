#include <iostream>
#include "lex.h"
#include <cctype>
#include <map>
#include <fstream>
#include <string>
#include <sstream>



ostream& operator<<(ostream& out, const LexItem& tok){
    Token tempTok = tok.GetToken();
    //int tempLine = tok.GetLinenum();
    string tempLexeme = tok.GetLexeme();
    string tokString = tokenPrint.find(tempTok)->second;

    if (tempTok == IDENT){

        if (kwmap.find(tok.GetLexeme())!= kwmap.end()){

            return out<<tempLexeme;

        }

        else{
            return out<< tokString<<"("<<tempLexeme<<")";
        }
                
    }

    else{
        return out<< tokString;
    }
}

LexItem id_or_kw(const string& lexeme, int linenum){
    //LexItem(Token token, string lexeme, int line) {
    if (lexeme=="END"){
        return LexItem(END,lexeme, linenum);
    }

     else if(lexeme=="PRINT"){
        return LexItem(PRINT,lexeme, linenum);
    }

    else if(lexeme=="PROGRAM"){
        return LexItem(PROGRAM,lexeme, linenum);
    }
    else if(lexeme=="READ"){
        return LexItem(READ,lexeme, linenum);
    }

    else if(lexeme=="INTEGER"){
        return LexItem(INTEGER,lexeme, linenum);
    }

    else if(lexeme=="REAL"){
        return LexItem(REAL,lexeme, linenum);
    }

    else if(lexeme=="CHAR"){
        return LexItem(CHAR,lexeme, linenum);
    }

    else if(lexeme=="IF"){
        return LexItem(IF,lexeme, linenum);
    }

    else if(lexeme=="THEN"){
        return LexItem(THEN,lexeme, linenum);
    }

    else {
        return LexItem(IDENT,lexeme, linenum);
    }
}

LexItem getNextToken(istream& in, int& linenum){
    enum TokState{START, INID, INSTRING, ININT, INREAL, INCOMMENT, INDONE} lexstate = START;
    string lexeme;
    bool doubString = false;
    bool possEqual = false;
    bool possConcat = false;
    char ch;
    

    while (in.get(ch))
    {

        char nextCharacter = in.peek();

        if (nextCharacter==EOF)
            return LexItem(DONE,"DONE",linenum);

        if (ch=='\n' && nextCharacter!=EOF){
            linenum++;
        }
        
        if (isalpha(ch)&&lexstate!=INSTRING){
            lexeme += toupper(ch); 
        }

        else{
            lexeme += ch; 
        }

        

        switch (lexstate)
        {
            
            case START:

                switch (ch){
                    case '+':
                        return LexItem(PLUS,"PLUS", linenum);

                    case '-':
                        return LexItem(MINUS,"MINUS", linenum);
                
                    case '*':
                        return LexItem(MULT,"MULT", linenum);


                    case '/':
                        if (nextCharacter == '/'){
                            possConcat = true;
                            continue;
                        }

                        else if (possConcat){
                            return LexItem(CONCAT,"CONCAT", linenum);
                        }
                            

                        else
                            return LexItem(DIV,"DIV", linenum);
                            
                    case '(':
                        return LexItem(LPAREN,"LPAREN", linenum);

                    case ')':
                        return LexItem(RPAREN,"RPAREN", linenum);

                    case '=':
                        if (nextCharacter == '='){
                            possEqual = true;
                            continue;
                        }

                        else if (possEqual){
                            return LexItem(EQUAL,"EQUAL", linenum);
                        }
                        else
                            return LexItem(ASSOP,"ASSOP", linenum);
                    
                    case '<':
                        return LexItem(LTHAN,"LTHAN", linenum);

                    case ':':
                        return LexItem(COLON,"COLON", linenum);

                    case ',':
                        return LexItem(COMA,"COMA", linenum);
                }

                if(ch=='\n'){
                    lexeme = "";
                }

                else if (nextCharacter==EOF)
                    return LexItem(DONE,"DONE",linenum);


                else if(isspace(ch)){
                    lexeme = "";
                    continue;
                }

                else if(isalpha(ch)){
                    
                    if (isalpha(nextCharacter)||isdigit(nextCharacter)){
                        lexstate = INID;
                    }

                    else if (nextCharacter==EOF)
                        return LexItem(DONE,"DONE",linenum);

                    else{
                        return LexItem(IDENT,lexeme, linenum); 
                    }
                }

                else if(isdigit(ch)){
                    if(nextCharacter == '.')
                        lexstate = INREAL;
                    else if(!isdigit(nextCharacter))
                        return LexItem(ICONST,lexeme,linenum);
                    else 
                        lexstate = ININT;

                }

                else if(ch =='.'){
                    if(isdigit(nextCharacter))
                        lexstate = INREAL;
                    else{
                        lexeme += nextCharacter;
                        return LexItem(ERR,lexeme, linenum); 
                    }
                }

                else if(ch == '"'||ch == '\''){
                    
                    if (ch == '"'){
                        lexeme ="\"";
                        doubString = true;
                    }
                    else{
                        lexeme ="'";
                    }
                    lexstate = INSTRING;
                }

                else if(ch=='!'){
                    lexstate = INCOMMENT;
                    lexeme = "";
                }

                else{
                    return LexItem(ERR,lexeme, linenum);
                }

                break;

            case INID:
                if (isalpha(nextCharacter)||isdigit(nextCharacter)){

                    lexstate = INID;
                }

                else if (nextCharacter==EOF)
                    return LexItem(DONE,"DONE", linenum);

                else
                    return LexItem(IDENT,lexeme, linenum);

                break;

            case INDONE:

                return LexItem(DONE,"DONE", linenum);

                break;


            case INSTRING:

                if (doubString)
                {
                    if (ch=='"'){
                        lexeme = lexeme.substr(1,lexeme.length()-2);
                        return LexItem(SCONST,lexeme,linenum);
                    }

                    else if(nextCharacter  =='\n'){
                        return LexItem(ERR,lexeme,linenum);
                    }

                    else{
                        continue;
                    }
                }

                else{

                    if (ch=='\''){
                        lexeme = lexeme.substr(1,lexeme.length()-2);
                        return LexItem(SCONST,lexeme,linenum);
                    }
                    
                    else if(nextCharacter =='\n'){
                        return LexItem(ERR,lexeme,linenum);
                    }

                    else{
                        continue;
                    }

                }

                if (nextCharacter=='\n'){
                    return LexItem(ERR,lexeme,linenum);
                }

                break;

            case ININT:
                if (isdigit(nextCharacter))
                {
                    continue;
                }

                else if (nextCharacter==EOF){
                    return LexItem(DONE,"DONE", linenum);
                }

                else if (nextCharacter=='.'){
                    lexstate = INREAL;
                }

                else{
                    return LexItem(ICONST,lexeme, linenum);
                }

                break;
            
            case INREAL:

                if (isdigit(nextCharacter))
                {
                    continue;
                }

                else if (ch=='.'&& !isdigit(nextCharacter))
                {
                    return LexItem(ERR,lexeme.substr (0,lexeme.length()-1),linenum);
                }

                else if (nextCharacter==EOF){
                    return LexItem(DONE,"DONE", linenum);
                }

                else{

                    return LexItem(RCONST,lexeme, linenum); 
                }

                break;
            
            case INCOMMENT:
                lexeme = "";
                if (ch !='\n'){
                    continue;
                }

                else if (nextCharacter==EOF){
                    return LexItem(DONE,"DONE", linenum);
                }
                
                else{

                    lexstate = START;
                }

                break;
                
            
            default:


                break;
        }
                
           
    }

    //std::cout<<(lexstate == START) <<endl;

    return LexItem(DONE,"DONE",linenum);    
    
}




