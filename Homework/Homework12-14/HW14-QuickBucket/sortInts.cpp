/*
Adileah Smith
11/28/18
Desc: sort
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "sort.h"
#include "timer.cpp"

using namespace std;

int main(int argc, char *argv[]){
    srand(time(0));
    string file = argv[2];
    int choice = atoi(argv[1]);
    vector<unsigned> sortMe;
    
    ifstream inFile;
    //string word;
    inFile.open(file.c_str());
    while(!inFile.eof()){  // Just using inFile will duplicate the last line.
        int num;
        inFile >> num;
         if(inFile.fail())break;
        sortMe.push_back(num);
         // .eof() will be false at the end correctly.
    }
    inFile.close();
    /*for(unsigned i = 0; i < 10; i++)
            cout << sortMe[i] << " ";
    cout << endl;*/
    if(choice == 1){
        sortMe = bubbleSort(sortMe);
        for(unsigned i = 0; i < sortMe.size(); i++)
            cout << sortMe[i] << " ";
    }
    else if (choice == 2){
        sortMe = heapSort(sortMe);
        for(unsigned i = 0; i < sortMe.size(); i++)
            cout << sortMe[i] << " ";
    }
    else if(choice == 3){
        sortMe = mergeSort(sortMe);
        for(unsigned i = 0; i < sortMe.size(); i++)
            cout << sortMe[i] << " ";
    }
    else if(choice == 4){
        sortMe = quickSort(sortMe);
        for(unsigned i = 0; i < sortMe.size(); i++)
            cout << sortMe[i] << " ";
    }
    else if(choice == 5){
        sortMe = countingSort(sortMe);
        for(unsigned i = 0; i < sortMe.size(); i++)
            cout << sortMe[i] << " ";
    }
    else{
        //sortMe=bubbleSort(sortMe);
        for(unsigned i = 0; i < sortMe.size(); i++)
            cout << sortMe[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}