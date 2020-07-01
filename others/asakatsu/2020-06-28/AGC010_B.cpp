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
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  ll sum = accumulate(all(A), 0LL);
  if(sum % (N*(N+1)/2)) {
    cout << "NO" << "\n";
    return 0;
  }
  int M = sum / (N*(N+1)/2);
  vector<ll> D(N);
  bool ok = true;
  int cnt = 0;
  rep(i, N) {
    D[i] = A[(i+1)%N]-A[i]-M;
    if(D[i] > 0 || -D[i] % N) {
      cout << "NO" << "\n";
      return 0;
    }
    cnt += -D[i] / N;
  }
  cout << (cnt == M ? "YES" : "NO") << "\n";
  return 0;
}
