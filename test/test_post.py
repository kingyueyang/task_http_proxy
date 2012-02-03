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
    import os
    os.system("cp test_sp1.py /tmp")
    os.system("cp test_sp2.py /tmp")
    os.system("mkdir /tmp/test")
    post('10.10.140.146:8888', '/usr/bin/python,python,/tmp/test_sp1.py')
    post('10.10.140.146:8888', '/usr/bin/python,python,/tmp/test_sp2.py')

