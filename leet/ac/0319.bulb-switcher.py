class Solution:
    def bulbSwitch(self, n: int) -> int:
        bulbs = [False for i in range(0, n)]
        sm = 0
        for i in range(0, n):
            for j in range(i, n, i + 1):
                bulbs[j] = not bulbs[j]
            print(i, sum(bulbs[0 : i + 1]), bulbs[0 : i + 1])
            sm = sm + bulbs[i]
        return sm
