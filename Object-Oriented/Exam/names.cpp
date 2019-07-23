#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void sort(vector<string> names){
    string t; 
    for(int i = 0; i < names.size(); i++){
        for(int j = 1; j < names[i].size(); j++){
			if(strcmp(names[i][j-1], names[i][j]) > 0){
				strcpy(t, names[i][j-1]);
				strcpy(names[i][j-1], names[i][j]);
				strcpy(names[i][j], t);
			}
		}
    }
}

int main(){
    vector<string> names;
    string temp;
    
    cout << "Enter as many names as you want! Then type \"END\" when you are done!" << endl;
    cin >> temp;
    while(temp != "END"){
        names.push_back(temp);
        cin >> temp;
    }
    for(int i = 0; i < names.size(); i++){
        cout << "Hello " << names[i] << "!" << endl;
    }
    
    for(int i = names.size(); i > 0; i--){
        cout << names[i - 1] << endl;
    }
    return 0;
}