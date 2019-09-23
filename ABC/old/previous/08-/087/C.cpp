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
  int A[2][N];
  for(int i=0; i<N; i++)
    cin >> A[0][i];
  for(int i=0; i<N; i++)
    cin >> A[1][i];
  int sum[2][N];
  sum[0][0] = A[0][0];
  sum[1][N-1] = A[1][N-1];
  for(int i=1; i<N; i++)
    sum[0][i] = sum[0][i-1] + A[0][i];
  for(int i=N-2; i>=0; i--)
    sum[1][i] = sum[1][i+1] + A[1][i];
  int ret = 0;
  for(int i=0; i<N; i++){
    int tmp = sum[0][i] + sum[1][i];
    if(tmp > ret)
      ret = tmp;
  }
  cout << ret << endl;
  return 0;
}

