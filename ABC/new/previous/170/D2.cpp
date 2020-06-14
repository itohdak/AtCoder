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
  vector<int> A(N);
  map<int, int> mp;
  rep(i, N) {
    cin >> A[i];
    mp[A[i]]++;
  }
  sort(all(A));
  vector<bool> num(1000005, true);
  int ans = 0;
  rep(i, N) {
    if(num[A[i]]) {
      if(mp[A[i]] == 1) ans++;
      for(int j=1; A[i]*j<1000005; j++) num[A[i]*j] = false;
    }
  }
  cout << ans << endl;
  return 0;
}
