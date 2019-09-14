#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > D(100005);
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    D[a].push_back(b);
  }
  priority_queue<int> q;
  ll ans = 0;
  REP(i, 1, M+1) {
    for(int d: D[i])
      q.push(d);
    if(!q.empty()) {
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
  return 0;
}

