#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A;
  int in;
  for(int i=0; i<N; i++){
    cin >> in;
    A.push_back(in);
  }
  sort(A.begin(), A.end(), greater<int>());

  int biggest = 0;
  int bigger = 0;
  for(int i=0; i<A.size()-1; i++){
    if(A[i] == A[i+1]){
      if(biggest == 0){
	biggest = A[i];
	i += 1;
      } else if(biggest > 0 && bigger == 0){
	bigger = A[i];
	break;
      }
    }
  }
  int ans = 0;
  if(biggest != 0 && bigger != 0){
    ans = biggest * bigger;
  }

  cout << ans << endl;
  return 0;
}

