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

void find_divisor(ll N, vector<ll>& divisor) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<ll> A(N);
  set<ll> se;
  map<ll, int> mp;
  rep(i, N) {
    cin >> A[i];
    se.insert(A[i]);
    mp[A[i]]++;
  }
  int cnt = 0;
  rep(i, N) {
    vector<ll> div;
    find_divisor(A[i], div);
    bool ok = true;
    // cout << div << endl;
    for(ll d: div) {
      if(d == A[i]) continue;
      if(se.count(d)) {
        ok = false;
        break;
      }
    }
    if(ok && mp[A[i]] == 1) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
