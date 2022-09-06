#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main(int argc,char *argv[]){

    string fileName;
    //cout<<"Enter the name of a file to read from: "<<endl;
    ifstream inFile;
    istream *in = &cin;



    if(argc > 1){
        
        inFile.open(argv[1]);
        if(inFile.is_open()){
            in = &inFile;
        }
            

        else{
            cerr <<"File cannot be opened: "<< argv[1] << endl;
            exit(1);
            }
        
    }



    string line;
    int nLines = 0;
    int nEmpty = 0;
    int nWords = 0;
    int nDigits = 0;
    int nLetters = 0;
    int nChar = 0;
while (getline(*in, line))
{
        nChar = nChar + line.length();
        
        nLines++;

        if (line.empty()){
            nEmpty++;
        }
        istringstream isStream(line); //modify this part
        string currWord;
        while (isStream>>currWord){
            //cout<<"this is the word "<<currWord<<endl;
            
            
            int currLen = currWord.length();


            nWords++;
            

            for (int i = 0; i < currLen; i++){

                if (isdigit(currWord[i])){
                    nDigits++;
                }

                if (isalpha(currWord[i])){
                    nLetters++;
                }

            } 

        }

    

        
    }

    
    if (nLines==0){
        cout<<"File is empty."<<endl;
    }

    else{
        cout<<"LINES: "<<nLines<<endl;
        cout<<"WORDS: "<<nWords<<endl;
        cout<<"CHARS: "<<nChar + nLines<<endl;
        cout<<"DIGITS: "<<nDigits<<endl;
        cout<<"LETTERS: "<<nLetters<<endl;
    }

    return 0;
}
