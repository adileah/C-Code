/*    @file SmartArray_test.cpp   
      @author < Fill Me In >
      @date < Fill Me In >

			@description Tests for the SmartArray class
*/

#include "gtest/gtest.h"

#include "SmartArray.h"



TEST(size,1){
  SmartArray<int> a;
  EXPECT_EQ(a.size(), 0);
}

TEST(size,2){
  SmartArray<int> a;
  a[3] = 10;
  EXPECT_EQ(a.size(), 4);
}

TEST(size,3){
  SmartArray<int> a;
  a[3] = 10;
  a[10] = 9;
  EXPECT_EQ(a.size(), 11);
}

TEST(bracket,1){
  SmartArray<int> a;
  a[3] = 10;
  EXPECT_EQ(a[3], 10);
}

TEST(bracket,2){
  SmartArray<int> a;
  a[3] = 10;
  a[10] = 9;
  EXPECT_EQ(a[10], 9);
}

TEST(bracket,exception){
  SmartArray<int> a;
  EXPECT_ANY_THROW( a[-3] );
}

TEST(bracket,block1){
  SmartArray<int> a;
  a[10] = 9;
  EXPECT_EQ(a[9], 0);
}

TEST(bracket,block2){
  SmartArray<int> a(55);
  a[10] = 9;
  EXPECT_EQ(a[9], 55);
}

TEST(bracket,block22){
  SmartArray<int> a(55);
  a[3] = 5;
  a[10] = 9;
  EXPECT_EQ(a[9], 55);
  cout << a << endl;
}

TEST(bracket,block3){
  SmartArray<string> a(" sleepy Trey");
  a[10] = " has a headache.";
  EXPECT_EQ(a[9], " sleepy Trey");
}

TEST(bracket,block4){
  SmartArray<string> a(" sleepy Trey");
  a[1] = "Jared";
  a[10] = " has a headache.";
  EXPECT_EQ(a[9], " sleepy Trey");
}
/*
TEST(copy,1){
  SmartArray<string> a(" sleepy Trey");
  a[1] = "Jared";
  a[10] = " has a headache.";
  SmartArray<string> b(a);
  EXPECT_EQ(b[9], " sleepy Trey");
}
*/
TEST(count,1){
  SmartArray<string> a(" sleepy Trey");
  a[1] = "Jared";
  a[10] = " has a headache.";
  EXPECT_EQ(a.count("Jared"), 1);
}

TEST(count, 2){
  SmartArray<int> a(5);
  a[2] = 3;
  EXPECT_EQ(a.count(3), 1);
}

TEST(count,5){
  SmartArray<string> a("batman");
  a[1] = "nanananna";
  a[10] = "pterodactyl";
  EXPECT_EQ(a.count("batman"), 9);
}

TEST(count, 4){
  SmartArray<int> a(5);
  a[2] = 3;
  EXPECT_EQ(a.count(3329050), 0);
}

TEST(count, 3){
  SmartArray<int> a(5);
  a[2] = 2;
  a[1] = 2;
  EXPECT_EQ(a.count(2), 2);
  EXPECT_EQ(a.count(0), 0);
}

TEST(booltest, 1){
  SmartArray<int> a(5);
  SmartArray<int> b(5);
  EXPECT_EQ(a == b, true);
}

TEST(booltest, 2){
  SmartArray<int> a(5);
  SmartArray<int> b(5);
  a[1] = 53;
  b[1] = 53;
  EXPECT_EQ(a == b, true);
}

TEST(booltest, 3){
  SmartArray<int> a(5);
  SmartArray<int> b(5);
  a[1] = 53;
  EXPECT_EQ(a == b, false);
}

TEST(booltest, 4){
  SmartArray<int> a(5);
  SmartArray<int> b(5);
  a[1] = 53;
  b[1] = -53;
  EXPECT_EQ(a == b, false);
}

TEST(booltest, 5){
  SmartArray<string> a("im a ");
  SmartArray<string> b("im a ");
  a[1] = "badman";
  b[1] = "dubberly";
  EXPECT_EQ(a == b, false);
}

TEST(string, 1){
  SmartArray<int> a(5);
  a[1] = 53;
  EXPECT_EQ(a.getAsString(), "[5, 53]");
}

TEST(string, 2){
  SmartArray<int> a(5);
  a[1] = 53;
  a[2] = 37;
  EXPECT_EQ(a.getAsString(), "[5, 53, 37]");
}

TEST(string, 3){
  SmartArray<int> a(5);
  EXPECT_EQ(a.getAsString(), "[]");
}

TEST(string, 4){
  SmartArray<int> a(5);
  a[0] = 1;
  EXPECT_EQ(a.getAsString(), "[1]");
}

TEST(string, 6){
  SmartArray<string> a("I wanna eat cheese");
  a[1] = "pen pinapple apple pen";
  EXPECT_EQ(a.getAsString(), "[I wanna eat cheese, pen pinapple apple pen]");
}

/*TEST(add, 1){
  SmartArray<int> a(5);
  SmartArray<int> b(5);
  a[2] = 3;
  b[2] = 37;
  b[3] = 47;
  SmartArray<int> c(5);
  c = a+b;
  EXPECT_EQ(a.getAsString(), "");
}*/

TEST(string, 5){
  SmartArray<int> a(5);
  a[1] = 1;
  EXPECT_EQ(a.getAsString(), "[5, 1]");
}

TEST(merge, 1){
  SmartArray<int> a(5);
  a[1] = 2;
  SmartArray<int> b(2);
  b[1] = 5;
  MergeSort(a, 0, 2);
  EXPECT_EQ(a.getAsString(), b.getAsString());
}