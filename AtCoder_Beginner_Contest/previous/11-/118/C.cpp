#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <climits>

using namespace std;
#define ll long long

pair<ll, int> minimum(vector<ll>& A) {
  ll tmp = LLONG_MAX;
  int idx = -1;
  for(int i=0; i<A.size(); i++) {
    if(A[i] != 0 && A[i] < tmp) {
      tmp = A[i];
      idx = i;
    }
  }
  return make_pair(tmp, idx);
}

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i=0; i<N; i++)
    cin >> A[i];
  ll tmp = LLONG_MAX;
  pair<ll, int> next;
  while((next = minimum(A)).first != tmp) {
    for(int i=0; i<N; i++) {
      if(i != next.second)
	A[i] %= next.first;
    }
    tmp = next.first;
  }
  cout << tmp << endl;
  return 0;
}

