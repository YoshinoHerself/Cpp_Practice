// 练习 6：销售记录，考察 operator*、文件流和最基础的格式控制
//
// 请补全所有标记为 //// 的位置。
//
// 题目要求：
// 1. Sale 保存商品名、单价和数量。
// 2. 如果单价或数量为负数，抛出 invalid_argument("bad sale")。
// 3. 重载 operator*，返回该销售记录的总价：price * count。
// 4. main 从标准输入读入 n 条记录，先写入文件 sales_report.txt。
// 5. 再用 ifstream 读取该文件内容，并输出到屏幕。
// 6. 输出总价时使用 fixed 和 setprecision(2)，每行格式如下：
//    name total
//
// 样例输入：
// 2
// apple 3.5 4
// book 12 2
//
// 样例输出：
// apple 14.00
// book 24.00

#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Sale {
private:
    string name;
    double price;
    int count;

public:
    Sale(string n = "", double p = 0, int c = 0) : name(n), price(p), count(c) {
        if (price < 0 || count < 0) {
            throw invalid_argument("bad sale");
        }
    }

    string getName() const {
        return name;
    }

    // 重载 operator*，返回总价。
    //////
};

int main() {
    try {
        int n;
        cin >> n;

        // 创建输出文件流 fout，文件名为 sales_report.txt。
        //////

        if (!fout) {
            throw runtime_error("cannot open output file");
        }

        for (int i = 0; i < n; i++) {
            string name;
            double price;
            int count;
            cin >> name >> price >> count;

            Sale s(name, price, count);

            // 向文件输出商品名和总价。
            // 总价保留两位小数。
            //////
        }

        fout.close();

        // 创建输入文件流 fin，读取 sales_report.txt。
        //////

        if (!fin) {
            throw runtime_error("cannot open input file");
        }

        string line;
        while (getline(fin, line)) {
            cout << line << endl;
        }
    } catch (const exception& e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}
