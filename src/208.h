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
        insert("apple");
        std::cout << search("apple") << std::endl;
        std::cout << search("app")   << std::endl;
        std::cout << startsWith("app") << std::endl;

        insert("app");
        std::cout << search("app") << std::endl;
    }

private:
    Trie* mTrie;
};
