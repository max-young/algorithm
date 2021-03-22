# include <iostream>

using namespace std;

int gcd_euclid(int m, int n) {
  while (true) {
    if (m == 0)
      return n;
    if (n == 0)
      return m;

    if (m > n)
      m = m - n;
    else if (m == n)
      return m;
    else
      n = n - m;
  }
}

int main() {
  int m, n;
  cout << "Please enter two non negtive integer: ";
  cin >> m >> n;
  int r = gcd_euclid(m, n);
  cout << "great common divisor of " << m << " and " << n << " is: " << r << endl; 
}