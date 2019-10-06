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
  int N;
  cin >> N;
  map<int, int> mp;
  rep(i, N) {
    int a;
    cin >> a;
    if(!mp.count(a)) mp[a] = 1;
    else             mp[a]++;
  }
  vector<pair<int, int> > v;
  for(auto m: mp)
    v.push_back(make_pair(m.first, m.second));
  int n = v.size();
  int l=0, r=n-1;
  int cnt = 0;
  while(l <= r) {
    while(l < n && v[l].second <= 1)  l++;
    while(r >= 0 && v[r].second <= 1) r--;
    if(l <= r) {
      if(l == r) {
        int tmp = v[l].second / 2 * 2;
        cnt += tmp;
        v[l].second -= tmp;
      } else {
        int tmp = min(v[l].second, v[r].second) - 1;
        cnt += tmp * 2;
        v[l].second -= tmp;
        v[r].second -= tmp;
        if(l + 1 == r)
          if(v[l].second == 2 || v[r].second == 2)
            cnt++;
      }
    }
  }
  cout << N - cnt << endl;
  return 0;
}

