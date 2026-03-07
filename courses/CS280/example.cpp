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
}//PrintStmt```