#include <iostream>

using namespace std;

struct Node {
  Node(int k): key(k){}
  int key;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* p = nullptr;
};

Node* root = nullptr;

Node* FindKey(Node* start, int key) {
  if (start == nullptr) {
    return nullptr;
  }

  if (start->key == key) {
    return start;
  }

  if (key < start->key) {
    return FindKey(start->left, key);
  }
  return FindKey(start->right, key);
}


Node* Insert(int key) {
 if (root == nullptr) {
   root = new Node(key);
   return root;
 }

 Node* parent = root;
 while(parent != nullptr) {
   if (key <= parent->key) {
     if (parent->left == nullptr) {
      parent->left = new Node(key);
      parent->left->p = parent;
      return parent->left;
     }
     parent = parent->left;
   } else {
     if (parent->right == nullptr) {
        parent->right = new Node(key);
        parent->right->p = parent;
        return parent->right;
     }
     parent = parent->right;
   }
 }
  return nullptr;
}

int DepthOfTree(Node* start) {
  if (start == nullptr) {
    return 0;
  }
  return std::max(DepthOfTree(start->left), DepthOfTree(start->right)) + 1;
}

void InOrderWalk(Node* start) {
  if (start == nullptr) {
    return;
  }
  InOrderWalk(start->left);
  cout<<" "<<start->key;
  InOrderWalk(start->right);
}


int main() {
  auto root = Insert(5);
  auto n1 = Insert(4);
  auto n2 = Insert(3);
  auto n3 = Insert(6);
  auto n4 = Insert(2);
  auto n5 = Insert(1);
  Insert(7);
  Insert(15);
  Insert(8);
  Insert(18);
  Insert(10);
  Insert(11);

  cout<<"Expect  3: "<<n5->p->p->key<<endl;
  cout<<root->key<<"  "<<root->left->key<<" "<<root->right->key<<endl;

  if (auto node = FindKey(root, 1)) {
    cout<<"Found 1 parent : "<<node->p->key<<endl;
  }
  cout<<"Depth of Tree: "<<DepthOfTree(root)<<endl;

  InOrderWalk(root);
}
