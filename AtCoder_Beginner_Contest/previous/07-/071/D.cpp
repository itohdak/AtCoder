#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long
#define mod 1000000007

int main(){
  int N;
  string S1, S2;
  cin >> N >> S1 >> S2;
  ll ans = 1;
  int state = 0;
  for(int i=0; i<N; i++){
    if(S1[i] == S2[i]){
      switch(state){
      case 0:
	ans *= 3;
	break;
      case 1:
	ans *= 2;
	break;
      case 2:
	ans *= 1;
	break;
      default:
	cout << "something wrong" << endl;
	exit(0);
      }
      state = 1;
    } else {
      switch(state){
      case 0:
	ans *= 3 * 2;
	break;
      case 1:
	ans *= 2 * 1;
	break;
      case 2:
	ans *= 3;
	break;
      default:
	cout << "something wrong" << endl;
	exit(0);
      }
      state = 2;
      i++;
    }
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}

