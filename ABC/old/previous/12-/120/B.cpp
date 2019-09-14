#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B, K;
  cin >> A >> B >> K;
  int count = 0;
  for(int i=min(A, B); i>0; i--) {
    if(A % i == 0 && B % i == 0)
      count++;
    if(count == K) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}

