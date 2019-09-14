#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  int F[N][10];
  for(int i=0; i<N; i++){
    for(int j=0; j<10; j++){
      cin >> F[i][j];
    }
  }
  int P[N][11];
  for(int i=0; i<N; i++){
    for(int j=0; j<11; j++){
      cin >> P[i][j];
    }
  }
  bool updated = false;
  int ret = 0;
  int open_close[10];
  for(int i=1; i<pow(2, 10); i++){
    int tmp = 0;
    for(int j=0; j<10; j++){
      open_close[j] = (int)(i / pow(2, j)) % 2;
    }
    for(int j=0; j<N; j++){
      int c = 0;
      for(int k=0; k<10; k++){
	if(open_close[k] * F[j][k] == 1){
	  c++;
	}
      }
      tmp += P[j][c];
    }
    if(updated){
      ret = max(tmp, ret);
    } else {
      ret = tmp;
      updated = true;
    }
  }
  cout << ret << endl;
  return 0;
}

