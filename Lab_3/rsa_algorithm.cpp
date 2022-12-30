//WAP to implement RSA algorithm.
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// Function to find the greatest common divisor
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// Function to find the modular multiplicative inverse
int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}
// Function to generate the keys
void generateKeys(int p, int q, int &e, int &d, int &n)
{
    // Calculate n
    n = p * q;
    // Calculate the Euler's totient function
    int phi = (p - 1) * (q - 1);
    // Choose a small odd prime for e
    e = 3;
    while (true)
    {
        if (gcd(e, phi) == 1)
            break;
        e += 2;
    }
    // Calculate the modular multiplicative inverse of e
    d = modInverse(e, phi);
}
// Function to encrypt the message
int encrypt(int message, int e, int n)
{
    int cipher = 1;
    for (int i = 0; i < e; i++)
        cipher = (cipher * message) % n;
    return cipher;
}
// Function to decrypt the message
int decrypt(int cipher, int d, int n)
{
    int message = 1;
    for (int i = 0; i < d; i++)
        message = (message * cipher) % n;
    return message;
}

int main()
{
    int p = 13, q = 11;
    // Generate the keys
    int e, d, n;
    generateKeys(p, q, e, d, n);

    cout << "Public key: (" << e << ", " << n << ")" << endl;
    cout << "Private key: (" << d << ", " << n << ")" << endl;
    // Test the encryption and decryption
    int message = 17;
    cout << "Original message: " << message << endl;

    int cipher = encrypt(message, e, n);
    cout << "Encrypted message: " << cipher << endl;

    int decrypted = decrypt(cipher, d, n);
    cout << "Decrypted message: " << decrypted << endl;
    return 0;
}