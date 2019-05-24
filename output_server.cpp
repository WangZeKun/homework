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
void OutputServer::PrintToScreen() {
  std::wcout << L"用户您好," << std::endl;
  std::wcout << L"欢迎您使用外卖订单派送系统 ~o(≧口≦) o ~"
             << std::endl; 
  std::wcout << std::endl;
  std::wcout << L"请输入回车键开始运行" << std::endl;
  getchar();//读取回车键
  system("cls");
}
//初始化地图
void OutputServer::PrintToConsole(const Model &m) {
  gotoxy(0,0);
  int i, j, position[17][17] = {0};
  Point point;
  for (i = 0; i < 17; i += 2) {
    for (j = 0; j < 17; j += 2) {
      position[i][j] = 1;
    }//将每个坐标初始化，标记为1
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
      position[(*it).from.x][(*it).from.y] = 2;//标记餐馆位置
      position[(*it).to.x][(*it).to.y] = 3;//标记食客位置
    }
    position[m.riders[i].position().x][m.riders[i].position().y] = 4;//标记骑手位置
  }
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
          std::wcout << L"⌂";
          break;
        case 2:
          std::wcout << L"\033[01;34m⌂\033[0m";  //餐馆
          break;
        case 3:
          std::wcout << L"\033[01;31m⌂\033[0m";  //食客
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
  std::wcout << L"时间：" << m.time() << "        " << std::endl;
  std::wcout << L"钱：" << m.money() << "        " << std::endl;
  std::wcout << L"接单数：" << m.num_sending() + m.num_finished() + m.num_outdate() << "        "
             << std::endl;
  std::wcout << L"超时数：" << m.num_outdate() << "        " << std::endl;
  std::wcout << L"完成数：" << m.num_finished() << "        " << std::endl;
}

void OutputServer::PrintToFile(const Model &m) {
  OutFile << "时间：" << m.time() << std::endl;
  OutFile << "钱：" << m.money() << std::endl;
  OutFile << "接单数：" << m.num_sending() + m.num_finished() + m.num_outdate() << std::endl;
  OutFile << "超时数：" << m.num_outdate() << std::endl;
  OutFile << "完成数：" << m.num_finished() << std::endl;
  for (size_t i = 0; i < m.riders.size(); i++) {
    auto point = m.riders[i].position();
    OutFile << "骑手" << i << "位置：" << point.x << " " << point.y
            << std::endl;
  }
}

void OutputServer::gotoxy(short x, short y) {
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y});
}
