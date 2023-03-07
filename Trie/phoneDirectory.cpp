#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

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
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word){
            
            TrieNode* child = root;

            while(word.length() != 0){

                int index = word[0] - 'a';
                
                if(child -> children[index]){
                    child = child -> children[index];
                }
                else{
                    child -> children[index] = new TrieNode(word[0]);;
                    child = child-> children[index];
                }

                
                word = word.substr(1);
            }

            child -> isTerminal = true;
        }
        void insertWord(string word){
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, string word){
            
            while(word.length() != 0){

                int index = word[0] - 'a';

                if(root -> children[index]){
                    root = root -> children[index];
                }
                else{
                    return false;
                }

                word = word.substr(1);
            }

            if (root -> isTerminal){
                return true;
            }

            return false;
        }

        bool search(string word){
            return searchUtil(root, word);
        }

        void printSuggestions(TrieNode* curr, vector<string> & temp, string prefix){

            if(curr -> isTerminal){
                temp.push_back(prefix);
                return;
            }
            for(char ch = 'a'; ch <= 'z'; ch++){

               TrieNode* next = curr -> children[ch -'a'];

                if(next != NULL){
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
                }
            }
        }

        void phoneDirectory(string str, vector<vector<string>> &output){

        TrieNode* prev = root;

        string prefix = "";

        char last_ch;

        for(int i=0; i<str.length(); i++){

            last_ch = str[i];
            prefix.push_back(last_ch);

            TrieNode* curr = prev -> children[last_ch -'a'];

            if(curr == NULL){
                break;
            }  

            vector<string> temp;

            this -> printSuggestions(curr, temp, prefix);      
            output.push_back(temp);
            temp.clear();
            
            prev = curr;
        } 
   
}
};


int main(){

    Trie* t = new Trie();

    vector<string> contactList = {"ninja", "coding"};

    for(int i=0; i<contactList.size(); i++){
        t -> insertWord(contactList[i]);
    }
    string str = "ninja";
    vector<vector<string>> output;
    t -> phoneDirectory(str, output);

    for(auto i : output){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}