// 练习 1：分数类，考察流、算术运算符重载和异常
//
// 请补全所有标记为 //// 的位置。
//
// 题目要求：
// 1. Fraction 使用 int 保存分子和分母。
// 2. 分母不能为 0。如果分母为 0，抛出 invalid_argument("zero denominator")。
// 3. 每个 Fraction 都要约分到最简形式，并且分母必须为正数。
// 4. 重载：
//    - operator>>，按 a/b 的形式读入一个分数
//    - operator<<，按 a/b 的形式输出一个分数
//    - operator+，实现两个分数相加
//    - operator<，实现两个分数比较大小
// 5. main 读入三个分数，输出它们的和，并输出其中最大的分数。
//
// 样例输入：
// 1/2 1/3 3/4
//
// 样例输出：
// sum=19/12
// max=3/4
//
// 样例输入：
// 1/2 3/0 1/4
//
// 样例输出：
// error: zero denominator

#include <iostream>
#include <numeric>
#include <stdexcept>
using namespace std;

class Fraction {
private:
    int num;
    int den;

    void normalize() {
        if (den == 0) {
            throw invalid_argument("zero denominator");
        }
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int g = gcd(num < 0 ? -num : num, den);
        if (g != 0) {
            num /= g;
            den /= g;
        }
    }

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        normalize();
    }

    // 在这里声明需要的友元运算符函数。
    //////
};

// 实现 operator>>。
// 提示：依次读取 int、char、int，中间的 char 必须是 '/'。
//////

// 实现 operator<<。
//////

// 实现 operator+。
//////

// 实现 operator<。
//////

int main() {
    try {
        Fraction a, b, c;
        cin >> a >> b >> c;

        Fraction sum = a + b + c;
        Fraction maxValue = a;
        if (maxValue < b) {
            maxValue = b;
        }
        if (maxValue < c) {
            maxValue = c;
        }

        cout << "sum=" << sum << endl;
        cout << "max=" << maxValue << endl;
    } catch (const exception& e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}
