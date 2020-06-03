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
  string S;
  cin >> S;
  int N = S.size();
  vector<ll> combo(N+10), kaburin(N+10), damage(N+10);
  kaburin[0] = 5;
  int wait = 0;
  auto calcDamage = [&](ll base, ll combo) {
    return base + base*(combo/10*0.1);
  };
  rep(i, N+10) {
    if(i) {
      damage[i] += damage[i-1];
      kaburin[i] += kaburin[i-1];
      combo[i] += combo[i-1];
    }
    if(i >= N) continue;
    if(wait) {
      wait--;
      continue;
    }
    if(S[i] == 'N' && kaburin[i] >= 1) {
      kaburin[i+1] -= 1;
      damage[i+2] += calcDamage(10, combo[i]);
      combo[i+2] += 1;
      kaburin[i+7] += 1;
    } else if(S[i] == 'C' && kaburin[i] >= 3) {
      wait = 2;
      kaburin[i+3] -= 3;
      damage[i+4] += calcDamage(50, combo[i]);
      combo[i+4] += 1;
      kaburin[i+9] += 3;
    }
  }
  cout << damage.back() << endl;
  return 0;
}
