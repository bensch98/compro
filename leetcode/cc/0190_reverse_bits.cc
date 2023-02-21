#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
  template <typename T>
  T reverse_bits(T n) {
    T p = 1;
    T res = 0;
    for (T i = 0; i < sizeof(T)*8; i++) {
      res <<= 1;
      res ^= n & p;
      n >>= 1;
    }
    return res;
  };

  uint32_t reverse_bits_1(uint32_t n) {
    n = ((n >> 16) | (n << 16));
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
  }
};

int main() {
  // testcases
  uint32_t n32 = 0b00000010100101000001111010011100;
  uint16_t n16 = 0b0000001010010100;
  uint8_t n8 = 0b00000010;
  Solution sol;

  uint32_t rev32 = sol.reverse_bits(n32);
  cout << (bitset<32>) n32 << endl << (bitset<32>) rev32 << endl;

  uint16_t rev16 = sol.reverse_bits(n16);
  cout << (bitset<16>) n16 << endl << (bitset<16>) rev16 << endl;

  uint8_t rev8 = sol.reverse_bits(n8);
  cout << (bitset<8>) n8 << endl << (bitset<8>) rev8 << endl;

  return 0;
}
