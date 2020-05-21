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

int N;
vector<string> res;
bool query(int k) {
  string in;
  k %= N;
  cout << k << endl;
  cin >> in;
  res[k] = in;
  if(in == "Vacant") return true;
  return false;
}
bool test(ll k, ll l, ll r) {
  query(k);
  if((k-l)%2) {
    
  } else {
    
  }
  return false;
}
ll binary_search() {
  ll ng = N, ok = 0;
  if(query(ok)) return ok;
  res = vector<string>(N);
  while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if(test(mid, ok, ng)) ok = mid;
    else ng = mid;
  }
  return ok;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  binary_search();
  return 0;
}
