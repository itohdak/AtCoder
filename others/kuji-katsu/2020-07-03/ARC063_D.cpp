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
  int N; ll T;
  cin >> N >> T;
  vector<ll> A(N);
  multiset<ll, greater<ll>> se;
  rep(i, N) {
    cin >> A[i];
    se.insert(A[i]);
  }
  map<ll, int> mp;
  rep(i, N) {
    se.erase(se.find(A[i]));
    mp[*se.begin()-A[i]]++;
  }
  cout << mp.rbegin()->second << "\n";
  return 0;
}
