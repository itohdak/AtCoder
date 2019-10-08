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
  ll H, W, N;
  cin >> H >> W >> N;
  vector<ll> A(N), B(N);
  int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
  int dy[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
  map<pair<int, int>, ll> mp;
  rep(i, N) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    rep(j, 9) {
      int x = A[i] + dx[j];
      int y = B[i] + dy[j];
      if(x < 1 || x > H-2 || y < 1 || y > W-2) continue;
      auto p = make_pair(x, y);
      if(mp.count(p))
        mp[p]++;
      else
        mp[p] = 1;
    }
  }
  vector<ll> ans(10);
  for(auto m: mp)
    ans[m.second]++;
  ans[0] = (H-2) * (W-2) - accumulate(all(ans), 0LL);
  for(ll a: ans)
    cout << a << endl;
  return 0;
}

