#!/usr/bin/env python
# coding=utf-8
from  xpinyin  import Pinyin
import xlrd


obj_name = input("you want to see who?:")

data = xlrd.open_workbook("cet.xlsx")
table = data.sheets()[0]

num_rows = table.nrows
for i in range(num_rows):
    if i == 1:
        continue
    li = table.row_values(i)
    utf_str = li[8]
    test = Pinyin()
    pinyin_str =  test.get_pinyin(utf_str)
    #print(pinyin_str)
    if pinyin_str == obj_name:
        obj_li = table.row_values(i)
        print (obj_li[6])

