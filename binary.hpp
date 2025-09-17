#pragma once
// basicly algorithm doing / 2 and reminder is storing in array and then prints all backwards
inline unsigned int ToBinary(int num) noexcept {
    if (num < 0) {
        return 0;
    }
    unsigned int *binary_num = new unsigned int[32]{};
    unsigned int res = 0;
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
// this code is for big numbers only
inline std::string ToBigBinary(long int num) noexcept { 
     if (num <= 0) return "0";
    
     std::string binary;
     while (num > 0) {
          binary = binary + (num % 2 ? "1" : "0"); // if remainder of division is above 0 then it is 1 else 0
          num /= 2;
     }
     return binary;
}
inline std::string ToBigBinary(long long int num) noexcept { 
     if (num <= 0) return "0";
    
     std::string binary;
     while (num > 0) {
          binary = binary + (num % 2 ? "1" : "0"); // if remainder of division is above 0 then it is 1 else 0
          num /= 2;
     }
     return binary;
}
