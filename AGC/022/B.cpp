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

int main() {
  int N;
  cin >> N;
  if(N == 3) {
    cout << 2 << ' ' << 5 << ' ' << 63 << endl;
  } else if(N == 4) {
    cout << 2 << ' ' << 5 << ' ' << 20 << ' ' << 63 << endl;
  } else if(N == 5) {
    cout << 2 << ' ' << 5 << ' ' << ' ' << 20 << ' ' << 30 << ' ' << 63 << endl;
  } else {
    set<int> se;
    ll sum = 0;
    int tmp = 2;
    int i = 0;
    int diff[] = {1, 1, 2, 2};
    while(se.size() < N) {
      se.insert(tmp);
      sum += tmp;
      tmp += diff[i];
      (++i) %= 4;
    }
    // cout << se << endl;
    switch(sum % 6) {
    case 2:
      se.erase(8);
      se.insert((tmp+5)/6*6);
      break;
    case 5:
      se.erase(9);
      se.insert((tmp+1)/6*6+4);
      break;
    case 3:
      se.erase(9);
      se.insert((tmp+5)/6*6);
      break;
    case 0:
      break;
    }
    for(int s: se) cout << s << ' ';
    cout << endl;
  }
  return 0;
}
