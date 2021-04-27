#include "include/hashTable.hpp"
#include "include/hashTableExceptions.hpp"

// Função hash baseada no método da divisão.
// Módulo de números primos tem menos chance de colidir, o número deve ser maior que o vetor

hashTable::hashTable() {

};


int hashTable::hash(int k, int i) {
  if (i == HASH_SIZE) {
      throw tableTotallyVisitedException();
  }
  return ((k % HASH_SIZE) + 1) % HASH_SIZE;
};

void hashTable::insert(int k, std::string v) {
  int i = 0;
  int index;
  
  try {
    index = hash(k, i);
  }
  catch(const std::exception& e) {
    throw tableOverflowException();
  }
  

  while (table[index]) {
    if (table[index]->key == k) {
      throw duplicateKeyException();
    }
    i++;
    try {
      index = hash(k, i);
    }
    catch(const std::exception& e) {
      throw tableOverflowException();
    }
  }

  element *aux = new element();
  aux->key = k;
  aux->value = v;

  table[index] = aux;
};

std::string hashTable::search(int k) {
  int i = 0;
  int index = hash(k, i);
  try {
    while (table[index]) {
      if (k == table[index]->key) {
        return table[index]->value;
      }
      i++;
      index = hash(k, i);
    }
  }
  catch(const std::exception& e) {
    throw notFoundException();
  }
  throw notFoundException();
};

void hashTable::remove(int k) {
  int i = 0;
  int index = hash(k, i);
  try {
    while (table[index]) {
      if (k == table[index]->key) {
         delete table[index];
         table[index] = nullptr;

        int j = 1;
        int holeIndex = index;
        int next = (index + j) % HASH_SIZE;

        while (table[next]) {
          if (hash(table[next]->key, 0) <= holeIndex) {
            if (next > holeIndex  || (hash(table[next]->key, 0) > next)) {
              table[holeIndex] = table[next];
              holeIndex = next;
              table[holeIndex] = nullptr;
            }
          }
          j++;
          next = (index + j) % HASH_SIZE;
        }
        return;
      }
      i++;
      index = hash(k, i);
    }
  }
  catch(const std::exception& e) {
    throw notFoundException();
  }
  throw notFoundException();
};
