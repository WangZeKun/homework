#pragma once
#include <windows.h> 
#include <fstream>
#include <cstdlib>
#include "Model.h"
#include "Point.h" 
class OutputServer {
 public:
  std::ofstream OutFile;

  OutputServer();
  ~OutputServer();
  void PrintToConsole(const Model &m); //��ӡ������̨
  void PrintToFile(const Model &m); //��ӡ���ļ�
  void PrintToScreen(); //��ӡ��ӭ����
 private:
  void optimizationConsole();
};
