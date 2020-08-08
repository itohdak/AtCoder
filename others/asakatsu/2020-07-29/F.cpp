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
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k, q; cin >> n >> k >> q;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  ll mn = longinf;
  rep(i, n) {
    ll tmp = A[i];
    priority_queue<ll, vector<ll>, greater<ll>> que;
    vector<ll> v;
    rep(j, n) {
      if(A[j] < tmp) {
        while((int)que.size() >= k) {
          v.push_back(que.top()); que.pop();
        }
        while(!que.empty()) que.pop();
      } else {
        que.push(A[j]);
      }
    }
    while((int)que.size() >= k) {
      v.push_back(que.top()); que.pop();
    }
    sort(all(v));
    if((int)v.size() < q) continue;
    mn = min(v[q-1]-v[0], mn);
  }
  cout << mn << "\n";
  return 0;
}
