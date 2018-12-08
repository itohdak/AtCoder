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
  if(N == 1) {
    cout << "Hello World" << endl;
  } else {
    int A, B;
    cin >> A >> B;
    cout << A + B << endl;
  }
  return 0;
}

