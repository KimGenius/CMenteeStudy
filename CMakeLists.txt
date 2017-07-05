cmake_minimum_required(VERSION 3.7)
project(MenteeStudy)

set(CMAKE_C_STANDARD 99)

#set(SOURCE_FILES A_PrintExam.c)
#set(SOURCE_FILES B_ValueExam.c)
#set(SOURCE_FILES exam/stack1.c)
#set(SOURCE_FILES exam/list.c)
#set(SOURCE_FILES exam/stack_q1.c)
#set(SOURCE_FILES exam/queue_q1.c)
#set(SOURCE_FILES exam/listQueue.c)
set(SOURCE_FILES exam/listqueue_q1.c)
add_executable(MenteeStudy ${SOURCE_FILES})