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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  priority_queue<int, vector<int>, greater<int>> q;
  q.push(0);
  vector<int> ans;
  vector<bool> vis(n);
  vis[0] = true;
  while(!q.empty()) {
    int tmp = q.top(); q.pop();
    ans.push_back(tmp);
    for(int ne: G[tmp]) {
      if(!vis[ne]) {
        q.push(ne);
        vis[ne] = true;
      }
    }
  }
  for(int a: ans) {
    if(a!=0) cout << ' ';
    cout << a+1;
  }
  cout << endk;
  return 0;
}
