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
  int n; cin >> n;
  vector<int> A(n);
  map<int, int> mp;
  rep(i, n) {
    cin >> A[i];
    mp[A[i]]++;
  }
  auto no = [&]() {
    cout << "Impossible" << "\n";
    exit(0);
  };
  int mx = mp.rbegin()->first;
  int mn = mp.begin()->first;
  if(mn != (mx+1)/2) no();
  if(mx%2==0 && mp[mx/2] != 1) no();
  if(mx%2==1 && mp[(mx+1)/2] != 2) no();
  int ib = (mx%2==0 ? mx/2+1 : (mx+1)/2+1);
  for(int i=ib; i<=mx; i++) {
    if(mp[i] < 2) no();
  }
  cout << "Possible" << "\n";
  return 0;
}
