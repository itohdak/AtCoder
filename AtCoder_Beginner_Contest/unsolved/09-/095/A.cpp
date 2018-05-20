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
  int ret = 700;
  for(int i=0; i<3; i++){
    if(S[i] == 'o'){
      ret += 100;
    }
  }
  cout << ret << endl;
  return 0;
}

