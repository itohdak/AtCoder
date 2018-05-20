#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

int main(){
  int N, M;
  cin >> N >> M;
  vector<bool> from_1(N, false), to_N(N, false);
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    if(a == 1)
      from_1[b-1] = true;
    if(b == N)
      to_N[a-1] = true;
  }
  bool ans = false;
  for(int i=0; i<N; i++){
    if(from_1[i] && to_N[i]){
      ans = true;
      break;
    }
  }
  if(ans)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}

