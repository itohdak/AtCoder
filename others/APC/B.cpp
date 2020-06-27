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
  vector<ll> A(N), B(N), sub(N);
  rep(i, N) cin >> A[i];
  rep(i, N) {
    cin >> B[i];
    sub[i] = B[i]-A[i];
  }
  sort(all(sub));
  // cout << sub << endl;
  ll cur = 0;
  rep(i, N) {
    if(sub[i] < 0) {
      cur += -sub[i];
    } else {
      cur -= min(sub[i]/2, cur);
    }
  }
  cout << (cur == 0 ? "Yes" : "No") << "\n";
  return 0;
}
