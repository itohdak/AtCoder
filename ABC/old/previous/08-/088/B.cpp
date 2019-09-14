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
  vector<int> A;
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    A.push_back(in);
  }
  sort(A.begin(), A.end(), greater<int>());
  int alice = 0, bob = 0;
  for(int i=0; i<N; i++){
    if(i % 2 == 0)
      alice += A[i];
    else
      bob += A[i];
  }
  cout << alice - bob << endl;
  return 0;
}

