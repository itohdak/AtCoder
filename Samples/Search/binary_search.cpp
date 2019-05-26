#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

bool test(vector<int> v, int k, int t) {
  return v[k] <= t; // modify here
}

int binary_search(vector<int> v, int n, int t) {
  int l = -1, r = n; // 初期値注意
  while(r - l > 1) {
    int mid = (l + r) / 2;
    if(test(v, mid, t))
      l = mid;
    else
      r = mid;
  }
  return l;
}

int main() {
  int a[] = {1,4,7,19,29};
  vector<int> v(a, a+5);
  int n = v.size();
  cout << "input: ";
  for(int i=0; i<n; i++)
    cout << v[i] << ' ';
  cout << endl;
  cout << binary_search(v, n, 1) << endl;
  cout << upper_bound(v.begin(), v.end(), 1) - v.begin() << endl; // upper_boundは条件を満たさない
  cout << lower_bound(v.begin(), v.end(), 1) - v.begin() << endl; // lower_boundは条件を満たす
  return 0;
}
