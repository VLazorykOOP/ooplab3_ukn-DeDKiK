#ifndef TIME_H
#define TIME_H

class Time {
private:
  int hour;
  int min;
  int sec;

public:
  Time();
  Time(int h, int m, int s);

  int getHour() const;
  void setHour(int newHour);
  int getMin() const;
  void setMin(int newMin);
  int getSec() const;
  void setSec(int newSec);

  void print24();
  void print12();
};

#endif // TIME_H