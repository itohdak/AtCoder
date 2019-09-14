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
  vector<int> from_1, to_N;
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    if(a == 1)
      from_1.push_back(b);
    if(b == N)
      to_N.push_back(a);
  }
  bool ans = false;
  for(int i=0; i<from_1.size(); i++)
    if(find(to_N.begin(), to_N.end(), from_1[i]) != to_N.end()){
      ans = true;
      break;
    }
  if(ans)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}

