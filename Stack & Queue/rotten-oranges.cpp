#include<bits/stdc++.h>
using namespace  std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int total_rows = grid.size();
        int total_cols = grid[0].size();
        int fresh = 0;

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(total_rows, vector<int>(total_cols, 0));

        //insert each rotten orange onto the queue
        for(int i = 0 ; i<total_rows ; i++){
            for(int j = 0 ; j<total_cols ; j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 1; //mark them visited
                    q.push({{i,j},0});
                }
                else if (grid[i][j] == 1){//fresh orange
                    fresh++;
                }
            }
        }

        if(fresh == 0 ){//if there are no fresh oranges in the first place
            return 0;
        }

        int time = 0;
        int max_time = INT_MIN;
        int del_row[] = {-1,0,1,0}; 
        int del_col[] = {0,1,0,-1};
        int rotten = 0;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            max_time = max(t,max_time);


            for(int i = 0 ; i<4 ;i++){
                int n_row = row + del_row[i];
                int n_col = col + del_col[i];
                if(n_col>=0 && n_col <  total_cols  && n_row >=0 && n_row < total_rows && visited[n_row][n_col] !=1 && grid[n_row][n_col] == 1){
                    q.push({{n_row,n_col},t+1});
                    visited[n_row][n_col] = 1;
                    rotten++;
                }
            }
        }

        if(rotten != fresh){
            return -1;
        }

        return max_time;


    }
};
