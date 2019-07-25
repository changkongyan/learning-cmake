# cmake最低版本
cmake_minimum_required(VERSION 3.7)

# 建立工程
project(xiaoai)

# Use this snippet *after* PROJECT(xxx):
IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR} CACHE PATH ... FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# 交叉编译、c++11等 采用add_definitions 命令


# 加入 greetings 库
add_subdirectory (greeting)  
include_directories ( ${PROJECT_SOURCE_DIR}/greeting )
# set 利用cache 设置全局变量 
# cmake的字符串会自动拼接
set(EXTRA_LIBS ${EXTRA_LIBS} greeting)

# 查找当前目录的所有源文件
aux_source_directory(. DIR_SRCS)

# 生成可执行文件
add_executable(xiaoai ${DIR_SRCS})
target_link_libraries (xiaoai  ${EXTRA_LIBS})