#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  int ans = 0;
  int unhappy = 0;
  rep(i, N) {
    if(S[i] == 'L') {
      if(i != 0 && S[i-1] == 'L') ans++;
      else unhappy++;
    } else {
      if(i != N-1 && S[i+1] == 'R') ans++;
      else unhappy++;
    }
  }
  cout << min(ans+2*K, N-1) << endl;
  return 0;
}

