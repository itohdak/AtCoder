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
  int Q[N];
  for(int i=0; i<N; i++){
    int p;
    cin >> p;
    Q[p-1] = i;
  }
  int max = 1;
  int tmp = Q[0];
  int n = 1;
  for(int i=1; i<N; i++){
    if(tmp < Q[i]){
      n++;
      tmp = Q[i];
    } else {
      if(max < n)
	max = n;
      tmp = Q[i];
      n = 1;
    }

    if(i == N-1)
      if(max < n)
	max = n;
  }

  cout << N - max << endl;
  return 0;
}
