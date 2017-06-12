#!/usr/bin/env python3
#-*- coding: utf-8 -*-

def addDict(dict1, dict2):
    d = {}
    keys = set(dict1.keys())
    keys.update(set(dict2.keys()))

    for k in keys:
        d[k] = dict1.get(k, dict2.get(k))

    return d
