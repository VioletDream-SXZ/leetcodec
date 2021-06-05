#ifndef __LISTNODE_H__
#define __LISTNODE_H__

#include <vector>

typedef struct ListNode {
    int       val;
    ListNode* next;

    ListNode();
    ListNode(int v);
    ListNode(int v, ListNode* node);

    static ListNode* createListNodeByVector(std::vector<int> vc);

    static void displayList(ListNode* header);
} ListNode;

#endif // __LISTNODE_H__