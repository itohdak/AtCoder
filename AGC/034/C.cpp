#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct data {
  int b;
  int l;
  int u;
  int idx;
  data(int b_, int l_, int u_, int i_) : b(b_), l(l_), u(u_), idx(i_) {}
};

bool comp1(data d1, data d2) {
  if(d1.u == d2.u)
    return d1.b < d2.b;
  else
    return d1.u > d2.u;
}
bool comp2(data d1, data d2) {
  if(d1.l == d2.l)
    return d1.b > d2.b;
  else
    return d1.l < d2.l;
}

vector<data> D1, D2;
set<int> S;
int N, X;

void dfs(int i, int j, ll tmp, ll tmpAns, ll& ans) {
  if(S.size() == N-1) {
    if(tmp < ans) ans = tmp;
  } else {
    while(S.find(D1[i].idx) != S.end()) i++;
    while(S.find(D2[j].idx) != S.end()) j++;
    if(tmp == 0) {
      S.insert(D1[i].idx);
      dfs(i+1, j, tmp + (X - D1[i].b) * D1[i].u, tmpAns+100, ans);
      S.erase(D1[i].idx);
      S.insert(D2[j].idx);
      dfs(i, j+1, tmp - D2[j].b * D2[j].l, tmpAns, ans);
      S.erase(D2[j].idx);
    } else if(tmp < 0) {
      S.insert(D1[i].idx);
      dfs(i+1, j, tmp + (X - D1[i].b) * D1[i].u, tmpAns+100, ans);
    } else {
      S.insert(D2[j].idx);
      dfs(i, j+1, tmp - D2[j].b * D2[j].l, tmpAns, ans);
    }
  }
}

int main() {
  cin >> N >> X;
  rep(i, N) {
    int b, l, u;
    cin >> b >> l >> u;
    D1.push_back(data(b, l, u, i));
    D2.push_back(data(b, l, u, i));
  }
  sort(D1.begin(), D1.end(), comp1);
  sort(D2.begin(), D2.end(), comp2);

  ll ans = longinf;
  dfs(0, 0, 0LL, 0LL, ans);
  cout << ans << endl;

  return 0;
}

