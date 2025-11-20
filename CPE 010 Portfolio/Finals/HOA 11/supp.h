//
// Created by oms2v on 21/10/2025.
//

#ifndef SUPP_H
#define SUPP_H

inline bool Unique(const int A[], const int n, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (A[i] == A[j]) {
                return false;
            }
        }
    }
    return true;
}

// Recursive power: O(n)
inline int rpower(const int x, const int n, int &count) {
    if (n == 0) return 1; // x^0 = 1
    count++;
    return x * rpower(x, n - 1, count);
}

// Binary recursive power: O(log n)
inline int brpower(const int x, const int n, int &count) {
    if (n == 0) return 1;

    int y = brpower(x, n / 2, count);

    if (n % 2 == 0) {
        count += 1; // y * y
        return y * y;
    } else {
        count += 2; // x * y * y
        return x * y * y;
    }
}



#endif //SUPP_H
