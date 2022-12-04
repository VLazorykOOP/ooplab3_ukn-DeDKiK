// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>

// Ваші файли загловки 
//
#include "Lab3Expaple.h"
int main()
{
    std::cout << " Lab #3  !\n";
//  Код виконання завдань
//  Головне меню завдань
//  Функції та класи можуть знаходитись в інших файлах проекту

    int conv = 1;
    if (conv == 1) conv = mainExample1();
    if (conv == 1) conv = mainExample3(); 
    if (conv == 1) conv = mainExample4();

}


#include "time.h"
#include <iostream>

int Time::getHour() const { return hour; }

void Time::setHour(int newHour) {
  if (newHour >= 0 && newHour <= 23)
    hour = newHour;
}

int Time::getMin() const { return min; }

void Time::setMin(int newMin) {
  if (newMin >= 0 && newMin <= 59)
    min = newMin;
}

int Time::getSec() const { return sec; }

void Time::setSec(int newSec) {
  if (newSec >= 0 && newSec <= 59)
    sec = newSec;
}

void Time::print24() {
  std::cout << hour << " годин " << min << " хвилин " << sec << " секунд"
            << std::endl;
}

void Time::print12() {
  if (hour >= 0 && hour <= 12)
    std::cout << hour << " a.m. ";
  else
    std::cout << hour - 12  << " p.m ";
  std::cout << min << " хвилин " << sec << " секунд" << std::endl;
}

Time::Time() {
  hour = 0;
  min = 0;
  sec = 0;
}

Time::Time(int h, int m, int s) {
  hour = h;
  min = m;
  sec = s;
}

#include "matrix.h"
#include <iostream>

int matrix::count = 0;

matrix::matrix() {
  N = 2;
  M = 2;
  arr = new float *[N];
  for (unsigned int i = 0; i < N; i++) {
    arr[i] = new float[M];
  }
  for (unsigned int i = 0; i < N; i++) {
    for (unsigned int z = 0; z < M; z++) {
      arr[i][z] = 0;
    }
  }
  stan = 0;
  count++;
}

matrix::~matrix() {
  for (unsigned int i = 0; i < N; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  count--;
}

matrix::matrix(const unsigned int N_) {
  N = N_;
  M = N_;
  arr = new float *[N];
  for (unsigned int i = 0; i < N; i++) {
    arr[i] = new float[M];
  }
  for (unsigned int i = 0; i < N; i++) {
    for (unsigned int z = 0; z < M; z++) {
      arr[i][z] = 0;
    }
  }
  stan = 0;
  count++;
}

matrix::matrix(unsigned int N_, unsigned int M_, float value) {
  N = N_;
  M = M_;
  arr = new float *[N];
  for (unsigned int i = 0; i < N; i++) {
    arr[i] = new float[M];
  }
  for (unsigned int i = 0; i < N; i++) {
    for (unsigned int z = 0; z < M; z++) {
      arr[i][z] = value;
    }
  }
  stan = 0;
  count++;
}

matrix::matrix(const matrix &input) {

  if (this != &input) {
    N = input.N;
    M = input.M;
    arr = new float *[N];
    for (unsigned int i = 0; i < N; i++) {
      arr[i] = new float[M];
    }
    for (unsigned int i = 0; i < N; i++) {
      for (unsigned int z = 0; z < M; z++) {
        arr[i][z] = input.arr[i][z];
      }
    }
  }
  stan = 0;
  count++;
}

matrix &matrix::operator=(const matrix &input) {
  if (this != &input) {
    N = input.N;
    M = input.M;
    arr = new float *[N];
    for (unsigned int i = 0; i < N; i++) {
      arr[i] = new float[M];
    }
    for (unsigned int i = 0; i < N; i++) {
      for (unsigned int z = 0; z < M; z++) {
        arr[i][z] = input.arr[i][z];
      }
    }
  }
  stan = 0;
  count++;
  return *this;
}

void matrix::setElem(unsigned int i, unsigned int j, float value) {
  arr[i][j] = value;
}

float matrix::getElem(unsigned int i, unsigned int j) { return arr[i][j]; }

matrix matrix::operator+(const matrix &b) const {
  unsigned int n = N <= b.N ? N : b.N;
  unsigned int m = M <= b.M ? M : b.M;
  matrix res(n, m, 0);
  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int z = 0; z < m; z++) {
      res.setElem(i, z, arr[i][z] + b.arr[i][z]);
    }
  }
  return res;
}

matrix matrix::operator-(const matrix &b) const {
  unsigned int n = N <= b.N ? N : b.N;
  unsigned int m = M <= b.M ? M : b.M;
  matrix res(n, m, 0);
  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int z = 0; z < m; z++) {
      res.setElem(i, z, arr[i][z] - b.arr[i][z]);
    }
  }
  return res;
}

matrix matrix::operator*(const matrix &b) const {
  if (N != b.M) {
    std::cout << "Matrices cannot be multiplied." << std::endl;
  }
  matrix res(N, b.M, 0);
  double sum = 0;
  for (unsigned int i = 0; i < N; i++) {
    for (unsigned int j = 0; j < M; j++) {
      for (unsigned int k = 0; k < b.M; k++) {
        sum += arr[i][k] * b.arr[k][j];
      }
      res.setElem(i, j, sum);
      sum = 0;
    }
  }
  return res;
}

