#include "output_server.h"

OutputServer::OutputServer() {
  OutFile = std::ofstream("./output.txt");

  CONSOLE_CURSOR_INFO cci;
  cci.bVisible = 0;
  cci.dwSize = sizeof(cci);
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

OutputServer::~OutputServer() {}
//欢迎界面
void OutputServer::EndPrint(const Model &m) { 
	std::wcout << L"程序运行结束！" << std::endl;
  if (m.statu() == FINISHED) {
    std::wcout << L"已完成所有订单！" << std::endl;
  } else if (m.statu() == BREAK) {
    std::wcout << L"已破产！" << std::endl;
  } else if (m.statu() == REVOKE) {
    std::wcout << L"已被吊销执照！" << std::endl;
  }

  std::wcout << std::endl;
  std::wcout << L"总金钱：" << m.money() + 300 * m.riders.size() << std::endl;
  std::wcout << L"总接单数：" << m.num_all() << std::endl;
  std::wcout << L"总完成数：" << m.num_finished() << std::endl;
  std::wcout << L"总超时数：" << m.num_outdate() << std::endl;

  std::wcout << std::endl;
  std::wcout << L"一共有" << m.riders.size() << L"个骑手" << std::endl;
  for (auto i = 0; i < m.riders.size(); i++) {
    std::wcout << L"骑手" << i << L":" << std::endl;
    std::wcout << L"接单数："
               << m.riders[i].finished_orders().size() +
                      m.riders[i].outdate_orders().size() +
                      m.riders[i].received_orders().size() +
                      m.riders[i].sending_orders().size()
               << std::endl;
    std::wcout << L"完成数：" << m.riders[i].finished_orders().size()
               << std::endl;
    std::wcout << L"超时数：" << m.riders[i].outdate_orders().size()
               << std::endl;
  }
}

void OutputServer::PrintToConsole(const Model &m) {
  //初始化地图
  std::vector<int> outdate_orders;   //当前时间的超时订单
  std::vector<int> finished_orders;  // 当前时间完成的订单
  int i, j, position[17][17] = {0};
  Point point;

  for (size_t i = 0; i < m.riders.size(); i++) {
    outdate_orders.insert(outdate_orders.end(),
                          m.riders[i].outdate_orders_now().begin(),
                          m.riders[i].outdate_orders_now().end());
    finished_orders.insert(finished_orders.end(),
                           m.riders[i].finished_orders_now().begin(),
                           m.riders[i].finished_orders_now().end());
  }

  for (i = 0; i < 17; i += 2) {
    for (j = 0; j < 17; j += 2) {
      position[i][j] = 1;
    }  //将每个坐标初始化，标记为1
  }
  //获取位置信息
  for (size_t i = 0; i < m.riders.size(); i++) {
    for (auto it = m.riders[i].received_orders().begin();
         it != m.riders[i].received_orders().end(); it++) {
      position[(*it).from.x][(*it).from.y] = 2;
      position[(*it).to.x][(*it).to.y] = 3;
    }
    for (auto it = m.riders[i].sending_orders().begin();
         it != m.riders[i].sending_orders().end(); it++) {
      position[(*it).from.x][(*it).from.y] = 2;  //标记餐馆位置
      position[(*it).to.x][(*it).to.y] = 3;      //标记食客位置
    }
    position[m.riders[i].position().x][m.riders[i].position().y] =
        4;  //标记骑手位置
  }

  //重设打印位置
  gotoxy(0, 0);
  //打印图例
  std::wcout << L"餐馆：" << L"\033[01;34m⌂ \033[0m"
             << L"    ";  //餐馆对应的表示
  std::wcout << L"食客：" << L"\033[01;31m⌂ \033[0m"
             << L"    ";            //食客对应的表示
  std::wcout << L"骑手：" << L'⛹';  //骑手对应的表示
  std::wcout << std::endl << std::endl;
  //更新地图
  for (i = 0; i < 17; i++) {
    for (j = 0; j < 17; j++) {
      switch (position[i][j]) {
        case 0:
          std::wcout << L"  ";
          break;
        case 1:  //普通房屋
          std::wcout << L"⌂ ";
          break;
        case 2:
          std::wcout << L"\033[01;34m⌂ \033[0m";  //餐馆
          break;
        case 3:
          std::wcout << L"\033[01;31m⌂ \033[0m";  //食客
          break;
        case 4:
          std::wcout << L'⛹';  //骑手
          break;
        default:;
      }
    }
    std::wcout << std::endl;
  }
  //打印当前运行结果

  gotoxy(40, 6);
  std::wcout << L"时间：" << m.time() << BLANK << std::endl;
  gotoxy(40, 7);
  std::wcout << L"钱：" << m.money() << BLANK << std::endl;
  gotoxy(40, 8);
  std::wcout << L"接单数：" << m.num_all() << BLANK << std::endl;
  gotoxy(40, 9);
  std::wcout << L"完成数：" << m.num_finished() << L" 结单：";
  for (auto i = 0; i < finished_orders.size(); i++) {
    std::wcout << finished_orders[i] << L" ";
  }
  std::wcout << BLANK << std::endl;
  gotoxy(40, 10);
  std::wcout << L"超时数：" << m.num_outdate() << L" 罚单：";
  for (auto i = 0; i < outdate_orders.size(); i++) {
    std::wcout << outdate_orders[i] << L" ";
  }
  std::wcout << BLANK << std::endl;
  for (auto i = 0; i < m.riders.size(); i++) {
    gotoxy(40, 10 + i + 1);
    auto point = m.riders[i].position();
    std::wcout << L"骑手" << i << L"位置：" << point.x << L"," << point.y
               << L" 停靠：";
    for (auto it = m.riders[i].dock_points().begin();
         it != m.riders[i].dock_points().end(); it++) {
      std::wcout << ((*it).type == FROM ? L"餐馆" : L"食客") << (*it).x << L" "
                 << (*it).y << L"  ";
    }
    std::wcout << BLANK << std::endl;
  }
}

void OutputServer::PrintToFile(const Model &m) {
  std::vector<int> outdate_orders;   //当前时间的超时订单
  std::vector<int> finished_orders;  // 当前时间完成的订单

  for (size_t i = 0; i < m.riders.size(); i++) {
    outdate_orders.insert(outdate_orders.end(),
                          m.riders[i].outdate_orders_now().begin(),
                          m.riders[i].outdate_orders_now().end());
    finished_orders.insert(finished_orders.end(),
                           m.riders[i].finished_orders_now().begin(),
                           m.riders[i].finished_orders_now().end());
  }

  OutFile << "时间：" << m.time() << std::endl;
  OutFile << "钱：" << m.money() << std::endl;
  OutFile << "接单数：" << m.num_all() << std::endl;
  OutFile << "完成数：" << m.num_finished() << " 结单：";
  for (auto i = 0; i < finished_orders.size(); i++) {
    OutFile << finished_orders[i] << L" ";
  }
  OutFile << std::endl;
  OutFile << "超时数：" << m.num_outdate() << " 罚单：";
  for (auto i = 0; i < outdate_orders.size(); i++) {
    OutFile << outdate_orders[i] << L" ";
  }
  OutFile << std::endl;
  for (size_t i = 0; i < m.riders.size(); i++) {
    auto point = m.riders[i].position();
    OutFile << "骑手" << i << "位置：" << point.x << " " << point.y
            << " 停靠：";
    for (auto it = m.riders[i].dock_points().begin();
         it != m.riders[i].dock_points().end(); it++) {
      OutFile << ((*it).type == FROM ? "餐馆" : "食客") << (*it).x << " "
              << (*it).y << "  ";
    }
  }
  OutFile << std::endl;
}

void OutputServer::gotoxy(short x, short y) {
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y});
}
