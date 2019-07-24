#ifndef BST_H
#define BST_H
/* Name: <fill this in>
   Date: <fill this in>
   Desc: Binary search tree
*/
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cassert>

using namespace std;

// Definition of a node 
struct Node_t{
  string data;
  Node_t* left;
  Node_t* right;
};

class BST{
    private:
      Node_t* root;
  
    public:
    
    BST(){
      root = NULL;
    }
  
    ~BST(){
        clear(root);
        root = NULL;
    }
  
    BST(const BST &other){
      root = duplicate(other.root);
    }
    
    BST& operator=(const BST &other){
        if(this == &other)return *this;
        clear(root);
        root = duplicate(other.root);
        return *this;
    }
  
    // Insert word into the BST
    void insert(const string &word){
        if(!root){
            root = new Node_t;
            root->data = word;
            root->left = NULL;
            root->right = NULL;
        }else{
            insert(word, root);
        }
    }
  
    // Number of nodes in the BST
    unsigned size()const{
        return size(root);
    }
    
    // The height of the tree (number of edges on longest path)
    unsigned height()const{
        if(!root)return 0;
        return height(root) - 1;
    }
    
    // Preorder traversal of the tree
    string preOrderTraversal()const{
        return preOrderTraversal(root);
    }
    
    // Postorder traversal of the tree
    string inOrderTraversal()const{
        return inOrderTraversal(root);
    }
    
    // Returns true if that value is stored, false otherwise
    bool find(const string &value)const{
        return find(root, value);
    }
    
    // Returns true if the tree is balanced, false otherwise
    // For all nodes, the number of nodes to the right and to the left
    // differ by at most 1.
    bool isBalanced()const{
        return isBalanced(root);
    }
    
    // Lab 09
    
    string getMin()const{
        // Fill me in
        return "";
    }
    
    string getMax()const{
        // Fill me in
        return "";
    }
    
    bool remove(const string &value){
        // Fill me in
        return false;
    }
    
    // HW 09
    
    void balance(){
        // Fill me in
    }
    
    private:
    
    // Recursive functions
    unsigned size(Node_t* n)const{
        if(!n)return 0;
        return size(n->left) + size(n->right) + 1;
    }
    
    void insert(const string &value, Node_t* node){
        assert(node);
        if(value <= node->data){
            if(node->left){
                insert(value, node->left);
            }else{
                node->left = new Node_t;
                node->left->data = value;
                node->left->left = NULL;
                node->left->right = NULL;
            }
        }else{
            if(node->right){
                insert(value, node->right);
            }else{
                node->right = new Node_t;
                node->right->data = value;
                node->right->left = NULL;
                node->right->right = NULL;
            }
        }
        return;
    }
    
    void clear(Node_t* n){
        if(!n)return;
        clear(n->left);
        clear(n->right);
        delete n;
    }
    
    bool find(Node_t* node,const string &value)const{
        if(!node){
            return false;
        }
        if(node->data == value){
            return true;
        }
        if(value < node->data){
            return find(node->left, value);
        }else{
            return find(node->right, value);
        }
    }
    
    unsigned height(Node_t* n)const{
        if(!n)return 0;
        // Return the max of the two branches
        unsigned left = height(n->left);
        unsigned right = height(n->right);
        return max(left,right) + 1;
    }
    
    bool isBalanced(Node_t* node)const{
        if(!node)return true;
        if(!isBalanced(node->left))return false;
        if(!isBalanced(node->right))return false;
        unsigned left = height(node->left);
        unsigned right = height(node->right);
        if(left < right){
            return right - left <= 1;
        }else{
            return left - right <= 1;
        }
    }
    
    string preOrderTraversal(Node_t* node)const{
        if(!node) return "";
        stringstream s;
        s << node->data;
        return s.str() + " " + preOrderTraversal(node->left) + preOrderTraversal(node->right);
    }
    
     string inOrderTraversal(Node_t* node)const{
        if(!node) return "";
        stringstream s;
        s << node->data;
        return inOrderTraversal(node->left) + " " + s.str() + " " + inOrderTraversal(node->right);
    }
    
    // Walk the 'other' tree and duplicate as you go.
    Node_t* duplicate(Node_t* other){
        if(!other)return NULL;
        Node_t* ret = new Node_t;
        ret->data = other->data;
        ret->right = duplicate(other->right);
        ret->left = duplicate(other->left);
        return ret;
    }
    
    // HW 09
    
    Node_t* rotateRight(Node_t* node){
        // Fill me in
        return NULL;
    }
    
    Node_t* rotateLeft(Node_t* node){
        // Fill me in
        return NULL;
    }
    
};

#endif
