#ifndef PROPERTY_H
#define PROPERTY_H

/*
    @author < Fill Me In >
    @date < Fill Me In >
	Simple non-pointer object demo Property interface file.
*/

#include <string>

using namespace std;

// Class to store information about a property able to give the yearly taxes.
class Property{
  private:

  string address;
  float* square_foot; 

  public:
  Property();
  Property(string addr);
  Property(string addr, float sqft);
  Property(const Property &other);
  
  ~Property();
  
  Property& operator=(const Property &);
   
  // Setters
  void setAcres(float acres);
  void setSquareFt(float sqft);
  
  // Getters
  string getAddress() const;
  
  float getAcres() const;
  float getSquareFt() const;
  
  float getYearTax() const;
  
};


#endif
