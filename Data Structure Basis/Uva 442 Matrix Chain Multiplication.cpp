//// UVa442 Matrix Chain Multiplication  栈
//// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=383
//// Rujia Liu
//// 题意：输入n个矩阵的维度和一些矩阵链乘表达式，输出乘法的次数。假定A和m*n的，B是n*p的，那么AB是m*p的，乘法次数为m*n*p
//// 算法：用一个栈。遇到字母时入栈，右括号时出栈并计算，然后结果入栈。因为输入保证合法，括号无序入栈
//#include <cstdio>
//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//struct Matrix {
//  int a, b;
//  Matrix(int a = 0, int b = 0) : a(a), b(b) {}
//} m[26];
//
//stack<Matrix> s;
//int n;
//
//int main() {
//  cin >> n;
//  for (int i = 0; i < n; i++) {
//    string name;
//    cin >> name;
//    int k = name[0] - 'A';
//    cin >> m[k].a >> m[k].b;
//  }
//  string expr;
//  while (cin >> expr) {
//    int len = expr.length();
//    bool error = false;
//    int ans = 0;
//    for (int i = 0; i < len; i++) {
//      if (isalpha(expr[i])) {
//        s.push(m[expr[i] - 'A']);
//      } else if (expr[i] == ')') {
//        Matrix t2 = s.top();
//        s.pop();
//        Matrix t1 = s.top();
//        s.pop();
//        if (t1.b != t2.a) {
//          error = true;
//          break;
//        }
//        ans += t1.a * t1.b * t2.b;
//        s.push(Matrix(t1.a, t2.b));
//      }
//    }
//    if (error) {
//      printf("error\n");
//    } else {
//      printf("%d\n", ans);
//    }
//  }
//
//  return 0;
//}
