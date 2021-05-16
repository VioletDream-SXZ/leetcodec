#include <vector>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

class Solution;

class Solution_1854 : public Solution {
public:
    virtual int maximumPopulation(vector<vector<int>>& logs) {
        int years[2055];
        int peoples[2055];
        int max_result = 0, result;
        memset(years, 0, sizeof(years));
        memset(peoples, 0, sizeof(peoples));

        for (int i = 0; i < logs.size(); ++i) {
            years[logs[i][0]] ++;
            years[logs[i][1]] --;
        }

        for (int i = 1; i < 2051; ++i) {
            peoples[i] = peoples[i - 1] + years[i];
            if (max_result < peoples[i]) {
                max_result = peoples[i];
                result = i;
            }
        }

        return result;
    }

    virtual void run() {
       std::vector<std::vector<int>> example_1 = {
           { 1993, 1999 }, { 2000, 2010 }
       };

       std::cout << "example_1 answer:" << maximumPopulation(example_1) << std::endl;

       std::vector<std::vector<int>> example_2 = {
           { 1950, 1961 }, { 1960, 1971 }, { 1970, 1981 }
       };
       std::cout << "example_2 answer:" << maximumPopulation(example_2) << std::endl;
    }
};
