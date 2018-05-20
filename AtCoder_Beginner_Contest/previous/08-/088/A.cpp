#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, A;
  cin >> N >> A;
  if(N % 500 <= A)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

