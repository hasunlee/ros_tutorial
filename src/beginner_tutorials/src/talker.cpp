#include "ros/ros.h" /* standard header to use ros */
#include "std_msgs/String.h"	/* stander message header file */
#include "beginner_tutorials/Num.h"	/* Num 메시지 파일 헤더 (빌드하면서 생성됨)*/
#include <sstream>

int main(int argc, char **argv)		//노드 메인 함수
{
  ros::init(argc, argv, "talker");	/* 노드명 초기화. rosmaster가 인식할 노드 명 */
  ros::NodeHandle n;			/* NodeHandle 이라는 도구상자의 이름을 n. 말그대로 핸들. 되며, n이 없어지면 노드도 shutdown된다*/
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  //Publisher 형태의 pub이라는 이름의  구조체(잡지 발행인 개체)를 선언할껀데, std_msgs::String 이라는 메세지 형태를 chatter라는 토픽이란 길로 발행하는 친구. subscriber는 chatter라는 길에서 이 메세지를 받는다.
// Publisher라는 구조체를 n.advertise 함수의 결과값으로 받는다. subsriber와 달리 직접 publish도 할수 있는 녀석이다.
 
  /* 1000(보통은 1)개까지 메세지를 저장해놓는, topic이름이 chatter, 메세지 종류는  std_msg::String>*/
  ros::Rate loop_rate(10);		/* rate_sleep 기준, 몇 Hz로 실행시킬지*/
  int count = 0;
  while (ros::ok())			/* Ctrl C 누르거나 shutdown 등이 되면 false 로 바뀜 */
  {
    std_msgs::String msg;		// std_msg::String 이라는 메세지 구조체  형식으로 msg라는 구조체 선언

    std::stringstream ss;
    ss << "hello world " << count;	/* ss는 클래스. ss.str은 그 안에 있는 문자열)*/
    msg.data = ss.str();		/* msg는 캐리어, 그 안에 어떤 이름의 변수들을 담느냐. ss.str은 그냥 c++ 에서 쓰던 str이니, ros 메세지에 넣어야지 */
// msg.score=count;


    ROS_INFO("%s", msg.data.c_str());	// printf같은거 
    chatter_pub.publish(msg);		/* publish라는 함수를 통해 잡지를 발행하는것 */
    ros::spinOnce();			// ros에서 보내온 대사관 같은 것이며, 루프를 돌며 subsriber에 떠먹여주는등 ros가 돌아가게 일을 한다.지금 당장 publisher에게 일을 하진 않지만, 나중에 다른 기능들을 껴넣으면 필요하게 될 수 있다. 	
    /*ros master는 누가 어디 구독했는지 갖다주는 곳. 우체국 */
    loop_rate.sleep();			/* 연산하고 남은 시간동안 쉬어*/
    ++count;
  }


  return 0;
}
