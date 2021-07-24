# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)#cmake 变量识别大小写
project(my_cmake)#project标签必须卸载前面，后面路径才会打印

message(LLL,${PROJECT_BINARY_DIR})#编译产生文件 保存地址 C:/Users/zhixun/AndroidStudioProjects/MyApplication/app/.cxx/cmake/debug/armeabi-v7a
message(BIAN,${PROJECT_SOURCE_DIR})#c代码所处的位置 C:/Users/zhixun/AndroidStudioProjects/MyApplication/app/src/main/cpp
message(cmake,${CMAKE_SOURCE_DIR})
include_directories(include) #加载这个目录下面所有 头文件，包含子目录， 这样在cpp中引用头文件可以不用写具体路径

#add_library(app native-lib.cpp test.cpp)# 添加源文件，生成可执行文件 app （本例缺乏main ，在native-lib.cpp中添加即可）
add_library(mymymyapp STATIC include/test.cpp)# 生成可执行文件, 默认静态
#message(libLS23.a路径 ${PROJECT_SOURE_DIR}/lib/libLS23.a)
#引用代码库-------------------------------------------------------------
add_library(staticFiled SHARED IMPORTED)# 1.首先定义个变量 staticFiled 经验类型 static 作用是 导入
include_directories(include)#2.导入库相匹配的头文件
#set_property(TARGET staticFiled PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/lib/app1)# 3. 为变量指定库指定库
#set_target_properties(staticFiled PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/lib/libapp.so)
#target_link_libraries(staticFiled)# 4. 添加链接,在下面一起添加，否则会被覆盖
#---------------------------------------------------------------------------

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        native-lib.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        native-lib
#        staticFiled
        mymymyapp
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})
