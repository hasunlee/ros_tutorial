#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)	/*std_msgs패키지의 String 형태 메세지를 받았을때 반응*/
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");	// 노드명 초기화

  ros::NodeHandle n;			// ros 시스템과 통신을 위한 노드 핸들 선언. self같은거네

  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  // chatter라는 이름의 메세지를 받는 ros::Subscriber 개체를 선언
  /* chatter라는 잡지를 구독하고, 잡지가 오면 chatterCallback 함수를 실행하는 sub이라는 이름의 구독자 개체를 설정.*/
  ros::spin();	//메세지가 오기 전까지 아무것도 안하고 대기
  
  return 0;
}
