#pragma once
#include <queue>
#include "Model.h"
#include "Order.h"
#include "Point.h"
class InputServer {
 public:
  InputServer();
  void inputFromConsole(Model &m);
  void inputData();
  ~InputServer();
  std::queue<Order> q;
};
