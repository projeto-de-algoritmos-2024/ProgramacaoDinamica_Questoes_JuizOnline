#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) { // estrutura obrigatoria do leetcode
        const int m = grid.size();
        const int n = grid[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (i > 0 && j > 0)
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                else if (i > 0)
                    grid[i][0] += grid[i - 1][0];
                else if (j > 0)
                    grid[0][j] += grid[0][j - 1];

        return grid[m - 1][n - 1];
    }
};

int main() {
    Solution sol;
    int m, n;

    cout << "Digite o número de linhas (m): ";
    cin >> m;
    cout << "Digite o número de colunas (n): ";
    cin >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Digite os valores da grade:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = sol.minPathSum(grid);
    cout << "A soma mínima do caminho é: " << result << endl;

    return 0;
}
