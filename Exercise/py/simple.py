#!/usr/bin/env python
# coding=utf-8
def cal_mean(readings):
    readings_total = sum(readings)
    number_of_readings = len(readings)
    mean = readings_total / number_of_readings
    return mean
from math import pow
def cal_variance(readings):
    readings_mean = cal_mean(readings)
    mean_difference_
