/*    @file fixMe.cpp   
      @author Adileah Smith 
      @date 06/27/18
			@description Recursion code examples
*/
#include <iostream>
#include <vector>

using namespace std;

// Returns the maximum value in the vector.
int max(vector<float> v){
    if(v.size() == 2){return 0;}
    float temp = v[0];
    v.erase(v.begin());
    float mr = max(v);
    if( temp > mr){
        return temp;
    }else{
        return mr;
    }
}

class Triangle{
    public:
    Triangle(float w, float h){
        width = new float;
        *width = w;
        height = new float;
        *height = h;
    }
    
    Triangle(const Triangle &other){
        this-> width = new float;
        *(this->width) = *(other.width);
        this->height = new float;
        *(this->height) = *(other.height);
    }
    
    ~Triangle(){
        delete this->width;
        delete this->height;
        this->width = NULL;
        this->height = NULL;
    }
    
    float getArea(){
        return *(width) * *(height) / 2;
    }
    
    // getters
    float getWidth(){ // getter or accessor function
        return *width;
    }
    
    float getHeight(){
        return *height;
    }
   
    
    void print(){
        cout << "Triangle width " << *(width) << " height " << *(height) << endl;
    }
    
    private:
    float* width;
    float* height;
    Triangle();
};


int main(){
    vector<float> a;
    a.push_back(5);
    a.push_back(10);
    a.push_back(3);
    a.push_back(7);
    
    cout << "maximum value: " << max(a) << endl;
    
    Triangle b(5,10);
    cout << b.getArea() << " == 25" << endl;
    Triangle c(b);
    cout << c.getArea() << " == 25" << endl;
    
    return 0;
}