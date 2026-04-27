// 练习 4：模 60 计数器，考察 ++、--、流运算符和异常
//
// 请补全所有标记为 //// 的位置。
//
// 题目要求：
// 1. Mod60 保存一个 [0, 59] 范围内的值。
// 2. 构造函数接收一个 int。如果它不在 [0, 59] 范围内，抛出 out_of_range("invalid value")。
// 3. 重载：
//    - 前置 ++ 和后置 ++
//    - 前置 -- 和后置 --
//    - operator>> 和 operator<<
// 4. ++ 遇到 59 时变成 0。
// 5. -- 遇到 0 时变成 59。
// 6. main 读入一个数，并依次输出：
//    原始值、前置 ++ 的结果、后置 ++ 返回的值、后置 ++ 后对象的值、
//    前置 -- 的结果、后置 -- 返回的值、后置 -- 后对象的值。
//
// 样例输入：
// 58
//
// 样例输出：
// original=58
// ++x=59
// x++=59
// after x++=0
// --x=59
// x--=59
// after x--=58
//
// 样例输入：
// 80
//
// 样例输出：
// error: invalid value

#include <iostream>
#include <stdexcept>
using namespace std;

class Mod60 {
private:
    int value;

    void check() const {
        if (value < 0 || value > 59) {
            throw out_of_range("invalid value");
        }
    }

public:
    Mod60(int v = 0) : value(v) {
        check();
    }

    // 重载前置 ++。
    //////

    // 重载后置 ++。
    //////

    // 重载前置 --。
    //////

    // 重载后置 --。
    //////

    // 声明流输入和流输出运算符。
    //////
};

// 实现 operator>>。
//////

// 实现 operator<<。
//////

int main() {
    try {
        Mod60 x;
        cin >> x;

        cout << "original=" << x << endl;
        cout << "++x=" << ++x << endl;
        cout << "x++=" << x++ << endl;
        cout << "after x++=" << x << endl;
        cout << "--x=" << --x << endl;
        cout << "x--=" << x-- << endl;
        cout << "after x--=" << x << endl;
    } catch (const exception& e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}
