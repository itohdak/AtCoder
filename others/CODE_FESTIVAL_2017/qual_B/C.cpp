#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N, M;
  cin >> N >> M;

  int map[N][N];
  for(int i=0; i<M; i++)
    for(int j=0; j<M; j++)
      map[i][j] = 0;

  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    map[a][b] = 1;
  }

  int ret = 0;
  for(int i=0; i<M; i++){ // 始点
    for(int j=0; j<M; j++){ // 終点
      if(i != j && map[i][j] != 1){
	for(int i1=0; i1<M; i1++){ // 2点目
	  if(map[i][i1] == 1){
	    for(int i2=0; i2<M; i2++){ // 3点目
	      if(i2 != i && map[i1][i2] == 1){
		if(map[i2][j] == 1){
		  map[i][j] = 1;
		  ret++;
		}
	      }
	    }
	  }
	}
      }
    }
  }

  cout << ret << endl;

  return 0;
}

