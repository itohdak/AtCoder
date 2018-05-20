#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, K;
  cin >> N >> K;
  int k2 = 2 * K;
  int B[k2][k2];
  for(int i=0; i<k2; i++){
    for(int j=0; j<k2; j++){
      B[i][j] = 0;
    }
  }

  ll x, y;
  int xb, yb, xn, yn;
  char c;
  for(int i=0; i<N; i++){
    cin >> x >> y >> c;
    xb = x % k2;
    yb = y % k2;
    xn = x / k2;
    yn = y / k2;
    if(c == 'W'){
    }
    else if(c == 'B'){
      yb = (yb+K) % k2;
    }
    int jbegin, jend, kbegin, kend;
    if(xb+K >= k2){
      jbegin = (xb+K+1) % k2;
      jend = xb+1;
    } else {
      jbegin = xb;
      jend = xb+K;
    }
    if(yb+K >= k2){
      kbegin = (yb+K+1) % k2;
      kend = yb+1;
    } else {
      kbegin = yb;
      kend = yb+K;
    }
    for(int j=jbegin; j<jend; j++)
      for(int k=kbegin; k<kend; k++)
	B[j][k]++;
  }

  int nmax = 0;
  for(int i=0; i<k2; i++){
    for(int j=0; j<k2; j++){
      if(B[i][j] > nmax){
	nmax = B[i][j];
      }
    }
  }
  cout << nmax << endl;

  return 0;
}

