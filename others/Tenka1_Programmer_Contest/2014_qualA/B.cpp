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
  S += "-------";
  int tame = 0;
  int waitTime = 6;
  vector<int> kaburin(waitTime);
  vector<int> damageQueue(4);
  int kaburinAvailable = 5;
  int combo = 0;
  int damage = 0;
  int nextDamage = 0;
  for(char c: S) {
    kaburinAvailable += kaburin[0];
    rep(i, waitTime-1) kaburin[i] = kaburin[i+1];
    kaburin[waitTime-1] = 0;

    damage += damageQueue[0];
    if(damageQueue[0]) combo++;
    rep(i, 3) damageQueue[i] = damageQueue[i+1];
    damageQueue[2] = 0;

    if(tame > 0) {
      tame--;
      if(tame == 0) {
        kaburin[waitTime-1] = 3;
        kaburinAvailable -= 3;
      }
    } else if(c == 'N') {
      if(kaburinAvailable >= 1) {
        kaburin[waitTime-1] = 1;
        kaburinAvailable -= 1;
        damageQueue[0] = 10 * (1 + combo/10 * 0.1);
      }
    } else if(c == 'C') {
      if(kaburinAvailable >= 3) {
        tame = 3;
        damageQueue[2] = 50 * (1 + combo/10 * 0.1);
      }
    } else {
    }
    cout << kaburinAvailable << ' ' << damage << ' ' << kaburin << endl;
  }
  cout << damage << endl;
  return 0;
}
