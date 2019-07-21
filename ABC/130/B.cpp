#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> L(N);
  int tmp = 0;
  int cnt = 1;
  rep(i, N) {
    cin >> L[i];
    tmp += L[i];
    if(tmp <= X) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

