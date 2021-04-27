#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

#include "../src/include/hashTable.hpp"
#include "../src/include/hashTableExceptions.hpp"

int main() {

  hashTable *h = new hashTable();

  std::string cores[] = {"Vermelho", "Laranja", "Amarelo", "Verde", "Ciano", "Anil", "Magenta"};

  for (int i = 0; i < 7; i++) {
    h->insert(i, cores[i]);
  }

  try {
    h->insert(0, "Vermelho");
    assert(false);
  }
  catch(const duplicateKeyException& e) {
    assert(true);
  }

  try {
    h->insert(7, "Preto");
    assert(false);
  }
  catch(const tableOverflowException& e) {
    assert(true);
  }

  try {
    h->search(7);
    assert(false);
  }
  catch(const notFoundException& e) {
    assert(true);
  }

  for (int i = 0; i < 7; i++) {
    assert(h->search(i) == cores[i]);
  }

  h->remove(0);
  try {
    h->search(0);
    assert(false);
  }
  catch(const notFoundException& e) {
    assert(true);
  }

  return 0;
}