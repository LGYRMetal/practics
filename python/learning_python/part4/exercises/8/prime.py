#!/usr/bin/env python3
#-*- coding: utf-8 -*-

def prime(x):
    if x <= 1:
        print(x, 'is not prime')
    else:
        y = x // 2
        while y > 1:
            if x % y == 0:
                print(x, 'has factor', y)
                break
            y -= 1
        else:
            print(x, 'is prime')
