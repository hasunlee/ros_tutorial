# %Tag(FULLTEXT)%

# https://enssionaut.com/board_robotics/1264 홈페이지에 자세한 CMake 설명있음.
cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials) # 패키지명. package.xml과 동일해야함.

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)
# 필요한 패키지들을 기술해주는 부분.
# catkin REQUIRED: catkin과 관련한 기본 패키지들
# COMPNENTS : (roscpp, rospy...) 패키지들도 추가로 덧붙혀줘~

## Declare ROS messages and services
add_message_files(FILES Num.msg)
# 의존하는 메세지를 설정하는 옵션. 새로운 메세지

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)
# 새로운 메세지들을 만들때 필요한 패키지

## Declare a catkin package
catkin_package()
# 캐킨 관련 빌드 정보 지정. INCLUDE_DIRS는 뭐고, LIBRARIES는 뭐고, CATKIN_DEPENDS는 뭐고 이렇게 빌드 옵션들을 넣어준다.(명령어에 옵션 달듯이)

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})
# 빌드 시 필요한 header가 들어있는 directory들
# ${catkin_INCLUDE_DIRS}:_INCLUDE DIRS를 붙히면, catkin과 그 하위로 딸려있는 roscpp...등의 include 폴더까지 포함시킨다.
# include: include 폴더를 사용

# 각 실행파일(노드) 을 빌드할때 필요한 옵션들
add_executable(talker src/talker.cpp) ## talker 라는 이름의 실행파일(타겟, 노드)를 만들껀데, 참고할 소스코드는 src/talker.cpp 파일을 참고할꺼야(볶수개 코드도 지정 가능)
target_link_libraries(talker ${catkin_LIBRARIES}) # target: 빌드된 실행파일. talker라는 이름의 실행파일(타겟, 노드)을 빌드 할껀데, 빌드할 실행파일이 어떤 라이브러리에 링크 되어 있는지지를 작섷ㅇ.
add_dependencies(talker beginner_tutorials_generate_messages_cpp) # 빌드할때 메세지나 서비스, dynamic_reconfigure 파라미터를 새로 생성하여 사용할경우, 노드를 만들때 이런 dependencies를 참고해라. 먼저 이걸 실행해서 메세지를 만든 다음에 talker를 빌드해라.

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener beginner_tutorials_generate_messages_cpp)

# %EndTag(FULLTEXT)%
