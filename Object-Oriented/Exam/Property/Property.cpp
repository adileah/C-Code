/*
    @author < Fill Me In >
    @date < Fill Me In >
	Simple non-pointer object demo - Property implementation file.
*/

#include <string>

#include "Property.h"

using namespace std;

const float SQUARE_FT_IN_ACRE = 43560.0;
const float YEAR_TAX_PER_FT2 = 0.25;

// Default constructor
Property::Property(){
  address = "Not Set";
  square_foot = new float;
  *square_foot = 0;
}

// Overloaded constructor - set address
Property::Property(string addr){
  address = addr;
    square_foot = new float;
  *square_foot = 0;
}

// Overloaded constructor - set address and size
Property::Property(string addr, float sqft){
  address = addr;
  square_foot = new float;
  *square_foot = sqft;
}

// Copy constructor
Property::Property(const Property &other){
  address = other.address;
  square_foot = new float;
  *square_foot = *other.square_foot;
}

// Destructor
Property::~Property(){
  delete this-> square_foot;
  square_foot = NULL;
}

// Assignment operator
Property& Property::operator=(const Property &other){
    *square_foot = *other.square_foot;
    address = other.address;
}

void Property::setAcres(float acres){
  *square_foot = acres * SQUARE_FT_IN_ACRE;
}


void Property::setSquareFt(float sqft){
  *square_foot = sqft;
}

string Property::getAddress() const{
  return address;
}

float Property::getAcres() const{
  return *square_foot / SQUARE_FT_IN_ACRE;
}

float Property::getSquareFt() const{
  return *square_foot;
}

float Property::getYearTax() const{
  if(*square_foot < 0){
    return 0.0;
  }else{
    return *square_foot * YEAR_TAX_PER_FT2;
  };
}


