#ifndef __SOLUTION_H__
#define __SOLUTION_H__
#include <stdio.h>

class Solution {
public:
    Solution() = default;

    virtual ~Solution() = default;

    virtual void run() = 0;
};

#endif // __SOLUTION_H__