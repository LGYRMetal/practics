#!/usr/bin/env python3
#-*- coding: utf-8 -*-

def copyDict(ordDict):
    d = {}
    for keys in ordDict:
        d[keys] = ordDict[keys]

    return d
