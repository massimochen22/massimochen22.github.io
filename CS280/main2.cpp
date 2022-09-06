#include <iostream>
#include "lex.h"
#include "lex.cpp"
#include <cctype>
#include <map>
#include <fstream>
#include <string>
#include <sstream>


int main(int argc, char *argv[])
{	
	bool vflag = false;
	bool iconstsflag = false;
    bool rconstsflag = false;
    bool idsflag = false;
    bool sconstsflag = false;
    bool noflag = false;

    
    
    //when there is no flags
    //handling the flags, the last possible argument is taken and marked as true. 
    //If its not possible it prints “UNRECOGNIZED FLAG {arg}”, where {arg} is 
    //whatever flag was given

 // for example main.cpp, file, -v , -ids, -sconsts, im
	for( int i=argc-1; i>0; i-- ) {
        string arg( argv[i] );

		if( arg == "-v" ){
			vflag = true;
        }

		else if( arg == "-iconsts" ){
			iconstsflag = true;
        }  
        
        else if( arg == "-sconsts" ){
			sconstsflag = true;
        }


        else if( arg == "-rconsts" ){
			rconstsflag = true;

        }
        else if( arg == "-ids" ){
			idsflag = true;
        }
            
		else if( arg[0] == '-' ) {
			cerr << "UNRECOGNIZED FLAG " << arg << endl;
            return 0;
		}

        else{

            noflag = true;

        }

	}


    ifstream file;
    file.open(argv[1]);
    
    int lineNumber = 1;
    LexItem tok;
    
    string line;
    
    int totLine = 0;

    if (argc<2){
        std::cout<< "No Specified Input File Name."<<std::endl;
    }

    
    else if (!file.is_open()){
       std::cout<<"CANNOT OPEN THE FILE "<<argv[1]<<std::endl;
        return 0;
    }


    else {
        int nEmpty = 0;
        int nline = 0;
        while (getline(file, line)){
            nline++;
            if (line.empty()){
                nEmpty++;
            }
        }
        

        if (nline == 0){
            std::cout<<"Lines: 0"<<std::endl;
            return 0;
        }
        
        totLine = nline;

        file.close();
        file.open(argv[1]);

    }




    // enters this block of code if the argument is "-v"
    if(vflag)
    {
        int totTok = 0;
    	while((tok = getNextToken(file,lineNumber)).GetToken()!=DONE && tok.GetToken()!=ERR ){
        
        totTok++;
        cout<<tok<<endl;


        }

        std::cout<<"Lines: "<<totLine<<std::endl;
        std::cout<<"Tokens: "<<totTok<<endl;

	}

    // enters this block of code if the argument is "-iconsts"
	else if(iconstsflag)
    {

    map<int,int> intMap;

    int totTok = 0;
    LexItem tok;

    
    while((tok = getNextToken(file,lineNumber)).GetToken()!=DONE && tok.GetToken()!=ERR ){
        totTok++;


        if (tok.GetToken()== ICONST){
            stringstream valueSt(tok.GetLexeme());
            int x = 0;
            valueSt>>x;
            intMap[x]++;
        }

    }

    if (tok.GetToken()==ERR){
        std::cout<<"Error in line "<<tok.GetLinenum()<<" ("<<tok.GetLexeme()<<")"<<std::endl;
        return 0;
    }


    std::cout<<"Lines: "<<totLine<<std::endl;

    std::cout<<"Tokens: "<<totTok<<endl;
    std::cout<<"INTEGERS:"<<endl;

    for(std::map<int,int>::iterator it2 = intMap.begin(); it2!=intMap.end();it2++){
        std::cout<<it2->first<<endl;
    }

	}
    
    else if(sconstsflag){

        
    map<string,int> stringMap;


    int totTok = 0;
    LexItem tok;
    //int nout = 0;

    
    while((tok = getNextToken(file,lineNumber)).GetToken()!=DONE && tok.GetToken()!=ERR ){
        totTok++;


        if (tok.GetToken()== SCONST){

            stringMap[tok.GetLexeme()]++;
        }

    }

    if (tok.GetToken()==ERR){
        std::cout<<"Error in line "<<tok.GetLinenum()<<" ("<<tok.GetLexeme()<<")"<<std::endl;
        return 0;
    }


    std::cout<<"Lines: "<<totLine<<std::endl;

    std::cout<<"Tokens: "<<totTok<<endl;
    std::cout<<"STRINGS:"<<endl;

    for(std::map<string,int>::iterator it3 = stringMap.begin(); it3!=stringMap.end();it3++){
        std::cout<<it3->first<<endl;
    }
        
        

    }

    // enters this block of code if the argument is "-rconsts"
    else if(rconstsflag){

        map<float,int> realMap;

        int totTok = 0;
        LexItem tok;

    
        while((tok = getNextToken(file,lineNumber)).GetToken()!=DONE && tok.GetToken()!=ERR ){
            totTok++;


            if (tok.GetToken()== RCONST){
                stringstream valueSt(tok.GetLexeme());
                float x = 0;
                valueSt>>x;
                realMap[x]++;
            }

        }

        if (tok.GetToken()==ERR){
            std::cout<<"Error in line "<<tok.GetLinenum()<<" ("<<tok.GetLexeme()<<")"<<std::endl;
            return 0;
        }


        std::cout<<"Lines: "<<totLine<<std::endl;

        std::cout<<"Tokens: "<<totTok<<endl;
        std::cout<<"REALS:"<<endl;

        for(std::map<float,int>::iterator it = realMap.begin(); it!=realMap.end();it++){
            std::cout<<it->first<<endl;
        }

        }

     // enters this block of code if the argument is "-ids"
    else if(idsflag){
        
    map<string,int> myMap;


    int totTok = 0;
    LexItem tok;
    //int nout = 0;

    
    while((tok = getNextToken(file,lineNumber)).GetToken()!=DONE && tok.GetToken()!=ERR ){
        totTok++;

        // nout++;


        if (tok.GetToken()== IDENT){

            if (kwmap.find(tok.GetLexeme())== kwmap.end())
                myMap[tok.GetLexeme()]++;
        }


        
        // if (nout>=30)
        //     break;

    }

    if (tok.GetToken()==ERR){
        std::cout<<"Error in line "<<tok.GetLinenum()<<" ("<<tok.GetLexeme()<<")"<<std::endl;
        return 0;
    }


    int mapSize = myMap.size();
    int counter = 0;

    std::cout<<"Lines: "<<totLine<<std::endl;

    std::cout<<"Tokens: "<<totTok<<endl;
    std::cout<<"IDENTIFIERS:"<<endl;

    for(std::map<string,int>::iterator it4 = myMap.begin(); it4!=myMap.end();it4++){
        counter++;
        std::cout<<it4->first;

        if(counter<mapSize)
            std::cout<<", ";

    }
    std::cout<<endl;



            
   }

   else if (noflag){

       int totTok = 0;
    	while((tok = getNextToken(file,lineNumber)).GetToken()!=DONE && tok.GetToken()!=ERR ){
        
        totTok++;

        }

        std::cout<<"Lines: "<<totLine<<std::endl;
        std::cout<<"Tokens: "<<totTok<<endl;

   }
 
        
    return 0;
    }