#pragma once
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "model.h"
#include "point.h"
class OutputServer {
 public:
  std::ofstream OutFile;

  OutputServer();
  ~OutputServer();
  void PrintToConsole(const Model &m);  //打印到控制台
  void PrintToFile(const Model &m);     //打印到文件
  void PrintToScreen();                 //打印欢迎界面
 private:
  void gotoxy(short x, short y);
};
