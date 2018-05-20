#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string S;
  cin >> S;
  int len = S.size();
  for(int i=len/2*2-2; i>0; i-=2){
    bool ret = true;
    for(int j=0; j<i/2; j++){
      if(S[j] != S[i/2+j]){
	ret = false;
	break;
      }
    }
    if(ret){
      cout << i <<endl;
      return 0;
    }
  }
  return 0;
}

