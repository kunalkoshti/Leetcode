class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        unordered_map<int, vector<int>> mp;
        mp[0] = {9, 1};
        mp[1] = {9, 2};
        mp[2] = {1, 1};
        mp[3] = {1, 2};
        mp[4] = {1, 3};
        mp[5] = {1, 4};
        mp[6] = {1, 5};
        mp[7] = {1, 6};
        mp[8] = {1, 7};
        mp[9] = {1, 8};
        int nums1 = 0, nums2 = 0, mul = 1;
        int carr = 0;
        while (n > 0) {
            int num = ((n % 10 - carr) + 10) % 10;
            if (n <= 9) {
                if (num == 0)
                    break;
                else if (num == 1)
                    nums1 += mul;
                else {
                    nums1 += mp[num][0] * mul;
                    nums2 += mp[num][1] * mul;
                }
            } else {
                int x = mp[num][0], y = mp[num][1];
                nums1 += x * mul;
                nums2 += y * mul;
                carr = (x + y+carr) / 10;
            }
            n /= 10;
            mul *= 10;
        }
        return {nums1, nums2};
    }
};