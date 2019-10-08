#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

#define MAX_N 55
ll C[MAX_N][MAX_N];
void make() {
  rep(i, MAX_N) {
    C[i][1] = i;
    C[i][i] = 1;
    C[0][i] = 1;
    C[i][0] = 1;
  }
  REP(i, 1, MAX_N) rep(j, i) {
    if(i-1 < 0 || j-1 < 0) continue;
    C[i][j] = C[i-1][j] + C[i-1][j-1];
  }
}
ll comb(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return C[n][r];
}

int main() {
  make();
  int N, A, B;
  cin >> N >> A >> B;
  vector<ll> V(N);
  unordered_map<ll, int> mp;
  rep(i, N) {
    cin >> V[i];
    if(mp.count(V[i])) mp[V[i]]++;
    else mp[V[i]] = 1;
  }
  sort(all(V), greater<ll>());
  unordered_map<ll, int> mp2;
  ll M = 0;
  rep(i, A) {
    M+= V[i];
    if(mp2.count(V[i])) mp2[V[i]]++;
    else mp2[V[i]] = 1;
  }
  double ave = double(M) / A;
  cout << setprecision(10) << ave << endl;
  if(ave == V[A-1]) {
    ll ans = 0;
    REP(i, mp2[V[A-1]], min(mp[V[A-1]], B-A+mp2[V[A-1]])+1)
      ans += comb(mp[V[A-1]], i);
    cout << ans << endl;
  } else {
    cout << comb(mp[V[A-1]], mp2[V[A-1]]) << endl;
  }
  return 0;
}

