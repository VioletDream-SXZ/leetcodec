#include <stdio.h>

#include "SolutionFactory.h"

int main(int argc, char** argv) {
    MKF_INITIALIZE_LEETCODEC();

    Solution* solution = MKF_GET_LEETCODEC(1600);
    if (solution) {
        solution->run();
    }
    return 0;
}
