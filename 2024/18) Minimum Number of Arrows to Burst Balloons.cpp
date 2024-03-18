class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        int count=1;
        int prev_start=points[0][0];
        int prev_end=points[0][1];
        for(int i=1;i<n;i++){
            int curr_start=points[i][0];
            int curr_end=points[i][1];
            if(curr_start>prev_end){
                count++;
                prev_start=curr_start;
                prev_end=curr_end;
            }
            else{ //overlap
                prev_start=max(prev_start,curr_start);
                prev_end=min(prev_end,curr_end);
            }
        }
        return count;
    }
};