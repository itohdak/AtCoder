#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> D;
  D.push_back(0);
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    D.push_back(in);
  }
  sort(D.begin(), D.end());
  int n = 0;
  // print D
  // cout << n << "回目" << endl;
  // n++;
  // for(int i=0; i<D.size(); i++)
  //   cout << D[i] << ' ';
  // cout << endl;
  //
  bool changed = true;
  int ret;
  while(changed){
    int min_diff = 24;
    int min_index;
    for(int i=0; i<D.size(); i++){
      if(i == D.size() - 1){
	if(24 - D[i] < min_diff){
	  min_diff = D[i+1] - D[i];
	  min_index = i;
	}
      } else {
	if(D[i+1] - D[i] < min_diff){
	  min_diff = D[i+1] - D[i];
	  min_index = i;
	}
      }
    }

    int swap_index;
    if(D[min_index] == 0 || D[min_index] == 12){
      swap_index = min_index + 1;
    } else {
      swap_index = min_index;
    }
    D[swap_index] = 24 - D[swap_index];
    sort(D.begin(), D.end());
    // print D
    // cout << n << "回目" << endl;
    // n++;
    // for(int i=0; i<D.size(); i++)
    //   cout << D[i] << ' ';
    // cout << endl;
    //
    int min_diff_new = 24;
    for(int i=0; i<D.size(); i++){
      if(i == D.size() - 1){
	if(24 - D[i] < min_diff_new){
	  min_diff_new = D[i+1] - D[i];
	}
      } else {
	if(D[i+1] - D[i] < min_diff_new){
	  min_diff_new = D[i+1] - D[i];
	}
      }
    }
    if(min_diff_new > min_diff){
      changed = true;
    } else {
      ret = min_diff;
      changed = false;
    }
  }
  cout << ret << endl;
  return 0;
}

