#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

void merge(vector<int> &array, int begin, int end, int middle);

void mergeSort(vector<int> &array, int begin, int end)
{
  if (end - begin <= 1)
    return;
  int middle = begin + (end - begin) / 2;
  mergeSort(array, begin, middle);
  mergeSort(array, middle, end);
  merge(array, begin, end, middle);
}

void merge(vector<int> &array, int begin, int end, int middle)
{
  vector<int> leftArray, rightArray;
  for (size_t i = 0; i < middle - begin; ++i)
    leftArray.push_back(array[begin+i]);
  for (size_t i = 0; i < end - middle; ++i)
    rightArray.push_back(array[middle+i]);
  int i = 0, j = 0, index = 0;
  while (i < (middle - begin) && j < (end - middle))
  {
    if (leftArray[i] < rightArray[j])
      array[begin + index++] = leftArray[i++];
    else
      array[begin + index++] = rightArray[j++];
  }
  while (i < (middle - begin))
    array[begin + index++] = leftArray[i++];
  while (j < (end - middle))
    array[begin + index++] = rightArray[j++];
}

int main()
{
  vector<int> v = {3, 6, 1, 2, 7, 2, 9, 4};
  mergeSort(v, 0, v.size());
  for_each(v.cbegin(), v.cend(), [](int x){ cout << x << " "; });
  cout << endl;
}