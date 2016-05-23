#!/usr/bin/env python
# -*- coding:utf-8 -*-

"""
遍历目录中的所有文件和目录，并生成全路径
"""

import os


def generate_file_list(path, file_type=[]):
    """
    path: 遍历的路径
    file_type: 文件类型列表，如果为空遍历所有文件，不为空遍历指定文件如[".c", ".h", ".py"]等
    """

    walks = os.walk(path)
    for walk in walks:
        for file in walk[2]:
            if not file_type:  # empty
                yield walk[0] + "\\" + file
            else:
                root, ext = os.path.splitext(file)
                if ext in file_type:
                    yield walk[0] + "\\" + file


def generate_dir_list(path):

    walks = os.walk(path)
    for walk in walks:
        for dir_name in walk[1]:
            yield walk[0] + "\\" + dir_name
