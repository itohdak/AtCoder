#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string A, B;
  cin >> A >> B;
  int a = A.size(), b = B.size();
  if(a < b)
    cout << "LESS" << endl;
  else if(a > b)
    cout << "GREATER" << endl;
  else {
    string ans = "EQUAL";
    for(int i=0; i<a; i++) {
      if(A[i] > B[i]) {
	ans = "GREATER";
	break;
      } else if(A[i] < B[i]) {
	ans = "LESS";
	break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

