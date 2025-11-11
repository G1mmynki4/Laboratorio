#include <iostream>

using T = int;

struct node {
  node* next;
  T data;
};

void print(const node* head) {
  while (head != nullptr) {
    std::cout << head->data << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

bool deallocate(node*& head) {
  if (head == nullptr) return false;

  node* index = head;
  node* previous = nullptr;

  do {
    previous = index;

    index = index->next;
    delete previous;

  } while (index != nullptr);
  head = nullptr;
  return true;
}

bool add_head(node*& head, T data) {
  node* new_node = new node;
  new_node->data = data;
  new_node->next = head;
  head = new_node;
  return true;
}

bool remove_head(node*& head, T& data) {
  if (head == nullptr) {
    return false;
  }

  data = head->data;
  const node* old = head;
  head = head->next;
  delete old;
  return true;
}

bool add_tail(node* head, T data) {
  node* new_node = new node;
  new_node->data = data;
  new_node->next = nullptr;

  if (head == nullptr) {
    head = new_node;
    return true;
  }

  node* tail = head;
  while (tail->next != nullptr) {
    tail = tail->next;
  }

  tail->next = new_node;
  return true;
}

bool remove_tail(node*& head, T& data) {
  if (head == nullptr) {
    return false;
  }

  if (head->next == nullptr) {
    data = head->data;
    delete head;
    head = nullptr;
    return true;
  }

  node* previous = head;
  node* tail = head->next;

  while (tail->next != nullptr) {
    previous = tail;
    tail = tail->next;
  }

  data = tail->data;
  delete tail;
  previous->next = nullptr;
  return true;
}

int main(int argc, char* argv[]) {
  node* head = nullptr;

  add_head(head, 10);
  add_head(head, 20);
  print(head);

  T a;
  remove_head(head, a);
  print(head);

  add_tail(head, 20);
  print(head);

  T b;
  remove_tail(head, b);
  print(head);

  deallocate(head);

  return 0;
}