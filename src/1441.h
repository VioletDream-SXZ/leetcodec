#ifndef __1441_H__
#define __1441_H__

#include <string>
#include <vector>
#include "Solution.h"

using namespace std;

class Solution_1441 : public Solution {
public:
    Solution_1441() = default;

    ~Solution_1441() = default;

    virtual vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int index = 0;
        int size = target.size();
        for (int i = 1; i <= n; ++i) {
            /* code */
            if (index >= size)
                break;
            
            if (i == target[index]) {
                result.push_back("push");
                index ++;
            } else {
                result.push_back("push");
                result.push_back("pop");
            }
        }
        return result;
    }

    virtual void run() {
        std::vector<int> example_1 = { 1, 3 };
        std::vector<std::string> answer_1 = buildArray(example_1, 3);
        for (int i = 0; i < answer_1.size(); ++i) {
            std::cout << answer_1[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // __1441_H__