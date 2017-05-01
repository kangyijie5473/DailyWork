#!/usr/bin/env python
# -*- coding: utf-8 -*-

import xlrd
obj_name = raw_input("you want to see who?:")
#unicode(obj_name,"utf-8")
data = xlrd.open_workbook("cet.xlsx")
table = data.sheets()[0]

num_rows = table.nrows
for i in range(num_rows):
    if i == 1:
        continue
    li = table.row_values(i)
    uni_str = li[-6]
    utf_str = uni_str.encode("utf-8")
    #utf_str = uni_str 哈哈
    if utf_str == obj_name:
        obj_li = table.row_values(i)
        #print obj_li[-3].encode("utf-8")
        print obj_li[-5],obj_li[-4]

        continue
