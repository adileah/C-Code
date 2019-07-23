//Name: Adileah Smith & Melissa Zwickl
//Date: May 22, 2018
//Description: Making & Modifying Points



#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Point{
    public:
    Point(float x_point, float y_point){
        x = x_point;
        y = y_point;
    }
    
    float getXValue(){
        return x;
    }
    
    float getYValue(){
        return y;
    }
    
    float magnitude(){
        return sqrt((x * x) + (y * y));
    }
    
    void setXValue(float x_point){
        x = x_point;
    }
    
    void setYValue(float y_point){
        y = y_point;
    }
    
    void print(){
        cout << "X: " << x << " Y: " << y << endl;
    }
    
    
    private:
    float x;
    float y;
};

Point center(vector<Point> points){
    float totalX = 0.0;
    float totalY = 0.0;
    for (unsigned i = 0; i < points.size(); i++){
        totalX += points[i].getXValue();
    }
    for (unsigned i = 0; i < points.size(); i++){
        totalY += points[i].getYValue();
    }
    return Point(totalX / points.size(), totalY / points.size());
}

void movePoints(vector<Point> &points){
    Point c = center(points);
    for(unsigned i = 0; i < points.size(); i++){
        points[i].setXValue(points[i].getXValue() - c.getXValue());
        points[i].setYValue(points[i].getYValue() - c.getYValue());
    }
}

void printPairs(vector<Point> points){
        for (unsigned i = 0; i < points.size(); i++){
            points[i].print();
        }
    }

int main(){
    vector<Point> points;
    float x_point, y_point;
    
     cout << "Give me two points on a graph:" << endl;
     cin >> x_point;
     cin >> y_point;
     
     while(x_point != -99 && y_point != -99){
         points.push_back( Point(x_point, y_point) );
         cin >> x_point;
         cin >> y_point;
     }
     
     int answer = 1;
     while (answer != 0){
         cout << "What can I do for you now? Enter 0 to exit." << endl;
         cout << "1. Print current pairs" << endl;
         cout << "2. Add more pairs" << endl;
         cout << "3. Clear all pairs" << endl;
         cout << "4. Magnitude of all pairs" << endl;
         cout << "5. Find the center of two points" << endl;
         cout << "6. Move points to center of graph" << endl;
         cin >> answer;
         if (answer == 1){
            printPairs(points);
         }else if (answer == 2){
             cout << "Enter more (x, y) points and enter -99 -99 when finished!" << endl;
             cin >> x_point;
             cin >> y_point;
             
             while(x_point != -99 && y_point != -99){
                 points.push_back( Point(x_point, y_point) );
                 cin >> x_point;
                 cin >> y_point;
             }
         }else if (answer == 3){
             points.clear();
         }else if(answer == 4){
            for (unsigned i = 0; i < points.size(); i++){
                cout << points[i].magnitude() << endl;
            }
         }else if(answer == 5){
             cout << "Calculated center point is ";
             center(points).print();
         }
         else if(answer == 6){
             movePoints(points);
             
         }
     }
         
    return 0;
}