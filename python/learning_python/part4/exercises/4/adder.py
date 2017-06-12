#!/usr/bin/env python3
#-*- coding: utf-8 -*-

def adder(good=0, bad=0, ugly=0):
    return good+bad+ugly

def adder1(**kargs):
    if kargs:
        keys = list(kargs.keys())
        s = kargs[keys.pop(0)]
    else:
        return None

    for i in keys:
        s += kargs[i]
    return s
