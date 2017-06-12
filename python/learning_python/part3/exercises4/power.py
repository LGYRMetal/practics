#!/usr/bin/env python3
#-*- coding: utf-8 -*-

"""
L = [1, 2, 4, 8, 16, 32, 64]
X = 5

found = False
i = 0
while not found and i < len(L):
    if 2 ** X == L[i]:
        found = True
    else:
        i = i+1

if found:
    print('at index', i)
else:
    print(X, 'not found')
"""

# a. 首先，以while循环else分句重写这个代码来消除found标志位和最终的if语句。
"""
L = [1, 2, 4, 8, 16, 32, 64]
X = 5

i = 0
while L[i] != 2 ** X:
    i += 1
else:
    if i < len(L):
        print('at index', i)
    else:
        print(X, 'not found')
"""

# b. 接着，使用for循环和else分句重写这个例子，去掉列表索引运算逻辑。提示：
#    要取得元素的索引，可以使用index方法（L.index(X)返回列表L中第一个X的
#    偏移值）。
"""
L = [1, 2, 4, 8, 16, 32, 64]
X = 5

for i in L:
    if i == 2 ** X:
        print('at index', L.index(i))
        break;
else:
    print(X, 'not found')
"""

# c. 接着，重写这个例子，改用简单的in运算符成员关系表达式，从而完全移除循环
#    （参考第8章的细节，或者以这种方式来测试：2 in [1, 2, 3]）
"""
L = [1, 2, 4, 8, 16, 32, 64]
X = 5

if 2 ** X in L:
    print('at index', L.index(2 ** X))
else:
    print(X, 'not found')
"""

# d. 最后， 使用for循环和列表append方法来产生2列表（L），而不是通过列表常量
#    硬编码。
"""
L = []
X = 5
for i in range(7):
    L.append(2 ** i)
print(L)

if 2 ** X in L:
    print('at index', L.index(2 ** X))
else:
    print(X, 'not found')
"""

# e. 把2 ** X表达式移到循环外，这样能够改善性能吗？(能, 每次循环都计算一次，
#    比只计算一次性能要好)如何编写代码？
"""
L = [1, 2, 4, 8, 16, 32, 64]
X = 5

found = False
target = 2**X
i = 0
while not found and i < len(L):
    if target == L[i]:
        found = True
    else:
        i = i+1

if found:
    print('at index', i)
else:
    print(X, 'not found')
"""

# f. 就像我们在练习题1中所看到过的，Python有一个map(function, list)工具也可
#    以产生2次方值的列表：map(lambda x: 2 ** x, range(7))。试着在交互模式下
#    输入这段代码；我们将会在第19章正式引入lambda。
X = 5
L = list(map(lambda x: 2 ** x, range(7)))

if 2 ** X in L:
    print('at index', L.index(2 ** X))
else:
    print(X, 'not found')

