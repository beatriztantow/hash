#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "../src/include/hashTable.hpp"
#include "../src/include/hashTableExceptions.hpp"

int main() {

  std::unique_ptr<hashTable> h = std::make_unique<hashTable>();

  std::string cores[] = {"Vermelho", "Laranja", "Amarelo", "Verde", "Ciano", "Anil", "Magenta"};

  h->insert(0,"batata");
  h->insert(7,"potato");
  
  h->remove(0);
  h->remove(7);

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