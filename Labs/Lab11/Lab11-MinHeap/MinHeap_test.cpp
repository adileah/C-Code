/* Name: < Fill me in>
   Date: < Fill me in>
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