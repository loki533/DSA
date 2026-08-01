#include<bits/stdc++.h>
using namespace std;

/*Approach 
    First store the start,end,meeting no onto a data structure
    Later sort them based on their endin time
    Now iterate over it
        if end<start add the meeting number to the resultant array*/

class Solution {
public:
    // Function to get all meetings that can be scheduled
    vector<int> maxMeetings(vector<int>& start, vector<int>& end) {
        vector<tuple<int,int,int>> meetings;

        for(int i=0;i<start.size();i++){
            meetings.push_back({end[i],start[i],i+1}); //i+1 for the meeting no
        }

        sort(meetings.begin(),meetings.end());//sort based on end time
        
        vector<int> result;
        int lastend=-1;

        for(auto m:meetings){
            int e=get<0>(m); //end time 
            int s = get<1>(m);
            int id = get<2>(m);

            if(s > lastend){ //compare the start time
                result.push_back(id);
                lastend=e;
            }

        }

        return(result);
    }
};