# Define required cmake and c++ versions
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20 CACHE STRING "C++ standard version")
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(ZoreEngineTemplate)

list(PREPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Specify project files
file (GLOB_RECURSE PROJECT_MAIN_FILES "src/*.cpp" "src/*.hpp")
#file (GLOB_RECURSE PROJECT_SHADER_FILES "assets/shaders/*")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX "src" FILES ${PROJECT_MAIN_FILES})
#source_group("shaders" FILES ${PROJECT_SHADER_FILES})


# Add executable based on the source files
if(WIN32)
	# Switch this to MT to compile statically (rather than dynamically with dll)
	set(CMAKE_CXX_FLAGS_RELEASE "/MD")
	set(CMAKE_CXX_FLAGS_DEBUG "/MDd")

	add_executable(${PROJECT_NAME} WIN32 ${PROJECT_MAIN_FILES} ${PROJECT_SHADER_FILES})
	
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    #set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX _d)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
	#set_property(TARGET MyTarget PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
else()
	add_executable(${PROJECT_NAME} ${PROJECT_MAIN_FILES} ${PROJECT_SHADER_FILES})
endif(WIN32)
target_include_directories(${PROJECT_NAME} PUBLIC "src")

# Import libraries
include("cmake/CPM.cmake")
include("cmake/ZoreEngine.cmake")

target_link_libraries(${PROJECT_NAME} ZoreEngine)

# Copy over asset files
#file(COPY "assets" DESTINATION ${CMAKE_BINARY_DIR})