#include "InputServer.h"

InputServer::InputServer() {}

void InputServer::inputFromConsole(Model &m) {
  while (q.front().time == m.now()) {
    m.add_order(q.front());//��Ӧʱ��ӵ�
    q.pop();//ɾ��
  }
}
void InputServer::inputData() {
  int n, time;//������ţ��µ�ʱ��
  int x1,y1,x2,y2;//����͹ݣ�ʳ������
  if ((FILE *fp = fopen("sales.txt", "r")) == NULL) printf("File could not be opened\n");
  //�ļ����ܱ���
  else {
    while (getchar() == EOF) {
      fscanf(fp, "%d%d", &n, &time);
      fscanf(fp, "%d%d", &x1, &y1);
      fscanf(fp, "%d%d", &x2, &y2);
      Order tempOrder = Order(n, Point(x1, y1), Point(x2, y2), time);
      q.push(tempOrder);  //���
    }//��ȡ��������
  }
}
InputServer::~InputServer() {}
