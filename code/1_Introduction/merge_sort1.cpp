#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

void merge(vector<int> &v, int begin, int end, int middle)
{
  vector<int> left(v.begin() + begin, v.begin() + middle);
  vector<int> right(v.begin() + middle, v.begin() + end);
  int i = 0, j = 0;
  int vIndex = begin;
  while (i < left.size() && j < right.size())
  {
    if (left[i] < right[j])
    {
      v[vIndex] = left[i];
      ++i;
    }
    else
    {
      v[vIndex] = right[j];
      ++j;
    }
    ++vIndex;
  }
  while (i < left.size())
  {
    v[vIndex] = left[i];
    ++i;
    ++vIndex;
  }
  while (j < right.size())
  {
    v[vIndex] = right[j];
    ++j;
    ++vIndex;
  }
}

void sort(vector<int> &v, int begin, int end)
{
  if (begin + 1 >= end)
    return;
  int middle = (end + begin) / 2;
  sort(v, begin, middle);
  sort(v, middle, end);
  merge(v, begin, end, middle);
}

int main()
{
  vector<int> v = {3, 2, 1, 5, 4, 4, 1, 3, 7, 3, 1};
  for_each(v.cbegin(), v.cend(), [](auto i)
           { cout << i << " "; });
  cout << endl;
  sort(v, 0, v.size());
  cout << "after sort......" << endl;
  for_each(v.cbegin(), v.cend(), [](auto i)
           { cout << i << " "; });
  cout << endl;

  return 0;
}