#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys, mytimer

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

print(sys.version)
for tester in (mytimer.timer, mytimer.best):
    print('<%s>' % tester.__name__)
    for test in (forLoop, listComp, mapCall, genExpr, genFunc):
        elapsed, result = tester(test)
        print('-' * 35)
        print('%-9s: %.5f => [%s...%s]' %
                (test.__name__, elapsed, result[0], result[-1]))
