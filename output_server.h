#pragma once
#include <windows.h> 
#include <fstream>
#include "model.h"
#include "point.h"
class OutputServer {
 public:
  std::ofstream OutFile;

  OutputServer();
  ~OutputServer();
  void PrintToConsole(const Model &m);
  void PrintToFile(const Model &m);

 private:
  void gotoxy(int x,int y);
};
