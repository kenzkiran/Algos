#include <iostream>

using namespace std;
struct Node
{
  int val;
  Node *next;
  Node(int vall) : val(vall) {}
};

Node *head;

Node *AddToList(int a)
{
  if (head == nullptr)
  {
    head = new Node(a);
    return head;
  }

  Node* n = head;
  while(n != nullptr) {
    if (n->next == nullptr) {
      break;
    }
    n = n->next;
  }
  n->next = new Node(a);
  return n->next;
}

void dumpList() {
  Node* n = head;
  while(n != nullptr) {
    cout<<" -> "<<n->val;
    n = n->next;
  }
}

Node *FindNode(int a) {
  if (head == nullptr) {
    return nullptr;
  }
  Node* n = head;
  while(n != nullptr) {
    if (n->val == a) {
      return n;
    }
    n = n->next;
  }
  return nullptr;
}

void RemoveFromList(Node *) {
}

int main() {
  AddToList(8);
  AddToList(9);
  AddToList(10);

  auto n = FindNode(9);
  cout<<"Ravi "<<n->next->val;
  dumpList();
}