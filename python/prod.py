#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from functools import reduce

def prod(L):
    return reduce(lambda x, y: x * y, L)
