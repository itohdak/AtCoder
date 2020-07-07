#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M; cin >> N >> M;
  vector<bool> done(N);
  vector<int> penalty(N);
  int ac = 0;
  rep(i, M) {
    int p; string S;
    cin >> p >> S; p--;
    if(!done[p]) {
      if(S == "WA") penalty[p]++;
      else {
        done[p] = true;
        ac++;
      }
    }
  }
  int pena = 0;
  rep(i, N) pena += penalty[i] * done[i];
  cout << ac << ' ' << pena << "\n";
  return 0;
}
