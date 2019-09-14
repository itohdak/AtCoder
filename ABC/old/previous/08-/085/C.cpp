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
  ll Y;
  cin >> N >> Y;
  for(int y=0; y<=N; y++){
    for(int z=0; z<=N-y; z++){
      if(5000 * y + 9000 * z == 10000 * N - Y){
	cout << N-y-z << ' ' << y << ' ' << z << endl;
	return 0;
      }
    }
  }
  cout << -1 << ' ' << -1 << ' ' << -1 << endl;
  return 0;
}

