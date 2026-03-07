#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main(int argc,char *argv[]){

    string fileName;
    cout<<"Enter the name of a file to read from: "<<endl;
    cin>>fileName;

    ifstream inFile (fileName);
    if (inFile.good()){
        string line;
        int nLines = 0;
        int nEmpty = 0;
        int nWords = 0;
        int nDigits = 0;

        while (getline(inFile, line))
        {
            nLines++;
            if (line.empty()){
                nEmpty++;
            }
            istringstream isStream(line); 
            string currWord;
            while (isStream>>currWord){
                //cout<<"this is the word "<<currWord<<endl;
                nWords++;
                int currLen = currWord.length();
                int holder1 = 0;
                int holder2 = 0;
                for (int i = 0; i < currLen; i++){

                    if (isdigit(currWord[i])){
                        holder2++;
                    }
                } 

                if(currLen==1 && !isalpha(currWord[0])){
                }

                else if(holder2==currLen ||(holder2==currLen-1 && currWord[0] == '+')|| (holder2==currLen-1 && currWord[0] == '-')){
                    nDigits++;
                }

            }

            
        }

        if (nLines==0){
            cout<<"Total Number of Lines: "<<nLines<<endl;
            cout<<"Number of non-blank lines: "<<nLines-nEmpty<<endl;
            cout<<"Number of Words: "<<0<<endl;
            cout<<"Number of Integers: "<<0<<endl;
        }

        else{
            cout<<"Total Number of Lines: "<<nLines<<endl;
            cout<<"Number of non-blank lines: "<<nLines-nEmpty<<endl;
            cout<<"Number of Words: "<<nWords<<endl;
            cout<<"Number of Integers: "<<nDigits<<endl;
        }
        
    }

    else{
        cout<<"File could not be opened "<<fileName;
    }
    

    return 0;
}
