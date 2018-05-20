#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B;
  cin >> A >> B;
  int ans = 0;
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      for(int k=0; k<10; k++){
	int num = i * 10001 + j * 1010 + k * 100;
	if(A <= num && num <= B) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

