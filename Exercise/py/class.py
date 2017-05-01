#!/usr/bin/env python
# coding=utf-8

__metaclass__ = type

class bird:
    def __init__(self):
        self.hungry = True
    def eat(self):
        if self.hungry:
            print "eating"
            self.hungry = False
        else:
            print "No"

class SingBird(bird):
    def __init__(self):
        super(SingBird, self).__init__()
        self.sound = "oh oh oh"
    def sing(self):
        print self.sound

sb = SingBird()
sb.sing()
sb.eat()
