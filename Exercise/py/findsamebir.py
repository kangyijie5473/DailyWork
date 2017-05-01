#!/usr/bin/env python
# coding=utf-8
import xlrd

obj_bir = raw_input("you want to see bir?:")
unicode(obj_bir,"utf-8")

data = xlrd.open_workbook("cet.xlsx")
table = data.sheets()[0]

num_rows = table.nrows
for i in range(num_rows):
    if i == 1:
        continue
    li = table.row_values(i)
    uni_str = li[-4]
    uni_str = uni_str[6:14]
    #print uni_str
    #utf_str = uni_str.encode("utf-8")
    if uni_str == obj_bir:
        obj_li = table.row_values(i)
        print obj_li[6].encode("utf-8")+obj_li[8].encode("utf-8")
        continue

