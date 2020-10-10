#include "header.hpp"

#define MAX_N 55
ll C[MAX_N][MAX_N];
void make() {
  rep(i, MAX_N) {
    C[i][1] = i;
    C[i][i] = 1;
    C[0][i] = 1;
    C[i][0] = 1;
  }
  REP(i, 1, MAX_N) rep(j, i) {
    if(i-1 < 0 || j-1 < 0) continue;
    C[i][j] = C[i-1][j] + C[i-1][j-1];
  }
}
ll comb(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return C[n][r];
}

// make()
