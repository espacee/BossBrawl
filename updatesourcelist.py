#!/usr/bin/python

# Update source list with git ls-files

import subprocess

f = open('CMakeLists.txt', 'r')
s = f.read()
f.close()

beg = s.find('add_executable(bossbrawl\n')
end = s.find(')', beg)

filelist = subprocess.check_output(['git', 'ls-files', 'src'])

newstr = s[:beg] + 'add_executable(bossbrawl\n' + filelist.decode('utf-8') + s[end:]
f = open('CMakeLists.txt', 'w')
f.write(newstr)
