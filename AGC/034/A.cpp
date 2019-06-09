#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  A--; B--; C--; D--;
  string S;
  cin >> S;
  int tmp, tmp2;
  bool ok = false;
  if(C < D) {
    tmp = 0;
    REP(i, B, D) {
      if(S[i] == '#') tmp++;
      else tmp = 0;
      if(tmp > 1) { cout << "No" << endl; return 0; }
    }
    tmp = 0;
    REP(i, A, C) {
      if(S[i] == '#') tmp++;
      else tmp = 0;
      if(tmp > 1) { cout << "No" << endl; return 0; }
    }
    cout << "Yes" << endl;
  } else {
    tmp = 0;
    tmp2 = S[B-1] == '.' ? 1 : 0;
    REP(i, B, D+1) {
      if(S[i] == '#') {
	tmp++;
	tmp2 = 0;
      }
      else { tmp = 0; tmp2++; }
      if(tmp > 1) { cout << "No" << endl; return 0; }
      if(tmp2 > 2) ok = true;
    }
    if((S[D-1] == '#' || S[D+1] == '#') && !ok) { cout << "No" << endl; return 0; }
    tmp = 0;
    REP(i, A, C) {
      if(S[i] == '#') tmp++;
      else tmp = 0;
      if(tmp > 1) { cout << "No" << endl; return 0; }
    }
    cout << "Yes" << endl;
  }
  return 0;
}

