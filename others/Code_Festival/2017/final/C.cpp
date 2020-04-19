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

vector<int> exists;
int ans;
void dfs(int i, int N, vector<int>& v) {
  if(i == N) {
    int n = v.size();
    int mn = 24;
    rep(i, n) REP(j, i+1, n) {
      mn = min(min(abs(v[i]-v[j]), 24-abs(v[i]-v[j])), mn);
    }
    ans = max(mn, ans);
    return;
  } else {
    if(exists[i] > 2) {
      ans = 0;
      return;
    } else if(exists[i] > 1) {
      v.push_back(i);
      v.push_back((24-i)%24);
      dfs(i+1, N, v);
      v.pop_back();
      v.pop_back();
    } else if(exists[i]) {
      v.push_back(i);
      dfs(i+1, N, v);
      v.pop_back();
      v.push_back((24-i)%24);
      dfs(i+1, N, v);
      v.pop_back();
    } else {
      dfs(i+1, N, v);
    }
  }
}
int main() {
  int N;
  cin >> N;
  vector<int> D(N);
  exists = vector<int>(13);
  exists[0] = 1;
  rep(i, N) {
    cin >> D[i];
    exists[D[i]]++;
  }
  vector<int> v;
  ans = 0;
  dfs(0, 13, v);
  cout << ans << endl;
  return 0;
}
