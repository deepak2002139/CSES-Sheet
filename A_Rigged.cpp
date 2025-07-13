
//                                                       A Template by Deepak Kumar

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n, vl(2));
        cin >> nums[0][0] >> nums[0][1];
        vector<int> dp(n, INT_MIN);
        dp[1] = nums[1][0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i][0] < nums[0][0] && nums[i][1] >= nums[0][1])
            {
                dp[i]=min(dp[i],nums[i][0]);
            }
            else
            {
                dp[i] = INT_MIN;
            }
        }

        if (dp[n - 1] == INT_MIN)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dp[n - 1] - 1 << endl;
        }
    }
    return 0;
}
