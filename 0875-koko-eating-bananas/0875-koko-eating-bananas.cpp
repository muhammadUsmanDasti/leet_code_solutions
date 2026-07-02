class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        int minK = 1;
        int maxK = maxPile;
        int result = maxPile;
        while(minK <= maxK) {
            int k = minK + (maxK - minK) / 2;
            long long H = 0;
            for (int j = 0; j < piles.size(); j++) {
                H += (piles[j] + k - 1) / k;
            }
            if(H <= h) {
                maxK = k - 1;
                result = k;
            }
            else{
                minK = k + 1;
            }

        }
        return result;
    }
};