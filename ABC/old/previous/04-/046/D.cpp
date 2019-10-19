#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  map<int, int> mp;
  vector<int> memo(N+1);
  int tmp = 0;
  rep(i, N) {
    memo[i] = tmp;
    if(S[i] == 'g') tmp++;
    else tmp--;
    if(mp.count(tmp)) mp[tmp]++;
    else mp[tmp] = 1;
  }
  memo[N] = tmp;
  ll ans = 0;
  tmp = 2;
  rep(i, N) {
    if(S[i] == 'g' &&
       mp.begin()->first >= tmp)
      tmp += 2, ans++;
    mp[memo[i+1]]--;
    if(mp[memo[i+1]] == 0)
      mp.erase(memo[i+1]);
  }
  cout << ans << endl;
  return 0;
}

