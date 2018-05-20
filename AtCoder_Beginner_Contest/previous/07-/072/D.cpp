#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int max_n = 100000;
  int P[max_n];

  int N;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> P[i];
  }
  int swap = 0;
  for(int i=0; i<N; i++){
    if(P[i] == i+1){
      int tmp = P[i];
      P[i] = P[i+1];
      P[i+1] = tmp;
      swap++;
    }
  }

  cout << swap << endl;

  return 0;
}

