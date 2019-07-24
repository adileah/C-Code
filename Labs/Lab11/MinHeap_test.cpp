/* Name: Adileah Smith
   Date: NOV 4, 2018
   Desc: Unit tests for the Min Heap
*/
#include "gtest/gtest.h"

#include "MinHeap.h"



// Code to remind you what unit tests look like.
TEST(size, 0){
  MinHeap a;
  EXPECT_EQ(a.size(), 0);
}
TEST(size, 1){
    MinHeap a;
    a.push("charlie");
    EXPECT_EQ(a.size(), 1);
}
TEST(size, 2){
    MinHeap a;
    a.push("charlie");
    a.push("lucky");
    EXPECT_EQ(a.size(), 2);
}
TEST(pop, 1){
    MinHeap a;
    EXPECT_ANY_THROW(a.pop());
}
TEST(pop, 2){
    MinHeap a;
    a.push("charlie");
    a.push("lucky");
    EXPECT_EQ(a.top(), "charlie");
    a.pop();
    a.push("zebra");
    EXPECT_EQ(a.top(), "lucky");
}
TEST(pop, 3){
    MinHeap a;
    a.push("charlie");
    a.push("lucky");
    a.push("zebra");
    a.pop();
    a.pop();
    EXPECT_EQ(a.top(), "zebra");
    EXPECT_EQ(a.size(), 1);
}
TEST(pop, 4){
    MinHeap a;
    a.push("charlie");
    a.push("lucky");
    a.push("zebra");
    a.pop();
    EXPECT_EQ(a.top(), "lucky");
    EXPECT_EQ(a.size(), 2);
}
TEST(bubble, 1){
    MinHeap a;
    a.push("charlie");
    a.push("lucky");
    EXPECT_EQ(a.top(), "charlie");
}

TEST(bubble, 2){
    MinHeap a;
    a.push("charlie");
    a.push("lucky");
    a.push("zebra");
    EXPECT_EQ(a.top(), "charlie");
}
TEST(bubble, 3){
    MinHeap a;
    a.push("charlie");
    a.push("lucky");
    a.push("zebra");
    a.push("alex");
    EXPECT_EQ(a.top(), "alex");
}

TEST(bubble, 4){
    MinHeap a;
    a.push("charlie");
    a.push("lucky");
    a.push("lucky");
    a.push("zebra");
    a.push("alex");
    EXPECT_EQ(a.top(), "alex");
}

TEST(bubble, 5){
    MinHeap a;
    a.push("charlie");
    a.push("lucky");
    a.push("zebra");
    a.push("alex");
    a.push("alex");
    EXPECT_EQ(a.top(), "alex");
}

TEST(bubble, 6){
    MinHeap a;
    a.push("charlie");
    a.push("lucky");
    a.push("zebra");
    a.push("alex");
    a.push("alex");
    a.push("b");
    a.push("c");
    a.push("d");
    a.push("e");
    a.push("f");
    EXPECT_EQ(a.top(), "alex");
}

TEST(manyValuesSize, 1){
  MinHeap a;
  for(unsigned i = 0; i < 550; i++){
    stringstream s;
    s << rand() % 100;
    a.push(s.str());
  }
  for(unsigned i = 0; i < 550; i++){
    EXPECT_EQ( a.size(), 550 - i );
    a.pop();
  }
  EXPECT_ANY_THROW( a.top() );
}