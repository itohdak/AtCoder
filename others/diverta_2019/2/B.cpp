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
  vector<ll> X(N), Y(N);
  rep(i, N) cin >> X[i] >> Y[i];
  map<pair<ll, ll>, int> mp;
  rep(i, N) {
    REP(j, i+1, N) {
      pair<ll, ll> d1, d2;
      d1 = make_pair(X[i]-X[j], Y[i]-Y[j]);
      d2 = make_pair(X[j]-X[i], Y[j]-Y[i]);
      map<pair<ll, ll>, int>::iterator it;
      it = mp.find(d1);
      if(it == mp.end()) mp[d1] = 1;
      else it->second++;
      it = mp.find(d2);
      if(it == mp.end()) mp[d2] = 1;
      else it->second++;
    }
  }
  int maxN = 0;
  for(map<pair<ll, ll>, int>::iterator it=mp.begin(); it!=mp.end(); it++)
    if(it->second > maxN) {
      maxN = it->second;
    }
  cout << N - maxN << endl;
  return 0;
}

