#!/usr/bin/env python3
#-*- coding: utf-8 -*-

from addDict import addDict

def addSeqs(seq1, seq2):
    seqType1 = type(seq1)
    seqType2 = type(seq2)

    if seqType1 == dict and seqType2 == dict:
        return addDict(seq1, seq2)
    elif seqType1 != dict and seqType2 != dict:
        s = set(seq1)
        s = s.union(seq2)
        return seqType1(s)
    else:
        print("字典和序列不能求合并")
