#ifndef __15_H__
#define __15_H__

#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "Solution.h"

using namespace std;

class Solution_15 : public Solution {
public:
    Solution_15() = default;

    ~Solution_15() = default;

    virtual vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> result_uint;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int first_pos = 0; first_pos < n; ++first_pos) {
            if (first_pos > 0 && nums[first_pos] == nums[first_pos - 1]) 
                continue;

            int third_pos = n -1;
            int target = -nums[first_pos];
            for (int second_pos = first_pos + 1; second_pos < n; ++second_pos) {
                if (second_pos > first_pos + 1 && nums[second_pos] == nums[second_pos - 1]) 
                    continue;

                while (third_pos > second_pos && nums[second_pos] + nums[third_pos] > target) third_pos--;
                if (second_pos == third_pos)
                    break;

                if (nums[second_pos] + nums[third_pos] == target)
                    result.push_back({nums[first_pos], nums[second_pos], nums[third_pos]});
            }
        }
        return result;
    }

    void coutVector(std::vector<int>& v) {
        for (int i = 0; i < v.size(); ++i) {
        	std::cout << v[i] << " ";
        }
        std::cout << std::endl;
        return;
    }

    virtual void run() {
        std::vector<int> example_1 = {-1,0,1,2,-1,-4};
        std::vector<std::vector<int>> answer_1 = threeSum(example_1);
        std::cout << "example_1:" << example_1[0] << " " << example_1[1] << " " << example_1[2] 
                  << " " << example_1[3] << " " << example_1[4] << " " << example_1[5] << std::endl;
        std::cout << "answer:" << std::endl;
        for (int i = 0; i < answer_1.size(); ++i) {
            for (int j = 0; j < answer_1[i].size(); ++j) {
                /* code */
                std::cout << answer_1[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif // __15_H__