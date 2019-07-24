/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for the BST classes
*/
#include "gtest/gtest.h"

#include "Trie.h"



/*  // Code to remind you what unit tests look like.
TEST(size, 0){
  LIST a;
  EXPECT_EQ(a.size(), 0);
}
*/

TEST(numNodes, 1){
  Trie a;
  EXPECT_EQ(a.numNodes(), 1);
}
// Add more tests here