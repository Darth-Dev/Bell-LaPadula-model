#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "refMon.h"
using namespace std;

int main(int argc, char** argv){

    refMon* refMonObj = new refMon();


    if(argc < 2 || argc >= 3){
        cout << "Usage: ./secureblp instructionList\n";
        return 1;
    }

    ifstream fstream(argv[1]);

    string line, word;
    string delim = " ";
    int pos;
    vector<string> tokens;

    while(getline(fstream, line, '\n')){

        istringstream ss(line);
        while(ss >> word){
            tokens.push_back(word);
            //cout << word << " ";
        }
        /*for (size_t i = 0; i < tokens.size(); i++)
        {
            cout << tokens[1] << " ";
            cout << (tokens[0] == "addsub") << " ";
        }*/
        


            if(tokens[0] == "addsub"){
                refMonObj->addSub(tokens[1], tokens[2]);
                tokens.clear();
                continue;

            }
            else if(tokens[0] == "addobj"){
                refMonObj->addObj(tokens[1], tokens[2]);
                tokens.clear();
                continue;
            }
            else if(tokens[0] == "status"){
                refMonObj->status();
                tokens.clear();
                continue;
            }
            else if(tokens[0] == "read"){
                refMonObj->read(tokens[1], tokens[2]);
                tokens.clear();
                continue;
            }
            else if(tokens[0] == "write"){

                try{
                    stoi(tokens[3]);
                    
                     
                }
                catch(...){
                    cout << "Bad Instruction : "; 
                    for(int i=0; i<tokens.size(); i++){cout << tokens[i] << " ";}cout << endl;
                    tokens.clear();
                    continue;
                }
                refMonObj->write(tokens[1], tokens[2], stoi(tokens[3]));
                tokens.clear();
                continue;
            }

                if( tokens[0] == "status"){
                    cout << "Bad Instruction : "; for(int i=0; i<tokens.size(); i++){cout << tokens[i] << " ";}cout << endl;
                }

    tokens.clear();
        
    }

    


    return 0;
}