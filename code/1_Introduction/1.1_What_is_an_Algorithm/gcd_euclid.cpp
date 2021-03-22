// 最大公约数的欧几里得算法
# include <iostream>

using namespace std;

int gcd_euclid(int m, int n) {
  while (n != 0) {
    int r =  m % n;
    m = n;
    n = r;
  }
  return m;
}

int main() {
  int m, n;
  cout << "Please enter two non negtive integer: ";
  cin >> m >> n;
  int r = gcd_euclid(m, n);
  cout << "great common divisor of " << m << " and " << n << " is: " << r << endl; 
}