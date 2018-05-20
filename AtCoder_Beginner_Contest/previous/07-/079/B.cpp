#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

long long Lucas(long long a, long long b, int n){
  if(n == 0)
    return b;
  else if(n == 1)
    return a;
  else
    return Lucas(a+b, a, n-1);
}

int main(){
  int N;
  cin >> N;
  cout << Lucas(1, 2, N) << endl;
  return 0;
}

