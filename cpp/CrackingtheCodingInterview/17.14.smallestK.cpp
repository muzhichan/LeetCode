#include "../common.hpp"
using std::vector;
using std::priority_queue;

// [ref](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/)

/*
时间复杂度：O(nlogn)，建堆的时间代价是 O(n)，删除的总代价是 O(klogn)，因为 k < n，故渐进时间复杂为 O(n+klogn)=O(nlogn)。

空间复杂度：O(logn)，即递归使用栈空间的空间代价。
*/
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int sz = arr.size();
        if (k >= sz) {
            return arr;
        }
        if (k == 0) {
            return vector<int> {};
        }
        // 大根堆
        priority_queue<int, vector<int>, std::less<int>> pq_;
        for (int i = 0; i < k; ++i) {
            pq_.push(arr[i]);
        }
        for (int j = k; j < sz; ++j) {
            if (arr[j] < pq_.top()) {
                pq_.pop();
                pq_.push(arr[j]);
            }
        }

        vector<int> ret;
        while (!pq_.empty()) {
            ret.push_back(pq_.top());
            pq_.pop();
        }
        return ret;
    }
};

class SolutionII {
public:
    int Partition(vector<int>& alist, int l, int r) {
        int m = l;
        for (int k = l + 1; k <= r; ++k) {
            if (alist[k] < alist[l]) {
                m++;
                if (m != k) {
                    std::swap(alist[m], alist[k]);
                }
            }
        }
        std::swap(alist[m], alist[l]);
        
        return m;
    }

    int QuickSelect(vector<int>& alist, int l, int r, int index) {
        int q = Partition(alist, l, r);
        if (index == q) {
            return q;
        } else {
            return q > index ? QuickSelect(alist, l, q - 1, index) : QuickSelect(alist, q + 1, r, index);
        }
    }

    vector<int> smallestK(vector<int>& arr, int k) {
        int sz = arr.size();
        if (k >= sz) {
            return arr;
        }
        if (k == 0) {
            return vector<int> {};
        }
        QuickSelect(arr, 0, sz - 1, k - 1);

        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            ret.push_back(arr[i]);
        }
        return ret;
    }
};
