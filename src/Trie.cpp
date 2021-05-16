#include "Trie.h"

Trie::Trie()
    : bEnd(false) {
    for (int i = 0; i < 30; ++i)
        mWord[i] = NULL;
}

Trie::~Trie() {
    for (int i = 0; i < 30; ++i) {
        if (mWord[i] != NULL) {
            delete mWord[i];
            mWord[i] = NULL;
        }
    }
}

void Trie::insert(std::string word) {
    innerInsert(word, 0);
}

bool Trie::search(std::string word) {
    return innerSearch(word, 0);
}

bool Trie::startsWith(std::string prefix) {
    return innerStartsWith(prefix, 0);
}

void Trie::innerInsert(std::string& word, int index) {
    int i;
    if (index == word.size()) {
        bEnd = true;
        return;
    }

    i = word[index] - 'a';
    if (mWord[i] == NULL) {
        mWord[i] = new Trie;
    }

    mWord[i]->innerInsert(word, index + 1);
}

bool Trie::innerSearch(std::string& word, int index) {
    int i;
    if (index == word.size())
        return bEnd;

    i = word[index] - 'a';
    if (mWord[i] == NULL)
        return false;

    return mWord[i]->innerSearch(word, index + 1);
}

bool Trie::innerStartsWith(std::string& prefix, int index) {
    int i;
    if (index == prefix.size())
        return true;

    i = prefix[index] - 'a';
    if (mWord[i] == NULL)
        return false;

    return mWord[i]->innerStartsWith(prefix, index + 1);
}
