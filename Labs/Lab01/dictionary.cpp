#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/*Adileah Smith
8/29/18
Lab 1*/

using namespace std;

int main(){
    ifstream inFile;
    string word;
    vector<string> dictionary;
    inFile.open("dictionary.txt");
    while(inFile){
        getline(inFile, word);
        dictionary.push_back(word);
    }
    
    string search = "potato bisquits";
    while (search != "0"){
        cout << "Give me a word to search for: " << endl;
        cin >> search;
        for(int i = 0; i < dictionary.size(); i++){
            bool equal = true;
            word = dictionary[i];
            for(int j = 0; j < search.size(); j++){
                if(search[j] != word[j]){
                    equal = false;
                }
            }
            if(equal){
                cout << word << endl;
            }
        }
    }
    
    
    
    return 0;
}