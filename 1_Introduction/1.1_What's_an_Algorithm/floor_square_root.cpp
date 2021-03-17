// 计算一个正整数的floor square root
# include <iostream>

using namespace std;

int floor_square_root(int n) {
  int i = 1;
  while (i * i <= n) {
    i++;
  }
  return i - 1;
}

int main() {
  cout << "Please enter a positive integer: ";
  int n;
  cin >> n;
  cout << "The floor square root of " << n << " is " << floor_square_root(n) << endl;
  return 0;
}