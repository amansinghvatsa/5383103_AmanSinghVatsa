#include <iostream>
#include <vector>
#include <string>
using namespace std;

using Grid = vector<string>;

Grid detonate(const Grid &g) {
    int r = g.size(), c = g[0].size();
    vector<vector<bool>> blast(r, vector<bool>(c, false));
    auto mark = [&](int i, int j){
        if (i>=0 && i<r && j>=0 && j<c) blast[i][j] = true;
    };
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (g[i][j] == 'O') {
                mark(i, j);
                mark(i-1, j);
                mark(i+1, j);
                mark(i, j-1);
                mark(i, j+1);
            }
        }
    }
    Grid out(r, string(c, 'O')); // assume full bombs, then clear blasts
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (blast[i][j]) out[i][j] = '.';
    return out;
}

Grid fullGrid(int r, int c) { return Grid(r, string(c, 'O')); }

Grid bomberMan(int n, const Grid &grid) {
    int r = grid.size(), c = grid[0].size();
    if (n == 1) return grid;
    if (n % 2 == 0) return fullGrid(r, c);

    // Odd n >= 3: cycle through two states: A (n=3), B (n=5)
    Grid A = detonate(grid);
    Grid B = detonate(A);
    if ((n - 3) % 4 == 0) return A;
    else return B;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c, n;
    if (!(cin >> r >> c >> n)) return 0;
    Grid g(r);
    for (int i = 0; i < r; ++i) cin >> g[i];

    Grid ans = bomberMan(n, g);
    for (auto &row : ans) cout << row << "\n";
    return 0;
}
