#!/usr/bin/env python
# -*- coding: utf-8 -*-
import xlrd

obj_bir = raw_input("you want to find id number?:")
unicode(obj_bir,"utf-8")
print type(obj_bir)

data = xlrd.open_workbook("cet.xlsx")
table = data.sheets()[0]

num_rows = table.nrows
for i in range(num_rows):
    if i == 1:
        continue
    li = table.row_values(i)
    uni_str = li[-4]    #这里用type()测试为unicode
    uni_sch_num = li[7]
    uni_sch_num = uni_sch_num[2:4]
    uni_str = uni_str[0:6]
    utf_str = uni_str.encode("utf-8")
    if uni_sch_num.encode("utf-8") != "15":
        continue
    if utf_str == obj_bir:
        obj_li = table.row_values(i)
        print obj_li[6].encode("utf-8")+obj_li[8].encode("utf-8")+obj_li[-4].encode("utf-8")
        continue

