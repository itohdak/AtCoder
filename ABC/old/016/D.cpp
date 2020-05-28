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
  pair<int, int> Pa, Pb;
  cin >> Pa.first >> Pa.second >> Pb.first >> Pb.second;
  int N;
  cin >> N;
  vector<pair<int, int>> P(N);
  int cnt = 0;
  auto isCrossing = [&](pair<int, int> p1, pair<int, int> p2,
                        pair<int, int> p3, pair<int, int> p4) {
    int dx1 = p2.first - p1.first;
    int dy1 = p2.second - p1.second;
    int dx2 = p4.first - p3.first;
    int dy2 = p4.second - p3.second;
    int D = dx1 * dy2 - dy1 * dx2;
    if(D == 0) return false;
    double k = (double)((p3.first-p1.first)*dy2 - (p3.second-p1.second)*dx2) / D;
    double cx = p1.first + k * dx1;
    if((p1.first-cx)*(p2.first-cx)<=0 &&
       (p3.first-cx)*(p4.first-cx)<=0) return true;
    else return false;
  };
  rep(i, N) cin >> P[i].first >> P[i].second;
  rep(i, N) {
    if(isCrossing(Pa, Pb, P[i], P[(i+1)%N])) {
      // cout << "(" << P[i-1].first << ", " << P[i-1].second << "), "
      //      << "(" << P[i].first << ", " << P[i].second << ")" << endl;
      cnt++;
    }
  }
  cout << cnt/2 + 1 << endl;
  return 0;
}
