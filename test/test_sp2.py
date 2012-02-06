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

file = random.randint(65535, 131050)
time.sleep(20)
os.system("touch /tmp/test/%s" % file)

