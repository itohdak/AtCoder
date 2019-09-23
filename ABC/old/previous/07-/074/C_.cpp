#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  double maxCons = -1;
  pair<int, int> maxPair;
  rep(b, F/(B*100)+1) {
    int G = F-b*B*100;
    rep(a, G/(A*100)+1) {
      int H = G-a*A*100;
      rep(d, H/D+1) {
        int I = H-d*D;
        rep(c, I/C+1) {
          int sug = c*C+d*D;
          int wat = a*A+b*B;
          if(sug <= wat*E && 100.0*sug/(wat*100+sug) > maxCons)
            maxCons = 100.0*sug/(wat*100+sug), maxPair = make_pair(wat*100+sug, sug);
        }
      }
    }
  }
  cout << maxPair.first << ' ' << maxPair.second << endl;
  return 0;
}

