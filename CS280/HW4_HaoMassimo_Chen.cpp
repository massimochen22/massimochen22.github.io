#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

int main(int argc,char *argv[]){

    ifstream inFile;
    inFile.open(argv[1]);
    //inFile.open("infile4.txt");
    
    if(inFile.is_open()){
        map<char,int> myMap;

        char tempChar;
        int totDig = 0;
        int totLet = 0;

        int nChar = 0;
        int maxNumLetters = 0;
        int maxNumDigits = 0;

        while (inFile.get(tempChar)){

            if (isdigit(tempChar)){
                nChar++;
                totDig++;
                myMap[tempChar]++;
            }

            else if (ispunct(tempChar)){
                nChar++;
                myMap[tempChar]++;
            }

            else if (isalpha(tempChar)){
                nChar++;
                totLet++;
                char c = toupper(tempChar);
                myMap[c]++;
            }

            else{
                continue;
            }
    

        }

        inFile.close();



        if (nChar>0){

            
            //int maxNumLetters = 0;
            //int maxNumDigits = 0;

            int nPunct = 0;

            for(auto it = myMap.begin(); it!=myMap.end();it++){

                int value= it->second;
                char key = it->first;
 
                if (isalpha(key)&& value>maxNumLetters ){

                    maxNumLetters = value;

                }

                else if (isdigit(key)&&value>maxNumDigits){

                    maxNumDigits = value;

                }

                else if (ispunct(key)){
                    nPunct++;
                }

            }
            
            if (totDig>0){
                for(auto it2 = myMap.begin(); it2!=myMap.end();it2++){

                    int value2= it2->second;
                    char key2 = it2->first;

                    if (isdigit(key2) && value2 == maxNumDigits){
                        cout<<"Digits of Largest number of occurrences: "<<key2<<": "<<value2<<endl;
                    }
                }
            }

            if (totLet>0){
                for(auto it3 = myMap.begin(); it3!=myMap.end();it3++){
                    int value3= it3->second;
                    char key3 = it3->first;

                    if (isalpha(key3) && value3 == maxNumLetters){
                        cout<<"Letters of Largest number of occurrences: "<< key3<<": "<<value3<<endl;
                    }
                }
            }

            cout<<"List of characters seen in the file and their number of occurrences:"<<endl;

            for(auto it4 = myMap.begin(); it4!=myMap.end();it4++){

                cout<<it4->first<<": "<<it4->second<<endl;

            }

            cout<<"Number of non-alphanumeric characters seen in the file: "<<nPunct<<endl;
                



            
        }

        else{
            cout<<"File is empty."<<endl;
        }

        

    }
        

    else{
        cout <<"File cannot be opened: "<< argv[1] << endl;
        exit(1);
        }
        

    return 0;
}
