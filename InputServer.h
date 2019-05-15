#pragma once
#include <queue>
#include <fstream>
#include "Model.h"
#include "Order.h"
#include "Point.h"
class InputServer {
 public:
  std::ifstream InFile;
  std::queue<Order> q;

  InputServer();
  ~InputServer();

  void inputFromConsole();
  void inputFromFile();
  void inputData(Model &m);
};
