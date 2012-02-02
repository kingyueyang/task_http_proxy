#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
    <+ MODULE_NAME +>

    <+ DESCRIPTION +>

    Licensed under the <+ LICENSE +> license, see <+ X +> for more details etc.
    Copyright by yueyang
"""

import httplib
import urllib

def post(url, params):
    conn = None
    conn = httplib.HTTPConnection(url)
    path = '/post'
    method = 'POST'
    try:
        conn.request(method, path, params)
    except:
        print "post: socket error"
        return
    try:
        rc = conn.getresponse()
    except:
        print "error"
        return

    buf = rc.read()
    print rc.status, rc.reason, buf

if __name__ == '__main__':
    print "POST: /post"
    post('10.10.140.146:8888', '/usr/bin/python,python,/tmp/echo.py')
    post('10.10.140.146:8888', '/usr/bin/python,python,/tmp/list.py')

