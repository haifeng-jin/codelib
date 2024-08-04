// Create a 2D vector.
// Example: auto my2DVector = create2DVector<int>(3, 4, 0);
// It initialize a 2D vector of type int of size 3 rows and 4 columns with
// initial value of 0.
template <typename T>
vector<vector<T>> Create2DVector(size_t rows, size_t cols, T init_value) {
  return vector<vector<T>>(rows, vector<T>(cols, init_value));
}

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        auto count = Create2DVector(n, 10, 0);
        for (auto& single_pick: pick) {
            count[single_pick[0]][single_pick[1]]++;
        }
        int winners = 0;
        for (int i = 0; i < n; i++) {
            bool succeed = false;
            for (int j = 0; j <= 10; j++) {
                if (count[i][j] > i) {
                    succeed = true;
                    break;
                }
            }
            if (succeed) {
                winners++;
            }
        }
        return winners;
    }
};