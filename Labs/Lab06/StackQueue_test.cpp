/* Name: Adileah Smith and Garrett Grey
   Date: October 3, 2018
   Desc: Unit tests for the Stack or Queue classes
*/
#include "gtest/gtest.h"
#include "Stack.h"
#include "Queue.h"
// Fill me in


  // Code to remind you what unit tests look like.
TEST(Qsize, 0){
  Queue a;
  EXPECT_EQ(a.size(), 0);
}
TEST(Qsize, 1){
  Queue a;
  a.enqueue(5);
  EXPECT_EQ(a.size(), 1);
}
TEST(Qsize, 2){
  Queue a;
  a.enqueue(5);
  a.dequeue();
  EXPECT_EQ(a.size(), 0);
}
TEST(Qenqueue, 1){
    Queue a;
    a.enqueue(5);
    EXPECT_EQ(a.peek(), 5);
}
TEST(Qenqueue, 2){
    Queue a;
    a.enqueue(5);
    a.enqueue(6);
    EXPECT_EQ(a.peek(), 5);
}
TEST(Qdequeue, 1){
    Queue a;
    EXPECT_ANY_THROW(a.dequeue());
}
TEST(Qdequeue, 2){
    Queue a;
    for(int i = 0; i < 5; i++){
        a.enqueue(i);
    }
    a.dequeue();
    EXPECT_EQ(a.size(), 4);
    EXPECT_EQ(a.peek(), 1);
}
TEST(Qpeek, 1){
    Queue a;
    EXPECT_ANY_THROW(a.peek());
}
TEST(Qpeek, 2){
    Queue a;
    for(int i = 0; i < 5; i++){
        a.enqueue(i);
    }
    EXPECT_EQ(a.peek(), 0);
}

TEST(Ssize, 0){
    Stack a;
    EXPECT_EQ(a.size(), 0);
}

TEST(Ssize, 1){
    Stack a;
    a.push(3);
    EXPECT_EQ(a.size(), 1);
}

TEST(Ssize, 2){
    Stack a;
    a.push(3);
    a.push(7);
    EXPECT_EQ(a.size(), 2);
}

TEST(Ssize, 10){
    Stack a;
    for(int i = 0; i < 10; i++){
        a.push(i);
    }
    EXPECT_EQ(a.size(), 10);
}

TEST(Spop, 1){
    Stack a;
    a.push(3);
    a.push(7);
    a.pop();
    EXPECT_EQ(a.size(), 1);
}

TEST(Spop, 2){
    Stack a;
    a.push(3);
    a.push(7);
    a.push(8);
    a.pop();
    EXPECT_EQ(a.size(), 2);
}

TEST(Speek, 0){
    Stack a;
    EXPECT_ANY_THROW(a.peek());
}

TEST(Speek, 1){
    Stack a;
    a.push(5);
    EXPECT_EQ(a.peek(), 5);
}

TEST(Speek, 2){
    Stack a;
    a.push(5);
    a.push(6);
    EXPECT_EQ(a.peek(), 6);
}

TEST(Speek, 3){
    Stack a;
    a.push(5);
    a.push(6);
    a.push(9);
    EXPECT_EQ(a.peek(), 9);
}