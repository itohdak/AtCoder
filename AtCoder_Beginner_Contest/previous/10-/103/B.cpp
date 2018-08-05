#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string S, T;
  cin >> S >> T;
  bool ret = false;
  int n = S.size();
  for(int i=0; i<n; i++){
    if(S == T){
      ret = true;
      break;
    } else {
      S = S[n-1] + S.substr(0,n-1);
    }
  }
  if(ret)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

