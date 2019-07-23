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
#include <stdexcept>
#include "MyComplex.h"

const double DELTA = 0.0001;

MyComplex::MyComplex(double real, double imaginary){
  this->real = real;
  this->imaginary = imaginary;
}

string MyComplex::getAsString() const{
    stringstream ret;
    if(imaginary < 0){
        ret << "(" << real << " - " << -imaginary << "i)";
    }else{
        ret << "(" << real << " + " << imaginary << "i)";
    }
    return ret.str();
}

//Operators

MyComplex MyComplex::operator-(const MyComplex &n) const{
    MyComplex ret(real - n.real, imaginary - n.imaginary);
    return ret;
    /*MyComplex ret;
    ret.real = real - n.real;
    ret.imaginary = imaginary - n.imaginary;
    return ret; */
}

MyComplex MyComplex::operator+(const MyComplex &n) const{
    MyComplex ret(real + n.real, imaginary + n.imaginary);
    return ret;
   /* MyComplex ret;
    ret.real = real + n.real;
    ret.imaginary = imaginary + n.imaginary;
    return ret; */
}

MyComplex MyComplex::operator*(const MyComplex &n) const{
    MyComplex ret(real*n.real + -(imaginary*n.imaginary), real*n.imaginary + imaginary*n.real);
    return ret;
}

MyComplex MyComplex::operator/(const MyComplex &n) const{
    MyComplex ret(((real*n.real) - (imaginary*n.imaginary))/((n.real*n.real + n.imaginary*n.imaginary)), 
                 ((real*n.imaginary) + ((imaginary*n.real)/(n.real*n.real + n.imaginary*n.imaginary))));
    return ret;
}

bool MyComplex::operator==(const MyComplex &n) const{
    if (getAsString() == n.getAsString()){
        return true;
    }else{
        return false;
    }    
}

//setters

void MyComplex::setReal(double n){
    real = n;
}
void MyComplex::setImaginary(double n){
    imaginary = n;
}

//getters

double MyComplex::getReal() const{
    return real;
}
double MyComplex::getImaginary() const{
    return imaginary;
}

//functions

double MyComplex::mag2() const{
    return (real*real) + (imaginary*imaginary);
}

double MyComplex::dist2(const MyComplex &n) const{
    return pow((real-n.real),2) + pow((imaginary - n.imaginary),2);
}