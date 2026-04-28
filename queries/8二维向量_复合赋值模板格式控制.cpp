// 练习 8：二维向量模板类，考察 operator+=、operator*=、模板和格式控制
//
// 请补全所有标记为 //// 的位置。
//
// 题目要求：
// 1. Vector2<T> 保存 x 和 y 两个坐标。
// 2. 重载 operator+=，实现向量加法。
// 3. 重载 operator*=，实现向量乘以一个标量。
// 4. 重载 operator<<，输出格式为：(x,y)。
// 5. 输出 double 类型向量时，使用 fixed 和 setprecision(1) 保留 1 位小数。
//
// 样例输入：
// 1.5 2.0
// 3.0 4.5
// 2.0
//
// 样例输出：
// after += (4.5,6.5)
// after *= (9.0,13.0)

#include <iomanip>
#include <iostream>
using namespace std;

template <typename T>
class Vector2 {
private:
    T x;
    T y;

public:
    Vector2(T xValue = T(), T yValue = T()) : x(xValue), y(yValue) {}

    // 重载 operator+=。
    //////

    // 重载 operator*=。
    //////

    // 声明输出流运算符。
    //////
};

// 实现 operator<<。
//////

int main() {
    double x1, y1, x2, y2, k;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> k;

    Vector2<double> a(x1, y1);
    Vector2<double> b(x2, y2);

    a += b;
    cout << fixed << setprecision(1);
    cout << "after += " << a << endl;

    a *= k;
    cout << "after *= " << a << endl;

    return 0;
}
