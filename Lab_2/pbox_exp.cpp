//2)Write a program to show the working mechanism of expansion P-box in DES.
#include <iostream>
#include <bitset>
using namespace std;
// Expansion P-box table
int EP[48] = {
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1
};
int main() {
    // Input 32-bit data
    bitset<32> input_data("11010101001111001100111110000001");
    cout << "Input data: " << input_data << endl;

    // Apply expansion P-box on input data
    bitset<48> output_data;
    for (int i = 0; i < 48; i++) {
        output_data[47-i] = input_data[32 - EP[i]];
    }

    cout << "Output data: " << output_data << endl;

    return 0;
}
