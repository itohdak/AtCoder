#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  long long A[N];
  bool count[N];
  for(int i=0; i<N; i++){
    cin >> A[i];
    count[i] = true;
  }
  for(int i=N-1; i>=0; i--){
    long long sum = 0;
    int j = i+1;
    while(j <= N){
      if(count[j-1])
	sum += A[j-1];
      j += (i+1);
    }
    if(sum < 0){
      int j = i+1;
      while(j <= N){
	count[j-1] = false;
	j += (i+1);
      }
    }
  }
  long long ret = 0;
  for(int i=0; i<N; i++){
    if(count[i])
      ret += A[i];
  }
  cout << ret << endl;
  return 0;
}

