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

bool arr[1000000000];
vector<ll> primes;
void Eratosthenes(int N) {
  for(int i=0; i<N; i++) {
    arr[i] = true;
  }
  for(int i=2; i<sqrt(N); i++) {
    if(arr[i]) {
      for(int j=0; i*(j+2)<N; j++) {
        arr[i*(j+2)] = false;
      }
    }
  }

  for(int i=2; i<N; i++) {
    if(arr[i]) {
      primes.push_back(i);
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  Eratosthenes(n);
  cout << primes.size() << "\n";
  return 0;
}
