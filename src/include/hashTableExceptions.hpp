#ifndef HASHTABLEEXCEPTIONS_H
#define HASHTABLEEXCEPTIONS_H

#include <exception>

class duplicateKeyException : public std::exception {
  public:
    const char * what () const throw () {
      return "Esta chave já foi inserida.\n";
    };
};

class tableTotallyVisitedException : public std::exception {
  public:
    const char * what () const throw () {
      return "A tabela de dispersao foi totalmente visitada e a operação não foi concluída.\n";
    };
};

class notFoundException : public std::exception {
  public:
    const char * what () const throw () {
      return "Esta chave nao foi encontrada.\n";
    };
};

class tableOverflowException : public std::exception {
  public:
    const char * what () const throw () {
      return "A tabela de dispersao esta cheia.\n";
    };
};

#endif