// 外卖派单模拟系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Model.h"
#include "InputServer.h"
#include "OutputServer.h"
#include <io.h>
#include <fcntl.h>



int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
  InputServer in;
  OutputServer out;
  Model m = Model(Point(1, 2));
  out.PrintToScreen();
  if (!in.InFile) {
    std::wcout << L"没有找到文件, 使用手动输入模式" << std::endl;
    in.inputFromConsole();
  } else {
    in.inputFromFile();
  }
  while (m.statu() == GOOD) {
    in.inputData(m);
    m.step();
    out.PrintToConsole(m);
    out.PrintToFile(m);
  }
}
