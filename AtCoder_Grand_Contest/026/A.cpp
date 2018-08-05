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
  vector<int> A(N);
  for(int i=0; i<N; i++)
    cin >> A[i];
  int count = 0;
  for(int i=1; i<N; i++){
    if(A[i-1] == A[i]){
      count++;
      i++;
    }
  }
  cout << count << endl;
  return 0;
}

