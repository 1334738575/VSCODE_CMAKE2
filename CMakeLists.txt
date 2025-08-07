cmake_minimum_required(VERSION 3.20)
project(VscodeCmake)

# project(VscodeCmake LANGUAGES CXX CUDA)

# ################################set#################################
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-g)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -g")

# ################################package#################################
set(Eigen3_DIR "C:\\Users\\DELL\\Desktop\\code\\eigen\\install2\\share\\eigen3\\cmake")
find_package(Eigen3)

# # enable_language(CUDA)
# find_package(CUDA)
# set(CMAKE_CUDA_ARCHITECTURES 89)
# message(STATUS "cuda include: ${CUDA_INCLUDE_DIRS}")
# message(STATUS "cuda include: ${CUDA_LIBRARIES}")

# ################################code#################################
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB ALL_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB ALL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB SUB_DIR "${SRC_DIR}/*")

foreach(ITEM ${SUB_DIR})
    if(IS_DIRECTORY ${ITEM})
        file(GLOB TMP_HEADER ${ITEM}/*.h)
        file(GLOB TMP_SRC ${ITEM}/*.cpp ${ITEM}/*.cu)
        list(APPEND ALL_HEADER ${TMP_HEADER})
        list(APPEND ALL_SRC ${TMP_SRC})
    endif()
endforeach()

# ################################library#################################
message(STATUS "source code: ${ALL_SRC}")
add_library(${PROJECT_NAME} SHARED
    ${ALL_HEADER}
    ${ALL_SRC}
)

# ################################include#################################
set(THIRD_HEADERS)

list(APPEND THIRD_HEADERS ${EIGEN3_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${THIRD_HEADERS}>
)

# ################################link#################################
set(THIRD_LIBRARIES)

list(APPEND THIRD_LIBRARIES Eigen3::Eigen)
# list(APPEND THIRD_LIBRARIES ${CUDA_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PUBLIC
    ${THIRD_LIBRARIES}
)

# ################################example#################################
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(test test/test.cpp)
target_link_libraries(test ${PROJECT_NAME})

# ################################install#################################
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/install)
set(TARGETNAME ${PROJECT_NAME}Targets)

# 安装库和头文件
install(TARGETS ${PROJECT_NAME}
    EXPORT ${TARGETNAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib # DLL 在 Windows 下会被安装到 bin/
    RUNTIME DESTINATION bin # 适用于 DLL 的运行时组件
    INCLUDES DESTINATION include
)

# install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
# DESTINATION include
# FILES_MATCHING PATTERN "*.h"  # 仅复制 .h 文件
# #   PATTERN "mylib" EXCLUDE       # 排除子目录
# )
install(FILES ${ALL_HEADER}
    DESTINATION include

    # PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
)

# 导出目标配置
install(EXPORT ${TARGETNAME}
    FILE ${TARGETNAME}.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION lib/cmake
)

# 生成包配置文件
include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION lib/cmake
)
write_basic_package_version_file(
    ${PROJECT_NAME}ConfigVersion.cmake
    VERSION 1.0.0
    COMPATIBILITY SameMajorVersion
)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION lib/cmake
)