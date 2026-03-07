#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

bool inLanguage(string & inputString){
    string s = inputString;

    if (s.length()==0){
        cout<<"entered?"<<endl;
        return false;
    }
    std::stack<char>myStack;
    char p[s.length()];
    bool seen = false;
    if (s.length()==1){
        if (s=="$"){
            return true;
        }
        else{
            return false;
        }
    }

    

    for (int i = 0; i < sizeof(p); i++) {
        if (s[i]!='$'&& seen == false){
            myStack.push(s[i]);
        }

        
        else{
            if(s[i]=='$'){
                i++;
            }
            seen = true;
            if (myStack.top() == s[i]){
                myStack.pop();
                continue;
            }
            else{
                return false;
            }       
        }
    }

    if (myStack.empty()){
        return true;
    }

    if (!seen){
        cout<<"string is missing $."<<endl;
    }

    return false;
}


int main(int argc, char *argv []){
	string sentence;
	bool isInLanguage;
    bool variable2 = false;
	int Lcount=0;
	
	ifstream file;
	if( argc >= 2 ) {
		file.open(argv[1]);
		if( !file) 
		{
			/* error */ 
			cerr << "File cannot be opened: " << argv[1] << endl;
			exit (1);
        }
				
	}
	else
	{
		cerr << "No file is found" << endl;
		exit (1);
	}
	
	getline(file, sentence);
    if (sentence.length()==0){
        variable2 = true;
        cout<<"Empty string is not in the Language."<<endl;
    }
       
    while ( !file.eof() && variable2!=true) {
       	Lcount++;
       	isInLanguage = inLanguage(sentence);
       	if (isInLanguage)
       	{
       		cout << sentence << " is a sentence in the Language." << endl;
		}
		else
		{
            cout << sentence << " is not a sentence in the Language." << endl;
			
		}
		 	
		getline(file, sentence); 
	}
}