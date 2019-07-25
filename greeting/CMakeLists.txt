# 是否使用英文表达
option (ENGLISH "Use English setting" ON)

# get_filename_component(<VAR> FileName PATH|ABSOLUTE|NAME|EXT|NAME_WE|REALPATH [CACHE])
# 将变量<VAR>设置为路径(PATH)，文件名(NAME)，文件扩展名(EXT)，去掉扩展名的文件名(NAME_WE)，完整路径(ABSOLUTE)，或者所有符号链接被解析出的完整路径(REALPATH)。
# 注意，路径会被转换为Unix的反斜杠(/)，并且没有结尾的反斜杠。该命令已经考虑了最长的文件扩展名。
# 例如：get_filename_component(CURRENT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/nihao.cpp NAME_WE )

# 查询是否存在*.h.in文件
# 必须添加 /, 表示当前目录下的所有文件
file(GLOB CONFIG_FILES ${CMAKE_CURRENT_SOURCE_DIR}/ *.h.in) 
foreach(CONFIG_FILE ${CONFIG_FILES})
    get_filename_component(GENERATE_FILE ${CONFIG_FILE} NAME_WE )
    configure_file(${CONFIG_FILE} ${CMAKE_CURRENT_SOURCE_DIR}/${GENERATE_FILE}.h)
endforeach()


# 生成动态库、可执行文件的名称
# STRING(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}) 
# 或者
get_filename_component(CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} NAME_WE )
# message(STATUS "......CURRENT_FOLDER=" ${CURRENT_FOLDER} )

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)


# 生成静态链接库
# 优先生成静态库
add_library(${CURRENT_FOLDER} STATIC ${DIR_SRCS})
# 生成动态链接库
# 动态库需导入开发环境中
add_library(${CURRENT_FOLDER}_DYNAMIC SHARED ${DIR_SRCS})
set_target_properties(${CURRENT_FOLDER}_DYNAMIC PROPERTIES OUTPUT_NAME ${CURRENT_FOLDER})

# 按照规则，动态库是应该包含一个版本号的，
# VERSION指代动态库版本，SOVERSION指代API版本。
set_target_properties (${CURRENT_FOLDER} PROPERTIES VERSION 1.0 SOVERSION 1)

# 我们需要将动态库以及头文件和源码文件安装到系统目录，才能真正让其他人开发使用
# 在本例中我们将共享库安装到<prefix>/lib目录
# 将头文件安装<prefix>/include/目录
# ARCHIVE特指静态库,LIBRARY特指动态库,RUNTIME特指可执行目标二进制
INSTALL (TARGETS ${CURRENT_FOLDER}_DYNAMIC  ${CURRENT_FOLDER} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
# 配置所有头文件
file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/ *.h) 
INSTALL (FILES ${HEADER_FILES} DESTINATION include/${CURRENT_FOLDER})
