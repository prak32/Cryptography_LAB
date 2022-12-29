#include <bits/stdc++.h>
using namespace std;
//Function to left rotate n by d bits
unsigned int leftRotate(unsigned int n, unsigned int d)
{
return (n << d) | (n >> (32 - d));
}

// Permuted Choice 1
int PC1[56] = {57, 49, 41, 33, 25, 17, 9,
1, 58, 50, 42, 34, 26, 18,
10, 2, 59, 51, 43, 35, 27,
19, 11, 3, 60, 52, 44, 36,
63, 55, 47, 39, 31, 23, 15,
7, 62, 54, 46, 38, 30, 22,
14, 6, 61, 53, 45, 37, 29,
21, 13, 5, 28, 20, 12, 4};

// Permuted Choice 2
int PC2[48] = {14, 17, 11, 24, 1, 5,
3, 28, 15, 6, 21, 10,
23, 19, 12, 4, 26, 8,
16, 7, 27, 20, 13, 2,
41, 52, 31, 37, 47, 55,
30, 40, 51, 45, 33, 48,
44, 49, 39, 56, 34, 53,
46, 42, 50, 36, 29, 32};

// Iteration Shift Array
int ISA[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

// Function to generate keys
void generateKeys(unsigned int key)
{
// Permuted Choice 1
unsigned int permutedKey[56];
for (int i = 0; i < 56; i++)
permutedKey[i] = (key >> (64 - PC1[i])) & 1;

for (int i = 0; i < 16; i++)
{
    int temp = permutedKey[0];
    for (int j = 0; j < 27; j++)
        permutedKey[j] = permutedKey[j + 1];
    permutedKey[27] = temp;

    temp = permutedKey[28];
    for (int j = 28; j < 55; j++)
        permutedKey[j] = permutedKey[j + 1];
    permutedKey[55] = temp;

    unsigned int roundKey[48];
    for (int j = 0; j < 48; j++)
        roundKey[j] = permutedKey[PC2[j] - 1];

    cout << "Round Key " << i + 1 << ": ";
    for (int j = 0; j < 48; j++)
        cout << roundKey[j];
    cout << endl;
}
}

int main()
{

unsigned int key = 0b00010011001010100001110100010101;
generateKeys(key);

return 0;
}