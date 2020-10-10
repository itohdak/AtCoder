#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  int allGcd = A[0];
  rep(i, n) allGcd = __gcd(allGcd, A[i]);
  if(allGcd != 1) {
    cout << "not coprime" << endk;
    return 0;
  }
  int M = 1000005;
  vector<int> cnt(M);
  rep(i, n) cnt[A[i]]++;
  vector<bool> done(M);
  for(int i=2; i<M; i++) {
    if(!done[i]) {
      int tmp = 0;
      for(int j=0; i*(j+1)<M; j++) {
        tmp += cnt[i*(j+1)];
        done[i*(j+1)] = true;
      }
      if(tmp > 1) {
        cout << "setwise coprime" << endk;
        return 0;
      }
    }
  }
  cout << "pairwise coprime" << endk;
  return 0;
}
