class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        // vector<int> arr(n);
        // arr = asteroids;

        vector<int> st;

        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) st.push_back(arr[i]);

            else {
                while(!st.empty() && st.back() > 0 && st.back() < abs(arr[i])) {
                    st.pop_back();
                }
                
                if(!st.empty() && st.back() == abs(arr[i])) st.pop_back();
                
                // only storing -ve eles when the list is empty or top ele is already -ve so no collison could occur
                else if(st.empty() || st.back() < 0) st.push_back(arr[i]);
            }
        }

        return st;
    }
};