#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int ForLoopVector(vector<int> gigundo, int asparagus){
    int found = 0;
    for(unsigned i = 0; i<gigundo.size(); i++){
        if(gigundo[i] == asparagus){
            found = 1;
        }
    }
    return found;
}

void fillRandVector(vector<int> &v, int size){
    for(int i = 0; i < size; i++){
        v.push_back(rand() % 10000);
    }
}
void fillRandSet(set<int> &s, int size){
    for(int i = 0; i < size; i++){
        s.insert(rand() % 10000);
    }
}

int main(){
    srand(time(0));
    int spork = 5234;
    set<int> aglet;
    fillRandSet(aglet, 1000000);
    vector<int> ostrich;
    fillRandVector(ostrich, 1000000);
    
    clock_t s_begin = clock();
    cout << aglet.count(spork) << endl;
    clock_t s_end = clock();
    
    clock_t v_begin = clock();
    cout << ForLoopVector(ostrich, spork) << endl;
    clock_t v_end = clock();
    
    cout << "number of values: " << ostrich.size() << endl;
    cout << "Set Count: " << (float)(s_end - s_begin) / (float)CLOCKS_PER_SEC << endl;
    cout << "For Loop Vector: " << (float)(v_end - v_begin) / (float)CLOCKS_PER_SEC << endl;
}