
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

char rotateWithinLetters(char letter, short amt){
    // For uppercase
    if(letter >= 'a' && letter <= 'z'){
        return ((letter - 'a' + amt + 26) % 26) + 'a';
    }
    // For lowercase
    else if(letter >= 'A' && letter <= 'Z'){
        return ((letter - 'A' + amt + 26) % 26) + 'A';
    }
    // For all others
    return letter; 
}

int main(int argc, char* argv[]){
    if(argc < 2){
        cout << "Enter a rotation amount on the command-line." << endl;
        return 0;
    }
    int amt = atoi(argv[1]);
    cout << "Will rotate by " << amt << " characters." << endl;
      
    string input_text;
    cout << "Enter text to incrypt/decrypt: ";
    getline(cin, input_text);
      
    for(int i = 0; i < input_text.length(); i++){
        input_text[i] = rotateWithinLetters(input_text[i], amt);
    }
    cout << endl << input_text << endl;
      
    return 0;
}