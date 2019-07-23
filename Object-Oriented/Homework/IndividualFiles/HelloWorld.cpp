/* 
Adileah Smith
csci 156 - summer term
Homework 1
*/
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    
    cout << "argc: " << argc << endl;
    for(int i = 0; i < argc; i++){
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }
    if (argc == 1){
        cout << "Hello World!" << endl;
        
    }else if (argc == 2){
            cout << "Hello " << argv[1] << "!!!" << endl;

    }else{
        for(int i = 0; i < atoi(argv[2]); i++){
            cout << "Hello " << argv[1] << "!!!" << endl;
        }
    }
    
    return 0;
}