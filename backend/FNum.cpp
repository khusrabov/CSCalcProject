#include "FNum.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// Right Strip: removes extra '0' chars from the right side of a string
std::string RStrip(const std::string& inpt) {
  auto start_it = inpt.begin();
  auto end_it = inpt.rbegin();
  while (*end_it == '0') ++end_it;
  return std::string(start_it, end_it.base());
}

bool CmpF(double A, double B, double epsilon) {
  return (std::fabs(A - B) < epsilon);
}

FNum::FNum() : int_part("0"), pow("00"), num(0){};

FNum::FNum(double fl) {
  num = fl;
  ComputeStrings();
}

FNum& FNum::operator=(const FNum& other) {
  int_part = other.int_part;
  fract_part = other.fract_part;
  pow = other.pow;
  num = other.num;

  return *this;
}

void FNum::ComputeDouble() {
  std::string floatString = int_part + "." + fract_part + "e" + pow;
  num = std::stod(floatString);
}

void FNum::ComputeStrings() {
  // Compare num with zero
  if (CmpF(num, 0.0f)) {
    int_part = "0";
    fract_part = "";
    pow = "";
    return;
  }

  // If num is not zero => put it into string stream
  // in order to get a num's representation using string
  std::ostringstream oss;
  oss.precision(100);
  oss << std::fixed << num;  // use fixed-point notation with 100 decimal places
  std::string str = oss.str();

  // Check if num is negative
  if (num < 0) {
    str = str.substr(1, str.length() - 1);
  }

  // Search for '.' char: separator of integer and fractal parts
  size_t dot_pos = str.find('.');
  size_t first_dig_pos = str.find_first_not_of(".0");
  int int_part_len = dot_pos - static_cast<int>(first_dig_pos);

  // Compute proper representation
  if (int_part_len >= 0 && int_part_len <= 8) {
    int_part = str.substr(first_dig_pos, int_part_len);
    fract_part = RStrip(str.substr(dot_pos + 1, 8 - 1 - int_part_len));
    pow = "";
  } else {
    pow = std::to_string(int_part_len > 8 ? int_part_len - 1 : int_part_len);
    int_part = str.substr(first_dig_pos, 1);
    fract_part = RStrip(str.substr(first_dig_pos + 1, 6));
  }

  // Add '-' if num is negative
  if (num < 0) {
    int_part = '-' + int_part;
  }
}

std::string FNum::GetString() {
  std::ostringstream oss;
  oss << std::setfill(' ') << std::left << std::setw(10)
      << int_part + "." + fract_part;
  oss << pow;
  return oss.str();
}

double& FNum::GetDouble() { return num; }

double FNum::GetDouble() const { return num; }

void FNum::AddToInt(char dig) {
  if (int_part == "0") {
    if (dig == '0') {
      return;
    }
    int_part = dig;
  } else {
    int_part += dig;
  }
  ComputeDouble();
}

void FNum::AddToFract(char dig) {
  fract_part += dig;
  ComputeDouble();
}

void FNum::AddToPow(char dig) {
  if (pow.length() == 2) {
    pow = pow.substr(1, 1);
  }
  pow += dig;
  ComputeDouble();
}

void FNum::ChangeIntSign() {
  if (int_part[0] == '-') {
    int_part = int_part.substr(1, int_part.length() - 1);
  } else {
    int_part = "-" + int_part;
  }
  ComputeDouble();
}

void FNum::ChangePowSign() {
  if (pow[0] == '-') {
    pow = pow.substr(1, pow.length() - 1);
  } else {
    pow = "-" + pow;
  }
  ComputeDouble();
}

void swap(FNum& lhs, FNum& rhs) {
  FNum temp(lhs);
  lhs = rhs;
  rhs = temp;
}

bool operator>=(const FNum& lhs, const FNum& rhs) {
  return lhs.GetDouble() >= rhs.GetDouble();
}

bool operator<(const FNum& lhs, const FNum& rhs) {
  return lhs.GetDouble() < rhs.GetDouble();
}

bool operator==(const FNum& lhs, const FNum& rhs);

bool operator!=(const FNum& lhs, const FNum& rhs);

FNum operator+(const FNum& lhs, const FNum& rhs) {
  FNum res(lhs.GetDouble() + rhs.GetDouble());
  return res;
}

FNum operator-(const FNum& lhs, const FNum& rhs) {
  FNum res(lhs.GetDouble() - rhs.GetDouble());
  return res;
}

FNum operator*(const FNum& lhs, const FNum& rhs) {
  FNum res(lhs.GetDouble() * rhs.GetDouble());
  return res;
}

FNum operator/(const FNum& lhs, const FNum& rhs) {
  FNum res(lhs.GetDouble() / rhs.GetDouble());
  return res;
}