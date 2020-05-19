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
  cin >> N;
  vector<string> S(N);
  vector<int> T(N);
  map<string, int> mp;
  rep(i, N) {
    cin >> S[i] >> T[i];
    mp[S[i]] = i;
  }
  string X;
  cin >> X;
  vector<ll> sum(N+1);
  rrep(i, N) sum[i] = sum[i+1] + T[i];
  cout << sum[mp[X]+1] << endl;
  return 0;
}
