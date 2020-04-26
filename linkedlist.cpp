#include <iostream>

using namespace std;
struct Node {
  int val;
  Node *next;
  Node(int vall) : val(vall), next(nullptr) {}
};

Node *head;

Node *AddToList(int a) {
  if (head == nullptr) {
    head = new Node(a);
    return head;
  }

  Node *n = head;
  while (n != nullptr) {
    if (n->next == nullptr) {
      break;
    }
    n = n->next;
  }
  n->next = new Node(a);
  return n->next;
}

void dumpList() {
  Node *n = head;
  while (n != nullptr) {
    cout << " -> " << n->val;
    n = n->next;
  }
}

Node *FindNode(int a) {
  if (head == nullptr) {
    return nullptr;
  }
  Node *n = head;
  while (n != nullptr) {
    if (n->val == a) {
      return n;
    }
    n = n->next;
  }
  return nullptr;
}

void RemoveFromList(Node *n) {
  if (n == nullptr) {
    return;
  }

  if (head == n) {
    head = head->next;
    delete n;
  }

  auto* cur = head;
  while(cur != nullptr) {
    if (cur->next == n) {
      cur->next = n->next;
      delete n;
      return;
    }
    cur = cur->next;
  }
 
}

int lengthOfList(Node* head) {
  if (head == nullptr) {
    return 0;
  }
  return lengthOfList(head->next) + 1;
}

int main() {
  AddToList(8);
  AddToList(9);
  AddToList(13);
  AddToList(12);
  AddToList(11);

  cout<<"Lenght : "<<lengthOfList(head)<<endl;
  auto n = FindNode(9);
  cout << "Ravi " << n->next->val<<endl;
  RemoveFromList(n);
  dumpList();
}