#!/usr/bin/python3

#replacing makefile script with python because im dumb
import os
import platform
import build.build as build

if platform.system() == "Linux":
    build.build()
else:
    print("OS not supported\nCreate a github issue and ill try and add support")
