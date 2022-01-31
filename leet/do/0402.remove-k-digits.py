class Solution:
    def minNum(self, num, k, i):
        print(num, k, i)
        if k == 0:
            return int(num)
        if i == len(num):
            return int(num)
        return min(
            Solution.minNum(self, num[0:i] + num[i + 1 :], k - 1, i),
            Solution.minNum(self, num, k, i + 1),
        )

    def removeKdigits(self, num: str, k: int) -> str:
        if k >= len(num):
            return str(0)
        return str(Solution.minNum(self, num, k, 0))
