#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B, N;
  cin >> A >> B >> N;
  string X;
  cin >> X;
  for(int i=0; i<N; i++){
    if(X[i] == 'S'){
      if(A > 0)
	A--;
    } else if(X[i] == 'C'){
      if(B > 0)
	B--;
    } else if(X[i] == 'E'){
      if(A > 0 || B > 0){
	if(A >= B)
	  A--;
	else
	  B--;
      }
    }
  }
  cout << A << endl << B << endl;
  return 0;
}

