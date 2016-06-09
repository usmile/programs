#!/usr/bin/python
# -*- coding:utf-8 -*-

import os

def file_list(path, file_type=[]):
    """
    get all files in the specified path
        path: root_path
        file_type: filter file types [".c", ".h", ".py"]
    """
    walks = os.walk(path)
    for walk in walks:
        for file in walk[2]:
            if not file_type:  # empty
                yield os.path.join(walk[0], file)
            else:
                root, ext = os.path.splitext(file)
                if ext in file_type:
                    yield os.path.join(walk[0], file)


def dir_list(path):
    '''
    get all dirs in the specified path
    '''
    walks = os.walk(path)
    for walk in walks:
        for dir_name in walk[1]:
            yield os.path.join(walk[0], dir_name)


if __name__ == '__main__':
    path = r"./"

    for i in dir_list(path):
        print(i)

    for j in file_list(path, [".py"]):
        print(j)
