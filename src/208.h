#ifndef _208_H__
#define _208_H__
#include <stdio.h>
#include <string>
#include <iostream>

#include "Trie.h"

class Solution;

class Solution_208 : public Solution {
public:
    Solution_208() {
        mTrie = new Trie;
    }

    ~Solution_208() {
        delete mTrie;
    }

    void insert(std::string word) {
        mTrie->insert(word);
    }

    bool search(std::string word) {
        return mTrie->search(word);
    }

    bool startsWith(std::string prefix) {
        return mTrie->startsWith(prefix);
    }

    virtual void run() {
        std::cout << "insert apple" << std::endl;
        insert("apple");
        std::cout << "search \"apple\" answer:" << search("apple") << std::endl;
        std::cout << "search \"app\" answer:" << search("app")   << std::endl;
        std::cout << "startsWith \"app\" answer:" << startsWith("app") << std::endl;
        std::cout << "insert app" << std::endl;
        insert("app");
        std::cout << "search \"app\" answer:" << search("app")   << std::endl;
        std::cout << search("app") << std::endl;
    }

private:
    Trie* mTrie;
};

#endif // _208_H__