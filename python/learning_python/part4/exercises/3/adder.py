#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def adder(*args):
    if args:
        s = list(args).pop(0)
        args = list(args)[1:]
    else:
        return None

    for i in args:
        s += i
    return s

print(adder('a', 'b'), type(adder('a', 'b')))
print(adder([1], [2]), type(adder([1], [2])))
print(adder(1.0, 2.0), type(adder(1.0, 2.0)))
print(adder(), type(adder()))
print(adder(1), type(adder(1)))
print(adder({0: 0, 1: 1}), type(adder({0: 0, 1: 1})))
#print(adder({0: 0, 1: 1}, {2: 2}), type(adder({0: 0, 1: 1}, {2: 2})))
