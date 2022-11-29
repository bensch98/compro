#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
  template <typename T>
  int hamming_weight(T n) {
    int cnt = 0;
    while (n) {
      if (n & 1) cnt++;
      n >>= 1;
    } 
    return cnt;
  }
};

int main() {
  uint32_t x32 = 0b00000000000000000000000000001011;
  uint16_t x16 = 0b0101010101010101;
  uint8_t x8 = 0b01010101;

  Solution sol;
  int res;

  res = sol.hamming_weight(x32);
  cout << "Hamming weight: " << res << endl;

  res = sol.hamming_weight(x16);
  cout << "Hamming weight: " << res << endl;

  res = sol.hamming_weight(x8);
  cout << "Hamming weight: " << res << endl;

  return 0;
}
