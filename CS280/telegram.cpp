#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <map>

using namespace std;
//

int main(int argc,char *argv[]){

    string fileName;
    cin>>fileName;
    map<string,string> myMap = {{"AA","B"},{"AD","2"},{"AF","E"},{"AG","5"},{"AV","R"},{"AX","L"},{"DA","I"},{"DD","9"},{"DF","N"},{"DG","A"},{"DV","1"},{"DX","C"},{"FA","3"},{"FD"," D"},{"FF","4"},{"FG","F"},{"FV"," 6"},{"FX"," G"},{"GA","7"},{"GD"," H"},{"GF","8"},{"GG","J"},{"GV"," 0"},{"GX"," K"},{"VA","M"},{"VD"," O"},{"VF","P"},{"VG","Q"},{"VV"," S"},{"VX"," T"},{"XA","U"},{"XD"," V"},{"XF","W"},{"XG","X"},{"XV"," Y"},{"XX"," Z"}};
    std::map<string,string>::iterator it;


    int count = 0;

    ifstream inFile (fileName); 
    std::string word = "";
    if (inFile.good()){
        string line;
         while (getline(inFile, line)){
            istringstream isStream(line); 
            string currWord;
            while (isStream>>currWord){

                it = myMap.find(currWord);
                string value= it->second;
                cout<< value;
            }            

        }
        cout<< " "<<endl;

    }

    

    return 0;
}

