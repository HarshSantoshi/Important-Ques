#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*children[26];
    bool end = false;

};
class Trie {
private : Node * root;
public:
    

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * curr = root;
        for(auto it : word){
            if(!curr->children[it-'a'] ){
                Node* newNode = new Node();
                curr->children[it-'a'] = newNode;
                curr = curr->children[it-'a'];
            }
            else{
                curr = curr->children[it-'a'];
            }
        }
        curr->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *curr = root;
        for(auto it : word){
            if(!curr->children[it-'a']){
                return false;
            }
            curr = curr->children[it-'a'];
        }
        return (curr->end == true);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *curr = root;
        for(auto it : prefix){
            if(!curr->children[it-'a']){
                return false;
            }
            curr = curr->children[it-'a'];
        }
        return true;
    }
};