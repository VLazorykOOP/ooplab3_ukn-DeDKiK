#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector {
private:
  float *arr;
  unsigned int N;
  short int stan;

public:
  Vector();
  ~Vector();
  Vector(int N);
  Vector(int N, float zhach);
  Vector(const Vector &input);
  Vector &operator=(const Vector &vect);
  void changeElemInPos(unsigned int position, float number = 0);
  void printElemInPos(unsigned int pos);
  friend std::ostream &operator<<(std::ostream &os, const Vector &sq);
  Vector operator+(const Vector &b) const;
  Vector operator-(const Vector &b) const;
  Vector operator*(unsigned int num) const;
  bool operator>(const Vector &b) const;
  bool operator<(const Vector &b) const;
  bool operator!=(const Vector &b) const;
  bool operator==(const Vector &b) const;
};

#endif // VECTOR_H