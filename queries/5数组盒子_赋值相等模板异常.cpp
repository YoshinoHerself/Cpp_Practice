// 练习 5：模板数组盒子，考察 operator=、operator==、模板和异常
//
// 请补全所有标记为 //// 的位置。
//
// 题目要求：
// 1. Box<T> 保存一组同类型数据，长度由构造函数指定。
// 2. 如果长度 n <= 0，抛出 invalid_argument("bad size")。
// 3. at(index) 访问元素。如果下标越界，抛出 out_of_range("bad index")。
// 4. 重载 operator=，要求完成深拷贝，并正确处理自赋值。
// 5. 重载 operator==，当两个 Box 长度相同且每个元素都相等时返回 true。
//
// 样例输入：
// 3
// 1 2 3
// 1 2 3
//
// 样例输出：
// same
// copied: 1 2 3

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Box {
private:
    int len;
    T* data;

public:
    Box(int n = 1) : len(n), data(nullptr) {
        if (len <= 0) {
            throw invalid_argument("bad size");
        }
        data = new T[len];
    }

    Box(const Box& other) : len(other.len), data(new T[other.len]) {
        for (int i = 0; i < len; i++) {
            data[i] = other.data[i];
        }
    }

    ~Box() {
        delete[] data;
    }

    int size() const {
        return len;
    }

    T& at(int index) {
        if (index < 0 || index >= len) {
            throw out_of_range("bad index");
        }
        return data[index];
    }

    const T& at(int index) const {
        if (index < 0 || index >= len) {
            throw out_of_range("bad index");
        }
        return data[index];
    }

    // 重载赋值运算符 operator=。
    //////

    // 重载相等运算符 operator==。
    //////
};

int main() {
    try {
        int n;
        cin >> n;

        Box<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> a.at(i);
        }
        for (int i = 0; i < n; i++) {
            cin >> b.at(i);
        }

        if (a == b) {
            cout << "same" << endl;
        } else {
            cout << "different" << endl;
        }

        c = a;
        cout << "copied:";
        for (int i = 0; i < c.size(); i++) {
            cout << " " << c.at(i);
        }
        cout << endl;
    } catch (const exception& e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}
