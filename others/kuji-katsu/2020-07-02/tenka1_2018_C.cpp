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
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  sort(all(A));

  ll ans = 0;
  if(N%2) {
    {
      int l=0, r=N-1;
      vector<int> v;
      v.push_back(A[N/2]);
      rep(i, N/2) {
        v.push_back(A[l++]);
        v.push_back(A[r--]);
      }
      ll cur = 0;
      rep(i, N-1) cur += abs(v[i+1]-v[i]);
      ans = max(cur, ans);
    }
    {
      int l=0, r=N-1;
      vector<int> v;
      v.push_back(A[N/2]);
      rep(i, N/2) {
        v.push_back(A[r--]);
        v.push_back(A[l++]);
      }
      ll cur = 0;
      rep(i, N-1) cur += abs(v[i+1]-v[i]);
      ans = max(cur, ans);
    }
  } else {
    {
      int l=0, r=N-1;
      vector<int> v;
      v.push_back(A[N/2]);
      rep(i, N/2-1) {
        v.push_back(A[l++]);
        v.push_back(A[r--]);
      }
      v.push_back(A[N/2-1]);
      ll cur = 0;
      rep(i, N-1) cur += abs(v[i+1]-v[i]);
      ans = max(cur, ans);
    }
    {
      int l=0, r=N-1;
      vector<int> v;
      v.push_back(A[N/2-1]);
      rep(i, N/2-1) {
        v.push_back(A[r--]);
        v.push_back(A[l++]);
      }
      v.push_back(A[N/2]);
      ll cur = 0;
      rep(i, N-1) cur += abs(v[i+1]-v[i]);
      ans = max(cur, ans);
    }
  }

  cout << ans << "\n";
  return 0;
}
