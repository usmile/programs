#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
from os.path import join, getsize
from hashlib import sha256

vnfd = r"C:\Users\boy\Desktop\study\vnfd"
need_sha256_dir = ["blueprints", "scripts"]


vercfg = ""

file_xml_fmt = '''\
    <file>{0}</file>
    <sha256>{1}</sha256>
'''


def gen_sha256_string(input_str):
    return "sha256sum: "  + input_str


def get_sha256_file(file):
    with open(file, "r") as f:
        content = f.read()
        s = gen_sha256_string(content)
        return s


def os_walk(path):
    files = []
    if "blueprints" in path:
        files.append(os.path.join(path, "basic.yaml"))
    elif "scripts" in path:
        files.append(os.path.join(path, "mml.yaml"))
        files.append(os.path.join(os.path.join(path, "upgrade"), "main.sh"))
    return files


def get_sha256_xml(file, sha256sum):
    return file_xml_fmt.format(file, sha256sum)


for root, dirs, files in os.walk(vnfd):
    break

for _dir in dirs:
    if _dir in need_sha256_dir:
        files = os_walk(os.path.join(vnfd, _dir))
        for file in files:
            xml = get_sha256_xml(os.path.relpath(file, vnfd).replace("\\", "/"), get_sha256_file(file))
            vercfg = vercfg + xml

print(vercfg)
