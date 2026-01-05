#include "linear_search.h"

int linearSearch(const std::vector<int>& a, int target) {
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == target)
            return i;
    }
    return -1;
}
