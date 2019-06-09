#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  bool D[100];
  for(int i=0; i<100; i++)
    D[i] = false;
  for(int i=0; i<N; i++){
    int d;
    cin >> d;
    D[d-1] = true;
  }
  int ret = 0;
  for(int i=0; i<100; i++){
    if(D[i])
      ret++;
  }
  cout << ret << endl;
  return 0;
}

