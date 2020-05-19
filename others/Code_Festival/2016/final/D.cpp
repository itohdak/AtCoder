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
  int N, M;
  cin >> N >> M;
  int MAX_X = 100000;
  vector<int> X(N);
  vector<int> cnt(MAX_X+1);
  rep(i, N) {
    cin >> X[i];
    cnt[X[i]]++;
  }
  vector<vector<deque<int>>> cnt2(M, vector<deque<int>>(2));
  rep(i, MAX_X+1) {
    rep(j, cnt[i]%2) cnt2[i%M][0].push_back(i);
    rep(j, cnt[i]/2*2) cnt2[i%M][1].push_back(i);
  }
  rep(i, M) {
    while(!cnt2[i][1].empty()) {
      cnt2[i][0].push_back(cnt2[i][1].front());
      cnt2[i][1].pop_front();
    }
  }
  int ans = 0;
  for(int i=0; i<=M/2; i++) {
    if(i == 0 || i == M-i) {
      while(cnt2[i][0].size() >= 2) {
        ans++;
        cnt2[i][0].pop_front();
        cnt2[i][0].pop_front();
      }
    } else {
      while(!cnt2[i][0].empty() && !cnt2[M-i][0].empty()) {
        ans++;
        cnt2[i][0].pop_front();
        cnt2[M-i][0].pop_front();
      }
    }
  }
  rep(i, M) {
    map<int, int> cnt3;
    while(!cnt2[i][0].empty()) {
      cnt3[cnt2[i][0].front()]++;
      cnt2[i][0].pop_front();
    }
    for(auto m: cnt3) {
      ans += m.second / 2;
    }
  }
  cout << ans << endl;
  return 0;
}
