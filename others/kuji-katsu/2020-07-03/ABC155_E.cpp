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
  string S;
  cin >> S;
  int N = S.size();
  vector<int> num(N+1);
  rep(i, N) num[i] = S[N-1-i]-'0';
  ll ans = accumulate(all(num), 0LL);
  rep(i, N+1) {
    if(num[i]>9) {
      num[i]%=10;
      num[i+1]++;
      ans++;
    }
    if(num[i]>5) {
      ans += (10-num[i])-num[i]+1;
      num[i] = 0;
      num[i+1]++;
    }
  }
  cout << num << endl;
  cout << ans << "\n";
  return 0;
}
