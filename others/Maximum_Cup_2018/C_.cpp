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
  int G[N]; // group no.
  vector<int> M[N]; // member of group
  for(int i=0; i<N; i++){
    G[i] = i;
    M[i].push_back(i);
  }
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    in--;
    if(G[i] != G[in]){
      int new_group = min(G[i], G[in]);
      int other;
      if(new_group == G[i]) other = G[in];
      else other = G[i];
      for(int j=0; j<M[other].size(); j++){
	G[M[other][j]] = new_group;
	M[new_group].push_back(M[other][j]);
      }
      M[other].clear();
    }

    // for(int i=0; i<N; i++){
    //   for(int j=0; j<M[i].size(); j++){
    // 	cout << M[i][j] << ' ';
    //   }
    //   cout << "| ";
    // }
    // cout << endl;
  }
  int ret = 0;
  for(int i=0; i<N; i++){
    if(M[i].size() % 2 == 0){
      ret += M[i].size() / 2;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ret << endl;
  return 0;
}
