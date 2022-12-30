//WAP to implement Diffe-Hellman key exchange algorithm.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
// Returns true if n is a prime number, false otherwise
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i <= sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
// Generates a random prime number in the range [min, max]
int generate_prime(int min, int max) {
    while (true) {
        int n = rand() % (max - min + 1) + min;
        if (is_prime(n)) {
            return n;
        }
    }
}
// Calculates a^b mod m
int mod_pow(int a, int b, int m) {
    int res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main() {
    // Set the seed for the random number generator
    srand(time(NULL));
    // Generate a random prime p in the range [1000, 10000]
    int p = generate_prime(1000, 10000);
    // Generate a random prime q in the range [100, 1000]
    int q = generate_prime(100, 1000);
    // Calculate n = p * q
    int n = p * q;
    // Generate a random integer g in the range [2, n-1]
    int g = rand() % (n - 1) + 2;
    // Generate a random private key for Alice in the range [2, n-1]
    int a = rand() % (n - 1) + 2;

    // Generate a random private key for Bob in the range [2, n-1]
    int b = rand() % (n - 1) + 2;

    // Calculate Alice's public key
    int A = mod_pow(g, a, n);
    // Calculate Bob's public key
    int B = mod_pow(g, b, n);
    // Calculate the shared secret key for Alice
    int s_a = mod_pow(B, a, n);
    // Calculate the shared secret key for Bob
    int s_b = mod_pow(A, b, n);
    // Print the shared secret key for Alice and Bob
    cout << "Shared secret key for Alice: " << s_a << endl;
    cout << "Shared secret key for Bob: " << s_b << endl;
    return 0;
}