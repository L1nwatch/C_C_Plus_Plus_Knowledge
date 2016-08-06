//
// Created by w@tch on 16/8/5.
//

/*
 * 题目描述
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 */
#include "vector"

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.size() > 0)
        {
            int low, high, middle;
            low = 0;
            high = rotateArray.size() - 1;
            middle = low;

            // 结束条件
            while (rotateArray[low] >= rotateArray[high])
            {
                // 结束条件
                if (high - low == 1)
                {
                    middle = high;
                    break;
                }

                // 求取中间的索引值
                middle = (low + high) / 2;

                // 判断中间值的大小, 知道它是前面的递增序列还是后面的递增序列
                if (rotateArray[middle] <= rotateArray[high])
                {
                    high = middle;
                }
                else if (rotateArray[middle] >= rotateArray[low])
                {
                    low = middle;
                }
            }

            return rotateArray[middle];
        }
        return 0;
    }
};

int main(void)
{
    vector<int> array = {7, 1, 2, 3, 4, 5, 6};

    printf("%d\n", Solution().minNumberInRotateArray(array));

    return 0;
}