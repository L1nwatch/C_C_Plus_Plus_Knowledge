//
// Created by w@tch on 16/7/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(vector<vector<int> > array, int target) {
        int row = array.size();
        int column = array[0].size();

        if (row > 0 && column > 0) {
            int x, y;
            x = 0, y = column - 1;
            while (x < row && y >= 0) {
                if (array[x][y] == target) {
                    return true;
                }
                else if (array[x][y] > target) {
                    --y;
                }
                else {
                    ++x;
                }
            }
        }

        return false;
    }
};

int main(void) {
    vector<vector<int> > array = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    Solution solution = Solution();
    cout << solution.Find(array, 3) << endl;
    cout << solution.Find(array, 10) << endl;
    return 0;
}