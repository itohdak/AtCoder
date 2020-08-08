#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; ll a, b; cin >> n >> a >> b;
  multiset<ll> st;
  rep(i, n) {
    ll a; cin >> a;
    st.insert(a);
  }
  if(a == 1) {
    for(ll a: st) cout << a << endk;
    return 0;
  }
  while(b && *st.begin()*a < *st.rbegin()) {
    ll mn = *st.begin();
    st.insert(mn*a);
    st.erase(st.find(mn));
    b--;
  }
  ll m = b/n;
  b %= n;
  deque<ll> q;
  ll pw = modpow(a, m);
  for(ll a: st) q.push_back(a%mod*pw%mod);
  while(b) {
    ll top = q.front();
    q.pop_front();
    q.push_back(top*a%mod);
    b--;
  }
  rep(i, n) cout << q[i] << endk;
  return 0;
}
