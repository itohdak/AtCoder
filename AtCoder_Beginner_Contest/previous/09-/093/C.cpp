#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  vector<int> N;
  for(int i=0; i<3; i++){
    int in;
    cin >> in;
    N.push_back(in);
  }
  sort(N.begin(), N.end());
  int A = N[0];
  int B = N[1];
  int C = N[2];
  if((B-A) % 2 == 0)
    cout << C - B + (B-A)/2 << endl;
  else
    cout << C - B + (B-A)/2 + 2 << endl;
  return 0;
}

