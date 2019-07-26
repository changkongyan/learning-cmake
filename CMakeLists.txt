# cmake最低版本
cmake_minimum_required(VERSION 3.8)

# 建立工程
# 自动生成各种内置变量
project(xiaoai)

# 设置当前可执行文件版本号
# The project version number.
set(VERSION_MAJOR   0   CACHE STRING "Project major version number.")
set(VERSION_MINOR   0   CACHE STRING "Project minor version number.")
set(VERSION_PATCH   1   CACHE STRING "Project patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

# 设置安装前缀
# Use this snippet *after* PROJECT(xxx):
IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR} CACHE PATH ... FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# 设置交叉编译工具链
# set(CMAKE_TOOLCHAIN_FILE ... )

# 设置c++11编译
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
        # 或者
        # add_definitions(-std=c++11)
elseif(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
        # 或者
        # add_definitions(-std=c++0x)
else()
     message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


# 设置编译Qt工程
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTORCC ON)

# find_package(Qt5 COMPONENTS Widgets DBus REQUIRED)
# if(Qt5_DIR)
# message(STATUS "find Qt5 include path:" ${Qt5_DIR} )
# else()
# message(STATUS "Don't find Qt5 include path:" ${Qt5_DIR} )
# endif()

# add_executable(... ....cpp)
# target_link_libraries(... Qt5::Widgets Qt5::DBus)

# find_package(Qt4 REQUIRED)
# add_executable(subscriber subscriber.cpp)
# target_link_libraries(subscriber Qt4::QtGui Qt4::QtDBus)


# 加入 greetings 库
add_subdirectory (greeting)  
include_directories ( ${PROJECT_SOURCE_DIR}/greeting )
# set 利用 cache 设置全局变量 
# cmake的字符串会自动拼接
set(EXTRA_LIBS ${EXTRA_LIBS} greeting)

# 查找当前目录的所有源文件
aux_source_directory(. DIR_SRCS)

# 生成可执行文件
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_executable(xiaoai ${DIR_SRCS})
target_link_libraries (xiaoai  ${EXTRA_LIBS})


# 生成开发文档
# dot  Graphviz dot utility used to render various graphs.
# mscgen Message Chart Generator utility used by Doxygen’s \msc and \mscfile commands.
# dia Dia the diagram editor used by Doxygen’s \diafile command.
# Require dot, treat the other components as optional
find_package(Doxygen REQUIRED dot OPTIONAL_COMPONENTS mscgen dia)
OPTION(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})
IF(BUILD_DOCUMENTATION)
    IF(NOT DOXYGEN_FOUND)
        MESSAGE(FATAL_ERROR "Doxygen is needed to build the documentation.")
    ENDIF()
    SET(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    SET(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    CONFIGURE_FILE(${doxyfile_in} ${doxyfile} @ONLY)
    ADD_CUSTOM_TARGET(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
    # INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION doc)
ENDIF()