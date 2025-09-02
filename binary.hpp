#pragma once
// basicly algorithm doing / 2 and reminder is storing in array and then prints all backwards
inline int ToBinary(unsigned int num) {
    unsigned int *binary_num = new unsigned int[32]{};
    int res = 0;
    int i = 0; // iteration we are currently elapsed
    while (num > 0) {
        binary_num[i] = num % 2;
        num = num / 2;
        ++i;
    }
    for (int j = i - 1; j >= 0; --j) { // -1 cuz of not needed 0 at start of the output
        res = res * 10 + binary_num[j];
    }
    delete[] binary_num;
    return res;
}
