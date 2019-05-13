#include "InputServer.h"

InputServer::InputServer() {}

void InputServer::inputFromConsole(Model &m) {
  while (q.front().time == m.now()) {
    m.add_order(q.front());//对应时间接单
    q.pop();//删除
  }
}
void InputServer::inputData() {
  int n, time;//定义序号，下单时间
  int x1,y1,x2,y2;//定义餐馆，食客坐标
  if ((FILE *fp = fopen("sales.txt", "r")) == NULL) printf("File could not be opened\n");
  //文件不能被打开
  else {
    while (getchar() == EOF) {
      fscanf(fp, "%d%d", &n, &time);
      fscanf(fp, "%d%d", &x1, &y1);
      fscanf(fp, "%d%d", &x2, &y2);
      Order tempOrder = Order(n, Point(x1, y1), Point(x2, y2), time);
      q.push(tempOrder);  //入队
    }//读取所有数据
  }
}
InputServer::~InputServer() {}
