# include <iostream>

using namespace std;

int gcd_euclid(int &m, int &n) {
  while (n != 0) {
    int r =  m % n;
    m = n;
    n = r;
  }
  return m;
}

int main() {
  int m = 60, n = 24;
  int r = gcd_euclid(m, n);
  cout << "great common divisor of " << m << " and " << n << " is: " << r << endl; 
}