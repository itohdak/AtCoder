#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int X;
  cin >> X;
  int ret = 1;
  for(int i=2; i<ceil(sqrt(X)); i++){
    int tmp = i;
    while(tmp * i <= X)
      tmp *= i;
    if(ret < tmp)
      ret = tmp;
  }
  cout << ret << endl;
  return 0;
}

