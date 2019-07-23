//Adileah Smith and Melissa Zwickl
//Date: May 17, 2018
//Description: Input words & string stuff

#include <iostream>
#include <vector>
#include <cstdlib>


using namespace std;

int addition(const vector<string> &a){ 
    int total = 0;
    for(unsigned i = 0; i < a.size(); i++){
        total += a[i].size();
    }
    return total;
}

float average(const vector<string> &a){
    return (float)addition(a) / a.size();
} 

void print(const vector<string> &a){
    for(unsigned i = 0; i < a.size(); i++){
        cout << a.at(i) << " ";
    }
    cout << endl;
}

int amount_letter(const vector<string> &a, char variable){
    int count = 0;
    for (unsigned i = 0; i < a.size(); i++){
        for (unsigned j = 0; j < a[i].size(); j++){
            if (a.at(i)[j] == variable || a.at(i)[j] == variable - 'a' + 'A'){
                count++;
            }
        }
    }
    return count;
}


int main(){
    vector<string> a;
    //vector<int> sorted;
    string temp;
    
    cout << "Give me any amount of words you want to, typing zzzzz (5 z's) to signal the end." << endl;
    cin >> temp;
    while(temp != "zzzzz"){
        a.push_back(temp);
        cin >> temp;
    }
    
    cout<<"You entered: "<< a.size() << " words." << endl;
    cout<<"Your average word length is: "<< average(a)<< endl;
    
    float total_letters = 0.0;
    
    for(char c = 'a'; c <= 'z'; c++){
        cout << "Amount of "<< c << " " << amount_letter(a, c) << endl;
        total_letters = amount_letter(a, c) + total_letters;
    }
    for(char c = 'a'; c <= 'z'; c++){
       cout << "Average number of " << c << "'s for each word is " << amount_letter(a, c) / total_letters << endl;
    }
    return 0;
}

