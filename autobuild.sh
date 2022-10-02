#########################################################################
# File Name: autobuild.sh
# Author: ZHONG
# mail: 1324418453@qq.com
# Created Time: 2022年04月2日 星期日 18时40分28秒
#########################################################################
#!/bin/bash

set -x

rm -rf `pwd`/build/*
cd `pwd`/build &&
	cmake .. &&
	make
