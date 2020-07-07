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
  int N;
  cin >> N;
  vector<ll> A(N);
  map<ll, int> mp;
  rep(i, N) {
    cin >> A[i];
    mp[A[i]]++;
  }
  vector<ll> avail, avail2;
  for(auto ele: mp) {
    if(ele.second >= 4) {
      avail.push_back(ele.first);
      avail2.push_back(ele.first);
    } else if(ele.second >= 2) {
      avail.push_back(ele.first);
    }
  }
  ll ans = 0;
  if(avail2.size() >= 1) ans = max(*avail2.rbegin() * *avail2.rbegin(), ans);
  if(avail.size() >= 2) ans = max(*avail.rbegin() * *(++avail.rbegin()), ans);
  cout << ans << "\n";
  return 0;
}
