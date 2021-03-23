# include <iostream>
# include <assert.h>

using namespace std;

void extended_euclid(int m, int n, int &r, int &s, int &t) {
  int r0 = m, r1 = n, s0 = 1, s1 = 0, t0 = 0, t1 = 1;
  int x, y, s2, t2;
  while (true) {
    if (r1 == 0) {
      cout << r0 << endl;
      cout << s0 << endl;
      cout << t0 << endl;
      assert (r0 == s0 * m + t0 * n);
      r = r0, s = s0, t = t0;
      return;
    }
    x = r0 / r1, y = r0 % r1;
    r0 = r1, r1 = y;
    s2 = s0 - x * s1;
    s0 = s1; s1 = s2;
    t2 = t0 - x * t1;
    t0 = t1; t1 = t2;
  }
}


int main() {
  int m, n;
  cout << "Please enter two non negtive integer: ";
  cin >> m >> n;
  int r, s, t;
  extended_euclid(m, n, r, s, t);
  cout << "great common divisor of " << m << " and " << n << " is: " << r << endl; 
  cout << "bezout number of " << m << " and " << n << " is: " << s << " and " << t << endl; 
  return 0;
}