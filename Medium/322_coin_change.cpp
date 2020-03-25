/*  322. Coin Change
 *
 *
 *  You are given coins of different denominations and a total amount of money amount. 
 *  Write a function to compute the fewest number of coins that you need to make up that amount. 
 *  If that amount of money cannot be made up by any combination of the coins, return -1.
 *
 *	Example 1:
 *
 *	Input: coins = [1, 2, 5], amount = 11
 *	Output: 3 
 *	Explanation: 11 = 5 + 5 + 1
 *
 *	Example 2:
 *
 *	Input: coins = [2], amount = 3
 *	Output: -1
 *	
 *	Note:
 *	You may assume that you have an infinite number of each kind of coin.
 *
*/

const int INF = 1e9 + 5;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (int sum = 1; sum <= amount; sum++) {
            for (int coin : coins) {
                if (sum - coin >= 0)
                    dp[sum] = min(dp[sum], dp[sum - coin] + 1);
            }
        }
        if (dp[amount] == INF)
            return -1;
        else
            return dp[amount];
    }
};
