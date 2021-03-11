// 埃拉托斯特尼筛法, 筛选素数
# include <iostream>
# include <vector>

using namespace std;

vector<int> sieve(int n) {
  vector<int> a {0, 0};
  for (int i = 2; i <= n; i++) {
    a.push_back(i);
  }

  int t = 2;
  while (t * t <= n) {
    if (a[t] != 0) {
      int j = t * t;
      while (j <= n) {
        a[j] = 0;
        j += t;
      }
    }
    t ++;
  }

  vector<int> r;
  for(int i = 0; i <= n; i++) {
    if (a[i] != 0)
      r.push_back(a[i]);
  }
  return r;
}

int main() {
  cout << "Please enter a integer that greater than 1: ";
  int n;
  cin >> n;
  vector<int> r = sieve(n);
  cout << "prime numbers that <= " << n << " is: " << endl;
  copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}