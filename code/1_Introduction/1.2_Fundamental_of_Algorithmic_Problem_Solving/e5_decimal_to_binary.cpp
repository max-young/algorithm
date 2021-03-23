#include <iostream>
#include <string>
using namespace std;

// 将十进制数字转换成二进制字符串表达
string decimalToBinaryString(int n)
{
  string binaryString ("");
  // 请注意这里使用do...while, 兼容n=0的情况
  do
  {
    int x = n / 2;
    int y = n % 2;
    n = x;
    binaryString = to_string(y) + binaryString;
  } while (n != 0);
  return binaryString;
}

int main(int argc, char const *argv[])
{
  cout << "Please enter a positive integer: ";
  int n;
  cin >> n;
  string binaryString;
  binaryString = decimalToBinaryString(n);
  cout << "Decinal number: " << n << " transform to binary is: " << binaryString << endl;
  return 0;
}