#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int P[10];

int main(){
  int N;
  cin >> N;
  int sum = 0;
  int max = 0;
  for(int i=0; i<N; i++) {
    cin >> P[i];
    sum += P[i];
    if(P[i] > max)
      max = P[i];
  }
  cout << sum - max / 2 << endl;
  return 0;
}

