#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*Adileah Smith
9/03/18
Homework 1
creates groups for CSCI 240*/

using namespace std;

void randomize(vector <string> &names, int times){
    for(int i = 0; i < names.size() - 1; i++){
        int rando = rand() % 27;
        string temp = names[rando];
        names[rando] = names[0];
        names[0] = temp;
    }
    if(times != 0){
        times--;
        randomize(names, times);
    }
}

int main(){
    srand(time(0));
    ifstream inFile;
    string word;
    vector<string> names;
    inFile.open("names.txt");
    while(inFile){
        getline(inFile, word);
        names.push_back(word);
    }
    for(int i = 0; i < names.size() - 1; i ++){
        cout << names[i] << endl;
    }
    cout << endl << endl << endl;
    randomize(names, 25);
    for(int i = 0; i < names.size() - 1; i ++){
        cout << names[i] << endl;
    }
    cout << endl << endl << endl;
    int groups;
    int size_groups;
    cout << "Give me how many groups you need: ";
    cin >> groups;
    size_groups = names.size() / groups;
    for(int i = 0; i < names.size() - 1; i++){
        cout << names[i] << endl;
        if((i + 1) % size_groups == 0){
            cout << endl << endl;
        }
    }
    return 0;
}