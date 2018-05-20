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
  int B[K][K];
  for(int i=0; i<K; i++){
    for(int j=0; j<K; j++){
      B[i][j] = 0;
    }
  }

  ll x, y;
  ll xb, yb, xn, yn;
  char c;
  for(int i=0; i<N; i++){
    cin >> x >> y >> c;
    xb = x % K;
    yb = y % K;
    xn = x / K;
    yn = y / K;
    if(c == 'W' && (xn + yn) % 2 == 0 ||
       c == 'B' && (xn + yn) % 2 == 1){
      for(int j=0; j<xb; j++){
	for(int k=0; k<yb; k++){
	  B[j][k]++;
	}
      }
      for(int j=xb; j<K; j++){
	for(int k=yb; k<K; k++){
	  B[j][k]++;
	}
      }
    }
    else if(c == 'W' && (xn + yn) % 2 == 1 ||
	    c == 'B' && (xn + yn) % 2 == 0){
      for(int j=xb; j<K; j++){
	for(int k=0; k<yb; k++){
	  B[j][k]++;
	}
      }
      for(int j=0; j<xb; j++){
	for(int k=yb; k<K; k++){
	  B[j][k]++;
	}
      }
    }
  }

  int nmax = 0;
  int nmin = K+1;
  for(int i=0; i<K; i++){
    for(int j=0; j<K; j++){
      if(B[i][j] > nmax){
	nmax = B[i][j];
      }
      if(B[i][j] < nmin){
	nmin = B[i][j];
      }
    }
  }
  cout << max(nmax, N-nmin) << endl;

  return 0;
}

