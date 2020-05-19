#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<vector<int> > E; // edges
void dfs(int tmp, int par, int value){
  int next_val = 0;
  /*
    implement here
    ex) update next_val
  */
  for(int c: E[tmp])
    if(c != par)
      dfs(c, tmp, next_val);
}
// dfs(0, -1, 0)

