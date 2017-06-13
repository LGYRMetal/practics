#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys, mytimer, math

reps = 10000
repslist = range(reps)

def forLoop():
    res = []
    for x in repslist:
       #res.append(abs(x))
        res.append(x + 10)
    return res

def listComp():
   #return [abs(x) for x in repslist]
    return [x+10 for x in repslist]

def mapCall():
   #return list(map(abs, repslist))
    return list(map((lambda x: x + 10), repslist))

def genExpr():
   #return list(abs(x) for x in repslist)
    return list(x+10 for x in repslist)

def genFunc():
    def gen():
        for x in repslist:
           #yield abs(x)
            yield x+10
    return list(gen())

def mypow(x):
    return x ** 0.5

def math_sqrt(x):
    return math.sqrt(x)

def buildin_pow(x):
    return pow(x, 0.5)

print(sys.version)
for tester in (mytimer.timer, mytimer.best):
    print('<%s>' % tester.__name__)
    for test in (math_sqrt, buildin_pow, mypow):
        elapsed, result = tester(test, _reps=10000000)
        print('-' * 35)
        print('{0: <9}: {1: 0.5f} => [{2}...{3}]'.format(
            test.__name__, elapsed, result[0], result[-1]))
