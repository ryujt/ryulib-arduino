#ifndef PATTERNSERVER_H
#define PATTERNSERVER_H


#include <Arduino.h>


class PatternServer
{
private:
	bool is_position_changed_;
	int x_;
	int y_;
	char buffer_[4 * 1024];
	SocketUDP udp_;
private:
  void rp_pos(String line)
  {
      String pos_x = line.substring(0, 3);
      String pos_y = line.substring(4, 7);

      x_ = pos_x.toInt();
      y_ = pos_y.toInt();
      
      is_position_changed_ = true;
  }
public:
	PatternServer() 
		: is_position_changed_(false)
	{
	}

	void begin() 
	{
		udp_.begin(1122);
	}

	void execute() 
	{
		String line = udp_.readString();

    if (line.length() <= 0) return;

    Serial.println(line);

//    if (line.substring(0, 4).equals("Move")) rp_pos(line.substring(4, line.length()-4));
    rp_pos(line);
	}

	bool get_position() 
	{
		if (is_position_changed_) {
			is_position_changed_ = false;
			return true;
		} else {
			return false;
		}
	}

	int get_x() { return x_; }
	int get_y() { return y_; }
};

#endif // PATTERNSERVER_H
