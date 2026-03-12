#include <iostream>
#include <vector>
#include <climits>

using namespace std;

auto printParens(const vector<vector<int> > &split, int i, int j, int &idx, string &expr) -> void {
    if (i == j) {
        expr += static_cast<char>('A' + idx++);
        return;
    }
    expr += '(';
    printParens(split, i, split[i][j], idx, expr);
    printParens(split, split[i][j] + 1, j, idx, expr);
    expr += ')';
}

void matrixChain(const vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> cost(n, vector<int>(n));
    vector<vector<int>> split(n, vector<int>(n));

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            cost[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int q = cost[i][k] + cost[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < cost[i][j]) {
                    cost[i][j] = q;
                    split[i][j] = k;
                }
            }
        }
    }

    string expr;
    int idx = 0;
    printParens(split, 0, n - 1, idx, expr);

    cout << "Optimal Parenthesize is : " << expr << endl;
    cout << "Optimal Cost is : " << cost[0][n - 1] << endl;
}

int main() {
    // Example 1: Change matrix chain dimensions and costs
    matrixChain({10, 20, 30, 40, 30});

    cout << endl;

    // Example 2: Another set of matrix chain dimensions and costs
    matrixChain({4, 10, 3, 12, 20, 7});

    return 0;
}
