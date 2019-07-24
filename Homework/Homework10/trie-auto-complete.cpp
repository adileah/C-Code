/* Name: Adileah Smith, Mel Moore, Trey Bowman
   Date: Oct 28, 2018
   Desc: Demo code to run a simple HTTP webserver.
   
   Compile with: g++ trie-auto-complete.cpp
*/

#include "http-server.cpp"
#include "TrieCopy.h"
#include <iostream>

using namespace std;

Trie trie;

// Convert a vector of strings into a JSON list
string listify(const vector<string> &list){
    stringstream s;
    s << "[";
    for(unsigned i = 0; i < list.size(); i++){
        s << "\"" << list[i] << "\"";
        if(i != list.size() -1){
            s << ",";
        }
    }
    s << "]";
    return s.str();
}

string doStuff(string query){
    vector<string> temp;
    vector<string> tomato = trie.getAllWords(query);
    vector<unsigned> count = trie.getAllCount(query);
    int place;
    for(unsigned j = 1; j <= tomato.size(); j++){
        place = 0;
          for(unsigned i = 1; i < tomato.size(); i++){
            if (count[place] < count[i]){
                place = i;
            }
        }
        if(j > 5 ){
            break;
        }
            temp.push_back(tomato[place]);
            count[place] = 0;
    }
    for(unsigned x = 0;x < temp.size();x++){
        
        cout << temp[x] << endl;
    }
    return listify(temp);
}

int main(int argc, char *argv[]){
    srand(time(0));
    string file = argv[1];
    ifstream inFile;
    inFile.open(file.c_str());
    string word;
    while(inFile >> word){
        if(word[word.size() - 1] == ','||word[word.size() - 1] == '.'){
            word = word.substr(0, word.size() - 1);
        }
        trie.insert(word);
    }
    inFile.close();
    // Start the webserver on port 8080
    HTTPServer server(8080);
    // Whenever /cgi-bin/doStuff? is accessed, call the given function with
    // everything after the ? as a paramter.
    server.addCallback("query", doStuff);
    
    // Run the server (will loop forever)
    server.run();
}