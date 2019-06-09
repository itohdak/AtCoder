#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N, C;
  cin >> N >> C;
  bool on_off[C][100000];
  for(int i=0; i<C; i++)
    for(int j=0; j<100000; j++)
      on_off[i][j] = false;
  for(int i=0; i<N; i++){
    int s, t, c;
    cin >> s >> t >> c;
    for(int j=s-1; j<t; j++){
      on_off[c-1][j] = true;
    }
  }
  int ret = 0;
  for(int i=0; i<100000; i++){
    int tmp = 0;
    for(int j=0; j<C; j++){
      if(on_off[j][i])
	tmp++;
    }
    ret = max(ret, tmp);
  }
  cout << ret << endl;
  return 0;
}

