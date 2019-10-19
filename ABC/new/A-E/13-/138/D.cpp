#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct data {
  int par;
  ll val;
  data(int par_=0, ll val_=0LL) : par(par_), val(val_) {}
};

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<data> D(N);
  vector<vector<int> > Edge(N, vector<int>());
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    Edge[a].push_back(b);
    Edge[b].push_back(a);
  }
  {
    vector<bool> flag(N);
    queue<int> next;
    next.push(0);
    flag[0] = true;
    while(!next.empty()) {
      int tmp = next.front();
      next.pop();
      for(vector<int>::iterator itr=Edge[tmp].begin();
          itr != Edge[tmp].end();
          itr++) {
        if(!flag[*itr]) {
          D[*itr].par = tmp;
          flag[*itr] = true;
          next.push(*itr);
        }
      }
    }
  }
  rep(i, Q) {
    int p;
    ll x;
    cin >> p >> x;
    p--;
    D[p].val += x;
  }

  vector<ll> A(N);
  {
    vector<bool> flag(N);
    queue<int> next;
    next.push(0);
    flag[0] = true;
    A[0] = D[0].val;
    while(!next.empty()) {
      int tmp = next.front();
      next.pop();
      for(vector<int>::iterator itr=Edge[tmp].begin();
          itr != Edge[tmp].end();
          itr++) {
        if(!flag[*itr]) {
          D[*itr].val += D[tmp].val;
          A[*itr] = D[*itr].val;
          flag[*itr] = true;
          next.push(*itr);
        }
      }
    }
  }
  rep(i, N) {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}

