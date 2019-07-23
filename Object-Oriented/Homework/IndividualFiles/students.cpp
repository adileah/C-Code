#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student{
    public:
    Student(string n, int a, float g, float t){
        name = n;
        age = a;
        gpa = g;
        attendance = t;
    }
    
    float getGPA(){
        return gpa;
    }
    int getAge(){
        return age;
    }
    string getName(){
        return name;
    }
    float getAttendance(){
        return attendance;
    }
    void setGPA(float g){
        gpa = g;
    }
    void setAge(int a){
        age = a;
    }
    void setName(string n){
        name = n;
    }
    void setAttendance(float t){
        attendance = t;
    }
    
    void print(){
        cout << "Name: " << name << endl;
        cout << "GPA: " << gpa << endl;
        cout << "Age: " << age << endl;
        cout << "Attendance (Percentage): " << attendance << "%" << endl;
    }
    
    
    private:
    string name;
    int age;
    float gpa;
    float attendance;
};

void searchName(vector<Student> students, string search){
    for (unsigned i = 0; i < students.size(); i++){
        if (search == students[i].getName()){
            students[i].print();
        }
    }
}

float averageGPA(vector<Student> students){
    float total_GPA = 0.0;
    for (unsigned i = 0; i < students.size(); i++){
        total_GPA += students[i].getGPA();
    }
    return total_GPA/students.size();
}

int main(){
    string n;
    int a;
    float g, t;
    vector<Student> students;
    
    cout << "Enter students with name, age, gpa, and attendance %. Enter STOP 0 0 0 when done." << endl;
    cin >> n;
    cin >> a;
    cin >> g;
    cin >> t;
    
    while(n != "STOP"){
        students.push_back( Student(n, a, g, t) );
        cin >> n;
        cin >> a;
        cin >> g;
        cin >> t;
    }
    int answer = 1;
    while (answer != 0){
        cout << "1. Enter more students." << endl;
        cout << "2. Search for student by name." << endl;
        cout << "3. Print out all students." << endl;
        cout << "4. Find amount of students and average GPA." << endl;
        cout << "Enter 0 to quit." << endl;
        cin >> answer;
        if (answer == 1){
            cout << "Enter students with name, age, gpa, and attendance %. Enter STOP 0 0 0 when done." << endl;
            cin >> n;
            cin >> a;
            cin >> g;
            cin >> t;
            while(n != "STOP"){
                students.push_back( Student(n, a, g, t) );
                cin >> n;
                cin >> a;
                cin >> g;
                cin >> t;
            }
        }else if(answer == 2){
            string search;
            cout << "Give me a name to search for." << endl;
            cin >> search;
            searchName(students, search);
        }else if(answer == 3){
            for (unsigned i = 0; i < students.size(); i++){
                students[i].print();
            }
        }else if(answer == 4){
            cout << "Students: " << students.size() << endl;
            cout << "Average GPA: " << averageGPA(students) << endl;
        }
    }
    
    return 0;
}