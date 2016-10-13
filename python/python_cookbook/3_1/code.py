#!/usr/bin/python3

a = (1, 2, 3)
name = locals()

for x in a:
    name['n%s' %a.index(x)] = x
    print('n%s = %d' %(a.index(x), name['n%s' %a.index(x)]))
