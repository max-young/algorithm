// 检查两个字符串是否是anagram, 即两个字符串里面的字符是否一样
#include <iostream>
#include <string>

using namespace std;

// ASC编码有256个字符
// 这么写的话, 这个算法只支持英文
const int CHAR_COUNT = 256;

bool check_anagram(string a, string b)
{
  int count[CHAR_COUNT] = {0};
  int i;
  for (i = 0; a[i] && b[i]; i++)
  {
    count[a[i]]++;
    count[b[i]]--;
  }
  // 检查a、b的长度是否一致
  // 也可以一开始就检查ab的长度
  if (a[i] || b[i])
  {
    return false;
  }
  for (i = 0; i < CHAR_COUNT; i++)
  {
    if (count[i] != 0)
      return false;
  }
  return true;
}

int main(int argc, char const *argv[])
{
  string a{"ate"};
  string b{"eat"};
  if (check_anagram(a, b))
    cout << "a and b is anagram" << endl;
  else
    cout << "a and b is not anagram" << endl;
  return 0;
}
