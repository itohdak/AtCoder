#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long
#define MOD 1000000007

int ans(int n){
  int ret = 1;
  for(int i=0; i<n; i++){
    ret *= 2;
    ret %= MOD;
  }
  return ret;
}

int main(){
  int N;
  cin >> N;
  vector<int> A;
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    A.push_back(in);
  }
  sort(A.begin(), A.end());
  bool ok = true;
  for(int i=0; i<N; i++){
    if(N % 2 == 0){
      if(i == 0 || i == 1){
	if(A[i] != 1){
	  ok = false;
	  break;
	}
      } else {
	if(A[i] != 2 * (i / 2) + 1){
	  ok = false;
	  break;
	}
      }
    } else {
      if(i == 0){
	if(A[i] != 0){
	  ok = false;
	  break;
	}
      } else {
	if(A[i] != 2 * ((i + 1) / 2)){
	  ok = false;
	  break;
	}
      }
    }
  }
  if(ok)
    cout << ans(N/2) << endl;
  else
    cout << 0 << endl;
  return 0;
}

