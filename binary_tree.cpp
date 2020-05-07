#include <iostream>
#include <vector>
using namespace std;

struct Node {
  Node(int k) : key(k) {}
  int key;
  Node *left = nullptr;
  Node *right = nullptr;
  Node *p = nullptr;
};

Node *root = nullptr;

Node *FindKey(Node *start, int key) {
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

Node *Insert(int key) {
  if (root == nullptr) {
    root = new Node(key);
    return root;
  }

  Node *parent = root;
  while (parent != nullptr) {
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

int DepthOfTree(Node *start) {
  if (start == nullptr) {
    return 0;
  }
  return std::max(DepthOfTree(start->left), DepthOfTree(start->right)) + 1;
}

void InOrderWalk(Node *start) {
  if (start == nullptr) {
    return;
  }
  InOrderWalk(start->left);
  cout << " " << start->key;
  InOrderWalk(start->right);
}

Node* TreeMinimum(Node *start) {
  if (start == nullptr)
    return nullptr;

  Node *n = start;
  while (n->left != nullptr) {
    n = n->left;
  }
  return n;
}

Node* TreeSuccessor(Node *start) {
  if (start == nullptr)
    return nullptr;

  if (start->right != nullptr) {
    return TreeMinimum(start->right);
  }

  auto parent = start->p;
  auto n = start;
  while (parent != nullptr && parent->right == n) {
    n = parent;
    parent = n->p;
  }
  return parent;
}

void dumpNode(Node *n) {
  if (n == nullptr) {
    return;
  }
  std::string left_str = (n->left) ? std::to_string(n->left->key) : "null";
  std::string right_str = (n->right) ? std::to_string(n->right->key) : "null";
  std::string children = "{ " + left_str + " , " + right_str + " }";
  cout << "Node:  " << n->key << " -> " << children << endl;
}

void DeleteNode(Node *node) {

  if (node == nullptr)
    return;
  // Case 1:  No children.
  auto parent = node->p;
  if (node->left == nullptr && node->right == nullptr) {
    cout<<"Considering case 1"<<endl;
    // set the corresponding parents left/right to nullptr
    if (parent) {
      if (parent->left == node) {
        parent->left = nullptr;
      } else {
        parent->right = nullptr;
      }
    } else {
      // implies root node
      root = nullptr;
    }
    delete node;
    return;
  }

  // case 2: if this node has only one child
  // then splice the child out and put it where the original node was
  bool only_one_child =
      (node->left == nullptr && node->right != nullptr) ||
      (node->right == nullptr && node->left != nullptr);

if (only_one_child) {
  cout<<"Considering case 2"<<endl;
    Node *to_splice = nullptr;
    if (node->left == nullptr) {
      // it implies node has only right node
      to_splice = node->right;
    } else {
      to_splice = node->left;
    }

    if (parent == nullptr) {
      // implies node under deletion is root;
      root = to_splice;
    } else {
      if (parent->left == node) {
        parent->left = to_splice;
      } else {
        parent->right = to_splice;
      }
    }
   delete node;
   return;
  }

  cout << "Considering case 3" << endl;
  // Last case: Node has both left and right nodes
  auto successor = TreeSuccessor(node);
  node->key = successor->key;
  auto successor_parent = successor->p;
  if (successor_parent->right == successor) {
    successor_parent->right = nullptr;
  } else {
    successor_parent->left = nullptr;
  }
  delete successor;
}


void InsertASortedArray(std::vector<int>& arr, int start, int end) {
  // break recursion
  auto len = (end - start) + 1;
  if (len <= 2) {
    Insert(arr[start]);
    if (len == 2)
      Insert(arr[end]);
    return;
  }

  cout<<"Ravi Inserting for Range: "<<start<<" - "<<end<<endl;
  int middle = (end + start) / 2;
  Insert( arr[middle] );
  InsertASortedArray(arr, start, middle - 1);
  InsertASortedArray(arr, middle + 1, end);
}

int main() {
  // root = Insert(15);
  // auto n1 = Insert(6);
  // auto n2 = Insert(18);
  // auto n3 = Insert(3);
  // auto n4 = Insert(7);
  // Insert(17);
  // Insert(20);
  // Insert(2);
  // Insert(4);
  // auto n13 = Insert(13);
  // auto n9 = Insert(9);

  // // dumpNode(n9);
  // // auto n = TreeSuccessor(n9);
  // // cout << "Successor of " << (n9->key) << " is " << (n->key) << endl;
  // DeleteNode(root);

  std::vector<int> sorted = {1,2,3,4,5,6,7,8,9,10};
  InsertASortedArray(sorted, 0, sorted.size() - 1);
  InOrderWalk(root);
  cout << endl;
  dumpNode(root);
}
