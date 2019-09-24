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
  int N = S.size();
  vector<int> ans(N);
  rep(i, N-1) {
    if(S[i] == 'R' && S[i+1] == 'L') {
      int tmp = i-1;
      ans[i]++;
      ans[i+1]++;
      while(tmp >= 0 && S[tmp] == 'R') {
        if((i - tmp) % 2 == 0)
          ans[i]++;
        else
          ans[i+1]++;
        tmp--;
      }
      tmp = i+2;
      while(tmp < N && S[tmp] == 'L') {
        if((tmp - i) % 2 == 0)
          ans[i]++;
        else
          ans[i+1]++;
        tmp++;
      }
    }
  }
  rep(i, N)
    cout << ans[i] << ' ';
  cout << endl;
  return 0;
}

