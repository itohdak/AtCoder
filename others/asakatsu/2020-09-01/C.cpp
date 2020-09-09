#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  int q; cin >> q;
  deque<char> que;
  for(char c: s) que.push_back(c);
  int flag = 0;
  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      flag ^= 1;
    } else {
      int f; cin >> f;
      char c; cin >> c;
      if((f-1)^flag) {
        que.push_back(c);
      } else {
        que.push_front(c);
      }
    }
  }
  if(flag) {
    while(!que.empty()) {
      cout << que.back();
      que.pop_back();
    }
  } else {
    while(!que.empty()) {
      cout << que.front();
      que.pop_front();
    }
  }
  cout << endk;
  return 0;
}
