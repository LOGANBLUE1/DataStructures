#include<bits/stdc++.h>
using namespace std;

class Trie {
public:
    char data;
    Trie* children[26];
    bool isEnd;
    int childCount;

    Trie(char d) {
        this->data = d;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        childCount = 0;
        isEnd = false;
    }
    
};

class Solution {
public:
    Trie* root;
    Solution() {
        root = new Trie('-');
    }

    void insert(string word) {
        Trie* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new Trie(c);
            }
            else{
                node->childCount++;
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }

    string searchWord(string word) {
        Trie* node = root;
        string result;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                return word;
            }
            result += c;
            if (node->children[i]->isEnd) {
                return result;
            }
            node = node->children[i];
        }
        return word;
    }

    void findLCP(string first, string &ans, Trie* root) {
        //yha main galti karunga
        if(root->isEnd) {
            return;
        }
        for(int i=0; i<first.length(); i++) {
            char ch = first[i];

            if(root->childCount == 1) {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else
                break;
            
            if(root->isEnd)
                break;
        }
    }
};