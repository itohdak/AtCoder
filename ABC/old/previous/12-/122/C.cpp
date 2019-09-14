#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> num(N);
  for(int i=1; i<N; i++) {
    string tmp = S.substr(i-1, 2);
    num[i] = num[i-1] + (tmp == "AC" ? 1 : 0);
  }
  // for(int i=0; i<N; i++)
  //   cout << num[i] << ' ';
  // cout << endl;
  for(int i=0; i<Q; i++) {
    int l, r;
    cin >> l >> r;
    cout << num[r-1] - num[l-1] << endl;
  }
  return 0;
}

