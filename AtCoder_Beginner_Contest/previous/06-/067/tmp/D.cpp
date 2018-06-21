#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  int connect[N][N];
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i == j)
	connect[i][j] = 0;
      else
	connect[i][j] = 100000;
    }
  }
  for(int i=0; i<N-1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    connect[a][b] = connect[b][a] = 1;
  }
  int d1[N], dN[N];
  for(int i=0; i<N; i++){
    if(i == 0){
      d1[i] = 0; dN[i] = 100000;
    } else if(i == N-1){
      dN[i] = 0; d1[i] = 100000;
    } else {
      d1[i] = dN[i] = 100000;
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(d1[i] > d1[j] + connect[j][i])
	d1[i] = d1[j] + connect[j][i];
      if(dN[i] > dN[j] + connect[j][i])
	dN[i] = dN[j] + connect[j][i];
    }
  }
  int Fennec = 0, Snuke = 0;
  for(int i=0; i<N; i++){
    if(d1[i] <= dN[i])
      Fennec++;
    else
      Snuke++;
  }
  if(Fennec > Snuke)
    cout << "Fennec" << endl;
  else
    cout << "Snuke" << endl;
  return 0;
}

