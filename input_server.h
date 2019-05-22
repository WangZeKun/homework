#pragma once
#include <queue>
#include "model.h"
#include "order.h"
#include "point.h"
class InputServer {
 public:
  InputServer();
  void InputFromConsole(Model &m);
  void InputData();
  ~InputServer();
  std::queue<Order> q;
};
