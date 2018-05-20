#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  int ret = 0;
  for(int i=0; i<=A; i++){
    for(int j=0; j<=B; j++){
      int tmp = X - 500 * i - 100 * j;
      if(tmp >= 0 && tmp % 50 == 0 && tmp / 50 <= C)
	ret++;
    }
  }
  cout << ret << endl;	
  return 0;
}

