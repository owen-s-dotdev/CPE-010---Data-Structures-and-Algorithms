#include <iostream>
#include "supp.h"
#include "studentvaccination.h"

int main() {
    int x = 2;
    int exponents[] = {1, 5, 16, 50, 100, 1000};

    for (int n : exponents) {
        int count_r = 0, count_br = 0;

        int result_r = rpower(x, n, count_r);
        int result_br = brpower(x, n, count_br);

        std::cout << "Exponent: " << n
             << "\n  rpower result = " << result_r << ", multiplications = " << count_r
             << "\n  brpower result = " << result_br << ", multiplications = " << count_br
             << "\n";
    }

    return 0;
}