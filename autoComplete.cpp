/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>    // std::reverse
#include <unordered_map>
#include <vector>
using namespace std;


class AutoComplete {
    //private:
    public:
    class Node {
        public:
        string prefix;
        std::unordered_map<char, Node*> *childern;          
        bool isEndOfWord;
    
        Node(string prefix) {
            this->prefix = prefix;
            this->childern = new std::unordered_map<char, Node*>();
        }
    };
    
    Node * trie;
    
    void insertWord(string s) {
        Node *curr = trie;
        for (int i = 0; i < s.length(); ++i)
        {
            std::unordered_map<char, Node*> *childern = curr->childern;
            if (childern->end() == childern->find(s[i]))
            {
                (*childern)[s[i]] = new Node(s.substr(0, i+1));
            }
            curr = (*childern)[s[i]];
            if (i == s.length() - 1) curr->isEndOfWord = true;
        }
    }
    
    //public:
    
    AutoComplete(string dict[], int length) {
        trie = new Node("");
        for (int i = 0; i < length; ++i)
            insertWord(dict[i]);
    }
    
    void getWordsForPrefix(string prefix, std::vector<string> &results) {
        Node *curr = trie;
        
        for (char c : prefix) {
            if (curr->childern->end() != curr->childern->find(c)) {
                curr = curr->childern->at(c);
            }
            else {
                return;
            }
        }
        findAllChildWords(curr, results);
    }
    
    void findAllChildWords(Node *n, std::vector<string> &results) {
        if (n->isEndOfWord) results.push_back(n->prefix);
        for (auto pair : *(n->childern)) {
            findAllChildWords(pair.second, results);
        }
    }
};

int main()
{
    string dict[] = {"ABC", "ABB", "ABD", "AAA"};
    AutoComplete autoComplete(dict, 4);
    std::vector<string> words;
    autoComplete.getWordsForPrefix("A", words);
    for (string s : words)
    {
        cout << s << endl;
    }
    return 0;
}
