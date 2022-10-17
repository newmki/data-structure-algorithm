#include <iostream>
#include <string>
#include <vector>

using namespace std;

char board[6][6] = {
    {'U', 'R', 'L', 'P', 'M', 0},
    {'X', 'P', 'R', 'E', 'T', 0},
    {'G', 'I', 'A', 'E', 'T', 0},
    {'X', 'T', 'N', 'Z', 'Y', 0},
    {'X', 'O', 'Q', 'R', 'S', 0},
    0
};

bool inRange(int y, int x) {
    if (y < 0 || y > 4)
        return false;
    if (x < 0 || x > 4)
        return false;
    return true;
}

const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1};

bool hasWord(int y, int x, const string& word) {
    if (!inRange(y, x)) return false;
    if (board[y][x] != word[0]) {
        return false;
    }
    if (word.size() == 1) return true;
    for (int direction = 0; direction < 8; ++direction) {
        int nextY = y + dy[direction];
        int nextX = x + dx[direction];
        if (hasWord(nextY, nextX, word.substr(1))) return true;
    }
    return false;
}

void test(int y, int x, string word) {
    bool has = hasWord(y, x, word);
    if (has) {
        cout << "HAS " << word << "\n";
    } else {
        cout << "Doesn't have " << word << "\n";
    }
}

int main(void) {
    string word;

    test(1, 1, "PRETTY");
    test(2, 0, "GIRL");
    test(1, 2, "REPEAT");
    return 0;
}