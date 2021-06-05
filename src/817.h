#ifndef __817_H__
#define __817_H__

#include <vector>
#include <set>
#include "Solution.h"
#include "ListNode.h"
#include "VectorUtils.h"

using namespace std;

class Solution_817 : public Solution {
public:
    Solution_817() = default;

    ~Solution_817() = default;

    virtual void run() {
        std::vector<int> example_1_list = {0, 1, 2, 3, 4};
        std::vector<int> example_1_vc   = {0, 1, 2, 4};
        ListNode* example_1_header = ListNode::createListNodeByVector(example_1_list);
        std::cout << "example:" << std::endl;
        ListNode::displayList(example_1_header);
        Utils::display_int_vector(example_1_vc);
        std::cout << "answer:" << numComponents(example_1_header, example_1_vc) << std::endl;
    }

    virtual int numComponents(ListNode* head, vector<int>& nums) {
        int result = 0;
        set<int> container;
        for (auto i : nums) {
            container.insert(i);
        }

        while(head) {
            // 判断结点的办法为，当前链表指针的数据在nums里面，并且当前指针的下一个结点为空或者下一个结点的数据不在nums里面，则视为存在结点。
            if (container.find(head->val) != container.end() &&
                (head->next == nullptr || container.find(head->next->val) == container.end())) {
                result ++;
                // printf("%d\n", head->val);
            }
            // printf("%d %p %d %d\n", head->val, head->next, container.find(head->val) != container.end(), head->next == nullptr || container.find(head->next->val) == container.end());
            head = head->next;
        }
        return result;
    }

private:
};

#endif // __817_H__