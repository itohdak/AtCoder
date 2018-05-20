#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  string S1, S2;
  cin >> S1 >> S2;
  int dom[2][N];
  for(int i=0; i<S1.size(); i++){
    dom[0][i] = (int)S1[i];
    dom[1][i] = (int)S2[i];
  }

  long long n = 1;
  int before; // 1: 縦 2: 横
  bool row = false;
  bool col = false;
  for(int i=0; i<S1.size(); i++){
    if(dom[0][i] == dom[1][i]){
      row = true;
      if(i != 0){
	if(before == 1)
	  n *= 2;
	else if(before == 2)
	  n *= 1;
      }
      before = 1;
    } else if(dom[0][i] == dom[0][i+1]){
      col = true;
      if(i != 0){
	if(before == 1)
	  n *= 2;
	else if(before == 2)
	  n *= 3;
      }
      before = 2;
      i++;
    }
  }

  int ans = 6 * n;

  if(!(row && col)){
    ans -= 3;
  }

  cout << ans % 1000000007 << endl;
  return 0;
}
