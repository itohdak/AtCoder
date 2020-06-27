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
  int N;
  cin >> N;
  vector<ll> A(N), sum(N+1);
  rep(i, N) cin >> A[i];
  sort(all(A));
  rep(i, N) sum[i+1] = sum[i] + A[i];
  auto bsearch = [&]() {
    auto test = [&](int k) {
      ll i = 0;
      ll curSum = A[k];
      while(true) {
        int j = upper_bound(all(A), 2*curSum) - begin(A);
        if(i == j) return (i == N ? true : false);
        curSum = sum[j];
        i = j;
      }
    };
    int ok = N-1, ng = -1;
    while(ok-ng>1) {
      int mid = (ok+ng)/2;
      (test(mid)?ok:ng) = mid;
    }
    return N-ok;
  };
  cout << bsearch() << "\n";
  return 0;
}
