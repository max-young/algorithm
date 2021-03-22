// consecutive integer check连续整数检查法求两个整数的最大公约数
# include <iostream>

using namespace std;

int cic_gcd(int m, int n) {
  int t = m < n? m:n;
  while (true) {
    if (m % t == 0) {
      if (n % t == 0)
        return t;
    }
    t--;
  }
}

int main() {
  cout << "Please enter two nonnegtive number: ";
  int m, n;
  cin >> m >> n;
  int r = cic_gcd(m, n);
  cout << "The gcd of " << m << " and " << n << " is " << r << endl;
  return 0;
}