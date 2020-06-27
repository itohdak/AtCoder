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
  ll N, A, B;
  cin >> N >> A >> B;
  if(A+B-1 > N || A*B < N) cout << -1 << endl;
  else {
    ll rem = N-(A+B-1);
    vector<ll> v;
    auto build = [&]() {
      rep(i, A) rrep(j, B) {
        if(i != 0 && j != B-1 && rem == 0) {
          REP(k, i+1, A) v.push_back(B*k+j);
          return;
        }
        v.push_back(B*i+j);
        if(i != 0 && j != B-1) rem--;
      }
    };
    build();

    /* 座標圧縮 */
    vector<ll> u;
    rep(i, v.size()) u.push_back(v[i]);
    sort(all(u));
    vector<ll> ans;
    rep(i, v.size()) {
      ans.push_back(lower_bound(all(u), v[i])-begin(u)+1);
    }
    rep(i, N) {
      if(i) cout << ' ';
      cout << ans[i];
    }
    cout << "\n";
  }
  return 0;
}
