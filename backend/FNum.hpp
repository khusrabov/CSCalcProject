#ifndef FNUM
#define FNUM

#include <string>

// Compares two floating point values
bool CmpF(double A, double B, double epsilon = 1e-99);

class FNum {
 public:
  FNum();

  FNum(double fl);

  FNum(const FNum& other) = default;

  FNum& operator=(const FNum& other);

  // Uses three strings to compute the num's value
  void ComputeDouble();

  // Uses num's value two compute three strings
  void ComputeStrings();

  std::string GetString();

  double& GetDouble();

  double GetDouble() const;

  // Add a char to the integer part of the variable
  void AddToInt(char dig);

  // Add a char to the fractal part of the variable
  void AddToFract(char dig);

  // Add a char to the exponent part of the variable
  void AddToPow(char dig);

  void ChangeIntSign();

  void ChangePowSign();

  friend void swap(FNum& lhs, FNum& rhs);

 private:
  // Stored number is represented using three strings
  std::string int_part;
  std::string fract_part;

  // pow contains exponent of a number
  std::string pow;

  // num contains stored number representation in double format
  double num;
};

bool operator>=(const FNum& lhs, const FNum& rhs);

bool operator<(const FNum& lhs, const FNum& rhs);

bool operator==(const FNum& lhs, const FNum& rhs);

bool operator!=(const FNum& lhs, const FNum& rhs);

FNum operator+(const FNum& lhs, const FNum& rhs);

FNum operator-(const FNum& lhs, const FNum& rhs);

FNum operator*(const FNum& lhs, const FNum& rhs);

FNum operator/(const FNum& lhs, const FNum& rhs);

#endif
