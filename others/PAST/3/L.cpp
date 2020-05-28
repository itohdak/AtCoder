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
  cin >> N;
  set<pair<ll, pair<int, int>>, greater<pair<ll, pair<int, int>>>> se1, se2;
  vector<int> K(N);
  vector<vector<ll>> T(N);
  rep(i, N) {
    cin >> K[i];
    T[i] = vector<ll>(K[i]);
    rep(j, K[i]) cin >> T[i][j];
  }
  vector<int> id(N);
  rep(i, N) {
    se1.emplace(T[i][0], make_pair(i, 0));
    se2.emplace(T[i][0], make_pair(i, 0));
    se2.emplace(T[i][1], make_pair(i, 1));
    id[i] = 2;
  }
  int M;
  cin >> M;
  rep(i, M) {
    int a;
    cin >> a;
    if(a == 1) {
      auto fi = *se1.begin();
      int i = fi.second.first;
      se1.erase(fi);
      se2.erase(fi);
      cout << fi.first << endl;
      if(id[i]-1<K[i]) {
        auto se = make_pair(T[i][id[i]-1], make_pair(i, id[i]-1));
        se1.insert(se);
      }
      if(id[i]<K[i]) {
        auto th = make_pair(T[i][id[i]], make_pair(i, id[i]));
        se2.insert(th);
      }
      id[i]++;
    } else {
      auto fi = *se2.begin();
      int i = fi.second.first;
      if(fi.second.second == id[i]-1) {
        se2.erase(fi);
        cout << fi.first << endl;
        if(id[i]<K[i]) {
          auto th = make_pair(T[i][id[i]], make_pair(i, id[i]));
          se2.insert(th);
        }
      } else {
        se1.erase(fi);
        se2.erase(fi);
        cout << fi.first << endl;
        if(id[i]-1<K[i]) {
          auto se = make_pair(T[i][id[i]-1], make_pair(i, id[i]-1));
          se1.insert(se);
        }
        if(id[i]<K[i]) {
          auto th = make_pair(T[i][id[i]], make_pair(i, id[i]));
          se2.insert(th);
        }
      }
      id[i]++;
    }
  }
  return 0;
}
