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
  S += "------";
  ll combo = 0;
  int kaburinCnt = 5;
  queue<int> kaburin;
  rep(i, 6) kaburin.push(0);
  int wait = 0;
  ll ans = 0;
  queue<ll> damage;
  damage.push(0);
  ll dtmp = 0;
  int throwType = 0;
  auto calcDamage = [&](ll base) {
    return base + base*(combo/10*0.1);
  };
  for(char c: S) {
    if(!wait) {
      if(c == 'N' && kaburinCnt >= 1) {
        wait = 1;
        dtmp = calcDamage(10);
        throwType = 1;
      } else if(c == 'C' && kaburinCnt >= 3) {
        wait = 3;
        dtmp = calcDamage(50);
        throwType = 2;
      }
    }

    if(wait) {
      wait--;
      if(wait == 0) {
        if(throwType == 1) {
          kaburinCnt -= 1;
          kaburin.push(1);
          damage.push(dtmp);
          dtmp = 0;
        } else {
          kaburinCnt -= 3;
          kaburin.push(3);
          damage.push(dtmp);
          dtmp = 0;
        }
      } else {
        kaburin.push(0);
        damage.push(0);
      }
    } else {
      kaburin.push(0);
      damage.push(0);
    }

    if(damage.front()) {
      combo++;
      ans += damage.front();
    }
    damage.pop();
    if(kaburin.front()) {
      kaburinCnt += kaburin.front();
    }
    kaburin.pop();
  }
  cout << ans << endl;
  return 0;
}
