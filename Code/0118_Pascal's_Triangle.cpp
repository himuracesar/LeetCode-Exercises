class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        if(numRows >= 1)
        {
            vector<int> row1;
            row1.push_back(1);

            triangle.push_back(row1);
        }

        if(numRows >= 2)
        {
            vector<int> row2;
            row2.push_back(1);
            row2.push_back(1);

            triangle.push_back(row2);
        }

        for(auto i = 3; i <= numRows; i++)
        {
            vector<int> row;
            row.push_back(1);

            int index = triangle.size() - 1;
            for(auto j = 0; j < triangle[index].size() - 1; j++)
                row.push_back(triangle[index][j] + triangle[index][j + 1]);

            row.push_back(1);
            triangle.push_back(row);
        }

        return triangle;
    }
};