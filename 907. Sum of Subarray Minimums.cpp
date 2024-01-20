class Solution {
public:
   const int MOD = 1000000007;

int sumSubarrayMins(std::vector<int>& arr) {
    int n = arr.size();
    std::stack<int> s1, s2;
    std::vector<long long> left(n), right(n, n);

    // Calculate left boundaries
    for (int i = 0; i < n; ++i) {
        while (!s1.empty() && arr[s1.top()] > arr[i]) {
            s1.pop();
        }
        left[i] = s1.empty() ? i + 1 : i - s1.top();
        s1.push(i);
    }

    // Calculate right boundaries
    for (int i = n - 1; i >= 0; --i) {
        while (!s2.empty() && arr[s2.top()] >= arr[i]) {
            s2.pop();
        }
        right[i] = s2.empty() ? n - i : s2.top() - i;
        s2.push(i);
    }

    // Calculate the final sum
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        result = (result + arr[i] * left[i] * right[i]) % MOD;
    }

    return static_cast<int>(result);
}

};
