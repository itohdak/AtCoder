#include "header.hpp"

template<typename T>
size_t longest_increasing_subsequence(const vector<T>& a, bool strict=true) {
  vector<T> lis;
  for(auto& p : a) {
    typename vector<T>::iterator it;
    if(strict) it = lower_bound(lis.begin(), lis.end(), p);
    else it = upper_bound(lis.begin(), lis.end(), p);
    if(it == lis.end()) lis.emplace_back(p);
    else *it = p;
  }
  return lis.size();
}

int main() {
  int a[] = {1, 2, 5, 3, 4};
  vector<int> ve(a, a+5);
  cout << longest_increasing_subsequence(ve) << endl; // >> 4
  return 0;
}
