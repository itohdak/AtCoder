#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

bool alpha1[26], alpha2[26];

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int max = -1;
  for(int i=0; i<N; i++){
    string S1 = S.substr(0, i);
    string S2 = S.substr(i, N);
    for(int j=0; j<26; j++)
      alpha1[j] = alpha2[j] = false;
    for(int j=0; j<i; j++)
      alpha1[int(S1[j]) - int('a')] = true;
    for(int j=0; j<N-i; j++)
      alpha2[int(S2[j]) - int('a')] = true;
    int tmp = 0;
    for(int j=0; j<26; j++)
      if(alpha1[j] && alpha2[j])
	tmp++;
    if(tmp > max)
      max = tmp;
  }
  cout << max << endl;
  return 0;
}

