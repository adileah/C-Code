#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int fib(int number){
    int num1=0;
    int num2=1;
    int num3=1;
    int i=1;
    while(i<number){
        num3=num1+num2;
        num1=num2;
        num2=num3;
        //cout<<num3<<endl;
        i++;
    }
    return num3;
}
    

int fib2(int number, int indent){
    /*for(int i = 0; i < indent; i++){
        cout << " ";
    }
    cout << "Fib(" << number << ")" << endl;*/
    if(number <= 1){
        return 1;
    }else if(number == 2){
        return 1;
    }else{
        return fib2(number - 1, indent + 5) + fib2(number - 2, indent + 5);
    }
}

// dynamic programing solution
/*int fib3(vector<int> a, number){
    
}*/

// fast recursion
int fib4(int one, int two, int goal){
    if(goal == 1){
        return two;
    }
    return fib4(two, one + two, goal - 1);
}

int fib4(int goal){
    return fib4(0, 1, goal);
}

int loop_pow(int num, int power){
    int ret = 1;
    for(int i = 0; i < power; i++){
        ret = ret * num;
    }
    return ret;
}

int recur_pow(int num, int power){
    if(power == 0){
        return 1;
    }
    return num * recur_pow(num, power - 1);
}

string reverse(string s){
    for(unsigned i = 0; i < s.size()/2; i++){
        char temp = s.at(i);
        s.at(i) = s.at(s.size() - 1 - i);
        s.at(s.size() - 1 - i) = temp;
    }
    return s;
}

string reverse2(string s){
    if(s.size() == 0){
        return "";
    }
    return s.at(s.size() - 1) + reverse2(s.substr(0, s.size() - 1));
    
}

bool palindrome(string s){
    return s == string(s.rbegin(), s.rend());    
}

bool palindrome_recur(string s){
    if(s.size() <= 1){
        return true;
    }
    if(s[0] != s[s.size() - 1]){
        return false;
    }
    return palindrome_recur(s.substr(1, s.size() - 2));
}

int min(vector<int> v){
    if(v.size() == 0)return 0;
    if(v.size() == 1)return v[0];
    int min = v[0];
    for(unsigned i = 1; i < v.size(); i++){
        if( min > v[i]){
            min = v[i];
        }
    }
    return min;
}

int minr(vector<int> v){
    if(v.size() == 0)return 0;
    if(v.size() == 1)return v[0];
    int temp = v[0];
    v.erase(v.begin());
    int mr = minr(v);
    if( temp < mr){
        return temp;
    }else{
        return mr;
    }
}

int main(){
    srand(time(0));
    vector <int> vec;
    for (int i = 0; i < 8; i++){
        vec.push_back(rand() % 15);
    }
    
    cout << "Fibanaci" << endl << "for loop: " << fib(10) << endl;
    cout << "Recursion: " << fib2(10, 0) << endl;
    //cout << fib3(a, 5) << endl;
    cout << "Fast Recusion: " << fib4(10) << endl;
    cout << endl << endl;
    
    cout << "Power (2^5)" << endl << "Loop: " << loop_pow(2, 5) << endl;
    cout << "Recursion: " << recur_pow(2, 5) << endl;
    cout << endl << endl;
    
    cout << "Reverse string(cow potato)" << endl << "Loop: " << reverse("cow potato") << endl;
    cout << "Recursion: " << reverse2("cow potato") << endl;
    cout << endl << endl;
    
    cout << "Palindrome (tacocat)" << endl << "Loop: " << palindrome("tacocat") << endl;
    cout << "Recursion: " << palindrome_recur("tacocat") << endl;
    cout << endl << endl;
    
    cout << "Minimum For Vector: ";
    for (int i = 0; i < vec.size(); i++){
        cout << vec.at(i) << "  ";
    }
    cout << endl << "Loop: " << min(vec) << endl;
    cout << "Recusion: " << minr(vec) << endl;
    cout << endl << endl;
    
    
}