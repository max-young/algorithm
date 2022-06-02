// algorithm select sort
// input: vector, size n
// output: vector, size n
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::swap;

void selectSort(vector<int> &v)
{
  int n = v.size();
  for (int i = 0; i < n; i++)
  {
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (v[j] < v[min])
      {
        min = j;
      }
    }
    swap(v[i], v[min]);
  }
}

int main()
{
  vector<int> v = {3, 5, 6, 1, 2, 4};
  selectSort(v);
  for (auto i : v)
  {
    cout << i << " ";
  }
}
