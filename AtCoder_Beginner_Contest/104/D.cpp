#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string S;
  cin >> S;
  int N = (int)S.size();
  vector<int> A(N+1, 0), B(N+1, 0), C(N+1, 0), D;
  A[N] = B[N] = C[N] = 0;
  for(int i=N-1; i>=0; i--){
    A[i] = A[i+1];
    B[i] = B[i+1];
    C[i] = C[i+1];
    if(S[i] == 'A')
      A[i]++;
    else if(S[i] == 'B')
      B[i]++;
    else if(S[i] == 'C')
      C[i]++;
    else {
      A[i]++; B[i]++; C[i]++;
      D.push_back(i);
    }
  }
  D.push_back(D[D.size()-1]-1);
  reverse(D.begin(), D.end());
  D.push_back(D[D.size()-1]+1);
  // for(int i=0; i<D.size(); i++)
  //   cout << D[i] << ' ';
  // cout << endl;
  ll sum = 0;
  for(int i=0; i<D.size(); i++){
    for(int j=i+1; j<D.size(); j++){
      // cout << D[i] << ' ' << D[j] << " : ";
      // cout << (A[0] - A[D[i]]) << ' ' << (B[D[i]] - B[D[j]]) << ' ' << C[D[j]] << endl;
      for(int a=0; a<i; a++)
	for(int b=0; b<j-i; b++)
	  for(int c=0; c<D.size()-j; c++)
	    sum += (A[0] - A[D[i]] - a) * (B[D[i]] - B[D[j]] - b) * (C[D[j]] - c);
      sum %= 1000000007;
    }
  }
  cout << sum << endl;
  return 0;
}

