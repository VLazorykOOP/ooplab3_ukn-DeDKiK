#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class matrix {

private:
  float **arr;
  unsigned int N;
  unsigned int M;
  short stan;

public:
  static int count;
  matrix();
  ~matrix();
  matrix(const unsigned int N_);
  matrix(unsigned int N_, unsigned int M_, float value);
  matrix(const matrix &input);
  matrix &operator=(const matrix &vect);
  unsigned int getN() { return N; };
  unsigned int getM() { return M; };
  void setElem(unsigned int i, unsigned int j, float value = 0);
  float getElem(unsigned int i, unsigned int j);
  matrix operator+(const matrix &b) const;
  matrix operator-(const matrix &b) const;
  matrix operator*(const matrix &b) const;
  matrix operator/(int num) const;
  bool operator>(const matrix &b) const;
  bool operator<(const matrix &b) const;
  bool operator!=(const matrix &b) const;
  bool operator==(const matrix &b) const;
  void setStan(short stan_);
  friend std::ostream &operator<<(std::ostream &os, const matrix &inp);
};

#endif // MATRIX_H