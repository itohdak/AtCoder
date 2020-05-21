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
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) {
    cin >> A[i];
    A[i]--;
  }
  vector<bool> vis(N);
  vector<int> depth(N);
  int tmp = 0;
  int prev;
  int dep = 0;
  while(!vis[tmp]) {
    vis[tmp] = true;
    depth[tmp] = dep;
    prev = tmp;
    tmp = A[tmp];
    dep++;
    K--;
    if(K == 0) {
      cout << tmp+1 << endl;
      return 0;
    }
  }
  int loopDepth = depth[prev] - depth[tmp] + 1;
  K %= loopDepth;
  if(K == 0) {
    cout << tmp+1 << endl;
    return 0;
  }
  while(K > 0) {
    tmp = A[tmp];
    K--;
    if(K == 0) {
      cout << tmp+1 << endl;
      return 0;
    }
  }
  return 0;
}
