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
  ll march[5];
  for(int i=0; i<5; i++)
    march[i] = 0;
  for(int i=0; i<N; i++){
    string in;
    cin >> in;
    if(in[0] == 'M') march[0]++;
    else if(in[0] == 'A') march[1]++;
    else if(in[0] == 'R') march[2]++;
    else if(in[0] == 'C') march[3]++;
    else if(in[0] == 'H') march[4]++;
  }
  ll ret = 0;
  for(int i=0; i<5; i++)
    for(int j=i+1; j<5; j++)
      for(int k=j+1; k<5; k++)
	ret += march[i] * march[j] * march[k];
  cout << ret << endl;

  return 0;
}

