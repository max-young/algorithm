// input array, begin, end
// out array
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int partition(vector<int> &array, int begin, int end)
{
  int standard = array[begin];
  vector<int> leftArray, rightArray;
  for (size_t i = begin + 1; i <= end; ++i)
  {
    if (array[i] <= standard)
      leftArray.push_back(array[i]);
    else
      rightArray.push_back(array[i]);
  }
  for (size_t i = 0; i < leftArray.size(); ++i)
    array[begin + i] = leftArray[i];
  int standardIndex = leftArray.size();
  array[begin + standardIndex] = standard;
  for (size_t i = 0; i < rightArray.size(); ++i)
    array[begin + standardIndex + 1 + i] = rightArray[i];
  return standardIndex;
}

void quickSort(vector<int> &array, int begin, int end)
{
  if (begin >= end)
    return;
  int standard = array[begin];
  vector<int> leftArray, rightArray;
  for (size_t i = begin + 1; i <= end; ++i)
  {
    if (array[i] <= standard)
      leftArray.push_back(array[i]);
    else
      rightArray.push_back(array[i]);
  }
  for (size_t i = 0; i < leftArray.size(); ++i)
    array[begin + i] = leftArray[i];
  int standardIndex = leftArray.size();
  array[begin + standardIndex] = standard;
  for (size_t i = 0; i < rightArray.size(); ++i)
    array[begin + standardIndex + 1 + i] = rightArray[i];
  quickSort(array, begin, begin + standardIndex - 1);
  quickSort(array, begin + standardIndex + 1, end);
}

int main()
{
  vector<int> v = {3, 6, 1, 2, 7, 2, 9, 4};
  // vector<int> v = {6, 3, 1, 2, 5, 7, 2, 4};
  quickSort(v, 0, v.size()-1);
  for_each(v.cbegin(), v.cend(), [](int x)
           { cout << x << " "; });
  cout << endl;
}