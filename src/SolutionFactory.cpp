#include "SolutionFactory.h"

#include "208.h"
#include "1854.h"

SolutionFactory* SolutionFactory::getInstance() {
    static SolutionFactory* instance = NULL;
    if (instance == NULL) {
        instance = new SolutionFactory();
    }
    return instance;
}

void SolutionFactory::initialize() {
    MKF_ADD_LEETCODEC(208, new Solution_208());
    MKF_ADD_LEETCODEC(1854, new Solution_1854());
}

void SolutionFactory::addSolution(int index, Solution* solution) {
    mSolutions.insert(std::pair<int, Solution*>(index, solution));
}

Solution* SolutionFactory::getSolution(int index) {
    if (mSolutions.find(index) == mSolutions.end()) {
        return NULL;
    }

    return mSolutions.find(index)->second;
}
