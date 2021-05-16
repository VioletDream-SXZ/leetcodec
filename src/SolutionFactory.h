#include <map>
#include "Solution.h"

#define MKF_INITIALIZE_LEETCODEC() \
SolutionFactory::getInstance()->initialize()

#define MKF_ADD_LEETCODEC(index, solution) \
{                                          \
    SolutionFactory* factory = SolutionFactory::getInstance(); \
    factory->addSolution(index, solution);                     \
}

#define MKF_GET_LEETCODEC(index) \
    SolutionFactory::getInstance()->getSolution(index)

class SolutionFactory {
public:
    static SolutionFactory* getInstance();

    static void initialize();

public:
    SolutionFactory() = default;

    ~SolutionFactory() = default;

    void addSolution(int index, Solution* solution);

    Solution* getSolution(int index);

private:
    std::map<int, Solution*> mSolutions;
};
