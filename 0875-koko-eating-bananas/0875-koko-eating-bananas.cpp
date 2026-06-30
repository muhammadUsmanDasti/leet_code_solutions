#include <cmath>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = piles[0];
        for(int i = 0; i < piles.size(); i++) {
            if(piles[i] > maxPile) {
                maxPile = piles[i];
            }
        }
        int minK = 1;
        int maxK = maxPile;
        int result = 0;
        while(minK <= maxK) {
            int k = minK + (maxK - minK) / 2;
            long H = 0;
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