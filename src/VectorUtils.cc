#include <stdio.h>
#include <iostream>
#include "VectorUtils.h"

namespace Utils {
    void display_int_vector(std::vector<int>& vc) {
        int size = vc.size();
        for (int i = 0; i < size; ++i) {
            printf("%d ", vc[i]);
        }
        printf("\n");
    }

    void display_int_vector(std::vector<std::string>& vc) {
        int size = vc.size();
        std::cout << "[";
        for (int i = 0; i < size; ++i) {
            if (i != size - 1) {
                std::cout << vc[i] << ",";
            } else {
                std::cout << vc[i];
            }
        }
        std::cout << "]";
        std::cout << std::endl;
    }
}