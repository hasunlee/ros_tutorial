# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials) # 패키지명. package.xml과 동일해야함.

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)
# 필요한 패키지들을 기술해주는 부분

## Declare ROS messages and services
add_message_files(FILES Num.msg)
# 의존하는 메세지를 설정하는 옵션. 새로운 메세지

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)
# 새로운 메세지들을 만들때 필요한 패키지

## Declare a catkin package
catkin_package()
# 캐킨 패키지 옵션으로 라이브러리, 캐킨 빌드 의존성, 시스템 의존 패키지를 기술한다

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})
# ${catkin_INCLUDE_DIRS}:이미 공유된, 전체적인 디렉토리를 쓰는것
# include: include 폴더를 사용

# 각 실행파일(노드) 을 빌드할때 필요한 옵션들
add_executable(talker src/talker.cpp) ## talker 라는 이름의 노드를 만들껀데, 참고할 소스코드는 src/talker.cpp 파일을 참고할꺼야
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker beginner_tutorials_generate_messages_cpp) # 노드를 만들때 이런 dependencies를 참고해라. 먼저 이걸 실행해서 메세지를 만든 다음에 talker를 빌드해라.

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener beginner_tutorials_generate_messages_cpp)

# %EndTag(FULLTEXT)%
