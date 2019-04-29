// 外卖派单模拟系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Model.h"

//对，这两个是段淋的
void input(Model &m);
void output(Model &m);

int main() { 
	Model m({1, 2});
  while (m.statu() == GOOD) {
    input(m);
    m.step();
    output(m);
  }
}

void input(Model &m) {}

void output(Model &m) {}
