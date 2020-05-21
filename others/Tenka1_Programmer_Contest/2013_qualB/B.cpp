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
  int Q;
  ll L;
  cin >> Q >> L;
  deque<pair<int, int>> q;
  ll cnt = 0;
  bool err = false;
  rep(i, Q) {
    string comm;
    cin >> comm;
    if(comm == "Push") {
      int N, M;
      cin >> N >> M;
      if(err) continue;
      if(cnt + N > L) {
        cout << "FULL" << endl;
        err = true;
        continue;
      }
      q.emplace_back(M, N);
      cnt += N;
    } else if(comm == "Pop") {
      int N;
      cin >> N;
      if(err) continue;
      if(cnt < N) {
        cout << "EMPTY" << endl;
        err = true;
        continue;
      }
      cnt -= N;
      while(N > 0) {
        if(q.back().second <= N) {
          N -= q.back().second;
          q.pop_back();
        } else {
          q.back().second -= N;
          N = 0;
        }
      }
    } else if(comm == "Top") {
      if(err) continue;
      if(cnt == 0) {
        cout << "EMPTY" << endl;
        err = true;
        continue;
      }
      cout << q.back().first << endl;
    } else {
      if(err) continue;
      cout << cnt << endl;
    }
  }
  if(!err) cout << "SAFE" << endl;
  return 0;
}
