#include <iostream>
using namespace std;
#include <vector>
// Find the prime factorization of n
vector<int> prime_factorization(int n) {
vector<int> factors;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      factors.push_back(i);
      n /= i;
    }
  }
  if (n > 1) {
    factors.push_back(n);
  }
  return factors;
}
// Find the order of a modulo m
int order(int a, int m) {
  int r = 1;
  for (int i = 1; i <= m; i++) {
    r = (r * a) % m;
    if (r == 1) {
      return i;
    }
  }
  return m;
}
// Find the primitive roots of n
  vector<int> primitive_roots(int n) {
  vector<int> roots;
  vector<int> factors = prime_factorization(n);
  // Find the orders of 2 modulo each prime factor
  vector<int> orders;
  for (int factor : factors) {
    orders.push_back(order(2, factor));
  }
  // Find the primitive roots
  for (int a = 2; a < n; a++) {
    bool is_root = true;
    for (int r : orders) {
      int x = 1;
      for (int i = 1; i <= r; i++) {
        x = (x * a) % n;
      }
      if (x != 1) {
        is_root = false;
        break;
      }
    }
    if (is_root) {
      roots.push_back(a);
    }
  }

  return roots;
}

int main() {
  int n;
  cout<<"Enter the number:";
  cin >> n;

  vector<int> roots = primitive_roots(n);
  cout <<"The primitive roots of "<< n << " = ";
  for (int root : roots) {
    cout<< root << " ";
  }
  cout << endl;
  return 0;
}