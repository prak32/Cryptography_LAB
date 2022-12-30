//WAP to implement the Miller-Rabin primality test.
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
typedef long long ll;

// Helper function to compute (a * b) % m
ll mulmod(ll a, ll b, ll m) {
  ll res = 0;
  a = a % m;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res + a) % m;
    }
    a = (a * 2) % m;
    b /= 2;
  }
  return res % m;
}

// Helper function to compute (a ^ b) % m
ll modulo(ll a, ll b, ll m) {
  ll res = 1;
  a = a % m;
  while (b > 0) {
    if (b % 2 == 1) {
      res = mulmod(res, a, m);
    }
    a = mulmod(a, a, m);
    b /= 2;
  }
  return res % m;
}

// Miller-Rabin primality test
bool isPrime(ll n, int k) {
  if (n <= 1 || n == 4) return false;
  if (n <= 3) return true;

  ll d = n - 1;
  while (d % 2 == 0) {
    d /= 2;
  }

  for (int i = 0; i < k; i++) {
    ll a = rand() % (n - 3) + 2;
    ll x = modulo(a, d, n);
    if (x == 1 || x == n - 1) continue;
    for (int j = 0; j < d - 1; j++) {
      x = mulmod(x, x, n);
      if (x == 1) return false;
      if (x == n - 1) break;
    }
    if (x != n - 1) return false;
  }
  return true;
}

int main() {
  int k = 4; // Number of iterations
  ll n = 11; // Number to test for primality

  if (isPrime(n, k)) {
    cout << n << " is prime." << endl;
  } else {
    cout << n << " is not prime." << endl;
  }

  return 0;
}

