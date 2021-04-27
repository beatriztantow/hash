#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>
#define HASH_SIZE 7


struct element {
  int key;
  std::string value;
};

class hashTable {
  private:
    element *table[HASH_SIZE] = {};
    int hash(int k, int i);

  public:
    hashTable();
    void insert(int k, std::string v);
    void update(int k, std::string v);
    std::string search(int k);
    void remove(int k);
};

#endif