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
  set<int> se;
  rep(i, N) se.insert(i+1);
  int to = 0;
  rep(i, N) {
    int a;
    cin >> a;
    if(!se.count(a)) to = a;
    se.erase(a);
  }
  if(se.size() == 1) cout << to << ' ' << *se.begin() << endl;
  else cout << "Correct" << endl;
  return 0;
}
