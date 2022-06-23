# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("zplayer")


# 设置生成的so动态库输出的路径
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})


#打印
message(WANNING "******************************************************************")
message(WANNING "CMAKE_SOURCE_DIR->" ${CMAKE_SOURCE_DIR})
message(WANNING "PROJECT_SOURCE_DIR->)" ${PROJECT_SOURCE_DIR})
message(WANNING "******************************************************************")
message(WANNING "1111------" ${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI})
message(WANNING "2222------" "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}")



AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src  SRC_LIST)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        zplayer

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${SRC_LIST})

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

#添加外部依赖的so
#add_library(
#        mpv
#        SHARED
#        IMPORTED)
#set_target_properties(
#        mpv
#        PROPERTIES IMPORTED_LOCATION
#        ${PROJECT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libmpv.so
#)
#include_directories(./include)

include_directories(${PROJECT_SOURCE_DIR}/include)


## 导入库文件
# CMAKE_SOURCE_DIR 等于 CMakeLists.txt所在的地址目录
# CMAKE_ANDROID_ARCH_ABI  等于 当前手机的CPU架构
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}")






target_link_libraries( # Specifies the target library.
        zplayer
        # Links the target library to the log library
        # included in the NDK.
        swscale
        avcodec
        mpv
        -llog
        -lGLESv3
        -lEGL
        -latomic)