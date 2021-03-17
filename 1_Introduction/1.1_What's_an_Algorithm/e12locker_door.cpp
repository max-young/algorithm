#include <iostream>
#include <vector>

using namespace std;

vector<int> lockersDoor(int n)
{
  vector<int> lockers(n, 0);
  int i = 0;
  while (i < n)
  {
    int j = 0;
    while (j <= i)
    {
      lockers[j] = (lockers[j] == 0) ? 1 : 0;
      j++;
    }
    i++;
  }
  return lockers;
}

int main()
{
  cout << "How many locked locker, please enter a positive integer: ";
  int n;
  cin >> n;
  vector<int> lockers = lockersDoor(n);
  int openCount = count(lockers.begin(), lockers.end(), 1);
  copy(lockers.begin(), lockers.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "We have " << n << " lockers" << endl;
  cout << "after pass" << endl;
  cout << openCount << " locker is open" << endl;
  return 0;
}