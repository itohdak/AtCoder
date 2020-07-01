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

bool is_prime(const unsigned n){
  switch(n){
  case 0: // fall-through
  case 1: return false;
  case 2: // fall-through
  case 3: return true;
  } // n > 3 が保証された

  if(n % 2 == 0) return false;
  if(n % 3 == 0) return false;
  // 2と3の倍数でないので6の倍数ではないことが保証された

  if(n % 6 != 1 && n % 6 != 5) return false;
  // 6の倍数前後の数(素数かもしれない数)であることが保証された

  // 6の倍数前後の数を使って試し割りをする
  for(unsigned i=5; i*i<=n; i+=6){
    if(n % i     == 0) return false; // 6n-1
    if(n % (i+2) == 0) return false; // 6n+1
  }

  return true;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int sum = 0;
  rep(i, n) sum += i+1;
  cout << (is_prime(sum) ? "WANWAN" : "BOWWOW") << "\n";
  return 0;
}
