#ifndef BST_H
#define BST_H
/* Name: Adileah Smith Mel Moore
   Date: Oct 16, 2018
   Desc: Binary search tree class to store strings
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
      unsigned wordcount;
    void insert(const string &word, Node_t* node){
        if(word<=node->data){
            if(node->left){
                insert(word, node->left);
            }else{
                node->left = new Node_t;
                node->left->data = word;
                node->left->left = NULL;
                node->left->right = NULL;
            }
        }else{
            if(node->right){
                insert(word, node->right);
            }else{
                node->right = new Node_t;
                node->right->data = word;
                node->right->left = NULL;
                node->right->right = NULL;
            }
        }
    }
    
    void pre(Node_t* node){
        if(!node)return;
        cout << node->data << " ";
        pre(node->left);
        pre(node->right);
    }
    void inorder(Node_t* node){
        if(!node)return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    
    bool findme(Node_t* node, string value, int depth_so_far){
        if(!node){
            cout << "Element " << value << " not found, depth " << depth_so_far << endl;
            return false;
        }
        if(node->data == value){
            cout << "Found " << value << " at depth " << depth_so_far << endl;
            return true;
        }
        if(value < node->data){
            return findme(node->left, value, depth_so_far + 1);
        }else{
            return findme(node->right, value, depth_so_far + 1);
        }
    }
    unsigned height(Node_t* node){
        if(!node)return 0;
        int left = height(node->left);
        int right = height(node->right);
        if(left > right){
            return left + 1;
        }else{
            return right + 1;
        }
    }
    void clear(Node_t* cur){
        if(!cur)return;
        if(cur->left){
            clear(cur->left);
        }
        if(cur->right){
            clear(cur->right);
        }
        delete cur;
    }
    Node_t* duplicate(Node_t* cur){
        if(!cur)return NULL;
         Node_t* temp = new Node_t;
         temp->data = cur->data;
         if(cur->left){
            temp->left = duplicate( cur->left );
         }
         if(cur->right){
             temp->right = duplicate(cur->right);
         }
         return temp;
    }
    /*bool balance(Node_t* cur, int left, int right){
        
    }*/
    
    bool remove(Node_t* node,const string &value){
        assert(node);  // Bad pointer
        assert(!(node->data == value)); // No way of fixing what points to me!
        if(node->left && node->left->data == value){ // remove my left child!
            if(!node->left->left && !node->left->right){ // single node
                delete node->left;
                node->left = NULL;
                return true;
            }else if(!node->left->left && node->left->right){ // No left child, bring right up
                Node_t* to_die = node->left;
                node->left = node->left->right;
                delete to_die;
                return true;
            }else if(!node->left->right && node->left->left){ // No right child, bring left up.
                Node_t* to_die = node->left;
                node->left = node->left->left;
                delete to_die;
                return true;
            }else{ // Two children, UG!
                // Find the smallest on the right and delete it.
                // Then change this node's value with that min
                string min = getMin(node->left->right);
                remove(node->left, min);
                node->left->data = min;
                return true;
            }
        }else if(node->right && node->right->data == value){ // remove my right child!
            if(!node->right->left && !node->right->right){ // single node
                delete node->right;
                node->right = NULL;
                return true;
            }else if(!node->right->left && node->right->right){ // No left child, bring right up
                Node_t* to_die = node->right;
                node->right = node->right->right;
                delete to_die;
                return true;
            }else if(!node->right->right && node->right->left){ // No right child, bring left up.
                Node_t* to_die = node->right;
                node->right = node->right->left;
                delete to_die;
                return true;
            }else{ // Two children, UG!
                // Find the smallest on the right and delete it.
                // Then change this node's value with that min
                string min = getMin(node->right->right);
                remove(node->right, min);
                node->right->data = min;
                return true;
            }
        }else if(value <= node->data){ // Go left
            return remove(node->left, value);
        }else{ // Go right
            return remove(node->right, value);
        }
    }
    
    string Min(Node_t* cur){
        if(!cur->left){
            return cur->data;
        }
        //cout << cur->data;
        else{
            return Min(cur->left);
        }
    }
    
    string Max(Node_t* cur){
        if(!cur->right){
            return cur->data;
        }
        else{
          return  Max(cur->right);
        }
    }
    
    /*void balance(Node_t* cur){
       // if(cur->right){
         //   cur->right = rotateRight(cur->right);
        //}
        
        if(cur){
            cur = rotateRight(cur);
        }
    }*/

    Node_t* rotateRight(Node_t* cur){
        if(!cur->left) return cur;
        Node_t* temp = cur->left;
        if(cur->left->right){
            cur->left = cur->left->right;
        }else{
            cur->left = NULL;
        }
        temp->right = cur;
        return temp;
    }
    
     Node_t* rotateLeft(Node_t* cur){
         if(!cur->right) return cur;
          Node_t* tempor = cur->right;
        if(cur->right->left){
            cur->right = cur->right->left;
        }else{
            cur->right = NULL;
        }
        
        tempor->left = cur;
        delete cur;
        return tempor;
    }
    
    public:
    
    BST(){
        root = NULL;
        wordcount = 0;
    }
  
    ~BST(){
        clear(root);
        root = NULL;
    }
  
    BST(const BST &other){
        wordcount = other.wordcount;
        clear(root);
        root = duplicate(other.root);
    }
  
    // Insert word into the BST
    void insert(const string &word){
        if(!root){
            root = new Node_t;
            root->data = word;
            wordcount++;
        }else{
            insert(word, root);   
            wordcount++;
        }
    }
  
    // Number of nodes in the BST
    unsigned size(){
        return wordcount;
    }
    
    // The height of the tree (number of edges on longest path)
    unsigned height(){
        return height(root);
    }
    
    // Preorder traversal of the tree
    // Just separate elements with a space, no []
    void preOrderTraversal(){
        pre(root);
        cout << endl;
    }
    
    // Postorder traversal of the tree
    // Just separate elements with a space, no []
    void inOrderTraversal(){
        inorder(root);
        cout << endl;
    }
    
    // Returns true if that value is stored, false otherwise
    bool find(const string &value){
        return findme(root, value, 0);
    }
    
    // Returns true if the tree is balanced, false otherwise
    // For all nodes, the number of nodes to the right and to the left
    // differ by at most 1.
    /*bool isBalanced()const{
        balance(root, 0, 0);
    }*/
    
    bool remove(string value){
        if (find(value) == 0){
            return false;
        }else{
           root = remove(value, root);
           return true;
        }
    }
    
    
    string getMin(){
        if(!root){
            throw logic_error("No nodes");
        }
        return Min(root);
    }
    
    string getMax(){
        return Max(root);
    }
    
    
    void print(){
        cout << endl;
        myprint(root, 0, "");
        cout << endl;
    }
    
    void myprint(Node_t* node, unsigned level, const string &prefix){
        if(!node)return;
        myprint(node->right, level + 1, prefix);
        // print the value, but indent
        cout << prefix << " :";
        for(unsigned i = 0; i < level * 2; i++){
            cout << "  ";
        }
        cout << node->data << endl;
        myprint(node->left, level + 1, prefix);
    }
    
    void rotateRootRight(){
        if(root){
            root = rotateRight(root);
        }
    }
    void rotateRootleft(){
        if(root){
            root = rotateLeft(root);
        }
    }

    bool remove(const string &value){
        if( !find(value) )return false;
        // Special case where removing the root node because root will need
        // to change.
        if(root->data == value){  // removing root
            if(!root->left && !root->right){ // single node
                delete root;
                root = NULL;
                return true;
            }else if(!root->left && root->right){ // No left child, bring right up
                Node_t* to_die = root;
                root = root->right;
                delete to_die;
                return true;
            }else if(!root->right && root->left){ // No right child, bring left up.
                Node_t* to_die = root;
                root = root->left;
                delete to_die;
                return true;
            }else{ // Two children, UG!
                // Find the smallest on the right and delete it.
                // Then change this node's value with that min
                string min = getMin(root->right);
                remove(root, min);
                root->data = min;
                return true;
            }
        }else{ // Not the root, let remove handle it!
            return remove(root, value);
        }
    }
};

#endif

