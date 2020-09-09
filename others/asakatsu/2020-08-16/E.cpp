#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
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
  int n; ll k; cin >> n >> k;
  vector<ll> A(n), F(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> F[i];
  sort(all(A));
  sort(all(F), greater<ll>());
  auto bsearch = [&]() {
                   auto test = [&](ll t) {
                                 vector<ll> B(n);
                                 rep(i, n) B[i] = t/F[i];
                                 ll need = 0;
                                 rep(i, n) need += max(0LL, A[i]-B[i]);
                                 return need <= k;
                               };
                   ll ok = longinf, ng = -1;
                   while(ok-ng>1) {
                     ll mid = (ok+ng)/2;
                     (test(mid) ? ok : ng) = mid;
                   }
                   return ok;
                 };
  cout << bsearch() << endk;
  return 0;
}