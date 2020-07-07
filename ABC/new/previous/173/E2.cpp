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

ll modinv(ll a, ll m=mod) {
  ll b = m, u = 1, v = 0;
  while(b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if(u < 0) u += m;
  return u;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  vector<ll> A(n);
  vector<ll> pos, neg;
  rep(i, n) {
    cin >> A[i];
    if(A[i] >= 0) pos.push_back(A[i]);
    else          neg.push_back(-A[i]);
  }
  if(n==k) {
    ll ans = 1;
    rep(i, n) (ans *= A[i]) %= mod;
    cout << (mod+ans)%mod << "\n";
  } else if((int)neg.size()==n && k%2) {
    sort(all(neg));
    ll ans = 1;
    rep(i, k) (ans *= neg[i]) %= mod;
    cout << (mod-ans) << "\n";
  } else {
    auto comp = [&](ll a1, ll a2) {
      return abs(a1) > abs(a2);
    };
    sort(all(A), comp);
    sort(all(pos), comp);
    sort(all(neg), comp);
    ll ans = 1;
    int pi=0, ni=0;
    rep(i, k) {
      (ans *= A[i]) %= mod;
      (A[i]>=0 ? pi : ni)++;
    }
    if(ans >= 0) {
      cout << ans << "\n";
    } else if(pi == 0) {
      cout << (-ans * modinv(neg[ni-1]) % mod) * pos[pi] % mod << "\n";
    } else if(ni == (int)neg.size()) {
      cout << (-ans * modinv(neg[ni-1]) % mod) * pos[pi] % mod << "\n";
    } else { // ni is always greater than 0
      if(pos[pi-1] * pos[pi] > neg[ni-1] * neg[ni]) {
        cout << (-ans * modinv(neg[ni-1]) % mod) * pos[pi] % mod << "\n";
      } else {
        cout << (-ans * modinv(pos[pi-1]) % mod) * neg[ni] % mod << "\n";
      }
    }
  }
  return 0;
}
