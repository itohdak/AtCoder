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
  vector<ll> A(N);
  rep(i, N)
    cin >> A[i];
  vector<vector<bool> > flag(2, vector<bool>(N, false));
  bool ret = true;
  rep(i, 35) {
    int cnt=0, cnt1=0, cnt0=0, cnt10=0, cnt01=0, cnt00=0, cnt11=0;
    rep(j, N) {
      if(A[j] % 2 == 0) {
        flag[i%2][j] = false;
      } else {
        cnt++;
        flag[i%2][j] = true;
      }
      if(flag[i%2][j]) {
        cnt1++;
        if(flag[(i+1)%2][j]) cnt11++;
        else                 cnt01++;
      } else {
        cnt0++;
        if(flag[(i+1)%2][j]) cnt10++;
        else                 cnt00++;
      }
      cnt++;
      A[j] /= 2;
    }
    if(cnt == cnt0) continue;
    if(cnt1 > 0) {
      if(N % 3 != 0) {
        ret = false;
        break;
      } else if(cnt0 != N / 3) {
        ret = false;
        break;
      }
    }
    if(cnt != cnt0 && cnt01 + cnt10 > 0) {
      if(cnt00 > 0) {
        ret = false;
        break;
      }
      if(cnt01 != cnt10) {
        ret = false;
        break;
      }
    }
  }
  if(ret)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

// 0 0 0 0 0 0 0 0 0

// 0 1 1 0 1 1 0 1 1
// 1 1 0 1 1 0 1 1 0
// 1 0 1 1 0 1 1 0 1

// 0 1 1 1 0 1 0 1 1

