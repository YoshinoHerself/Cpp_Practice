// 练习 2：成绩记录类，考察流运算符、比较、加法和异常
//
// 请补全所有标记为 //// 的位置。
//
// 题目要求：
// 1. ScoreRecord 包含学生姓名和成绩。
// 2. 成绩必须在 [0, 100] 范围内，否则抛出 out_of_range("invalid score")。
// 3. 重载：
//    - operator>>，按 name score 的形式读入
//    - operator<<，按 name:score 的形式输出
//    - operator<，成绩低的对象更小
//    - operator+，合并两个成绩记录，返回平均成绩记录。
//      合并后的姓名固定为 "Average"。
// 4. main 读入两个成绩记录，按成绩从低到高输出，然后输出平均成绩。
//
// 样例输入：
// Tom 88 Jerry 96
//
// 样例输出：
// Tom:88
// Jerry:96
// Average:92
//
// 样例输入：
// Tom 120 Jerry 96
//
// 样例输出：
// error: invalid score

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class ScoreRecord {
private:
    string name;
    int score;

    void checkScore() const {
        if (score < 0 || score > 100) {
            throw out_of_range("invalid score");
        }
    }

public:
    ScoreRecord(string n = "", int s = 0) : name(n), score(s) {
        checkScore();
    }

    // 在这里声明需要的友元运算符函数。
    //////
};

// 实现 operator>>。
//////

// 实现 operator<<。
//////

// 实现 operator<。
//////

// 实现 operator+。
//////

int main() {
    try {
        ScoreRecord a, b;
        cin >> a >> b;

        if (b < a) {
            cout << b << endl;
            cout << a << endl;
        } else {
            cout << a << endl;
            cout << b << endl;
        }

        cout << (a + b) << endl;
    } catch (const exception& e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}
