#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <deque>

using namespace std;

int main(){
  int K;
  cin >> K;
  int graph[K];
  bool visited[K];
  for(int i=0; i<K; i++){
    if(i == 1) graph[i] = 0;
    else graph[i] = K;

    visited[i] = false;
  }

  deque<int> queue;
  visited[1] = true;
  queue.push_back(1);
  while(graph[0] == K){
    int tmp = queue[0];
    queue.pop_front();

    int target1 = (tmp + 1) % K;
    graph[target1] = min(graph[target1], graph[tmp] + 1);
    if(!visited[target1]){
      visited[target1] = true;
      queue.push_back(target1);
    }

    int target2 = (tmp * 10) % K;
    graph[target2] = min(graph[target2], graph[tmp]);
    if(!visited[target2]){
      visited[target2] = true;
      queue.push_back(target2);
    }
  }

  cout << (graph[0] + 1) << endl;

  return 0;
}
