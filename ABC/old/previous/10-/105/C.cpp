#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll N;
  cin >> N;
  ll M = abs(N);
  string ans;
  if(N == 0){
    ans = "0";
  } else {
    if(N > 0){
      if(M % 2 == 1)
	ans = "1";
      else
	ans = "0";
      M /= 2;
    }

    while(M > 0){
      if(M % 4 == 3){
	ans = "01" + ans;
	M -= -1;
      } else if(M % 4 == 2){
	ans = "10" + ans;
	M -= 2;
      } else if(M % 4 == 1){
	ans = "11" + ans;
	M -= 1;
      } else if(M % 4 == 0){
	ans = "00" + ans;
	M += 0;
      }
      M /= 4;
    }
  }
  cout << ans << endl;
  return 0;
}

