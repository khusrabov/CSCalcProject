#ifndef REQUEST_HANDLER
#define REQUEST_HANDLER

#include <iostream>
#include <vector>

#include "MemManager.hpp"

// Constants for input_state
const int entering_int_part = 1;
const int entering_fract_part = 2;
const int entering_exp_part = 3;
const int showing_res = 4;

class RequestHandler {
 public:
  RequestHandler();

  std::string HandleReq(int ID);

  void Turn();

  void Cx();

  void PPress();

  void XPowY();

  void SwapXY();

  void ArrowUp();

  void Mult();

  void Plus();

  void Minus();

  void Delen();

  void Negative();

  void VP();

  void FPress();

  void NumPress(int ID);

  void Dot();

 private:
  MemManager mem;
  std::vector<void (RequestHandler::*)()> funcs = {
      &RequestHandler::Turn,   &RequestHandler::Cx,
      &RequestHandler::PPress, &RequestHandler::XPowY,
      &RequestHandler::SwapXY, &RequestHandler::ArrowUp,
      &RequestHandler::Mult,   &RequestHandler::Plus,
      &RequestHandler::Delen,  &RequestHandler::Minus,
      &RequestHandler::Dot,    &RequestHandler::Negative,
      &RequestHandler::VP,     &RequestHandler::FPress};

  // digs_entered stores current ammount of digits
  // that have been entered. Maximum possible value
  // is 8.
  size_t digs_entered;
  
  bool powered_on;
  bool p_pressed;
  bool f_pressed;
  bool error_happened;
  int input_state;
};

#endif
