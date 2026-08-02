#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSafe(int row , int col,int n,vector<vector<int>>& maze,vector<vector<int>>& visited){
        if(row>=0 && row<n && col<n && col>=0 && visited[row][col]!=1 && maze[row][col]!=0){
            return true;
        }
        return false;
    }

    void ratInMaze_helper(vector<vector<int>>& maze,vector<vector<int>>& visited, int row ,int col,vector<string>& ans,string path) {

        
        int n = maze.size();
        if(row== n-1 && col==n-1){
            ans.push_back(path);
            return;
        }
    
        visited[row][col]=1;

        //check down move
        if (isSafe(row+1,col,n,maze,visited)){
            ratInMaze_helper(maze,visited,row+1,col,ans,path+"D");
        }

        //Left
        if (isSafe(row,col-1,n,maze,visited)){
            ratInMaze_helper(maze,visited,row,col-1,ans,path+"L");
        }

        //Right
        if(isSafe(row,col+1,n,maze,visited)){
            ratInMaze_helper(maze,visited,row,col+1,ans,path+"R");
        }

        if(isSafe(row-1,col,n,maze,visited)){
            ratInMaze_helper(maze,visited,row-1,col,ans,path+"U");
        }

        //Backtrack
        visited[row][col]=0;
        //since path is being passed by value and not reference no need to modify it

        
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<vector<int>> visited(n,vector<int>(n,0));
        vector<string> ans;
        string path;

        if(maze[0][0]==0 || n==0){
            return ans;
        }

        ratInMaze_helper(maze,visited,0,0,ans,path);
        return ans;
        
    }
};