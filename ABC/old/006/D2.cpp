#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> C(n); rep(i, n) cin >> C[i];
  cout << n-longest_increasing_subsequence(C) << "\n";
  return 0;
}
