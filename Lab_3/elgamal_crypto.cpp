#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int p = 13; // A prime number
const int g = 5;  // A primitive root modulo p

int main()
{
    srand(time(0)); // Seed the random number generator

    // Alice generates a secret key x and sends Bob the public key (p, g, g^x mod p)
    int x = rand() % (p - 1) + 1; // Generate a random secret key x in the range [1, p-1]
    int gx = (int)pow(g, x) % p; // Compute g^x mod p
    cout << "Alice's secret key: " << x << endl;
    cout << "Alice's public key: (" << p << ", " << g << ", " << gx << ")" << endl;

    // Bob generates a secret key y and sends Alice the public key (p, g, g^y mod p)
    int y = rand() % (p - 1) + 1; // Generate a random secret key y in the range [1, p-1]
    int gy = (int)pow(g, y) % p; // Compute g^y mod p
    cout << "Bob's secret key: " << y << endl;
    cout << "Bob's public key: (" << p << ", " << g << ", " << gy << ")" << endl;

    // Alice and Bob can now use the Diffie-Hellman key exchange to compute a shared secret key
    int s = (int)pow(gy, x) % p; // Alice computes (g^y)^x mod p
    int t = (int)pow(gx, y) % p; // Bob computes (g^x)^y mod p
    cout << "Shared secret key (Alice): " << s << endl;
    cout << "Shared secret key (Bob): " << t << endl;

    return 0;
}
