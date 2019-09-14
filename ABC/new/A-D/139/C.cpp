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
  vector<ll> H(N);
  rep(i, N)
    cin >> H[i];
  int ans = 0;
  int tmp = 0;
  rep(i, N-1) {
    tmp = 0;
    while(i+tmp < N-1 && H[i+tmp] >= H[i+tmp+1])
      tmp++;
    if(tmp > ans)
      ans = tmp;
    i += tmp;
  }
  cout << ans << endl;
  return 0;
}

