#!/usr/bin/env python3
# -*- coding: utf-8 -*-

height = float(input('请输入你的身高, 单位(米): '))
weight = float(input('请输入你的体重, 单位(公斤): '))

#bmi = weight / (height * height)
bmi = weight / height ** 2 

if bmi <= 18.5:
    #print('过轻')
    result = '过轻'
elif bmi > 18.5 and bmi <= 25:
    #print('正常')
    result = '正常'
elif bmi > 25 and bmi <=28:
    #print('过重')
    result = '过重'
elif bmi > 28 and bmi <=32:
    #print('肥胖')
    result = '肥胖'
elif bmi > 32:
    #print('严重肥胖')
    result = '严重肥胖'

print('你的BMI指数是 %.1f, %s' % (bmi, result))
