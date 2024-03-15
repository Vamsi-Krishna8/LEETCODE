//Explanation Link : https://leetcode.com/problems/furthest-building-you-can-reach/solutions/4881190/c-easy-layman-solution-with-clear-explanation-comments

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        int i=0;
        for(i=0;i<heights.size()-1;i++){
            int diff=heights[i+1]-heights[i];
            // Only consider positive differences where a jump is needed
            if(diff>0){ // Use a ladder for this jump,by adding to the min-heap
                pq.push(diff);
                // If we have used more ladders than available,
                // replace the smallest ladder-used jump with bricks
                if(pq.size()>ladders){
                    bricks-=pq.top(); // Use bricks for the smallest jump we've used a ladder on so far
                    pq.pop(); // Remove this jump as we're now using bricks instead of a ladder
                }
            }
            // If we run out of bricks, we can't move to the next building
            if(bricks<0) return i; // Return the last building index we could reach
        }
        return i; // If we haven't run out of resources, return the last building we could reach
    }
};