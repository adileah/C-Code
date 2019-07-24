#ifndef TRIE_H
#define TRIE_H
/* Name: Adileah Smith, Mel Moore, Trae Bowman
   Date: Oct 28, 2018
   Desc: Trie class to store strings
   If either of you can use gitkeeper please submit it cause I'm having problems with it.
   I'll try my best
*/
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cassert>

using namespace std;

// I suggest making Node a class so the constructor can null all pointers, plus
// the destructor can
class Node{
    public:
    bool word;
    Node* children[26];
    Node(){
        word = false;
        for(unsigned i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
    ~Node(){
        for(unsigned i = 0; i < 26; i++){
            if(children[i])delete children[i];
        }
    }
};


class Trie{
    private:
      // Fill me in
     Node* root;
  
    public:
    
    Trie(){
      // Fill me in
      root = new Node;
    }
  
    ~Trie(){
        delete root;
        root = NULL;
    }
  
    Trie(const Trie &other){
       // Do the dumb thing and get all words, then insert them!
       vector<string> other_words = other.getAllWords();
       root = new Node;
       for(unsigned i = 0; i < other_words.size(); i++){
           insert(other_words[i]);
       }
    }
    
    Trie& operator=(const Trie &other){
        if(this == &other)return *this;
        delete root;
        root = NULL;
        root = new Node;
        // Do the dumb thing and get all words, then insert them!
       vector<string> other_words = other.getAllWords();
       for(unsigned i = 0; i < other_words.size(); i++){
           insert(other_words[i]);
       }
        return *this;
    }
  
    // Insert word into the Trie, true if successful, false if not able (punctuation)
    bool insert(const string &word){
        // Fill me in
        return insert(root, word);
    }
  
    // Number of words in the Trie
    unsigned size()const{
        // Fill me in
        return size(root);
    }
    
    // Number of nodes in the Trie
    unsigned numNodes()const{
        return numNodes(root);
    }
    
    // Returns all words stored in the Trie as a vector of strings
    vector<string> getAllWords()const{
        vector<string> ret;
        getAllWords(root, ret, "");
        /*cout << endl;
        for(unsigned i = 0; i < ret.size(); i++){
            cout << ret[i] << " ";
        }
        cout << endl;
        */
        return ret;
    }
    
    // Returns true if that word is stored, false otherwise
    bool find(const string &value)const{
        return find(root, value);
    }
    
    void remove(string value){
        remove(root, value);
    }
    
    unsigned height()const{
        
    return height(root) - 1;
       return 0;
    }
    
    void freeUpMemory(){
        freeUpMemory(root);
    }
    
    vector<string> getAllWords(string prefix){
        vector<string> ret;
        Node* node = start(root, prefix);
        getAllWords(node, ret, prefix);
        return ret;
    }
    
    private:
    
    Node* start(Node* node, string prefix){
        if(prefix == "")return node;
        int ndx = tolower(prefix[0]) - 'a'; // So 0 is a
        if(ndx < 0 || ndx > 25)return NULL;
        if(!node->children[ndx])return NULL;
        return start(node->children[ndx], prefix.substr(1));
    }
    
    unsigned numNodes(Node* node)const{
        if(!node)return 0;
        unsigned count = 0;
        for(unsigned i = 0; i < 25; i++){
            count += numNodes(node->children[i]);
        }
        return count + 1;
    }
    
    bool insert(Node* node, const string &word){
        if(word == ""){ // Mark this as being a word
            node->word = true;
            return true;
        }
        int ndx = tolower(word[0]) - 'a'; // So 0 is a
        if(ndx < 0 || ndx > 25){
            //cout << word[0] << " not a character" << endl;
            return false;
        }
        if(!node->children[ndx])node->children[ndx] = new Node;
        return insert(node->children[ndx], word.substr(1));
    }
    
    unsigned size(Node* node)const{
        if(!node)return 0;
        unsigned count = 0;
        for(unsigned i = 0; i < 25; i++){
            count += size(node->children[i]);
        }
        if(node->word)return count + 1;
        else return count;
    }
    
    bool find(Node* node, const string &word)const{
        if(word == ""){ // Empty string, return if a word ended here
            return node->word;
        }
        int ndx = tolower(word[0]) - 'a'; // So 0 is a
        if(ndx < 0 || ndx > 25){
            //cout << word[0] << " not a character" << endl;
            return false;
        }
        if(!node->children[ndx])return false;  // No node where it should be
        return find(node->children[ndx], word.substr(1));
    }
    
    void remove(Node* node, const string value){
        if(value == ""){
            node->word = false;
            return;
        }
        int ndx = tolower(value[0]) - 'a';
        if(ndx < 0 || ndx > 25){
            return;
        }
        if(!node->children[ndx])return;
        return remove(node->children[ndx], value.substr(1));
        
    }
    
    unsigned height(Node* node)const{
        if(!node) return 0;
        unsigned x = 0; //just testing something out. Ignore for now.
        for(unsigned i = 0; i < 25; i++){
            unsigned y = height(node->children[i]);
            
            if(y > x){
                x = y;
            }
      
        }
            return x + 1;  
    }
    
    void getAllWords(Node* node, vector<string> &words, string soFar)const{
        if(!node)return;
        if(node->word)words.push_back(soFar);
        for(unsigned i = 0; i < 25; i++){
            char toAdd = 'a' + i;
            getAllWords(node->children[i], words, soFar + toAdd);
        }
    }
    
    void freeUpMemory(Node* node){
        if (!node){
            return;
        }
        for(unsigned i = 0; i < 26; i++){
            if(node->children[i]){
                if(size(node->children[i])==0){
                    delete node->children[i];
                    node->children[i] = NULL;
                }
                else{
                    freeUpMemory(node->children[i]);
                }
            }
        }
    }
};

#endif