#include <iostream>
#include <ostream>
using T = int;

struct node {
  T data;
  node* next;
};

void add_head(node*& head, T data) {
  auto new_node = new node(data, head);
  head = new_node;
}

void add_tail(node*& head, T data) {
  const auto new_node = new node{data, nullptr};

  if (head == nullptr) {
    head = new_node;
    return;
  }

  node* temp = head;
  node* prev = head;

  while (temp != nullptr) {
    prev = temp;
    temp = temp->next;
  }
  prev->next = new_node;
}

void print_list(const node* head) {
  while (head != nullptr) {
    std::cout << head->data << std::endl;
    head = head->next;
  }
}

void delete_list(node*& head) {
  if (head == nullptr) return;

  const node* temp = head;
  const node* prev = nullptr;

  while (temp != nullptr) {
    prev = temp;
    temp = temp->next;
    delete prev;
  }
  head = nullptr;
}

// DA FINIRE
bool delete_at_index(node*& head, const size_t index) {
  if (head == nullptr) return false;

  node* temp = head;
  if (head->next == nullptr) {
    temp = head;
    delete head;
    head = nullptr;
    return true;
  }

  for (unsigned int i = 1; i <= index; ++i) {
    temp = temp->next;
    if (temp == nullptr) return false;
  }
}

int main() {
  node* head = nullptr;
  add_head(head, 50);
  add_tail(head, 60);
  add_head(head, 70);

  print_list(head);

  delete_list(head);
}