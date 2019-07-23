/*    @file BigInt_test.cpp   
      @author < Fill Me In >
      @date < Fill Me In >
			@description Tests for the BigInt class
*/

#include "gtest/gtest.h"

#include "BigInt.h"

TEST(constructor, one){
  BigInt a(0);
  EXPECT_EQ(a.getAsString(),"0");
}

TEST(constructor, 10){
  BigInt a(10);
  EXPECT_EQ(a.getAsString(),"10");
}

TEST(constructor, 2000000){
  BigInt a(2000000);
  EXPECT_EQ(a.getAsString(),"2,000,000");
}

TEST(add, one){
  BigInt a(5);
  BigInt b(10);
  BigInt c = a + b;
  EXPECT_EQ(c.getAsString(),"15");
}

TEST(add, two){
  BigInt a(10000);
  BigInt b(25000);
  BigInt c = a + b;
  EXPECT_EQ(c.getAsString(),"35,000");
}

TEST(add, three){
  BigInt a(20000000);
  BigInt b(57000000);
  BigInt c = a + b;
  EXPECT_EQ(c.getAsString(),"77,000,000");
}

TEST(lessthan, one){
  BigInt a(20000000);
  BigInt b(57000000);
  EXPECT_EQ(a<b, true);
}

TEST(lessthan, two){
  BigInt b(20000000);
  BigInt a(57000000);
  EXPECT_EQ(a<b, false);
}

TEST(greaterthan, one){
  BigInt a(20000000);
  BigInt b(57000000);
  EXPECT_EQ(a>b, false);
}
TEST(greaterthan, two){
  BigInt b(20000000);
  BigInt a(57000000);
  EXPECT_EQ(a>b, true);
}