// 练习 7：字符串解析，考察 stringstream、operator() 和异常
//
// 请补全所有标记为 //// 的位置。
//
// 题目要求：
// 1. 输入一行字符串，格式为：姓名,成绩
// 2. 使用 stringstream 解析这行字符串。
// 3. ScoreChecker 是一个函数对象，重载 operator()。
// 4. operator() 接收一个 int 成绩，如果成绩不在 [0, 100]，抛出 out_of_range("bad score")。
// 5. 如果字符串格式不是 姓名,成绩，抛出 runtime_error("bad format")。
// 6. 输出格式为：name passed 或 name failed，成绩 >= 60 算通过。
//
// 样例输入：
// Alice,85
//
// 样例输出：
// Alice passed
//
// 样例输入：
// Bob,120
//
// 样例输出：
// error: bad score

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

class ScoreChecker {
public:
    // 重载函数调用运算符 operator()。
    //////
};

class StudentRecord {
private:
    string name;
    int score;

public:
    StudentRecord(string n = "", int s = 0) : name(n), score(s) {}

    string getName() const {
        return name;
    }

    bool passed() const {
        return score >= 60;
    }
};

StudentRecord parseLine(const string& line) {
    stringstream ss(line);
    string name;
    int score;
    char comma;

    // 使用 stringstream 解析 name,score。
    // 如果格式错误，抛出 runtime_error("bad format")。
    //////

    ScoreChecker checker;
    checker(score);
    return StudentRecord(name, score);
}

int main() {
    try {
        string line;
        getline(cin, line);

        StudentRecord stu = parseLine(line);
        cout << stu.getName() << " ";
        if (stu.passed()) {
            cout << "passed" << endl;
        } else {
            cout << "failed" << endl;
        }
    } catch (const exception& e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}
