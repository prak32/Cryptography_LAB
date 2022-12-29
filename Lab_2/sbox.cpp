#include <iostream>
#include <bitset>
using namespace std;

bitset<48> sbox_expand(bitset<32> input) {
bitset<48> output;
  int expansion_table[64] = {
      14, 4, 13, 1, 2, 15,11, 8, 3, 10, 6, 12,  5, 9, 0, 7, 
	  0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8, 
	  4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
      15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13
  };

  for (int i = 0; i < 64; i++) {
    output[43-i] = input[31-expansion_table[i]+1];
  }

  return output;
}

int main() {

  bitset<32> input(string("10110101101010101010101010101011"));
  bitset<48> output = sbox_expand(input);

  cout << "Input:  " << input << endl;
  cout << "Output: " << output << endl;

  return 0;
}
