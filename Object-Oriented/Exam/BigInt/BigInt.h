#ifndef BIGINT_H
#define BIGINT_H  

/*    @file BigInt.cpp   
      @author < Fill Me In >
      @date < Fill Me In >

			@description Implements a class for manipulating large numbers.
*/

#include <string>
#include <vector>

using namespace std;

class BigInt{
  public:
  
  BigInt(unsigned);
  BigInt();
  BigInt operator+(BigInt ) const; 
  bool operator==(const BigInt &) const; 
  string getAsString() const; 
  void setValue(unsigned);
  bool operator<(const BigInt &) const;
  bool operator>(const BigInt &) const;
  
  private:
  vector<unsigned short> digits;
};

ostream& operator<<(ostream &o, const BigInt &r);

  
#endif