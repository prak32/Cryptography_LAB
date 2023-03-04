//3)WAP to find primitive roots.
#include <iostream>
#include <cmath>
using namespace std;

int power(int a, int b, int mod) {
    int ans = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int prime_factors(int n, int factors[]) {
    int count = 0;
    while (n % 2 == 0) {
        factors[count++] = 2;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors[count++] = i;
            n /= i;
        }
    }
    if (n > 2) factors[count++] = n;
    return count;
}

// Function to check if a number is primitive root of a prime
bool is_primitive(int n, int p, int phi, int factors[], int factor_count) {
    for (int i = 0; i < factor_count; i++) {
        if (power(n, phi / factors[i], p) == 1) {
            return false;
        }
    }
    return true;
}

void primitive_roots(int p) {
    int factors[100];
    int phi = p - 1;
    int factor_count = prime_factors(phi, factors);

    int roots_count = 0;
    int roots[100];

    for (int i = 2; i < p; i++) {
        if (gcd(i, p) == 1 && is_primitive(i, p, phi, factors, factor_count)) {
            roots[roots_count++] = i;
        }
    }

    cout << "Primitive Roots of " << p << " are: ";
    for (int i = 0; i < roots_count; i++) {
        cout << roots[i] << " ";
    }
    cout << endl;
}

int main() {
    int p;
    cout << "Enter a prime number: ";
    cin >> p;
    primitive_roots(p);
    return 0;
}