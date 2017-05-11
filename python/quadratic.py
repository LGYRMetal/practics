#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from math import sqrt

def quadratic(a, b, c):
    y = sqrt(b ** 2 - 4 * a * c)
    x1 = (-b + sqrt(b ** 2 - 4 * a * c)) / (2 * a)
    x2 = (-b - sqrt(b ** 2 - 4 * a * c)) / (2 * a)

    return x1, x2
