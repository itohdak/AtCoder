#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<int> W(N), S(N+1);
  rep(i, N) {
    cin >> W[i];
    S[i+1] = S[i] + W[i];
  }
  int ans = inf;
  rep(i, N+1)
    ans = min(abs(S[N]-S[i]-S[i]), ans);
  cout << ans << endl;
  return 0;
}

