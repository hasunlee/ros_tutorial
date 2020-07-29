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
// sub라는 구조체를 n.subcribe함수의 결과값으로 받는다. sub 구조체 자체는 켜고 끄는거 밖에 못한다. 그냥 살아있냐 아니냐만 기능.
  /* chatter라는 잡지를 구독하고, 잡지가 오면 chatterCallback 함수를 실행하는 sub이라는 이름의 구독자 개체를 설정.*/
  ros::spin();	// spinOnce를 무한번 계속 호출하는 놈. spinOnce는 ros에서 보내온 대사관. 위에 subscribe 선언만 되어있으면 의미가 없으니, subcribe 개체를 위해 도착한게 있는지 보고, 있으면 subcribe를 작동하게 하여 Callback을 작동하도록 계속 한다.
  
  return 0;
}
