#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int Nmax = 300;

void wf(long long cost[Nmax][Nmax], long long output[Nmax][Nmax], int N){
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      output[i][j] = cost[i][j];

  for(int k=0; k<N; k++)
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
	output[i][j] = min(output[i][j], output[i][k] + output[k][j]);
}

bool is_needed(long long cost[Nmax][Nmax], int N, int i, int j){
  for(int k=0; k<N; k++){
    if(k != i && k != j &&
       cost[i][j] == cost[i][k] + cost[k][j])
      return false;
  }
  return true;
}

int main(){
  long long A[Nmax][Nmax];
  long long shortest_pathes[Nmax][Nmax];

  int N;
  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> A[i][j];
    }
  }

  wf(A, shortest_pathes, N);

  bool ret = true;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(A[i][j] != shortest_pathes[i][j]){
	ret = false;
	break;
      }
    }
    if(!ret) break;
  }

  if(ret){
    long long sum = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
	if(i < j && is_needed(A, N, i, j)){
	  sum += A[i][j];
	}
      }
    }
    cout << sum << endl;
  }
  else cout << -1 << endl;

  return 0;
}

