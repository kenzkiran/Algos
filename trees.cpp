#include <iostream>
#include <queue>

using namespace std;
struct Node {
  Node(int a): val(a) {};
  int val = 0;
  bool is_visited = false;
  std::vector<Node*> children;
  void dump() {
    std::string  str_childs("[ ");
    for(auto i = 0; i < children.size(); ++i) {
      str_childs.append(std::to_string(children[i]->val));
      str_childs.append(", ");
    }
    str_childs.append("]");
    cout<<"Node: "<<val<<" - > "<<str_childs<<endl;
  }
};

Node* head;

void buildTree() {
/* A sample Tree

             75
       /      |      \
   9         10         23
 / | \       / \       /  \
15 91 0    1    55    81   02
                          /  \ 
                         27  16 

*/

  // build a tree
  head = new Node(75);
  head->children.push_back(new Node(9));
  head->children.push_back(new Node(10));
  head->children.push_back(new Node(23));
  
  head->children[0]->children.push_back(new Node(15));
  head->children[0]->children.push_back(new Node(91));
  head->children[0]->children.push_back(new Node(0));

  head->children[1]->children.push_back(new Node(1));
  head->children[1]->children.push_back(new Node(55));
  
  head->children[2]->children.push_back(new Node(81));
  head->children[2]->children.push_back(new Node(02));
  

  head->children[2]->children[1]->children.push_back(new Node(27));
  head->children[2]->children[1]->children.push_back(new Node(16));
}


Node* findBFS(Node* root, int val) {
  // not checking for null
  if (root->val == val) {
    return root;
  }
  std::queue<Node*> q;
  q.push(root);
  root->is_visited = true;
  while(!q.empty()) {
    auto node = q.front();
    q.pop();
    cout<<"Ravi Checking "<<node->val<<endl;
    if (node->val == val) {
      return node;
    }
    node->is_visited = true;
    for(auto i = 0; i < node->children.size(); ++i) {
      if (!node->children[i]->is_visited) {
        q.push(node->children[i]);
      }
    }
  }
  return nullptr;
}

Node* findDFS(Node* root, int val) {
  if (root->val == val) {
    return root;
  }
  // cout<<"Ravi checking "<<root->val<<endl;
  for(auto i = 0; i < root->children.size(); ++i) {
    auto n = findDFS(root->children[i], val);
    if (n) {
      return n;
    }
  }
  return nullptr;
};

int main() {
 buildTree();
 head->dump();
 
//  auto n = findDFS(head, 02);
//  if (n) {
//    n->dump();
//  }

 auto nn = findBFS(head, 02);
 if (nn) {
   nn->dump();
 }
}