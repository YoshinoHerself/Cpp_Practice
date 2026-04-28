// 练习 9：可选值模板类，考察 operator bool、模板和异常
//
// 请补全所有标记为 //// 的位置。
//
// 题目要求：
// 1. Maybe<T> 表示“可能有值，也可能没有值”的对象。
// 2. 默认构造的 Maybe<T> 没有值。
// 3. 使用 Maybe(T v) 构造的对象有值。
// 4. 重载 operator bool，使对象可以直接用于 if 判断。
// 5. value() 返回内部值。如果没有值，抛出 logic_error("empty value")。
// 6. main 读入一个命令：
//    - just x：表示有一个整数 x
//    - none：表示没有值
//
// 样例输入：
// just 25
//
// 样例输出：
// value=25
//
// 样例输入：
// none
//
// 样例输出：
// empty
// error: empty value

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class Maybe {
private:
    bool hasValue;
    T stored;

public:
    Maybe() : hasValue(false), stored(T()) {}

    Maybe(T v) : hasValue(true), stored(v) {}

    // 重载类型转换运算符 operator bool。
    //////

    T value() const {
        // 如果没有值，抛出 logic_error("empty value")。
        //////
        return stored;
    }
};

int main() {
    try {
        string command;
        cin >> command;

        Maybe<int> m;
        if (command == "just") {
            int x;
            cin >> x;
            m = Maybe<int>(x);
        } else if (command == "none") {
            m = Maybe<int>();
        } else {
            throw runtime_error("bad command");
        }

        if (m) {
            cout << "value=" << m.value() << endl;
        } else {
            cout << "empty" << endl;
            m.value();
        }
    } catch (const exception& e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}
