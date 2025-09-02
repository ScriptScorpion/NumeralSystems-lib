#pragma once
#include <stdlib.h>
// basicly algorithm doing / 16 and reminder is storing in array and then prints all backwards
static inline char *ToHex(int num) {
     if (num < 0) {
          return "";
     }
     unsigned char *hex_num = (unsigned char*)calloc(sizeof(unsigned char) * 32, sizeof(unsigned char)); // we creating with unsigned char to insure no strange characters are going to output
     char *res = (char*)calloc(sizeof(char) * 32, sizeof(char)); 
     int i = 0; // iteration we are currently elapsed
     while (num > 0) {
          hex_num[i] = (num % 16) + '0';
          num = num / 16;
          ++i;
     }
     
     for (int j = i - 1, t = 0; j >= 0; --j, ++t) { // -1 cuz of not needed 0 at start of the output
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
          res[t] = hex_num[j];
     }
     free(hex_num);
     return res;
}
