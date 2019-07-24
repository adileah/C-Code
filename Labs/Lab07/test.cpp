/**
 * Created by Kalpathi Subramanian, 1/30/18
 * Paul Talaga 10/10/2018
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "BSTElement.h"
#include <sstream>

using namespace std;
using namespace bridges;

string toString(int a){
	stringstream s;
	s << a;
	return s.str();
}

int main () {

	// note: you must fill in with your Bridges credentials
	Bridges::initialize(5, "adileah" , "654099023671");

	// create a few tree nodes with integer data

	BSTElement<int,int> *el0 = new BSTElement<int,int>(1,1);
	BSTElement<int,int> *el1 = new BSTElement<int,int>(2,2);
	BSTElement<int,int> *el2 = new BSTElement<int,int>(3,3);
	BSTElement<int,int> *el3 = new BSTElement<int,int>(4,4);
	BSTElement<int,int> *el4 = new BSTElement<int,int>(5,5);
	BSTElement<int,int> *el5 = new BSTElement<int,int>(6,6);
	BSTElement<int,int> *el6 = new BSTElement<int,int>(7,7);

	// Set the labels
	el0->setLabel( toString( el0->getKey() ) );
	el1->setLabel( toString( el1->getKey() ) );
	el2->setLabel( toString( el2->getKey() ) );

	//  link the elements
	el3->setLeft(el1);
	el3->setRight(el5);
	el1->setLeft(el0);
	el1->setRight(el2);
	el5->setLeft(el4);
	el5->setRight(el6);
	

	Bridges::setDataStructure(el3);
	Bridges::visualize();
}