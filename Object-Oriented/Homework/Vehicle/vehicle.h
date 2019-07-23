#ifndef VEHICLE_H
#define VEHICLE_H  

/*    @file vehicle.cpp   
      @author Adileah Smith
      @date Jun 17 2018

			@description Implements 5 classes for vehicle information
*/

#include <string>

using namespace std;

const int CURRENT_YEAR = 2018;  // Use this variable whever you are doing
                                // your price/year calculations.

class Vehicle {
    public:
    int wheels;
    float price;
    int passengers;
    int year;
    string color;
    int getPassengers(){return passengers;}
    int getWheels(){return wheels;}
    int getYear(){return year;}
    void setYear(int y){
        if (y > CURRENT_YEAR){
            year = CURRENT_YEAR;
        }else{
            year = y;
        } 
    }
    void setColor(string c){color = c;}
    string getColor(){return color;}
};

class Car : public Vehicle {
    private:
    bool air;
    bool dvd;
    public:
    Car(){
        wheels = 4;
        price = 0;
        passengers = 4;
        year = 2016;
        color = "indigo";
        air = false;
        dvd = false;
    }
    void setPassengers(int p){
        while(p < 1 || p > 10){
            cout << "enter valid number of passengers" << endl;
            cin >> p;
        }
        passengers = p;
    }
    void setWheels(){wheels = 4;}
    float getPrice(){
        float potato = price;
        if(air){potato+=200;}
        if(dvd){potato+=100;}
        potato+=5000*passengers;
        potato-=500*(CURRENT_YEAR-getYear());
        if (potato <= 100){return 100;}
        return potato;
    }
    void setAir(bool a){air = a;}
    void setDvd(bool d){dvd = d;}
    bool getAir(){return air;}
    bool getDvd(){return dvd;}
};

class Bike : public Vehicle {
    public:
    Bike(){
        wheels = 2;
        price = 1000;
        passengers = 1;
        year = 2016;
        color = "green";
    }
    void setPassengers(){passengers = 1;}
    void setWheels(){wheels = 2;}
    void setPrice(){price = 1000;}
    float getPrice(){
        float potato = price-100.0*(CURRENT_YEAR - getYear());
        if(potato <= 0){return 0;}
        else{return potato;}
    }
};

class Truck : public Vehicle {
    private:
    int cap;
    public:
    Truck(){
        wheels = 10;
        price = 10000;
        passengers = 4;
        year = 2016;
        color = "brown";
        cap = 1000;
    }
    void setPrice(){price = 10000;}
    void setPassengers(int p){
        while(p < 1 || p > 4){
            cout << "enter valid number of passengers" << endl;
            cin >> p;
        }
        passengers = p;
    }
    void setWheels(int w){
        while(w < 4 || w > 16){
            cout << "enter valid number of wheels" << endl;
            cin >> w;
        }
        wheels = w;
    }
    float getPrice(){
        float potato = price;
        potato = potato + 1000*passengers + 1.25*cap + 200*wheels;
        potato = potato - 500*(CURRENT_YEAR-getYear());
        if (potato <= 200){return 200;}
        return potato;
    }
    void setCap(int c){
        while(cap < 0 || cap > 20000){
            cout << "Enter valid weight held" << endl;
            cin >> c;
        }
        cap = c;
    }
    int getCap(){return cap;}
};

class Airplane : public Vehicle {
    private:
    float cap;
    int props;
    public:
    Airplane(){
        price = 15000;
        passengers = 37;
        year = 2016;
        color = "black";
        cap = 1000;
        props = 3;
    }
    void setPrice(){price = 15000;}
    void setPassengers(int p){
        while(p < 1 || p > 40){
            cout << "enter valid number of passengers" << endl;
            cin >> p;
        }
        passengers = p;
    }
    float getPrice(){
        float potato = price;
        potato+=1000*passengers + 5.25*cap + 100*props;
        potato-=500*(CURRENT_YEAR-year);
        if (potato <= 1000){
            return 1000;
        }
        return potato;
    }
    void setWheels(){wheels = 0;}
    void setCap(int c){
        while(cap < 0 || cap > 20000){
            cout << "Enter valid weight held" << endl;
            cin >> c;
        }
        cap = c;
    }
    int getCap(){return cap;}
    void setProps(int p){props = p;}
    int getProps(){return props;}
    
};



#endif
