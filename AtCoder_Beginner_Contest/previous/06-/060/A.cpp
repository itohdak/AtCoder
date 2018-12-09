#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string A, B, C;
  cin >> A >> B >> C;
  if(A[A.size()-1] == B[0] && B[B.size()-1] == C[0])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

