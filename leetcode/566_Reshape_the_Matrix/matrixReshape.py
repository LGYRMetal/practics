class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        row = len(nums)
        col = len(nums[0])

        if row * col == r * c:
            tmp = []
            for i in range(row):
                for j in range(col):
                    tmp.append(nums[i][j])
            tmp.reverse()
            l1 = []
            l2 = []
            for i in range(r):
                for j in range(c):
                    l1.append(tmp.pop())
                l2.append(l1)
                l1 = []
            return l2
        else:
            return nums
