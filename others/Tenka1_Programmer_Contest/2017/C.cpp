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
  ll N;
  cin >> N;
  // 4*h*n*w == N*(n*w+h*w+h*n)
  // w*(4*h*n-N*n-N*h) == N*h*n
  for(ll h=1; h<=3500; h++) {
    for(ll n=1; n<=3500; n++) {
      ll a = (4*h*n-N*n-N*h);
      ll b = N*h*n;
      if(a!=0 && b%a==0 && b/a<=3500 && b/a>=1) {
        cout << h << ' ' << n << ' ' << b/a << "\n";
        return 0;
      }
    }
  }
  return 0;
}
