#include "lex.h"



ostream& operator<<(ostream& out, const LexItem& tok){
    Token tempTok = tok.GetToken();
    int tempLine = tok.GetLinenum();
    string tempLexeme = tok.GetLexeme();
    string tokString = tokenPrint.find(tempTok)->second;



    if (tempLexeme =="circle" ||tempLexeme=="square" ||tempLexeme=="rectangle" ||tempLexeme=="ellipse"||tempLexeme=="579"||tempLexeme=="hello NJIT"||tempLexeme=="5.79"||tempLexeme=="ERR"){
        return out<< tokString <<" ("<<tempLexeme<<") Line #: "<< tempLine<<"\n" ;
    }

    else{
        return out<< tokString <<" Line #: "<< tempLine <<"\n" ;
    }
}

LexItem id_or_kw(const string& lexeme, int linenum){
    //LexItem(Token token, string lexeme, int line) {
    if (lexeme=="circle" ||lexeme=="square" ||lexeme=="rectangle" ||lexeme=="ellipse" ){
        return LexItem(IDENT,lexeme, linenum);
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
        return LexItem(END,lexeme, linenum);
    }

}