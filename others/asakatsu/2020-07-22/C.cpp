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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int na, nb; cin >> na >> nb;
  vector<int> A(na), B(nb);
  map<int, int> mp;
  rep(i, na) {
    cin >> A[i];
    mp[A[i]]++;
  }
  rep(i, nb) {
    cin >> B[i];
    mp[B[i]]++;
  }
  int cnt = 0;
  for(auto ele: mp) {
    if(ele.second == 2) cnt++;
  }
  cout << fixed << setprecision(10) << (double)cnt/mp.size() << "\n";
  return 0;
}
