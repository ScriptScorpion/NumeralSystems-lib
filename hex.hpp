#pragma once
#include <string>
// basicly algorithm doing / 16 and reminder is storing in array and then prints all backwards
inline std::string ToHex(int num) noexcept{
     if (num < 0) {
          return "";
     }
     unsigned char *hex_num = new unsigned char[32]{};
     std::string res = "";
     int i = 0; // iteration we are currently elapsed
     while (num > 0) {
          hex_num[i] = (num % 16) + '0';
          num = num / 16;
          ++i;
     }
     for (int j = i - 1; j >= 0; --j) { // -1 cuz of not needed 0 at start of the output
          switch (hex_num[j] - '0') {
               case 10:
                    hex_num[j] = 'A';
                    break;
               case 11:
                    hex_num[j] = 'B';
                    break;
               case 12:
                    hex_num[j] = 'C';
                    break;
               
               case 13:
                    hex_num[j] = 'D';
                    break;
               case 14:
                    hex_num[j] = 'E';
                    break;
               
               case 15:
                    hex_num[j] = 'F';
                    break;
               
               default:
                    break;
          } 
          res += hex_num[j];
     }
     delete[] hex_num;
     return res;
}
