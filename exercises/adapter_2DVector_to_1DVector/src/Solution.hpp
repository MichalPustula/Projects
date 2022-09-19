//https://leetcode.com/problems/convert-1d-array-into-2d-array/

#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int row, int col) 
    {
        vector<vector<int>> output;

        if (original.size() == 0) { return output; }
        if (col == 0 )            { return output; }
        if (col == 1 )            { return construct2DArray(original, row); }

        for(int i = 0; i < col; i++)
        {
            vector<int> temp;
            
            for(int j = 0; j < row; j++)
            {

                if(((i*row)+j) < original.size())
                {
                    temp.push_back(original.at((i*row)+j));
                }
                else
                {
                    output.push_back(temp);
                    return output;
                }
            }
            output.push_back(temp);
        }
        return output;
    }

    vector<vector<int>> construct2DArray(vector<int>& original, int row) 
    {
        vector<vector<int>> output;

        if (row == 0) { return output; }
        if (original.size() == 0) { return output; }

        vector<int> temp;
        int size;

        if(row < original.size()) { size = row; }
        else                      { size = original.size(); }

        for ( int i = 0; i < size; i++)
        {
            temp.push_back(original.at(i));
        }
        output.push_back(temp);
        return output;
    }
};

