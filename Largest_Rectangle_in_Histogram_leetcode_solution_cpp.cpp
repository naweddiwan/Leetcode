#define height second
#define index first
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
    stack<pair<int, int>> s; //to make index height make
    pair<int, int> tp;       //to store top element of the stack
    int max_area = 0;
    int curr_area = 0;

    int i= 0;
    while(i<heights.size())
    {
        if(s.empty() || (s.top().height) <= heights[i])
        {
            s.push(make_pair(i, heights[i]));  
            i++;
        }
        else
        {
            tp = s.top();
            s.pop();
            if(s.empty())
                curr_area = tp.height *(i);
            else
                curr_area = tp.height *(i-(s.top()).index-1);

            if(max_area < curr_area)
                max_area = curr_area;
        }

        
    }
    while(!s.empty())
    {
         tp = s.top();
            s.pop();
            if(s.empty())
                curr_area = tp.height *(i);
            else
                curr_area = tp.height *(i-(s.top()).index-1);

            if(max_area < curr_area)
                max_area = curr_area;
    }
    return max_area;
    }
};
