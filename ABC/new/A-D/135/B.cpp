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
  vector<int> P(N);
  rep(i, N) cin >> P[i];
  int cnt = 0;
  rep(i, N)
    if(P[i] != i+1)
      cnt++;
  if(cnt == 2 || cnt == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

