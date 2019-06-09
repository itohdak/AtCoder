#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  int A[N][20];
  for(int i=0; i<N; i++){
    ll in;
    cin >> in;
    for(int j=0; j<20; j++){
      A[i][j] = in % 2;
      in /= 2;
    }
  }

  int ones[N+1][20];
  for(int j=0; j<20; j++)
    ones[0][j] = 0;
  for(int i=1; i<N+1; i++){
    for(int j=0; j<20; j++){
      ones[i][j] = ones[i-1][j];
      if(A[i-1][j] == 1)
	ones[i][j]++;
    }
  }

  ll ret = 0;
  int prev_r = 0;
  for(int l=0; l<N+1; l++){
    for(int r=prev_r; r<N+1; r++){
      bool ok = true;
      for(int i=0; i<20; i++){
	if(ones[r][i] - ones[l][i] >= 2){
	  ok = false;
	  break;
	}
      }
      if(!ok){
	ret += r - l - 1;
	prev_r = r - 1;
	break;
      } else if(r == N){
	ret += r - l;
	prev_r = r;
	break;
      }
    }
  }

  cout << ret << endl;
  return 0;
}
