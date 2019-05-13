#pragma once
#include "Model.h"
#include"Point.h"
class OutputServer {
 public:
  OutputServer();
  ~OutputServer();
  static PrintToConsole(const Model &m);
};
