#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
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
  int N;
  cin >> N;
  bool ok = false;
  REP(k, 1, sqrt(2*N)+1) {
    if(k*(k+1)/2==N) {
      ok = true;
      cout << "Yes" << endl;
      cout << k+1 << endl;
      vector<vector<int> > ans(k+1);
      int i = 1;
      int tmp = 0;
      while(i <= N) {
	int tmp2 = 1;
	while(ans[tmp].size() < k) {
	  ans[tmp].push_back(i);
	  ans[tmp+tmp2].push_back(i);
	  tmp2++;
	  i++;
	}
	tmp++;
      }
      rep(i, k+1) {
	cout << k << ' ';
	for(int a: ans[i]) cout << a << ' ';
	cout << endl;
      }
      break;
    }
  }
  if(!ok) cout << "No" << endl;
  return 0;
}
