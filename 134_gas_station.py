class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        res = -1
        rsum = 0
        for (i, j) in zip(gas, cost):
            rsum += i - j

        if rsum < 0:
            return res

        rsum = 0
        for i in range(len(gas)):
            rsum += gas[i] - cost[i]
            if rsum < 0:
                rsum = 0
                res = -1
            elif (res == -1):
                res = i
            
        return res
