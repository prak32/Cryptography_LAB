//6)WAP to implement Elgamal Cryptographic System
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
// function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// function to calculate the power of a number modulo another number
int power(int x, int y, int p) {
    int res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// function to generate a random prime number in a given range
int generatePrime(int min, int max) {
    int p = rand() % (max - min + 1) + min;
    while (!isPrime(p)) {
        p = rand() % (max - min + 1) + min;
    }
    return p;
}

int main() {
    int minPrime = 1000;  // minimum prime number to generate
    int maxPrime = 2000;  // maximum prime number to generate
    int p = generatePrime(minPrime, maxPrime);  // shared prime number
    int g = rand() % (p - 2) + 1;  // generator
    int x = rand() % (p - 2) + 1;  // private key of Alice
    int y = power(g, x, p);        // public key of Alice
    int k = rand() % (p - 2) + 1;  // random number k
    int m;                        // message to be encrypted
    int c1, c2;                   // encrypted message
    int decrypted;                // decrypted message

    // print the values of p, g, x, and y
    cout << "p = " << p << endl;
    cout << "g = " << g << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    // get the message to be encrypted
    cout << "Enter the message to be encrypted: ";
    cin >> m;

    // encrypt the message
    c1 = power(g, k, p);
    c2 = (m * power(y, k, p)) % p;

    // print the encrypted message
    cout << "Encrypted message: (" << c1 << ", " << c2 << ")" << endl;

    // decrypt the message
    decrypted = (c2 * power(c1, p - 1 - x, p)) % p;

    // print the decrypted message
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
