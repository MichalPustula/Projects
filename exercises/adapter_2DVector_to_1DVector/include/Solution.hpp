//https://leetcode.com/problems/convert-1d-array-into-2d-array/

#include <vector>
using namespace std;


class Solution {
public:
vector<vector<int>> construct2DArray(vector<int>& original, int row, int col) 
{
    vector<vector<int>> output(row, vector<int> (col));

	vector<vector<int>> empty_output;

	if(row*col != static_cast<int>(original.size())) { return empty_output; }
    if(row == 0 && col == 0) { return empty_output; }

    for(size_t i = 0; i < original.size(); i++)
    {
        int x = i % col; 
        int y = i / col; 
        output[y][x] = original[i];
    }
    return output;
}
};

/*
class Solution {
public:

vector<vector<int>> construct2DArray(vector<int>& original, int row, int col) 
{
    vector<vector<int>> output;

    vector<vector<int>> empty_output;

	if(row*col != original.size()) { return empty_output; }
    if(row == 0 && col == 0) { return empty_output; }

    vector<int> temp;
    for(int i = 0; i < original.size(); i++)
    {
        if(i % col == 0 && i != 0)
        {
            output.push_back(temp);
            vector<int> temp2;
            temp = temp2;
        }
        temp.push_back(original.at(i));
    }
    output.push_back(temp);
    return output;
}
};
*/


