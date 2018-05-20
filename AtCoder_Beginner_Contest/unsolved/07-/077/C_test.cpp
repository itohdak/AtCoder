#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int binary_search(const int limit,
		  const vector<int>::iterator iter,
		  const int length)
{
  // for(int i=0; i<length; i++){
  //   cout << *(iter+i) << ' ';
  // }
  // cout << endl;

  if(length == 1){
    if(*iter > limit) return 1;
    else return 0;
  }

  int half;
  if(length % 2 == 1) half = length / 2;
  else half = length / 2 - 1;

  if(*(iter+half) > limit){
    // cout << "+ " << half << endl;
    return half + 1 + binary_search(limit, iter+half+1, length-(half+1));
  } else {
    return binary_search(limit, iter, half+1);
  }
}

int main(){
  vector<int> data;
  for(int i=0; i<10; i++){
    data.push_back(i);
  } // {0,1,2,3,4,5,6,7,8,9}
  sort(data.begin(), data.end(), greater<int>()); // {9,8,7,6,5,4,3,2,1,0}
  for(int i=0; i<10; i++){
    cout << binary_search(i, data.begin(), data.size()) << endl;
  }

  return 0;
}

