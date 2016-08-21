#!/bin/sh

#定义路径名
cur_dir=$(pwd)                       #当前脚本路径
cpp_proj_trunk_path="$cur_dir/../"   #trunk路径
profile_path="/home/$USER/.profile"            #用户配置文件

#在系统中声明全局变量
if [ ! $CPP_PROJ_PATH ]; then 
	echo "export CPP_PROJ_PATH=\"$cpp_proj_trunk_path\"" >> $profile_path
	source $profile_path
fi

#打印
echo "export cpp proj path succ, it is $CPP_PROJ_PATH"
