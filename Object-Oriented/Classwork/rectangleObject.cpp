#include <iostream>
#include <vector>
#include <math.h>
/*
    two vectors: one with heights, another with widths
*/

using namespace std;

class Rectangle{
    public:
    Rectangle(float w, float h, string c){
        width = w;
        height = h;
        color = c;
    }
    
    float getPerimeter(){
        return width * 2 + height * 2;    
    };
    
    void print(){
        cout << "( " << width << " , " << height << ") " << endl << "color is " << color << endl;
    }
    
    float getArea(){
        return width * height;
    }
    float width;
    float height;
    string color;
};


void printArea(vector<Rectangle> rectangles){
    int area = 0;
    for(int i = 0; i < rectangles.size(); i++){
        cout << "Area of rectangle " << i << " is: " << rectangles[i].getArea()<< endl; 
        area += rectangles[i].getArea();
    }
    cout << "Total area is: " << area << endl;
}

void printPairs(vector<Rectangle> rectangles){
    for(int i = 0; i < rectangles.size(); i++){
        rectangles[i].print();
        cout << "Perimeter is " << rectangles[i].getPerimeter() <<  endl;
    }
}



int main(){
    // height
    // width
    // perimeter
    // area
    vector<Rectangle> rectangles;
    
    float w, h;
    string c; 
    cout << "Give me width, height, followed by \"-99 -99 none\" to end" << endl;
    cin >> w;
    cin >> h;
    cin >> c;
    
    while(w != -99 && h != -99 && c != "none"){ // fixme
        rectangles.push_back( Rectangle(w,h,c) );
        cin >> w;
        cin >> h;
        cin >> c;
    }
    
    printPairs(rectangles);
    
    // print total area of all rectangles.
    //  print out areas
    printArea(rectangles);
    
    // add color attribute
    
    
    
}