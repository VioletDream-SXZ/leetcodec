#ifndef __TRIE_H__
#define __TRIE_H__
#include <stdio.h>
#include <string>

/***
 * 字典树的运行流程
 * 插入: 遍历字符串，将所有的单词都固定到字典树上面，结尾标志bEnd为1，否则bEnd为0
 * 查找: 遍历字符串，将所有的单词都在树上遍历，如果存在，继续查找，直到字符串的尾部根bEnd标记为1，返回true，否则，返回0
 * 查找前缀: 遍历字符串，如果所有单词都在树上，则返回true，否则，返回false
 */
class Trie {
public:
    Trie();

    ~Trie();

    void insert(std::string word);

    bool search(std::string word);

    bool startsWith(std::string prefix);

private:
    void innerInsert(std::string& word, int index);

    bool innerSearch(std::string& word, int index);

    bool innerStartsWith(std::string& prefix, int index);

private:
    Trie* mWord[30];
    bool  bEnd;
};

#endif // __TRIE_H__