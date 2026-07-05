class Solution {
public:

     vector<int> findNGE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n); // to store idx of nse's of all elements

        stack<int> st;

        for(int i=n-1;i>=0;i--) {
            
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i); // push the idx of the current ele
        }
        return ans;
    }

    // find prev greater or equal ele to handle edge case like [1, 1] to not count same subarray twice
    vector<int> findPGEE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;

        for(int i=0;i<n;i++) {
            
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i); 
        }
        return ans;
    }

    vector<int> findNSE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n); // to store idx of nse's of all elements

        stack<int> st;

        for(int i=n-1;i>=0;i--) {
            
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i); // push the idx of the current ele
        }
        return ans;
    }

    // find prev smaller or equal ele to handle edge case like [1, 1] to not count same subarray twice
    vector<int> findPSEE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;

        for(int i=0;i<n;i++) {
            
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i); 
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        long long sum = 0;

        for(int i = 0; i < n; i++) {
            
            int left = i - psee[i]; // count contribution from left
            int right = nse[i] - i; // count contri from right

            long long freq = left *right * 1LL; //  total freq of ele in subarrays

            long long val = (freq*arr[i]*1LL); // final total value with contribution of a ele

            sum = (sum + val); // adding value to the sum
        }
        return sum;
    };

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse = findNGE(arr);
        vector<int> psee = findPGEE(arr);

        long long sum = 0;

        for(int i = 0; i < n; i++) {
            
            int left = i - psee[i]; // count contribution from left
            int right = nse[i] - i; // count contri from right

            long long freq = left *right * 1LL; //  total freq of ele in subarrays

            long long val = (freq*arr[i]*1LL); // final total value with contribution of a ele

            sum = (sum + val); // adding value to the sum
        }
        return sum;
    };

    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumSubarrayMaxs(nums);
        long long minSum = sumSubarrayMins(nums);

        return (maxSum - minSum);
    }
};