matrix matrix::operator/(int num) const {
  matrix res(N, M, 0);
  if (num == 0) {
    std::cout << "Can't divide by 0!" << std::endl;
    return res;
  }

  for (unsigned int i = 0; i < N; i++) {
    for (unsigned int z = 0; z < M; z++) {
      res.setElem(i, z, arr[i][z] / num);
    }
  }
  return res;
}

bool matrix::operator>(const matrix &b) const {
  unsigned int n = N <= b.N ? N : b.N;
  unsigned int m = M <= b.M ? M : b.M;

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int z = 0; z < m; z++) {
      if (arr[i][z] <= b.arr[i][z]) {
        return false;
      }
    }
  }
  return true;
}

bool matrix::operator<(const matrix &b) const {
  unsigned int n = N <= b.N ? N : b.N;
  unsigned int m = M <= b.M ? M : b.M;

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int z = 0; z < m; z++) {
      if (arr[i][z] >= b.arr[i][z]) {
        return false;
      }
    }
  }
  return true;
}

bool matrix::operator!=(const matrix &b) const {
  unsigned int n = N <= b.N ? N : b.N;
  unsigned int m = M <= b.M ? M : b.M;

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int z = 0; z < m; z++) {
      if (arr[i][z] == b.arr[i][z]) {
        return false;
      }
    }
  }
  return true;
}

bool matrix::operator==(const matrix &b) const {
  unsigned int n = N <= b.N ? N : b.N;
  unsigned int m = M <= b.M ? M : b.M;

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int z = 0; z < m; z++) {
      if (arr[i][z] != b.arr[i][z]) {
        return false;
      }
    }
  }
  return true;
}

std::ostream &operator<<(std::ostream &os, const matrix &inp) {
  for (unsigned int i = 0; i < inp.N; i++, os << std::endl) {
    for (unsigned int z = 0; z < inp.M; z++) {
      os << inp.arr[i][z] << " ";
    }
  }
  return os;
}

#include "vector.h"
#include <iostream>
#include <math.h>

Vector::Vector() {
  arr = new float[1];
  arr[0] = 0;
  stan = 0;
  N = 1;
}

Vector::~Vector() {
  if (arr)
    delete[] arr;
}

Vector::Vector(int N_) {
  if (N_ <= 0) {
    arr = NULL;
    N = 0;
    stan = -1;
    std::cout << "Error. N <=0. Stan is -1." << std::endl;
  } else {
    arr = new float[N_];
    for (int i = 0; i < N_; i++) {
      arr[i] = 0;
    }
    stan = 0;
    N = N_;
  }
}

Vector::Vector(int N_, float znach) {
  if (N_ <= 0) {
    arr = NULL;
    N = 0;
    stan = -1;
    std::cout << "Error. N <=0. Stan is -1." << std::endl;
  } else {
    arr = new float[N_];
    for (int i = 0; i < N_; i++) {
      arr[i] = znach;
    }
    stan = 0;
    N = N_;
  }
}

Vector::Vector(const Vector &input) {
  if (this != &input) {
    N = input.N;
    arr = new float[N];
    stan = 0;
    for (unsigned int i = 0; i < N; i++)
      arr[i] = input.arr[i];
  }
}

Vector &Vector::operator=(const Vector &vect) {
  if (N != vect.N) {
    if (arr)
      delete[] arr;
    N = vect.N;
    arr = new float[N];
    stan = 0;
  }
  for (unsigned int i = 0; i < N; i++)
    arr[i] = vect.arr[i];
  return *this;
}

void Vector::changeElemInPos(unsigned int position, float number) {
  if (arr) {
    if (position <= N) {
      arr[position] = number;
    } else
      std::cout << "Error: N > positions in array." << std::endl;
  }
}

void Vector::printElemInPos(unsigned int pos) { std::cout << arr[pos]; }

std::ostream &operator<<(std::ostream &os, const Vector &inp) {
  for (unsigned int i = 0; i < inp.N; i++) {
    os << inp.arr[i] << " ";
  }
  return os;
}

Vector Vector::operator+(const Vector &b) const {
  int resN;
  resN = N < b.N ? N : b.N;
  if (resN >= 0) {
    Vector result(resN);
    for (int i = 0; i < resN; i++) {
      result.arr[i] = arr[i] + b.arr[i];
    }
    return result;
  }
  return Vector(0);
}

Vector Vector::operator-(const Vector &b) const {
  int resN;
  resN = N < b.N ? N : b.N;
  if (resN >= 0) {
    Vector result(resN);
    for (int i = 0; i < resN; i++) {
      if (arr[i] - b.arr[i] <= 0)
        result.arr[i] = 0;
      else
        result.arr[i] = arr[i] - b.arr[i];
    }
    return result;
  }
  return Vector(0);
}

Vector Vector::operator*(unsigned int num) const {
  Vector result(N);
  for (unsigned int i = 0; i < N; i++) {
    result.arr[i] = arr[i] * num;
  }
  return result;
}

bool Vector::operator>(const Vector &b) const {
  for (unsigned int i = 0; i < N; i++) {
    if (arr[i] <= b.arr[i])
      return false;
  }
  return true;
}

bool Vector::operator<(const Vector &b) const {
  for (unsigned int i = 0; i < N; i++) {
    if (arr[i] >= b.arr[i])
      return false;
  }
  return true;
}

bool Vector::operator!=(const Vector &b) const {
  for (unsigned int i = 0; i < N; i++) {
    if (arr[i] == b.arr[i])
      return false;
  }
  return true;
}

bool Vector::operator==(const Vector &b) const {
  for (unsigned int i = 0; i < N; i++) {
    if (arr[i] != b.arr[i])
      return false;
  }
  return true;
}
