#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
    <+ MODULE_NAME +>

    <+ DESCRIPTION +>

    Licensed under the <+ LICENSE +> license, see <+ X +> for more details etc.
    Copyright by yueyang
"""

import os
import random
import time

file = random.randint(1,65535)
time.sleep(10)
os.system("touch /tmp/test/%s" % file)

