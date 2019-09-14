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
  vector<string> S;
  for(int i=0; i<N; i++){
    string in;
    cin >> in;
    S.push_back(in);
  }
  int M;
  cin >> M;
  vector<string> T;
  for(int i=0; i<M; i++){
    string in;
    cin >> in;
    T.push_back(in);
  }

  int ret = 0;
  for(int i=0; i<N; i++){
    int p = 0;
    string s = S[i];
    for(int j=0; j<N; j++)
      if(S[j] == s) p++;
    for(int j=0; j<M; j++)
      if(T[j] == s) p--;
    if(p > ret)
      ret = p;
  }
  cout << ret << endl;
  return 0;
}

