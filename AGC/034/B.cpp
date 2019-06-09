#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  string S;
  cin >> S;
  int N = (int)S.size();
  ll ans = 0;
  int tmp = 0;
  for(int i=N-1; i>=0; i--) {
    if(i == 0) {
      if(S[i] == 'A')
	ans += tmp;
    } else {
      if(S[i-1] == 'B' && S[i] == 'C') {
	tmp++;
	i--;
      } else if(S[i] == 'A') {
	ans += tmp;
      } else {
	tmp = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

