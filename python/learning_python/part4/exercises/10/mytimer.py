#!/usr/bin/env python3
#-*- coding: utf-8

# version 3 (3.x only)
"""
Use 3.0 keyword-only default arguments, instead of ** and dict pops.
No need to hoist range() out of test in 3.0: a generator, not a list
"""
import time, sys
trace = lambda *args: None # or print
timefunc = time.clock if sys.platform == 'win32' else time.time

def timer(func, *pargs, _reps=1000, **kargs):
    res = []
    trace(func, *pargs, kargs, _reps)
    start = timefunc()
    for i in range(_reps):
        ret = func(i)
        res.append(ret)
    elapsed = timefunc() - start
    return (elapsed, res)

def best(func, *pargs, _reps=50, **kargs):
    best = 2 ** 32
    res = []
    for i in range(_reps):
        (time, ret) = timer(func, *pargs, _reps=1, **kargs)
        res += ret
        if time < best: best = time
    return (best, res)

# version 2
"""
timer(spam, 1, 2, a=3, b=4, _reps=1000) calls and times spam(1, 2, a=3)
_reps times, and returns total time for all runs, with final result;

best(spam, 1, 2, a=3, b=4, _reps=50) runs best-os-N timer to filter out
any system load variation, and returns best time among _reps tests
"""

"""
import time, sys

if sys.platform[:3] == 'win':
    timefunc = time.clock   # Use time.clock on Windows
else:
    timefunc = time.time    # Better resolution on some Unix platforms

def trace(*args): pass      # Or: print args

def timer(func, *pargs, **kargs):
    _reps = kargs.pop('_reps', 1000) # Passed-in or default reps
    trace(func, pargs, kargs, _reps)
    repslist = range(_reps) # Hoist range out of for 2.6 lists
    start = timefunc()
    for i in repslist:
        ret = func(*pargs, **kargs)
    elapsed = timefunc() - start
    return (elapsed, ret)

def best(func, *pargs, **kargs):
    _reps = kargs.pop('_reps', 50)
    best = 2 ** 32
    for i in range(_reps):
        (time, ret) = timer(func, *pargs, _reps=1, **kargs)
        if time < best: best = time
    return (best, ret)
"""

# version 1
"""
import time
reps = 1000
repslist = range(reps)

def timer(func, *pargs, **kargs):
    start = time.clock()
    for i in repslist:
        ret = func(*pargs, **kargs)
    elapsed = time.clock() - start
    return (elapsed, ret)
"""
