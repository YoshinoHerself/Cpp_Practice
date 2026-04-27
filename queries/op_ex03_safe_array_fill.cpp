// 练习 3：安全数组类，考察下标运算符、流输出和异常
//
// 请补全所有标记为 //// 的位置。
//
// 题目要求：
// 1. SafeArray 固定保存 5 个整数。
// 2. 重载两种 operator[]：
//    - 非 const 版本返回 int&，使元素可以被修改
//    - const 版本返回 const int&，使 const 对象可以被读取
// 3. 如果下标不在 [0, 4] 范围内，抛出 out_of_range("index out of range")。
// 4. 重载 operator<<，输出 5 个整数，整数之间用一个空格分隔。
// 5. main 读入 5 个整数，然后读入下标和值。
//    程序把 arr[index] 改成该值，并输出整个数组。
//
// 样例输入：
// 1 2 3 4 5
// 2 99
//
// 样例输出：
// 1 2 99 4 5
//
// 样例输入：
// 1 2 3 4 5
// 8 99
//
// 样例输出：
// error: index out of range

#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
private:
    int data[5];

public:
    SafeArray() {
        for (int i = 0; i < 5; i++) {
            data[i] = 0;
        }
    }

    void read() {
        for (int i = 0; i < 5; i++) {
            cin >> data[i];
        }
    }

    // 重载非 const 版本的 operator[]。
    //////

    // 重载 const 版本的 operator[]。
    //////

    // 声明输出流运算符。
    //////
};

// 实现 operator<<。
//////

int main() {
    try {
        SafeArray arr;
        arr.read();

        int index, value;
        cin >> index >> value;
        arr[index] = value;

        cout << arr << endl;
    } catch (const exception& e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}
