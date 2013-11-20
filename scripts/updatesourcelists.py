#!/usr/bin/python

# Update source lists with the help of git ls-files
# Updates:
# executable target bossbrawl
# executable target brawledit
# ui target of brawledit

import subprocess
import os

def updatecmakelists(filename, begin_where, ls_what):
    f = open(filename, 'r')
    s = f.read()
    f.close()

    beg = s.find(begin_where)
    end = s.find(')', beg)

    filelist = subprocess.check_output(['git', 'ls-files'] + ls_what, cwd='./' + os.path.dirname(filename))
    
    # We also need to add some additional stuff to the brawledit target
    additional = ''
    
    if begin_where == 'add_executable(brawledit\n':
        additional = '${UIS_HDRS}\n'

    newstr = s[:beg] + begin_where + filelist.decode('utf-8') + additional + s[end:]
    
    f = open(filename, 'w')
    f.write(newstr)
    f.close()

# Update CMake build files

# Common modules
updatecmakelists('src/Common/CMakeLists.txt', 'add_library(map\n', ['Map'])
updatecmakelists('src/Common/CMakeLists.txt', 'add_library(util\n', ['Util'])
updatecmakelists('src/Common/CMakeLists.txt', 'add_library(entities\n', ['Entities'])

# Game
updatecmakelists('src/Game/CMakeLists.txt', 'add_executable(bossbrawl\n', ['Core', 'Gui', 'States'])

# Editor
updatecmakelists('src/Editor/CMakeLists.txt', 'add_executable(brawledit\n', ['*.cpp', '*.h', '*.hpp'])
updatecmakelists('src/Editor/CMakeLists.txt', 'qt5_wrap_ui(UIS_HDRS\n', ['*.ui'])
