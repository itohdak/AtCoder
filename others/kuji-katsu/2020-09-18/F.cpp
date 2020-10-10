#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int q; cin >> q;
  ll sum = 0, sum1 = 0, sum2 = 0;
  priority_queue<ll> q1;
  priority_queue<ll, vector<ll>, greater<ll>> q2;
  int n = 0;
  rep(i, q) {
    int t; cin >> t;
    if(t == 1) {
      ll a, b;
      cin >> a >> b;
      sum += b;
      if(n == 0) {
        q1.push(a);
        sum1 += a;
      } else if(n%2==0) {
        if(a > q1.top()) {
          q2.push(a);
          sum2 += a;
          q1.push(q2.top());
          sum1 += q2.top();
          sum2 -= q2.top();
          q2.pop();
        } else {
          q1.push(a);
          sum1 += a;
        }
      } else {
        if(a > q1.top()) {
          q2.push(a);
          sum2 += a;
        } else {
          q1.push(a);
          sum1 += a;
          q2.push(q1.top());
          sum2 += q1.top();
          sum1 -= q1.top();
          q1.pop();
        }
      }
      n++;
    } else {
      ll med = q1.top();
      cout << med << ' ' << (med*(int)q1.size()-sum1)+(sum2-med*(int)q2.size())+sum << endk;
    }
  }
  return 0;
}
