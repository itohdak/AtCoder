#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

map<ll, ll> mp;
ll X;
bool test(int n) {
  ll tmp = 1;
  rep(i, 5) tmp *= n;
  if(mp.count(tmp-X)) {
    cout << n << ' ' << mp[tmp-X] << endl;
    return true;
  } else if(mp.count(-tmp+X)) {
    cout << n << ' ' << -mp[-tmp+X] << endl;
    return true;
  } else {
    mp[tmp] = n;
    return false;
  }
}
int main() {
  cin >> X;
  ll tmp = 1;
  mp[0] = 0;
  while(!test(tmp)) { tmp++; }
  return 0;
}
