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
  int ret = 0;
  int need2 = 0;
  int need5 = 0;
  for(int i=0; i<S.size(); i++){
    char tmp = S[i];
    if(S[i] == '2'){
      if(need2 > 0){
	need2--; need5++;
      } else {
	ret++; need5++;
      }
    } else {
      if(need5 > 0){
	need5--; need2++;
      } else {
	cout << -1 << endl;
	return 0;
      }
    }
  }
  if(need5 > 0){
    cout << -1 << endl;
  } else {
    cout << ret << endl;
  }
  return 0;
}

