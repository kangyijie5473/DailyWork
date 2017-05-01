#!/usr/bin/env python
# coding=utf-8
# Jack Kang

import xlrd
data = xlrd.open_workbook("cet.xlsx")
table = data.sheets()[0]

num_rows = table.nrows
for i in range(num_rows):
    if i == 1:
        continue
    li = table.row_values(i)
    uni_str = li[7];
    str = uni_str[0:3]
    if str == "140":
        print uni_str


