#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  map<ll, pair<int, ll>, greater<ll> > mp; // val, (i, num)
  mp[0] = make_pair(-1, 1);
  rep(i, N) {
    ll a;
    cin >> a;
    if(!mp.count(a)) {
      mp[a] = make_pair(i, 1);
    } else {
      mp[a].second++;
      mp[a].first = min(mp[a].first, i);
    }
  }
  vector<ll> ans(N);
  for(auto itr=mp.begin(); itr!=mp.end();) {
    ll tmp = itr->first;
    int i = (itr->second).first;
    ll num = (itr->second).second;
    itr++;
    ll tmp2 = itr->first;
    int i2 = (itr->second).first;
    ans[i] += (tmp - tmp2) * num;
    if(i2 == -1) break;
    (itr->second).first = min((itr->second).first, i);
    (itr->second).second += num;
  }
  for(auto a: ans)
    cout << a << endl;
  return 0;
}

