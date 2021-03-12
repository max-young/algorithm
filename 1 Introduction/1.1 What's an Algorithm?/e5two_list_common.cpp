# include <iostream>
# include <vector>

using namespace std;

// 两个有序的元素是整数的序列, 找到它们的共同的元素
vector<int> common_of_two_list(vector<int> m, vector<int> n) {
  vector<int> result;
  vector<int>::iterator mi = m.begin();
  vector<int>::iterator ni = n.begin();
  while (mi != m.end() && ni != n.end()) {
    if (*mi < *ni)
      mi++;
    else if (*mi == *ni) {
      result.push_back(*mi);
      mi++;
      ni++;
    }
    else
      ni++;
  }
  return result;
}

int main() {
  vector<int> m = {2, 5, 5, 5, 7};
  vector<int> n = {2, 2, 3, 5, 5, 7};
  cout << "the common elements of {";
  copy(m.begin(), m.end(), ostream_iterator<int>(cout, " "));
  cout << "} and {";
  copy(n.begin(), n.end(), ostream_iterator<int>(cout, " "));
  cout << "} is: ";
  vector<int> r = common_of_two_list(m, n);
  copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}