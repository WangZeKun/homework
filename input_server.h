#pragma once
#include <fstream>
#include <queue>
#include "model.h"
#include "order.h"
#include "point.h"
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
