cmake_minimum_required(VERSION 3.5)

# Project Name
project(engine)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add your source files here
set(SOURCE_FILES 
    engine_src/engine.cpp 
    utils/point.cpp
    utils/list.cpp
    utils/primitive.cpp
    # Add other source files as needed
)

# Set Toolkits_DIR
set(TOOLKITS_FOLDER "" CACHE PATH "Path to Toolkits folder")

# Set TinyXML directory
set(TINYXML_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/tinyXML")

# Add TinyXML library
add_library(tinyxml2 ${TINYXML_FOLDER}/tinyxml2.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if(WIN32)
    # Windows-specific settings
    if(NOT EXISTS "${TOOLKITS_FOLDER}/glut/GL/glut.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glut/glut32.lib")
        message(FATAL_ERROR "GLUT not found")
    endif()

    include_directories(${TOOLKITS_FOLDER}/glut)
    target_link_libraries(${PROJECT_NAME} ${TOOLKITS_FOLDER}/glut/glut32.lib)

    if(EXISTS "${TOOLKITS_FOLDER}/glut/glut32.dll")
        file(COPY ${TOOLKITS_FOLDER}/glut/glut32.dll DESTINATION ${CMAKE_BINARY_DIR})
    endif()

    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

else()

    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
    set(CMAKE_C_COMPILER "/usr/bin/clang")

    # Adiciona a flag -stdlib=libc++ para usar a biblioteca C++ do LLVM
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    # Linux and Mac-specific settings
    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)

    include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${TINYXML_FOLDER})
    target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} tinyxml2)
endif()
