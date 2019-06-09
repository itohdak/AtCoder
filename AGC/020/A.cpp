#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  if(abs(A - B) % 2 == 0)
    cout << "Alice" << endl;
  else
    cout << "Borys" << endl;
  return 0;
}

