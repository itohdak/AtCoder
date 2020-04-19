#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N], B[N];

  for(int i=0; i<N; i++){
    cin >> A[i];
    if(A[i] % 2 == 0) // even
      B[i] = true;
    else // odd
      B[i] = false;
  }

  int odd = 1;
  for(int i=0; i<N; i++){
    if(B[i] == true)
      odd *= 2;
    else
      odd *= 1;
  }

  cout << pow(3, N) - odd << endl;

  return 0;
}

