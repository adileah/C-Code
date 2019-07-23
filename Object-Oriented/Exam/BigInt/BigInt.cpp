/*    @file MyComplex.cpp   
      @author < Fill Me In >
      @date < Fill Me In >

			@description Implements a class for manipulating complex numbers.
*/

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include "BigInt.h"

BigInt::BigInt(){
  digits.push_back(1);
}

BigInt::BigInt(unsigned number){
  while( number > 0){
    digits.push_back( number % 10);
    number = number / 10;
  }
}


BigInt BigInt::operator+(BigInt other) const{
  BigInt current = *this;
  vector<unsigned short> ret;
  while(other.digits.size() < current.digits.size()){
    other.digits.push_back(0);
  }
  while(other.digits.size() > current.digits.size()){
    current.digits.push_back(0);
  }
  
  unsigned carry = 0;
  for(unsigned i = 0; i < other.digits.size(); i++){
    int value = other.digits.at(i) + current.digits.at(i) + carry;
    ret.push_back( value % 10);
    carry = value / 10;
  }
  if(carry != 0){
    ret.push_back(carry);
  }
  BigInt r;
  r.digits = ret;
  return r;
}

  
bool BigInt::operator==(const BigInt &other) const{
  if(digits.size() >= other.digits.size()){
    for(unsigned i = 0; i < other.digits.size(); i++){
     if( digits[i] != other.digits[i]){
        return false;
      }
    }
  }else if(digits.size() < other.digits.size()){
   for(unsigned i = 0; i < digits.size(); i++){
     if( digits[i] != other.digits[i]){
        return false;
      }
    }
  }
  return true;
}


ostream& operator<<(ostream &o, const BigInt &r){
  o << r.getAsString();
  return o;
}


string BigInt::getAsString() const{
    stringstream ret;
    if(digits.size() == 0){
      return "0";
    }
    else if (digits.size() <= 3){
      
      for(unsigned i = digits.size(); i > 0;i--){
        ret << digits[i-1];
      }
    }
    else{
      for(unsigned i = digits.size(); i > 0; i--){
        if (i%3 == 0){
          ret << ',';
        }
        ret << digits[i-1];
      }
    }
    
    return ret.str();
  }
  
void BigInt::setValue(unsigned number){
  
}
bool BigInt::operator<(const BigInt &n) const{
  if(digits.size() < n.digits.size()){
    return true;
  }
  else if(digits.size() > n.digits.size()){
    return false;
  }else{
    for (int i = n.digits.size() - 1; i >= 0; i--){
      if (digits[i] < n.digits[i]){
        return true;
      }
      else if (digits[i] > n.digits[i]){
        return false;
      }
    }
  }
}
bool BigInt::operator>(const BigInt &n) const{
  if(digits.size() > n.digits.size()){
    return true;
  }
  else if(digits.size() < n.digits.size()){
    return false;
  }else{
    for (int i = n.digits.size() - 1; i >= 0; i--){
      if (digits[i] > n.digits[i]){
        return true;
      }
      else if (digits[i] < n.digits[i]){
        return false;
      }
    }
  }
  return false;
}

  

