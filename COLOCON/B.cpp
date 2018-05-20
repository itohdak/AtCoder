#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N, X;
  string S;
  int T[N];
  cin >> N >> X;
  cin >> S;
  for(int i=0; i<N; i++){
    cin >> T[i];
  }
  int time = 0;
  for(int i=0; i<N; i++){
    if(S[i] == '0') time += T[i];
    else if(T[i] > X) time += X;
    else time += T[i];
  }
  cout << time << endl;
  return 0;
}

