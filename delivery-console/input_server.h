#pragma once
#include <fstream>
#include <queue>
#include "../delivery-model/model.h"
#include "../delivery-model/order.h"
#include "../delivery-model/point.h"


//读取订单，并添加入队列
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
