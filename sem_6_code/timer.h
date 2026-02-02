#pragma once

class Minutes {
private:
  int value_;

public:
  explicit Minutes(int minutes);

  int getValue() const;
};

class Seconds {
private:
  int value_;

public:
  explicit Seconds(int seconds);

  int getValue() const;
};

void setTimer(Minutes m);
