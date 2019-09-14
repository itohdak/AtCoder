#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  long long X, Y;
  cin >> X >> Y;
  int ret = 0;
  long long num = X;
  while(num <= Y){
    num *= 2;
    ret++;
  }
  cout << ret << endl;
  return 0;
}

