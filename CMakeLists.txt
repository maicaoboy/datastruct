cmake_minimum_required(VERSION 3.14)
project(CLion C)

#set(CMAKE_C_STANDARD 11)

# 指定为C++11 版本
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Status)
add_subdirectory(CourseBook)
add_subdirectory(ExerciseBook)
add_subdirectory(Handouts)
add_subdirectory(RealPaperExam)
