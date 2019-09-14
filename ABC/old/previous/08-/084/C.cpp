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
  int C[N], S[N], F[N];
  for(int i=1; i<N; i++)
    cin >> C[i] >> S[i] >> F[i];
  for(int i=1; i<=N; i++){
    if(i == N)
      cout << 0 << endl;
    else{
      int time = S[i];
      for(int j=i; j<N; j++){
	time = ceil(max(0, (time - S[j])) / (double)F[j]) * F[j] + S[j] + C[j];
      }
      cout << time << endl;
    }
  }
  return 0;
}

