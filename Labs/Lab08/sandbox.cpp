/* Name: Paul Talaga
   Date: 10/16/2018
   Desc: Testing file
*/
#include <iostream>
#include "BST.h"


int main(){
  BST a;
  a.insert("apple");
  a.insert("tangerine");
  a.insert("pinapple");
  a.insert("acting");
  a.insert("zebra");
  a.insert("pear");
  a.insert("sandpaper");
  a.preOrderTraversal();
  a.inOrderTraversal();
  a.find("apple");
  a.find("pineapple");
  cout << a.size() << endl;
  cout << a.height() << endl;
  cout << a.getMax() << endl;
  cout << a.getMin() << endl << endl << endl;
  a.print();
  a.rotateRootRight();
  a.print();
  cout << a.remove("pear");
  a.print();
  return 0;
}