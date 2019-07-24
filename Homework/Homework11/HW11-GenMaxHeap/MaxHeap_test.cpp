/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for the Min Heap
*/
#include "gtest/gtest.h"

#include "MaxHeap.h"



// Code to remind you what unit tests look like.
TEST(size, 0){
  MaxHeap <unsigned> a;
  EXPECT_EQ(a.size(), 0);
}
TEST(size, 1){
    MaxHeap <string> a;
    a.push("Charlie");
    EXPECT_EQ(a.size(), 1);
}
TEST(size, 2){
    MaxHeap <string> a;
    a.push("Charlie");
    a.push("lucky");
    EXPECT_EQ(a.size(), 2);
}
TEST(size, 3){
    MaxHeap <unsigned> a;
    a.push(5);
    a.push(6);
    EXPECT_EQ(a.size(), 2);
}
TEST(size, 4){
    MaxHeap <float> a;
    a.push(3.2);
    a.push(3);
    EXPECT_EQ(a.size(), 2);
}
TEST(pop, 1){
    MaxHeap <string> a;
    EXPECT_ANY_THROW(a.pop());
}
TEST(pop, 2){
    MaxHeap <string> a;
    a.push("charlie");
    a.push("lucky");
    EXPECT_EQ(a.top(), "lucky");
    a.pop();
    EXPECT_EQ(a.top(), "charlie");
}
TEST(pop, 3){
    MaxHeap <string> a;
    a.push("charlie");
    a.push("lucky");
    a.push("zebra");
    a.pop();
    a.pop();
    EXPECT_EQ(a.top(), "charlie");
    EXPECT_EQ(a.size(), 1);
}
TEST(pop, 4){
    MaxHeap <string> a;
    a.push("charlie");
    a.push("lucky");
    a.push("zebra");
    a.pop();
    EXPECT_EQ(a.top(), "lucky");
    EXPECT_EQ(a.size(), 2);
}
TEST(pop, 5){
    MaxHeap <float> a;
    a.push(3.2);
    a.push(3);
    a.pop();
    EXPECT_EQ(a.top(), 3);
}
TEST(bubble, 1){
    MaxHeap <string> a;
    a.push("charlie");
    a.push("lucky");
    EXPECT_EQ(a.top(), "lucky");
}

TEST(bubble, 2){
    MaxHeap <string> a;
    a.push("charlie");
    a.push("lucky");
    a.push("zebra");
    EXPECT_EQ(a.top(), "zebra");
}
TEST(bubble, 3){
    MaxHeap <string> a;
    a.push("charlie");
    a.push("lucky");
    a.push("zebra");
    a.push("alex");
    EXPECT_EQ(a.top(), "zebra");
}

TEST(bubble, 4){
    MaxHeap <string> a;
    a.push("charlie");
    a.push("lucky");
    a.push("lucky");
    a.push("zebra");
    a.push("alex");
    EXPECT_EQ(a.top(), "zebra");
}

TEST(bubble, 5){
    MaxHeap <string> a;
    a.push("charlie");
    a.push("lucky");
    a.push("zebra");
    a.push("alex");
    a.push("alex");
    EXPECT_EQ(a.top(), "zebra");
}

TEST(bubble, 6){
    MaxHeap <string> a;
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
    EXPECT_EQ(a.top(), "zebra");
}
TEST(bubble, 7){
    MaxHeap <int> a;
    a.push(5);
    a.push(6);
    EXPECT_EQ(a.top(), 6);
}
TEST(bubble, 8){
    MaxHeap <int> a;
    a.push(5);
    a.push(6);
    a.push(7);
    a.push(7);
    a.push(8);
    EXPECT_EQ(a.top(), 8);
}

TEST(manyValuesSize, 1){
  MaxHeap <string> a;
  for(unsigned i = 0; i < 250; i++){
    stringstream s;
    s << rand() % 100;
    a.push(s.str());
  }
  for(unsigned i = 0; i < 250; i++){
    EXPECT_EQ( a.size(), 250 - i );
    a.pop();
  }
  EXPECT_ANY_THROW( a.top() );
}