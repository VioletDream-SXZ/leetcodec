#include <stdio.h>
#include "VectorUtils.h"

namespace Utils {
    void display_int_vector(std::vector<int>& vc) {
        int size = vc.size();
        for (int i = 0; i < size; ++i) {
            printf("%d ", vc[i]);
        }
        printf("\n");
    }
}