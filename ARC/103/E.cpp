#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<pair<int, int> > edges;
  if(s[n-1] == '1' || s[0] == '0') {
    cout << -1 << endl;
    return 0;
  }
  REP(i, 1, n) {
    if(s[i-1] != s[n-1-i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  vector<int> j(n, n-1);
  int tmp = n-1;
  for(int i=n-1; i>=0; i--) {
    j[i] = tmp;
    if(s[i] == '1') tmp = i;
  }
  rep(i, n-1)
    edges.push_back(make_pair(i+1, j[i]+1));
  for(auto e: edges)
    cout << e.first << ' ' << e.second << endl;
  return 0;
}

