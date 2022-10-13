#include <iostream>
#include <vector>
using namespace std;

void printPicked(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

void pick(int n, vector<int>& picked, int toPick) {
    if (toPick == 0) {
        printPicked(picked);
        return ;
    }

    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for (int i = smallest; i < n; ++i) {
        picked.push_back(i);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}

int main(void) {
    vector<int> v;
    pick(5, v, 2);
    return 0;
}
