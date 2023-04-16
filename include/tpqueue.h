// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
#define M 100

template<typename T, int size>
class TPQueue {
 private:
    T arr[M];
    int first, last, count;

 public:
    TPQueue() {
      first = 0;
      last = 0;
      count = 0;
    }
    bool isEmpty() const {
      if (count == 0)
      return true;
      else
      return false;
    }
    bool isFull() const {
      if (count == size)
      return true;
      else
      return false;
    }
    void push(const T& val) {
      if (isFull())
      throw std::string("Queue Full(");
      count++;
      int с = first, b = last;
      while (с != last && arr[с].prior >= val.prior)
        с = ++с % size;
      while (b != с) {
        arr[b] = arr[--b % size];
        b = (--b + size) % size;
      }
      last = ++last % size;
      arr[с] = val;
    }
    const T & pop() {
      if (isEmpty())
        throw std::string("Queue Empty((");
      count--;
      return arr[first++ % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
