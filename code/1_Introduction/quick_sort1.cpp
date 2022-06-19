#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void quickSort(vector<int> &v, int begin, int end)
{
  if (begin >= end)
    return;
  int baseIndex = begin;
  int base = v[baseIndex];
  for (size_t i = baseIndex + 1; i < end; ++i)
  {
    int currentNum = v[i];
    if (currentNum < base)
    {
      for (size_t j = i; j > baseIndex; --j)
        v[j] = v[j - 1];
      v[baseIndex] = currentNum;
      ++baseIndex;
    }
  }
  quickSort(v, begin, baseIndex);
  quickSort(v, baseIndex + 1, end);
}

int main()
{
  vector<int> v = {1, 5, 2, 4, 3};
  for_each(v.cbegin(), v.cend(), [](auto i)
           { cout << i << " "; });
  cout << endl;
  quickSort(v, 0, v.size());
  for_each(v.cbegin(), v.cend(), [](auto i)
           { cout << i << " "; });
  cout << endl;
}