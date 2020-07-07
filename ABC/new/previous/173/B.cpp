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
  vector<int> cnt(4);
  vector<string> S(n);
  rep(i, n) {
    cin >> S[i];
    if(S[i] == "AC") cnt[0]++;
    else if(S[i] == "WA") cnt[1]++;
    else if(S[i] == "TLE") cnt[2]++;
    else cnt[3]++;
  }
  cout << "AC x " << cnt[0] << "\n";
  cout << "WA x " << cnt[1] << "\n";
  cout << "TLE x " << cnt[2] << "\n";
  cout << "RE x " << cnt[3] << "\n";
  return 0;
}
