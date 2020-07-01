#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  ll K;
  cin >> N >> M >> K;
  vector<ll> A(N), B(M), sumA(N+1), sumB(M+1);
  rep(i, N) {
    cin >> A[i];
    sumA[i+1] = sumA[i] + A[i];
  }
  rep(i, M) {
    cin >> B[i];
    sumB[i+1] = sumB[i] + B[i];
  }
  int ans = 0;
  // cout << sumA << sumB << endl;
  rep(i, N+1) {
    if(sumA[i] > K) continue;
    int cur = upper_bound(all(sumB), K-sumA[i]) - begin(sumB);
    // cout << i << ' ' << cur << endl;
    ans = max(i+cur-1, ans);
  }
  cout << ans << "\n";
  return 0;
}
