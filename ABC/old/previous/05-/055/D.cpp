#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

char rev(char c) {
  return c == 'S' ? 'W' : 'S';
}

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  string cand[4] = {"SS", "SW", "WS", "WW"};
  for(string s: cand) {
    string ans(N, '-');
    ans[N-1] = s[0], ans[0] = s[1];
    rep(i, N) {
      int pr = i == 0 ? N-1 : i-1;
      int ne = i == N-1 ? 0 : i+1;
      char Sne;
      if(ans[i] == 'S') Sne = S[i] == 'o' ? ans[pr] : rev(ans[pr]);
      else              Sne = S[i] == 'o' ? rev(ans[pr]) : ans[pr];
      if(i == N-2) {
        if(ans[ne] != Sne)
          break;
      } else if(i == N-1) {
        if(ans[ne] == Sne) {
          cout << ans << endl;
          return 0;
        }
      } else {
        ans[ne] = Sne;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}

