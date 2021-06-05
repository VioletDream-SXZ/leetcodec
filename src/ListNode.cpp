#include <stdio.h>
#include "ListNode.h"

ListNode::ListNode() {
    val   = 0;
    next  = nullptr;
}

ListNode::ListNode(int v) {
    val   = v;
    next  = 0;
}

ListNode::ListNode(int v, ListNode* node) {
    val   = v;
    next  = node;
}

ListNode* ListNode::createListNodeByVector(std::vector<int> vc) {
    ListNode* result = nullptr;
    ListNode* list = nullptr;

    result = new ListNode();
    list   = result;
    for (int i = 0; i < vc.size(); ++i) {
        ListNode* node = new ListNode(vc[i]);
        list->next = node;
        list = node;
    }
    list = result->next;
    delete result;
    return list;
}

void ListNode::displayList(ListNode* header) {
    ListNode* node = header;
    while(node) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}