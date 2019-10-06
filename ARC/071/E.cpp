#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  string S, T;
  cin >> S >> T;
  int q;
  cin >> q;
  int Ns = S.size(), Nt = T.size();
  vector<int> Vs(Ns+1), Vt(Nt+1);
  rep(i, Ns)
    Vs[i+1] = Vs[i] + (S[i] == 'A' ? 1 : 2);
  rep(i, Nt)
    Vt[i+1] = Vt[i] + (T[i] == 'A' ? 1 : 2);
  rep(i, q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int vs = (Vs[b] - Vs[a-1]) % 3, vt = (Vt[d] - Vt[c-1]) % 3;
    if(vs == vt)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

