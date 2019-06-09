#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
 
int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> A(N);
  vector<ll> B(M), C(M);
  map<ll, int> mp;
  ll tmp = 0;
  ll ans = 0;
  rep(i, N) {
    cin >> A[i];
    if(mp.find(A[i]) != mp.end())
      mp[A[i]]++;
    else
      mp[A[i]] = 1;
    tmp += A[i];
  }
  ans = tmp;
  rep(i, M) {
    cin >> B[i] >> C[i];
    int count = B[i];
    map<ll, int>::iterator itr = mp.begin();
    while(count > 0 && itr->first < C[i]) {
      if(itr->second < count) {
	if(mp.find(C[i]) != mp.end())
	    mp[C[i]] += itr->second;
	else
	    mp[C[i]] = itr->second;
	tmp += (C[i] - itr->first) * itr->second;
	count -= itr->second;
	itr->second = 0;
      } else {
	if(mp.find(C[i]) != mp.end())
	    mp[C[i]] += count;
	else
	    mp[C[i]] = count;
	tmp += (C[i] - itr->first) * count;
	itr->second -= count;
	count = 0;
      }
      itr++;
    }
    ans = max(tmp, ans);
  }
  cout << ans << endl;
  return 0;
}
