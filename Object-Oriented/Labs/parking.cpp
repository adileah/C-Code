/*Adileah Smith and Jared Hilt
Parking Lot lab
*/
#include <iostream>
#include <vector>

using namespace std;

class Car{
    public:
    //Constructors
    Car(string n){
        name = n;
    }
    
    //Getters and Setters
    string getName(){return name;}
    void setName(string n){name = n;}
    
    private:
    string name;
    
};

class ParkingLot{
    public:
    //Constructor
    ParkingLot(string n, unsigned s, float r){
        name = n;
        spots_avail = s;
        rate = r;
    }
    
    void addCar(){
        string name;
        
        cout << "What is the name?" << endl;
        cin >> name;
        
        cars_in_lot.push_back(*(new Car(name)));
        spots_avail--;
        spots_taken++;
    }
    
    void removeCarByName(){
        bool input = 1;
        bool car_found = false;
        while(input && !car_found){
            for (unsigned i = 0; i < cars_in_lot.size(); i++){
                cout << cars_in_lot.at(i).getName() << "\t";
                if (i > 0 && i % 5 == 0){
                    cout << endl;
                }
            }
            cout << endl;
            string search;
            cout << "What car do you want to remove?" << endl;
            cin >> search; 
            
            
            
            for (unsigned i = 0; i < cars_in_lot.size(); i++){
                if (cars_in_lot.at(i).getName().find(name)){
                    car_found = true;
                    cout << "We found the car and have removed it!" << endl;
                    cars_in_lot.erase(cars_in_lot.begin()+i);
                    spots_avail++;
                    spots_taken--;
                }
            }
            if(!car_found){
                
                cout << "We couldn't find your car! Would you like to search again? [1/0]" << endl;
                cin >> input;
            }
        }
    }
    
    void enter(){
        addCar();
    }
    
    void leave(){
        removeCarByName();
    }
    
    //Getters and Setters
    void setSpotsAvailable(unsigned a){spots_avail = a;}
    void setSpotsTaken(unsigned t){spots_taken = t;}
    void setRate(float r){rate = r;}
    void setName(string n){name = n;}
    unsigned getSpotsAvailable(){return spots_avail;}
    unsigned getSpots_taken(){return spots_taken;}
    float getRate(){return rate;}
    string getName(){return name;}
    
    float getProfit(){
        return cars_in_lot.size()*rate;
    }

    void printStats(){
        cout << "The " << name << " Lot" << endl;
        cout << "There are " << spots_avail << " spots available." << endl;
        cout << "There are " << spots_taken << " spots taken" << endl;
        cout << "The rate is $" << rate << endl;
        cout << endl;
    }

    private:
    string name;
    unsigned spots_avail, spots_taken;
    float rate;
    vector<Car> cars_in_lot;
};



void addLot(vector<ParkingLot> &pl){
    string name;
    unsigned rate = 0;
    unsigned spots = 0;
    cout << "Enter new lot name, rate, and number of spots." << endl;
    cin >> name;
    cin >> rate;
    cin >> spots;
    
    pl.push_back(*(new ParkingLot(name, spots, rate)));
}

void makeStandardLots(vector<ParkingLot> &parking_lots){
    parking_lots.push_back(*(new ParkingLot("Economy", 20, 5)));
    parking_lots.push_back(*(new ParkingLot("Standard", 60, 10)));
    parking_lots.push_back(*(new ParkingLot("Premium", 30, 20)));
}

void printMenu(vector<ParkingLot> &pl){
    for (unsigned i = 0; i < pl.size(); i++){
        pl.at(i).printStats();
        cout << endl;
    }
    
    for(unsigned i = 0; i < pl.size(); i++){
        cout << i+1 << ": Enter " << pl.at(i).getName() << " Lot" << endl;
    }
    for(unsigned i = 0; i < pl.size(); i++){
        cout << pl.size() + i + 1 << ": Exit " << pl.at(i).getName() << " Lot" << endl;
    }
    
    cout << pl.size() * 2 + 1 << ": Add Lot" << endl;
    cout << pl.size() * 2 + 2 << ": Get Profit" << endl;
    cout << pl.size() * 2 + 3 << ": Exit" << endl;
    
    
}

void printProfit(vector<ParkingLot> &pl){
    float daily_profit = 0;
    for(unsigned i = 0; i < pl.size(); i++){
        daily_profit += pl.at(i).getProfit();
    }
    
    cout << "The daily profit is currently at $" << daily_profit << "/day." << endl << endl;
    
}

void getUserChoice(vector<ParkingLot> &pl){
    
    unsigned choice = 1;
    while (choice >=1 && (choice <=pl.size() * 2 + 2)){
        printMenu(pl);
        cout << "What would you like to do?" << endl;
        cin >> choice;
        
        while (choice > pl.size() * 2 + 3){
            cout << "Please input a valid choice..." << endl;
            cin >> choice;
        }
        
        if (choice <= pl.size()){
           pl.at(choice - 1).enter();
        }else if(choice <= pl.size() * 2){
            pl.at(choice % pl.size() - 1).leave();
        }else if(choice == pl.size() * 2 + 1){
            addLot(pl);
        }else if(choice == pl.size() * 2 + 2){
            printProfit(pl);
        }else if(choice == pl.size() * 2 + 4){
            return;
        }
    }
    
}

/*void runLoop(vector<ParkingLot> &pl){
    bool running = true;
    
}*/



int main(){
    vector <ParkingLot> parking_lots;
    makeStandardLots(parking_lots);
    
    getUserChoice(parking_lots);
    
    return 0;
}