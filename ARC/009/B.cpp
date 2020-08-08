#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  map<char, char> mp, mp2;
  rep(i, 10) {
    char b; cin >> b;
    mp[b] = char('0'+i);
    mp2[char('0'+i)] = b;
  }
  int n; cin >> n;
  vector<int> A(n);
  rep(i, n) {
    string s; cin >> s;
    for(char& c: s) c = mp[c];
    A[i] = atoi(s.c_str());
  }
  sort(all(A));
  rep(i, n) {
    string s = to_string(A[i]);
    for(char& c: s) c = mp2[c];
    cout << s << endk;
  }
  return 0;
}
