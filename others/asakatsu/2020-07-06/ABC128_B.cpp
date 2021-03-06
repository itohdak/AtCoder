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
  int n; cin >> n;
  vector<string> S(n);
  vector<int> P(n);
  vector<int> id(n);
  rep(i, n) {
    cin >> S[i] >> P[i];
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) {
      if(S[i] == S[j]) return P[i] > P[j];
      return S[i] < S[j];
    });
  rep(i, n) cout << id[i]+1 << "\n";
  return 0;
}
