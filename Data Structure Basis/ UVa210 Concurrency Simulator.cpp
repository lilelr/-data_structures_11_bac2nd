//// UVa210 Concurrency Simulator 队列，双端队列
//// Rujia Liu
//// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=146
//#include <cctype>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <queue>
//using namespace std;
//
//const int maxn = 1000;
//
//deque<int> readyQ; // 双端队列
//queue<int> blockQ;
//int c[5];                // 表示5个操作，各自的执行时间
//int n, quantum, var[26], // 最多有26个变量
//    ip[maxn];            // ip[pid]是程序pid的当前行号。所有程序都存在prog数组，更类似真实的情况，代码也更短
//bool locked;             // 全局只有一个互斥锁
//char prog[maxn][10];
//
//// 执行 pid 程序
//void run(int pid) {
//  int q = quantum;
//  while (q > 0) {
//    char *p = prog[ip[pid]];
//    switch (p[2]) {
//    case '=': // b = 59
//      var[p[0] - 'a'] =
//          isdigit(p[5]) ? (p[4] - '0') * 10 + p[5] - '0' : p[4] - '0';
//      q -= c[0];
//      break;
//    case 'i': // print b
//      printf("%d: %d\n", pid + 1, var[p[6] - 'a']);
//      q -= c[1];
//      break;
//    case 'c': // lock
//      if (locked) {
//        blockQ.push(pid); // 进队尾
//        return;           // 当前程序直接结束运行
//      }
//      locked = true; //第一个获得锁，往下执行
//      q -= c[2];
//      break;
//    case 'l': // unlock
//      locked = false;
//      if (!blockQ.empty()) {
//        int pid2 = blockQ.front();
//        blockQ.pop();
//        readyQ.push_front(
//            pid2); // 唤醒blockQ的第一个等待进程，从readyQ的头部插入
//      }
//      q -= c[3];
//      break;
//    case 'd': // end
//      return;
//    }
//    ip[pid]++;
//  }
//  readyQ.push_back(pid); //当前程序把uantum 使用完，加入到readQ队列末
//}
//
//int main() {
//  int T;
//  scanf("%d", &T);
//  while (T--) {
//    scanf("%d %d %d %d %d %d %d\n", &n, &c[0], &c[1], &c[2], &c[3], &c[4],
//          &quantum);
//    memset(var, 0, sizeof(var));
//
//    int line = 0; // line 是执行语句的行号 如0~20行为程序1， 21~40行为程序2
//    for (int i = 0; i < n; i++) {
//      fgets(prog[line++], maxn, stdin);
//      ip[i] =
//          line -
//          1; // ip[pid]是程序pid的当前行号。所有程序都存在prog数组，更类似真实的情况，代码也更短
//      while (prog[line - 1][2] != 'd')
//        fgets(prog[line++], maxn, stdin);
//      readyQ.push_back(i); // i 为程序执行顺序号
//    }
//
//    locked = false;
//    while (!readyQ.empty()) {
//      // 从 readyQ 中出队一个pid去执行
//      int pid = readyQ.front();
//      readyQ.pop_front();
//      run(pid);
//    }
//    if (T)
//      printf("\n");
//  }
//  return 0;
//}
