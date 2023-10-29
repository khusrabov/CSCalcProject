#include "RequestHandler.hpp"

#include <cmath>
#include <iostream>

std::string StringForOffState() {
  std::string str = "--------";
  for (int i = 0; i < 14; ++i) {
    str = str.append("/--------");
  }

  return str;
}

RequestHandler::RequestHandler()
    : powered_on(false),
      p_pressed(false),
      f_pressed(false),
      error_happened(false),
      digs_entered(0),
      input_state(entering_int_part) {}

std::string RequestHandler::HandleReq(int ID) {
  if (ID < 10) {
    NumPress(ID);
  } else if ((error_happened && ID < 12) || !error_happened) {
    ((*this).*(funcs[ID - 10]))();
  }

  if (!powered_on) {
    return StringForOffState();
  }

  std::string res;
  for (int i = 0; i < 8; ++i) {
    res += mem.RegAt(i).GetString() + "/";
  }
  for (int i = 1; i < 7; ++i) {
    res += mem.StackAt(i).GetString() + "/";
  }

  if (error_happened) {
    size_t pos = res.find("/");
    res = res.substr(pos, res.length() - pos);
    res = "peregrev" + res;
  }

  return res;
}

void RequestHandler::Turn() {
  powered_on = !powered_on;
  Cx();
  mem.ClearAll();
}

void RequestHandler::Cx() {
  mem.ClearX();
  p_pressed = false;
  f_pressed = false;
  digs_entered = 0;
  input_state = entering_int_part;
  if (error_happened) {
    error_happened = false;
  }
}

void RequestHandler::PPress() { p_pressed = !p_pressed; }

void RequestHandler::XPowY() {
  if (!p_pressed) {
    mem.RegAt(0) = std::pow(mem.RegAt(0).GetDouble(), mem.RegAt(1).GetDouble());
    input_state = showing_res;
  }
}

void RequestHandler::SwapXY() {
  if (!p_pressed) {
    swap(mem.RegAt(0), mem.RegAt(1));
  } else {
    mem.RegAt(0) = std::log(mem.RegAt(0).GetDouble());
    p_pressed = !p_pressed;
  }
  digs_entered = 8;
  input_state = showing_res;
}

void RequestHandler::ArrowUp() {
  if (!p_pressed) {
    mem.RegAt(1) = mem.RegAt(0);
    digs_entered = 0;
    input_state = showing_res;
  }
}

void RequestHandler::Mult() {
  if (p_pressed) {
    mem.RegAt(0) = M_PI;
    digs_entered = 8;
    p_pressed = !p_pressed;
  } else {
    mem.RegAt(0) = mem.RegAt(0) * mem.RegAt(1);
    digs_entered = 8;
  }
  input_state = showing_res;
}

void RequestHandler::Plus() {
  if (p_pressed) {
    mem.RegAt(0) = std::sin(mem.RegAt(0).GetDouble());
    p_pressed = !p_pressed;
  } else {
    mem.RegAt(0) = mem.RegAt(0) + mem.RegAt(1);
  }
  digs_entered = 8;
  input_state = showing_res;
}

void RequestHandler::Minus() {
  if (p_pressed) {
    mem.RegAt(0) = std::cos(mem.RegAt(0).GetDouble());
    p_pressed = !p_pressed;
  } else {
    mem.RegAt(0) = mem.RegAt(1) - mem.RegAt(0);
  }
  digs_entered = 8;
  input_state = showing_res;
}

void RequestHandler::Delen() {
  if (p_pressed) {
    mem.RegAt(0) = std::exp(mem.RegAt(0).GetDouble());
    p_pressed = !p_pressed;
  } else {
    if (CmpF(mem.RegAt(0).GetDouble(), 0.0f)) {
      std::cout << "hello!\n";
      error_happened = true;
    } else {
      mem.RegAt(0) = mem.RegAt(1) / mem.RegAt(0);
    }
  }
  digs_entered = 8;
  input_state = showing_res;
}

void RequestHandler::Negative() {
  if (f_pressed) {
    mem.RegAt(0) = mem.RegAt(0) * mem.RegAt(0);
    f_pressed = !f_pressed;
    digs_entered = 8;
    input_state = showing_res;
  } else if (p_pressed) {
    mem.RotateRight();
    p_pressed = !p_pressed;
    input_state = showing_res;
  } else if (input_state == entering_int_part ||
             input_state == entering_fract_part || input_state == showing_res) {
    mem.RegAt(0).ChangeIntSign();
  } else {
    mem.RegAt(0).ChangePowSign();
  }
}

void RequestHandler::Dot() {
  if (f_pressed) {
    if (CmpF(mem.RegAt(0).GetDouble(), 0.0f)) {
      error_happened = true;
      Cx();
    } else {
      mem.RegAt(0) = FNum(1 / mem.RegAt(0).GetDouble());
    }
    f_pressed = !f_pressed;
    digs_entered = 8;
    input_state = showing_res;
  } else if (p_pressed) {
    mem.RotateLeft();
    p_pressed = !p_pressed;
    input_state = showing_res;
  } else if (input_state == entering_int_part) {
    input_state = entering_fract_part;
    ++digs_entered;
  }
}

void RequestHandler::VP() {
  if (f_pressed) {
    if (mem.RegAt(0).GetDouble() < 0) {
      error_happened = true;
    }
    mem.RegAt(0) = std::sqrt(mem.RegAt(0).GetDouble());
    f_pressed = !f_pressed;
    digs_entered = 8;
    input_state = showing_res;
  } else {
    input_state = entering_exp_part;
  }
}

void RequestHandler::FPress() { f_pressed = !f_pressed; }

void RequestHandler::NumPress(int ID) {
  if (error_happened) { error_happened = false; }
  if (f_pressed) {
    if (ID >= 2 && ID <= 7) {
      mem.RegAt(0) = mem.RegAt(ID);
      digs_entered = 8;
      input_state = showing_res;
    }
    f_pressed = !f_pressed;
    return;
  }
  if (p_pressed) {
    if (ID >= 2 && ID <= 7) {
      mem.RegAt(ID) = mem.RegAt(0);
      digs_entered = 0;
      input_state = showing_res;
    }
    p_pressed = !p_pressed;
    return;
  }

  if (input_state == showing_res) {
    mem.RegAt(0) = 0.0f;
    input_state = entering_int_part;
    digs_entered = 0;
  }

  if (digs_entered >= 8 && input_state != entering_exp_part) {
    return;
  }
  switch (input_state) {
    case entering_int_part:
      mem.RegAt(0).AddToInt('0' + ID);
      ++digs_entered;
      break;
    case entering_fract_part:
      mem.RegAt(0).AddToFract('0' + ID);
      ++digs_entered;
      break;
    case entering_exp_part:
      mem.RegAt(0).AddToPow('0' + ID);
      break;
    default:
      break;
  }
}
