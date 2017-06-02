class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
       #return ' '.join(list(map(''.join, list(map(list, map(reversed, s.split()))))))
        return ' '.join(map(''.join,  map(reversed, s.split()))) # my
       #return ' '.join(x[::-1] for x in s.split())
       #return ' '.join(s.split()[::-1])[::-1]
