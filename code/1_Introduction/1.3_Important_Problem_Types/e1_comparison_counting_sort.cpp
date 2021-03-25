#include <iostream>
#include <vector>

using namespace std;

vector<int> comparisonCountingSort(vector<int> v)
{
  vector<int> Count(v.size(), 0);
  for (int i = 0; i <= (v.size() - 2); i++)
  {
    for (int j = i + 1; j <= (v.size() - 1); j++)
    {
      if (v[i] <= v[j]) {
        Count[j]++;
      } else {
        Count[i]++;
      }
    }
  }
  vector<int> S(v.size(), 0);
  copy(Count.begin(), Count.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  for (int i = 0; i <= (v.size() - 1); i++) {
    S[Count[i]] = v[i];
  }
  return S;
}

int main(int argc, char const *argv[])
{
  cout << "Please enter integer push to a vector, non integer to stop input: ";
  istream_iterator<int> begin(cin), end;
  vector<int> A(begin, end);
  vector<int> S = comparisonCountingSort(A);
  cout << "[";
  copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
  cout << "] after sort is: [";
  copy(S.begin(), S.end(), ostream_iterator<int>(cout, " "));
  cout << "]" << endl;
  return 0;
}