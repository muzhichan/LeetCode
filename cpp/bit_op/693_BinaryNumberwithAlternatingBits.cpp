#include "../common.hpp"
using namespace std;

/***************
****************/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long a = (n ^ (n >> 1));
        return (a & (a + 1)) == 0;
    }
};
