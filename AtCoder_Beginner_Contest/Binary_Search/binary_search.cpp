#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

#define MAX 28

vector<int> A(10000000000);

int binary_search(int n, int target){
  int left = 0;
  int right = n-1;
  int mid;

  while(left <= right){
    mid = (left + right) / 2;
    if(A[mid] == target){
      return 0;
    } else if(A[mid] < target){
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return 0;
}

int main(){
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for(int i=0; i<N; i++)
    cin >> A[i] >> B[i];
  sort(B.begin(), B.end());
  ll ans = 0;
  for(int k=0; k<28; k++){
    ll T = (1 << k);
    int begin=0, end=N-1, mid;
    while(begin < end){
      mid = (begin + end) / 2;
      if(mid > )
    }
  }
  return 0;
}
