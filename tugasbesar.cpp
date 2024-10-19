#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

// Fungsi untuk membuat node baru
Node* newNode(int data) {
  Node* node = new Node;
  node->data = data;
  node->next = nullptr;
  return node;
}

// Fungsi untuk menambahkan node baru ke akhir linked list
void append(Node** head, int data) {
  Node* new_node = newNode(data);

  if (*head == nullptr) {
    *head = new_node;
    return;
  }

  Node* last = *head;
  while (last->next != nullptr) {
    last = last->next;
  }

  last->next = new_node;
}

// Penambahan Function error untuk merusak project disini
// Fungsi untuk membalik linked list
Node* reverseLinkedList(Node* head) {
    Node *prev = nullptr, *current = head, *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Error sampai sini

// Fungsi untuk menemukan node tengah kedua dalam linked list
int findSecondMiddleNode(Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return -1; // Linked list kosong atau hanya memiliki satu node
  }

  Node* slow = head;
  Node* fast = head;

  // Temukan node tengah
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // Jika jumlah node genap, slow sudah menunjuk ke node tengah pertama
  // Jika jumlah node ganjil, pindahkan slow ke node berikutnya untuk menunjuk ke node tengah pertama

  return slow->data;
}

int main() {
  Node* head = nullptr;
  int n;

  cout << "Masukkan jumlah node: ";
  cin >> n;

  cout << "Masukkan data node: ";
  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;
    append(&head, data);
  }

  int secondMiddleData = findSecondMiddleNode(head);

  if (secondMiddleData == -1) {
    cout << "Tidak ada node tengah." << endl;
  } else {
    cout << "Nilai node tengah: " << secondMiddleData << endl;
  }

  return 0;
}