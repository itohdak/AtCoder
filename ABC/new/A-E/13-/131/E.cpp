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
  cin >> N >> K;
  if(K > (N-1) * (N-2) / 2)
    cout << -1 << endl;
  else {
    int tmp = (N-1) * (N-2) / 2 - K;
    cout << N-1+tmp << endl;
    REP(i, 1, N)
      cout << 1 << ' ' << i+1 << endl;
    REP(i, 1, N) {
      REP(j, i+1, N) {
	if(tmp == 0) return 0;
	cout << i+1 << ' ' << j+1 << endl;
	tmp--;
      }
    }
  }
  return 0;
}

