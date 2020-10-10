#include "header.hpp"

template<int char_size, int base>
struct Trie {
  struct Node {
    vector<int> next;
    vector<int> accept;
    int c;
    int common;
    Node(int c_) : c(c_), common(0) {
      next.assign(char_size, -1);
    }
  };
  vector<Node> nodes;
  int root;
  Trie() : root(0) {
    nodes.push_back(Node(root));
  }

  void insert(const string& word, int word_id) {
    int node_id = 0;
    for(int i=0; i<(int)word.size(); i++) {
      int c = (int)(word[i] - base);
      int& next_id = nodes[node_id].next[c];
      if(next_id == -1) {
        next_id = (int)nodes.size();
        nodes.push_back(Node(c));
      }
      ++nodes[node_id].common;
      node_id = next_id;
    }
    ++nodes[node_id].common;
    nodes[node_id].accept.push_back(word_id);
  }
  void insert(const string& word) {
    insert(word, nodes[0].common);
  }

  bool search(const string& word, bool prefix=false) {
    int node_id = 0;
    for(int i=0; i<(int)word.size(); i++) {
      int c = (int)(word[i] - base);
      int& next_id = nodes[node_id].next[c];
      if(next_id == -1) return false;
      node_id = next_id;
    }
    return (prefix ? true : nodes[node_id].accept.size() > 0);
  }
  bool start_with(const string& word) {
    return search(word, true);
  }

  int count() const {
    return (nodes[0].common);
  }
  int size () const {
    return ((int)nodes.size());
  }
};
