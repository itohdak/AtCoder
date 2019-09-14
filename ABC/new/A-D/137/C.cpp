#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  unordered_map<string, ll> mp;
  rep(i, N) {
    cin >> S[i];
    sort(S[i].begin(), S[i].end());
    if(mp.find(S[i]) == mp.end())
      mp[S[i]] = 1;
    else
      mp[S[i]]++;
  }
  ll ans = 0;
  for(auto itr=mp.begin(); itr!=mp.end(); itr++)
    ans += itr->second * (itr->second-1) / 2;
  cout << ans << endl;
  return 0;
}

