//4)WAP to implement Diffie-Hellman Key Exchange Algorithm.
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
// function to check if a number is prime
bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// function to calculate the power of a number modulo another number
int power(int x, int y, int p)
{
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
int generatePrime(int min, int max)
{
    int p = rand() % (max - min + 1) + min;
    while (!isPrime(p)) {
        p = rand() % (max - min + 1) + min;
    }
    return p;
}

int main()
{
    int minPrime = 1000;  // minimum prime number to generate
    int maxPrime = 2000;  // maximum prime number to generate
    int g = 2;            // generator
    int p = generatePrime(minPrime, maxPrime);  // shared prime number
    int a, b;             // secret keys of A and B
    int A, B;             // public keys of A and B
    int sharedKeyA, sharedKeyB;  // shared secret keys of A and B

    // print the values of p and g
    cout << "p = " << p << endl;
    cout << "g = " << g << endl;

    // generate secret keys of A and B
    a = rand() % (p - 2) + 1;
    b = rand() % (p - 2) + 1;

    // calculate public keys of A and B
    A = power(g, a, p);
    B = power(g, b, p);

    // print public keys of A and B
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;

    // calculate shared secret keys of A and B
    sharedKeyA = power(B, a, p);
    sharedKeyB = power(A, b, p);

    // print shared secret keys of A and B
    cout << "Shared secret key of A = " << sharedKeyA << endl;
    cout << "Shared secret key of B = " << sharedKeyB << endl;

    return 0;
}