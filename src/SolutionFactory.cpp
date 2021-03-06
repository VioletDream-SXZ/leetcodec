#include "SolutionFactory.h"

#include "15.h"
#include "208.h"
#include "817.h"
#include "1441.h"
#include "1600.h"
#include "1854.h"

SolutionFactory* SolutionFactory::getInstance() {
    static SolutionFactory* instance = NULL;
    if (instance == NULL) {
        instance = new SolutionFactory();
    }
    return instance;
}

void SolutionFactory::initialize() {
    MKF_ADD_LEETCODEC(15,   new Solution_15());
    MKF_ADD_LEETCODEC(208,  new Solution_208());
    MKF_ADD_LEETCODEC(817,  new Solution_817());
    MKF_ADD_LEETCODEC(1441, new Solution_1441());
    MKF_ADD_LEETCODEC(1600, new ThroneInheritance());
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
