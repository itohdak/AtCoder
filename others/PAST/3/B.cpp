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
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int> cnt(M);
  vector<vector<int>> solved(N);
  rep(q, Q) {
    int type;
    cin >> type;
    if(type == 1) {
      int n;
      cin >> n;
      --n;
      int point = 0;
      for(int s: solved[n]) {
        point += N-cnt[s];
      }
      cout << point << endl;
    } else {
      int n, m;
      cin >> n >> m;
      --n, --m;
      cnt[m]++;
      solved[n].push_back(m);
    }
  }
  return 0;
}
