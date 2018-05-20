#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int sub(int n, int m, int prev){// n : box, m : ball
  if(n == 1){
    return 1;
  } else {
    int ret = 0;
    for(int i=ceil(m*1.0/n); i<=min(prev, m); i++){
      ret += sub(n-1, m-i, i);
    }
    return ret;
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  cout << sub(n, m, m) << endl;
}
