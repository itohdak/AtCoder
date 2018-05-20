#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

int main(){
  ll K;
  cin >> K;
  int N = 50;
  vector<ll> a(N, K/N);
  for(int i=0; i<N; i++)
    a[i] += i;
  for(int i=0; i<K%N; i++){
    for(int j=0; j<N; j++){
      if(i == j)
	a[j] += N;
      else
	a[j]--;
    }
  }
  cout << N << endl;
  for(int i=0; i<N; i++)
    cout << a[i] << ' ';
  cout << endl;
  return 0;
}

