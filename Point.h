#pragma once
#include<cmath>
enum PointType {
	FROM, //�͹�
	TO, //ʳ��
};
//������Point
class Point {
 public:
  // x����
  int x;

  // y����
  int y;

  //�������
  PointType type;

  //����Ӧ�Ķ���id
  unsigned order_id;

  Point();
  Point(int x, int y);
  Point(int x, int y, PointType type, unsigned order_id);
  ~Point();

  //������������پ���
  static int GetDistant(const Point& from, const Point& to);

	//�ж��Ƿ񵽴�
	//����
	//		Point position ��ǰλ��
	//    Point destination Ŀ��λ��
	//���
	//		�Ƿ񵽴�
  static bool IsArrive(const Point& position, const Point& destination);

	//������һ�����ߵ�λ��
	//����
	//    Point position ��ǰλ��
	//    Point destination Ŀ��λ��
	//���
	//    Point  �ƶ�����һ���������
  static Point Move(const Point& position, const Point& destination);

	//����������
  bool operator==(const Point& b) const;
  bool operator<(const Point& p) const;
  bool operator>(const Point& p) const;
};
