#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:

char data;
TrieNode* children[26];
bool isTerminal;  //to check the termination for the particular string

TrieNode(char ch){
    this -> data = ch;
    for(int i=0; i<26; i++){
        children[i] = NULL;
    }
    isTerminal = false;
}
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('n');
    }

    void insertUtil(TrieNode* root, string word){

        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        //finding the index to be inserted
        int index = word[0] - 'a';
        TrieNode* child;

        //checking whether the character is present or not

        //if present
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }

        //if absent

        else{
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }


        insertUtil(child, word.substr(1));

    }
    void insertWord(string word){
        insertUtil(root, word);
    }
//will return true if and only if all characters are present and the last character is terminal else false
    bool searchUtil(TrieNode* root, string word){

        if(word.length() == 0){
            return root -> isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // if particular character is present

        if(root -> children[index] != NULL){
            child = root -> children[index];
        }

        // if particular character is absent
        else{
                return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        
        return searchUtil(root, word);
    }
    void removeUtil(TrieNode* root, string word){

        TrieNode* child = root;
        while(word.length()!= 0){

            int index = word[0] -'a';
            child = child -> children[index];
            word = word.substr(1);
        }
    cout << child -> data << endl;
        child -> isTerminal = false;
     
    }

    void removeWord(string word){
        if(searchWord(word)){
            removeUtil(root, word);
        }
        else cout << "No Such Word is Present" << endl;
    }

    bool prefixUtil(TrieNode* root, string word){

        TrieNode* child = root ;

        while(word.length() != 0){
            int index = word[0]-'a';

            if(child -> children[index] != NULL){
                child = child -> children[index];
            }
            else return false;

            word = word.substr(1);
        }

        return true;
    }
    bool prefixWord(string word){
        return prefixUtil(root, word);
    }

    };

int main(){

    Trie t;
    t.insertWord("arm");
    cout << t.searchWord("arm") << endl;
    cout << t.searchWord("army") << endl;
    cout << t.searchWord("ar") << endl;
    t.insertWord("army");
    t.insertWord("ram");
    t.insertWord("string");
    t.insertWord("street");

    cout << t.searchWord("string") << " string is present "<< endl;
    cout << t.searchWord("gyan")<< endl;
    cout << t.searchWord("ram") << endl;
    t.removeWord("string");
    cout << t.searchWord("string") << endl;

    // t.removeWord("army");
    if(t.searchWord("army")){
        cout << "army word is present" << endl;
    }
    else cout << "No word there" << endl;

    cout << t.prefixWord("std");
    return 0;
}