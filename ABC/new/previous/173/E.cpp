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
  int n, k; cin >> n >> k;
  vector<ll> A(n);
  vector<ll> pos, neg;
  rep(i, n) {
    cin >> A[i];
    if(A[i] >= 0) pos.push_back(A[i]);
    else neg.push_back(-A[i]);
  }
  int np = pos.size(), nn = neg.size();
  if(n == k) {
    ll ans = 1;
    rep(i, k) (ans *= A[i]) %= mod;
    cout << (ans+mod)%mod << "\n";
  } else if(n == nn && k%2) {
    sort(all(neg));
    ll ans = 1;
    rep(i, k) (ans *= neg[i]) %= mod;
    cout << mod-ans << "\n";
  } else {
    ll ans = 1;
    sort(all(pos), greater<ll>());
    sort(all(neg), greater<ll>());
    int cnt = 0;
    int i=0, j=0;
    auto addpos = [&]() {
      (ans *= pos[i]) %= mod;
      i++;
      cnt++;
    };
    auto addneg = [&]() {
      (ans *= neg[j]) %= mod;
      (ans *= neg[j+1]) %= mod;
      j += 2;
      cnt += 2;
    };
    while(cnt < k) {
      if(k-cnt == 1) {
        addpos();
      } else if(i == np) {
        addneg();
      } else if(j >= nn-1) {
        addpos();
      } else if(i == np-1) {
        if(pos[i] > neg[j]*neg[j+1]) addpos();
        else addneg();
      } else {
        if(pos[i]*pos[i+1] > neg[j]*neg[j+1]) addpos();
        else addneg();
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
