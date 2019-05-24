#pragma once
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "model.h"
#include "point.h" 


static const char* BLANK = "                ";
//����������н��
class OutputServer {
 public:
  std::ofstream OutFile;

  OutputServer();
  ~OutputServer();
  void PrintToConsole(const Model &m);  //��ӡ������̨
  void PrintToFile(const Model &m);     //��ӡ���ļ�
  void PrintToScreen();                 //��ӡ��ӭ����
 private:
  void gotoxy(short x, short y);
};

