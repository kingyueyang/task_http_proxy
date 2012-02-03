#!/bin/sh

curl http://192.168.142.1:8888/post --data-ascii "/usr/bin/python,python,/tmp/echo.py"

