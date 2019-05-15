#pragma once
#include <cstdlib>
#include <fstream>
#include "Model.h"
#include "Point.h"
class OutputServer {
 public:
  std::ofstream OutFile;

  OutputServer();
  ~OutputServer();
  void PrintToConsole(const Model &m);
  void PrintToFile(const Model &m);
};
