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

#define MAX_N 200005

class UnionFind
{
public:
  int par[MAX_N];
  int depth[MAX_N];
  int nGroup[MAX_N];

  UnionFind(int n) {
    init(n);
  }

  void init(int n) {
    for(int i=0; i<n; i++) {
      par[i] = i;
      depth[i] = 0;
      nGroup[i] = 1;
    }
  }

  int root(int x) {
    if(par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return;

    if(depth[x] < depth[y]) {
      par[x] = y;
      nGroup[y] += nGroup[x];
      nGroup[x] = 0;
    } else {
      par[y] = x;
      nGroup[x] += nGroup[y];
      nGroup[y] = 0;
      if(depth[x] == depth[y])
        depth[x]++;
    }
  }
};
bool isNum(char c) {
  return '0' <= c && c <= '9';
}
int char2int(char c) {
  return int(c-'A');
}
int int2int(char c) {
  return int(c-'0');
}
int main() {
  int N;
  cin >> N;
  vector<string> S(2);
  rep(i, 2) cin >> S[i];
  UnionFind uf(26);
  map<int, int> mp;
  rep(i, N) {
    if(isNum(S[0][i]) && isNum(S[1][i])) continue;
    else if(isNum(S[0][i])) {
      mp[char2int(S[1][i])] = int2int(S[0][i]);
    } else if(isNum(S[1][i])) {
      mp[char2int(S[0][i])] = int2int(S[1][i]);
    } else {
      uf.unite(char2int(S[0][i]), char2int(S[1][i]));
      rep(j, 2) if(!mp.count(char2int(S[j][i]))) mp[char2int(S[j][i])] = -1;
    }
  }
  // cout << mp << endl;
  vector<int> ans(26, -1);
  if(!isNum(S[0][0]) && !isNum(S[1][0])) ans[uf.root(char2int(S[0][0]))] = -2;
  for(auto m: mp) if(m.second != -1) ans[uf.root(m.first)] = m.second;
  ll res = 1;
  for(auto m: mp) {
    if(ans[uf.root(m.first)] == -1) {
      res *= 10;
      ans[uf.root(m.first)] = 10;
    } else if(ans[uf.root(m.first)] == -2) {
      res *= 9;
      ans[uf.root(m.first)] = 10;
    }
  }
  cout << res << endl;
  return 0;
}
