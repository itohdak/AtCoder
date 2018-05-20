#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A;
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    A.push_back(in);
  }
  int ret = 0;
  bool able = true;
  while(able){
    for(int i=0; i<N; i++){
      if(A[i] % 2 == 0){
	A[i] /= 2;
      } else {
	able = false;
	break;
      }
    }
    if(able){
      ret++;
    }
  }
  cout << ret << endl;
  return 0;
}

