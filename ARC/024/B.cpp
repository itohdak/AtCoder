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
  vector<int> C(N);
  rep(i, N) cin >> C[i];
  int l = 0, r = 0;
  vector<int> cnt;
  while(l < N && r < N) {
    while(r < N && C[l] == C[r]) r++;
    cnt.push_back(r-l);
    l = r;
  }
  if(cnt.size() == 1) {
    cout << -1 << endl;
    return 0;
  }
  if(cnt.size()%2) {
    cnt[0] += *(--cnt.end());
    cnt.pop_back();
  }
  cout << (*max_element(all(cnt))-1)/2+1 << endl;
  return 0;
}
