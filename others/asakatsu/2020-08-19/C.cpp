#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n);
  map<ll, int> cnt;
  rep(i, n) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  if(n%3) {
    if(cnt.size()==1 && cnt.count(0)) cout << "Yes" << endk;
    else cout << "No" << endl;
  } else {
    bool ok = true;
    for(auto ele: cnt) if(ele.second%(n/3)) ok = false;
    if(!ok) cout << "No" << endk;
    else {
      if(cnt.size()==1) {
        if(cnt.count(0)) cout << "Yes" << endk;
        else cout << "No" << endk;
      } else if(cnt.size()==2) {
        if(cnt.count(0) && cnt[0]==n/3) cout << "Yes" << endk;
        else cout << "No" << endk;
      } else if(cnt.size()==3) {
        vector<ll> B;
        for(auto ele: cnt) B.push_back(ele.first);
        if((B[0]^B[1]^B[2])==0 &&
           cnt[B[0]]==n/3 &&
           cnt[B[1]]==n/3 &&
           cnt[B[2]]==n/3) cout << "Yes" << endk;
        else cout << "No" << endk;
      } else {
        cout << "No" << endk;
      }
    }
  }
  return 0;
}
