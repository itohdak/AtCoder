#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  string S;
  cin >> S;
  int n = S.size();
  int ret = n;
  for(int i=0; i<n-1; i++){
    if(S[i] != S[i+1]){
      ret = min(ret, max(i+1, n-(i+1)));
    }
  }
  cout << ret << endl;
  return 0;
}
