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
  cin >> N >> M;
  vector<int> A(M), B(M);
  vector<int> cnt(N);
  rep(i, M) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    cnt[A[i]]++; cnt[B[i]]++;
  }
  rep(i, N) if(cnt[i]%2) {
    cout << "NO" << "\n";
    return 0;
  }
  cout << "YES" << "\n";
  return 0;
}
