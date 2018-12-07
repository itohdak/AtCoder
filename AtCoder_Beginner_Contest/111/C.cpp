#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int v[100000];
int A[100000];
int B[100000];

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> v[i];
    if(i % 2 == 0)
      A[v[i]-1]++;
    else
      B[v[i]-1]++;
  }
  int M_odd = 0;  int m_odd = 0;
  int i_odd = -1;
  int M_even = 0;  int m_even = 0;
  int i_even = -1;
  for(int i=0; i<100000; i++) {
    if(A[i] > M_even) {
      m_even = M_even;
      M_even = A[i];
      i_even = i;
    }
    if(B[i] > M_odd) {
      m_odd = M_odd;
      M_odd = B[i];
      i_odd = i;
    }
  }
  if(i_even == i_odd)
    cout << min(n - M_even - m_odd, n - M_odd - m_even) << endl;
  else
    cout << n - M_even - M_odd << endl;
  return 0;
}

