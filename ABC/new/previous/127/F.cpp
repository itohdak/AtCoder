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
  int Q;
  cin >> Q;
  ll bs = 0;
  priority_queue<ll> q1;
  priority_queue<ll, vector<ll>, greater<ll>> q2;
  q1.push(-longinf); q2.push(longinf);
  ll sum1 = 0, sum2 = 0;
  int N = 0;
  rep(q, Q) {
    int t;
    cin >> t;
    if(t == 1) {
      ll a, b;
      cin >> a >> b;
      if(N%2==0) {
        if(a < q2.top()) {
          q1.push(a);
          sum1 += a;
        } else {
          q2.push(a);
          sum2 += a;
          a = q2.top(); q2.pop();
          sum2 -= a;
          q1.push(a);
          sum1 += a;
        }
      } else {
        if(a < q1.top()) {
          q1.push(a);
          sum1 += a;
          a = q1.top(); q1.pop();
          sum1 -= a;
          q2.push(a);
          sum2 += a;
        } else {
          q2.push(a);
          sum2 += a;
        }
      }
      bs += b;
      N++;
    } else {
      cout << q1.top() << ' '
           << q1.top()*((int)q1.size()-(int)q2.size())-sum1+sum2+bs << "\n";
    }
  }
  return 0;
}
