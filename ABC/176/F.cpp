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
  vector<int> A(3*n);
  rep(i, 3*n) {
    cin >> A[i];
    A[i]--;
  }
  map<int, int> cnt;
  int ans = 0;
  auto dfs = [&](auto dfs, int i) {
               if(i == 3*n) return;
               cnt[A[i]]++;
               if(cnt[A[i]] == 3) {
                 if(i % 3 == 0) {
                 } else if(i % 3 == 2) {
                 }
               }
               dfs(dfs, i+1);
               cnt[A[i]]--;
             };
  rep(i, 3*n) {
    cnt[A[i]]++;
    if(cnt[A[i]] == 3) {
    }
  }
  return 0;
}
