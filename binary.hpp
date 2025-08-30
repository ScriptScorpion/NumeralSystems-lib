#pragma once
// basicly algorithm doing / 2 and reminder is storing in array and then prints all backwards
inline unsigned int ToBinary(unsigned int num) {
    unsigned int *binary_num = new unsigned int[32]{};
    unsigned int *binary_copy = new unsigned int[32]{};
    unsigned int res = 0;
    int i = 0; // iteration we are currently elapsed
    while (num > 0) {
        binary_num[i] = num % 2;
        num = num / 2;
        ++i;
    }
    for (int j = i - 1, p = 0; j >= 0; --j, ++p) { // -1 cuz of not needed 0 at start of the output
        binary_copy[p] = binary_num[j];
    }
    delete[] binary_num;
    for (int t = 0; t < i; ++t) {
        res = res * 10 + binary_copy[t];
    }
    delete[] binary_copy;
    return res;
}