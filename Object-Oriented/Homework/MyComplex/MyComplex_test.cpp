/*    @file MyComplex_test.cpp   
      @author < Adileah Smith >
      @date < 2/2/18 >

			@description Tests for the MyComplex class
*/

#include "gtest/gtest.h"
#include <math.h>
#include "MyComplex.h"

ostream& operator<<(ostream &o, const MyComplex &r){
  o << r.getAsString();
  return o;
}

// constructor & getAsString
TEST(construct_string,1){
  MyComplex a(1,2);
  EXPECT_EQ(a.getAsString(), "(1 + 2i)");
}

TEST(construct_string,2){
  MyComplex a(1,-2);
  EXPECT_EQ(a.getAsString(), "(1 - 2i)");
}

TEST(construct_string,3){
  MyComplex a(-1,-2);
  EXPECT_EQ(a.getAsString(), "(-1 - 2i)");
}

TEST(addition, 1){
  MyComplex a(1,2);
  MyComplex b(1,2);
  MyComplex c = a + b;
  EXPECT_EQ(c.getAsString(), "(2 + 4i)");
}

TEST(addition, 2){
  MyComplex a(1,2);
  MyComplex b(-1,-2);
  MyComplex c = a + b;
  EXPECT_EQ(c.getAsString(), "(0 + 0i)");
}

TEST(addition, 3){
  MyComplex a(1,2);
  MyComplex b(1,-3);
  MyComplex c = a + b;
  EXPECT_EQ(c.getAsString(), "(2 - 1i)");
}

TEST(addition, 4){
  MyComplex a(-1,-2);
  MyComplex b(1,2);
  MyComplex c = a + b;
  EXPECT_EQ(c.getAsString(), "(0 + 0i)");
}

TEST(addition, 5){
  MyComplex a(-1,-2);
  MyComplex b(-1,-2);
  MyComplex c = a + b;
  EXPECT_EQ(c.getAsString(), "(-2 - 4i)");
}

TEST(subtraction, 1){
  MyComplex a(1,2);
  MyComplex b(1,2);
  MyComplex c = a - b;
  EXPECT_EQ(c.getAsString(), "(0 + 0i)");
}

TEST(subtraction, 2){
  MyComplex a(1,2);
  MyComplex b(2,-2);
  MyComplex c = a - b;
  EXPECT_EQ(c.getAsString(), "(-1 + 4i)");
}

TEST(subtraction, 3){
  MyComplex a(1,-2);
  MyComplex b(-1,2);
  MyComplex c = a - b;
  EXPECT_EQ(c.getAsString(), "(2 - 4i)");
}

TEST(subtraction, 4){
  MyComplex a(-1,-2);
  MyComplex b(-1,2);
  MyComplex c = a - b;
  EXPECT_EQ(c.getAsString(), "(0 - 4i)");
}

TEST(subtraction, 5){
  MyComplex a(-1,-2);
  MyComplex b(1,2);
  MyComplex c = a - b;
  EXPECT_EQ(c.getAsString(), "(-2 - 4i)");
}

TEST(Multiplication, 1){
  MyComplex a(1,2);
  MyComplex b(1,2);
  MyComplex c = a * b;
  EXPECT_EQ(c.getAsString(), "(-3 + 4i)");
}

TEST(Multiplication, 2){
  MyComplex a(1,2);
  MyComplex b(1,-2);
  MyComplex c = a * b;
  EXPECT_EQ(c.getAsString(), "(5 + 0i)");
}

TEST(Multiplication, 3){
  MyComplex a(1,2);
  MyComplex b(-1,-2);
  MyComplex c = a * b;
  EXPECT_EQ(c.getAsString(), "(3 - 4i)");
}

TEST(Division, 1){
  MyComplex a(1,2);
  MyComplex b(1,2);
  MyComplex c = a / b;
  EXPECT_EQ(c.getReal(), -0.6);
}
//float(-3)/float(5) -> I don't understand why it wouldn't let me use this instead of -0.6

TEST(Division, 2){
  MyComplex a(1,2);
  MyComplex b(-1,2);
  MyComplex c = a / b;
  EXPECT_EQ(c.getReal(), -1);
}

TEST(Division, 3){
  MyComplex a(1,-2);
  MyComplex b(1,2);
  MyComplex c = a / b;
  EXPECT_EQ(c.getReal(), 1);
}

TEST(Division, 4){
  MyComplex a(-1,-2);
  MyComplex b(1,2);
  MyComplex c = a / b;
  EXPECT_EQ(c.getReal(), 0.6);
}

TEST(Equal, 1){
  MyComplex a(-1,-2);
  MyComplex b(-1,-2);
  EXPECT_EQ(a.getAsString() == b.getAsString(), true);
}

TEST(Equal, 2){
  MyComplex a(-1,-2);
  MyComplex b(-1,2);
  EXPECT_EQ(a.getAsString() == b.getAsString(), false);
}

TEST(Magnitude, 1){
  MyComplex a(1,2);
  EXPECT_EQ(a.mag2(), 5);
}
TEST(Magnitude, 2){
  MyComplex a(-1,-2);
  EXPECT_EQ(a.mag2(), 5);
}

TEST(Distance, 1){
  MyComplex a(1,2);
  MyComplex b(-1,-2);
  EXPECT_EQ(a.dist2(b), 20);
}

TEST(Distance, 2){
  MyComplex a(1,2);
  MyComplex b(1,2);
  EXPECT_EQ(a.dist2(b), 0);
}
