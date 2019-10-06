#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  map<int, int> mp;
  rep(i, N) {
    int a;
    cin >> a;
    if(!mp.count(a)) mp[a] = 1;
    else             mp[a]++;
  }
  if(mp.size() % 2 == 1)
    cout << mp.size() << endl;
  else
    cout << mp.size() - 1 << endl;
  return 0;
}

