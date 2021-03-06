#include "test.hpp"
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::vector;
using std::pair;

class Base {
public:
    Base() {
        std::cout << "Default constructor" << std::endl;
    }
    Base(int cnt, int len): cnt_(cnt), len_(len) {
        std::cout << "Constructor with param" << std::endl;
    }
    Base(const Base& orig): cnt_(orig.cnt_), len_(orig.len_) {
        std::cout << "Copy constructor" << std::endl;
    }
    Base& operator=(const Base& rhs) {
        cnt_ = rhs.cnt_;
        len_ = rhs.len_;
        std::cout << "Copy-assignment constructor" << std::endl;

        return *this;
    }
    ~Base() {};
private:
    int cnt_;
    int len_;
};

/*
 * typename when template
**/
// template<typename T>
// void SelectionSort(std::vector<T>& arr)
// typedef typename std::vector<T>::size_type size_type;

void TestSet() {
    set<int> sv;
    sv.insert(3);
    sv.insert(3);
    sv.insert(4);

    for (auto& s : sv) {
        cout << s << " " << endl;
    }
}

void TestLonglong() {
    int a = 1;
    cout << (a << 31) << endl;
    long long i = (a << 30) * (a << 30);
    cout << i << endl;
    long long ii = (static_cast<long long>(a) << 30) * (a << 30);
    cout << ii << endl;
}

void TestLambda() {
    int x = 11;
    int y = 13;

    auto fl = [&x, &y]() mutable -> void {
        x = 1;
        std::cout << x << " " << y << std::endl;
    };
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    std::cout << x << " " << y << std::endl;
    fl();
    std::cout << x << " " << y << std::endl;
}

void TestSort() {
    vector<int> v = {2, 3, 1, -1, 0, 8, -11};
    // 默认升序
    // std::sort(v.begin(), v.end());
    // 降序 
    // auto cmp = [](const int& a, const int& b) {
    //     return a > b;
    // };
    // std::sort(v.begin(), v.end(), cmp);
    
    // 降序
    // std::sort(v.begin(), v.end(), std::greater<int>());

    vector<vector<int>> vv = {{2, 2},
                              {1, 2},
                              {3, 2},
                              {5, 4},
                              {-1, 3},
                              {0, 9}};
    auto cmp = [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    };
    // sort 是稳定的排序
    std::sort(vv.begin(), vv.end(), cmp);

    PrintVVector(vv);
}

void TestHeap() {
    vector<int> ivec = {15, 1, 12, 30, 20};
    // default is max-heap
    std::make_heap(ivec.begin(), ivec.end(), std::less<int>());
    PrintVector(ivec);

    std::pop_heap(ivec.begin(), ivec.end());
    std::cout << ivec[4] << std::endl;
    ivec.pop_back();

    ivec.push_back(73);
    std::push_heap(ivec.begin(), ivec.end());
    PrintVector(ivec);
}

pair<string, int> GetPerson() {
    return std::make_pair("Sven", 23);
}
void TestPair() {
    pair<string, int> name_age("Muzhi", 28);
    pair<string, int> n1 = name_age;

    pair<int, int> point(0, 0);
    point.first = 1.7;
    point.second = 2.6;

    pair<string, vector<int>> line;
    line = std::make_pair("kant", vector<int>{1, 4, 5});

    string name;
    int age;
    std::tie(name, age) = GetPerson();
}

int main() {
    // Base b = {1, 2};
    // Base b1;
    // b1 = b;
    // TestSet();
    // TestSort();
    TestHeap();

    return 0;
}