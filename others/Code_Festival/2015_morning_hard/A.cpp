#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  deque<ll> q;
  rep(i, N) {
    ll a;
    cin >> a;
    q.push_back(a);
  }
  ll ans = 0;
  rep(i, N/2) {
    ll front1 = q.front(); q.pop_front();
    ll front2 = q.front(); q.pop_front();
    ll back1 = q.back();   q.pop_back();
    ll back2 = q.back();   q.pop_back();
    ll cntFront = front1 * 2 + front2 + 1;
    ll cntBack = back1 * 2 + back2 + 1;
    if(cntFront < cntBack) {
      ans += cntFront;
      ll front3 = q.front();
      q.pop_front();
      q.push_front(front1+front2+front3+2);
      q.push_back(back2);
      q.push_back(back1);
    } else {
      ans += cntBack;
      ll back3 = q.back();
      q.pop_back();
      q.push_back(back1+back2+back3+2);
      q.push_front(front2);
      q.push_front(front1);
    }
  }
  cout << ans << endl;
  return 0;
}
