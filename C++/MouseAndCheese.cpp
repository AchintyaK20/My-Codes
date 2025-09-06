#include <iostream>
#include <set>
using namespace std;

class Mouse {
    bool move(int row, int col);
    bool hasCheese(int row, int col);

    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> oppositeDirections = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    set<pair<int, int>> visited;

    bool dfs(int row, int col) {
        if (hasCheese(row, col)) {
            return true;
        }
        visited.insert({row, col});
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];

            if (visited.count({newRow, newCol})) {
                continue;
            }

            if (!move(newRow, newCol)) {
                move(row + oppositeDirections[i][0], col + oppositeDirections[i][1]);
                continue;
            }

            if (dfs(newRow, newCol)) {
                return true;
            }
            move(row + oppositeDirections[i][0], col + oppositeDirections[i][1]);
        }
        return false;
    }

public:
    bool getCheese() {
        return dfs(0, 0);
    }
};

int main() {
    return 0;
}