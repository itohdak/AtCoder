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
  ll n; cin >> n;
  vector<ll> div, div2;
  find_divisor(n-1, div);
  find_divisor(n, div2);
  int cnt = 0;
  for(ll d: div2) {
    ll m = n;
    if(d<2) continue;
    while(m>0) {
      // cout << m << "\n";
      if(m==1) {
        cnt++;
        break;
      } else if(m%d) {
        if((m-1)%d==0) cnt++;
        break;
      } else {
        m /= d;
      }
    }
  }
  cout << div.size()-1+cnt << "\n";
  return 0;
}
