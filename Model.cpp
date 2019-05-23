#include "model.h"

Model::Model(Point init_position)
    : init_position_(init_position), statu_(GOOD),time_(0) {}

unsigned Model::num_outdate() const {
  int outdate = 0;  //��ʱ������
  for (int i = 0; i < riders.size(); i++) {
    outdate = outdate + riders[i].outdate_orders();
  }  //�����������֣�ͳ�Ƴ�ʱ������
  return outdate;
}

unsigned Model::money() const {
  int total = 1000 - riders.size() * 300;  //��ǰ��Ǯ��
  for (int i = 0; i < riders.size(); i++) {
    total = total + 10 * riders[i].finished_orders();
    total = total - 50 * riders[i].outdate_orders();
  }  //�����������֣�ͳ�Ƶ�ǰ��Ǯ��
  return total;
}

unsigned Model::time() const { return time_; }

ProgramStatus Model::statu() const { return statu_; }

void Model::AddRider() { riders.push_back(Rider(init_position_)); }

void Model::CheckIsBreak() {
  if (statu_ != GOOD) {
    return;
  }
  if (money() < 0) {
    statu_ = BREAK;
  }  //��Ǯ��С����ʱ�Ʋ�
}

void Model::CheckIsRevoke() {
  if (statu_ != GOOD) {
    return;
  }
  for (int i = 0; i < riders.size(); i++)
    if (riders[i].illegal_orders() != 0) statu_ = REVOKE;
}

void Model::CheckIsFinished() {
  if (statu_ != GOOD) {
    return;
  }

  int flag = 0;  //��ǵ�ǰ״̬�ı�������flag==0ʱ���ӵ����ɵ�����Ϊ�㣬�������
  for (int i = 0; i < riders.size(); i++) {
    if (riders[i].received_orders().size() != 0 ||
        riders[i].sending_orders().size() != 0) {
      flag = 1;
    }
  }
  if (flag == 0) {
    statu_ = FINISHED;
  }
}

void Model::AddOrder(Order o) {
  Order NewOrder = o;
  waiting_order.push(NewOrder);
}

void Model::Step() {
  statu_ = GOOD; // ��ʼ��statu_

  while (!waiting_order.empty()) {
    std::queue<Point> path;
    int index = -1, min = INT_MAX, cost = 100;
    for (auto i = 0; i < riders.size(); i++) {
      if (riders[i].sending_orders().size() + riders[i].received_orders().size() * 2 >
          18)
        continue;
      auto [path_tmp, cost_tmp] =
          Algorithm::cal_solution(riders[i], waiting_order.front(), time_);
      if (cost_tmp - riders[i].all_cost() < min) {
        path = path_tmp, cost = cost_tmp, index = i,
        min = cost - riders[i].all_cost();
      } else if (cost_tmp - riders[i].all_cost() == min &&
                 (cost_tmp < cost ||
                  (cost_tmp == cost && path_tmp.size() < path.size()))) {
        path = path_tmp, cost = cost_tmp, index = i;
      }
    }
    if (cost > 60 && money() >= 300) {
      AddRider();
      auto [path_tmp, cost_tmp] = Algorithm::cal_solution(
          riders[riders.size() - 1], waiting_order.front(), time_);
      riders[riders.size() - 1].ChangePath(path_tmp, cost_tmp);
      riders[riders.size() - 1].received_orders.insert(waiting_order.front());
    } else {
      riders[index].ChangePath(path, cost);
      riders[index].received_orders.insert(waiting_order.front());
    }
    // waiting_order.erase(waiting_order.begin());
    waiting_order.pop();
  }
  for (auto i = 0; i < riders.size(); i++) {
    riders[i].Step(time_);
  }
  time_++;
  CheckIsBreak();
  CheckIsRevoke();
  CheckIsFinished();
}

unsigned Model::num_sending() const {
  int sending = 0;  //���������
  for (int i = 0; i < riders.size(); i++) {
    sending += riders[i].sending_orders().size();
    sending += riders[i].received_orders().size();
  }  //�����������֣�ͳ����ɵĶ�����
  return sending;
}

unsigned Model::num_finished() const {
  int finished = 0;  //���������
  for (int i = 0; i < riders.size(); i++) {
    finished = finished + riders[i].finished_orders();
  }  //�����������֣�ͳ����ɵĶ�����
  return finished;
}
