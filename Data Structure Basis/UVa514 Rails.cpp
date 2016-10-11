//// UVa514 Rails
//// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=455
//// Rujia Liu
//#include <cstdio>
//#include <stack>
//using namespace std;
//const int MAXN = 1000 + 10;
//
//int n, target[MAXN];
//
//int main() {
//  while (scanf("%d", &n) == 1) {
//    stack<int> s;
//    int A = 1, B = 1;
//    for (int i = 1; i <= n; i++)
//      scanf("%d", &target[i]);
//    int ok = 1;
//    while (B <= n) {
//      if (A == target[B]) { // 相等则各自加1
//        A++;
//        B++;
//      } else if (!s.empty() && s.top() == target[B]) {
//        /**
//         *  栈顶元素与target[B]相等，栈顶元素退栈
//         */
//        s.pop();
//        B++;
//      } else if (A <= n)
//        // A 与target[B]不相等，入栈
//        s.push(A++);
//      else {
//        ok = 0;
//        break;
//      }
//    }
//    printf("%s\n", ok ? "Yes" : "No");
//  }
//  return 0;
//}
