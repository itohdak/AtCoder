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

int N;
vector<int> X, Y, C;
bool test(long double k) {
  vector<multiset<pair<long double, int>>> se(2);
  rep(i, N) {
    se[0].emplace(X[i]-k/C[i], 1);
    se[0].emplace(X[i]+k/C[i], -1);
    se[1].emplace(Y[i]-k/C[i], 1);
    se[1].emplace(Y[i]+k/C[i], -1);
  }
  rep(i, 2) {
    int cnt = 0;
    for(auto ele: se[i]) {
      if(ele.second == 1) {
        cnt++;
      } else {
        if(cnt < N) return false;
      }
      if(cnt == N) {
        break;
      }
    }
  }
  return true;
}

long double binary_search() {
  long double ng = 0, ok = 200000000;
  while(abs(ok - ng) > 1e-10) {
    long double mid = (ok + ng) / 2;
    if(test(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  X = vector<int>(N);
  Y = vector<int>(N);
  C = vector<int>(N);
  rep(i, N) cin >> X[i] >> Y[i] >> C[i];
  cout << fixed << setprecision(10) << binary_search() << endl;
  return 0;
}
