#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int max_n = 100000;
  int A[max_n];
  for(int i=0; i<max_n; i++)
    A[i] = 0;

  int N;
  cin >> N;
  for(int i=0; i<N; i++){
    int index;
    cin >> index;
    A[index]++;
  }

  int max = 0;
  for(int i=0; i<max_n-2; i++){
    int sum_3 = A[i] + A[i+1] + A[i+2];
    if(sum_3 > max)
      max = sum_3;
  }

  cout << max << endl;

  return 0;
}

