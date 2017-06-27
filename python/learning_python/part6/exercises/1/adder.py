#-*- coding: utf-8 -*-

class Adder:
    def __init__(self, data=[]):
        self.data = data

    def __add__(self, other):
        return self.add(self.data, other)

    def add(self, x, y):
        print("Not Implemented")

class ListAdder(Adder):
    def add(self, list1, list2):
        return list1 + list2

class DictAdder(Adder):
    def add(self, dict1, dict2):
        d = {}
        for key in dict1:
            d[key] = dict1[key]
        for key in dict2:
            d[key] = dict2[key]

        return d
