#include <array>
#include <iostream>
#include <vector>

using std::array;
using std::cin;
using std::cout;
using std::vector;
using std::cout;
using std::endl;

int main()
{
  size_t a, b;
  cout << "please enter matrix m row size and column size:";
  cin >> a >> b;
  int m[b][a];
  for (size_t i = 0; i < a; ++i)
  {
    cout << "please input " << i + 1 << "st row number: ";
    for (size_t j = 0; j < b; ++j)
      cin >> m[j][i];
  }

  size_t c, d;
  while (c != b)
  {
    cout << "please enter matrix n row size and column size:";
    cin >> c >> d;
    if (c != b)
      cout << "matrix n row size should equal to matrix m column size";
  }
  int n[d][c];
  for (size_t i = 0; i < c; ++i)
  {
    cout << "please input " << i + 1 << "st row number: ";
    for (size_t j = 0; j < d; ++j)
      cin >> n[j][i];
  }

  int result[d][a];
  for (size_t i = 0; i < a; ++i)
  {
    for (size_t j = 0; j < d; ++j)
    {
      result[j][i] = 0;
      for (size_t k = 0; k < b; ++k)
        result[j][i] += (m[k][i] * n[j][k]);
    }
  }

  for (size_t i = 0; i < a; ++i)
  {
    for (size_t j = 0; j < b; ++j)
      cout << m[j][i] << " ";
    cout << endl;
  }

  for (size_t i = 0; i < c; ++i)
  {
    for (size_t j = 0; j < d; ++j)
      cout << n[j][i] << " ";
    cout << endl;
  }

  for (size_t i = 0; i < a; ++i)
  {
    for (size_t j = 0; j < d; ++j)
      cout << result[j][i] << " ";
    cout << endl;
  }

  return 0;
}