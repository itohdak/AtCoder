#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

ll modpow(ll a, ll N, ll mod) {
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
  int n, a; cin >> n >> a;
  a--;
  string k; cin >> k;
  vector<int> B(n);
  rep(i, n) {
    cin >> B[i];
    B[i]--;
  }
  set<int> vis;
  vector<int> loop, tmp;
  while(1) {
    if(vis.count(a)) {
      auto begin = find(all(tmp), a);
      loop = vector<int>(end(tmp)-begin);
      copy(begin, end(tmp), loop.begin());
      break;
    }
    tmp.push_back(a);
    vis.insert(a);
    a = B[a];
  }
  if(k.size() < 6 && atoi(k.c_str()) <= tmp.size()) {
    int p = atoi(k.c_str());
    cout << tmp[p]+1 << endk;
  } else {
    int m = loop.size();
    int p = 0;
    reverse(all(k));
    rep(i, k.size()) {
      (p += modpow(10, i, m) * (k[i]-'0')) %= m;
    }
    rep(i, tmp.size()) {
      p--;
      p = (p+m)%m;
    }
    cout << loop[p]+1 << endk;
  }
  return 0;
}
