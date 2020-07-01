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
  int N, Q;
  cin >> N >> Q;
  vector<ll> S(N), T(N), X(N);
  set<pair<ll, pair<int, ll>>> se;
  rep(i, N) {
    cin >> S[i] >> T[i] >> X[i];
    se.emplace(S[i]-X[i], make_pair(1, X[i]));
    se.emplace(T[i]-X[i], make_pair(-1, X[i]));
  }
  vector<pair<ll, int>> D(Q);
  rep(i, Q) {
    cin >> D[i].first;
    D[i].second = i;
  }
  sort(all(D));
  vector<ll> ans(Q, longinf);
  auto itr = se.begin();
  set<ll> se2; se2.insert(longinf);
  int cur = 0;
  while(true) {
    if(cur == Q) break;
    while(itr != se.end() && itr->first <= D[cur].first) {
      if(itr->second.first == 1) {
        se2.insert(itr->second.second);
      } else {
        se2.erase(itr->second.second);
      }
      itr++;
    }
    if(itr == se.end()) break;
    ans[D[cur].second] = *se2.begin();
    cur++;
  }
  rep(i, Q) cout << (ans[i]==longinf ? -1 : ans[i]) << "\n";
  return 0;
}
