#-*- coding: utf-8 -*-

class Mylist(list):
    def __init__(self, start=[]):
        self.data = start[:]

    def __add__(self, other):
        print(self.__class__.__name__)
        return list.__add__(self, other)

    def __getitem__(self, index):
        print(self.__class__.__name__)
        return list.__getitem__(self, index)
