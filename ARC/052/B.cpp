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
const double pi = 3.14159265358979;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  vector<int> X(N), R(N), H(N);
  vector<double> sum(20005);
  rep(i, N) {
    cin >> X[i] >> R[i] >> H[i];
    double vAll = R[i] * R[i] * pi * H[i] / 3;
    for(int x=X[i]+1; x<=X[i]+H[i]; x++) {
      double r1 = (double)(X[i]+H[i]-x+1) / H[i];
      double r2 = (double)(X[i]+H[i]-x) / H[i];
      sum[x] += vAll * (pow(r1, 3) - pow(r2, 3));
    }
  }
  rep(i, 20005) if(i) sum[i] += sum[i-1];
  cout << fixed << setprecision(10);
  rep(q, Q) {
    int A, B;
    cin >> A >> B;
    cout << sum[B] - sum[A] << endl;
  }
  return 0;
}
