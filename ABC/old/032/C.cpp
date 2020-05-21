#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> S(N);
  bool zero = false;
  rep(i, N) {
    cin >> S[i];
    if(S[i] == 0) zero = true;
  }
  if(zero) {
    cout << N << endl;
    return 0;
  }
  int l=0, r=0;
  ll mul = 1;
  int ans = 0;
  rep(i, N) {
    while(r < N && mul*S[r] <= K) {
      mul *= S[r];
      r++;
    }
    ans = max(r-l, ans);
    if(l != r) mul /= S[l];
    l++;
    r = max(l, r);
  }
  cout << ans << endl;
  return 0;
}
