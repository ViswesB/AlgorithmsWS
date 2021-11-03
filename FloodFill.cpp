/*
733. Flood Fill
Easy

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]

 

Constraints:

    m == image.length
    n == image[i].length
    1 <= m, n <= 50
    0 <= image[i][j], newColor < 216
    0 <= sr < m
    0 <= sc < n
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    
    bool isIndexValid(int maxRow,int maxCol,int row,int col) {
        if(row < 0 || row >= maxRow || col < 0 || col >= maxCol)
            return false;
        return true;
    }
    
    void fill(vector<vector<int>>& image, int sr, int sc, int sourceColor, int newColor) {
        int maxRow = image.size();
        int maxCol = image[0].size();
        
        if(!isIndexValid(maxRow,maxCol,sr,sc))
            return;
        
        if(image[sr][sc] != sourceColor)
            return;
        
        image[sr][sc] = newColor;
        
        //invoke color change in all 4 directions i.e. UP/DOWN/LEFT/RIGHT
        fill(image,sr-1,sc,sourceColor,newColor); //up
        fill(image,sr+1,sc,sourceColor,newColor); //down
        fill(image,sr,sc-1,sourceColor,newColor); //left
        fill(image,sr,sc+1,sourceColor,newColor); //right
    }
    
    //GRID PROBLEM WITH DFS
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)
            return image;
        
        fill(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
};

int main() {
    shared_ptr<Solution> sol = make_shared<Solution>();
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    auto updatedImage = sol->floodFill(image,1,1,2);
    for(auto itr: updatedImage) {
        for (auto i : itr)
            cout << i << "\t";
        cout << endl;
    }
    return 0;
}