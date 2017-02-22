// 다음 MCU에서만 동작한다.  NodeMCU와 충돌하여 제한을 둠
#if defined(__AVR_ATmega328P__)  || defined(__AVR_ATmega32U4__)

#ifndef RYUGAME_H
#define RYUGAME_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <LinkedList.h>


class GameEngine;
class GameLayer;

class GameControlBase
{
protected:
	Adafruit_PCD8544 *_LCD;
	GameEngine *_Engine;
	GameLayer *_Layer;

	byte _ID = 0;

	// Radius of hit area.  
	// _HitSize is limitation of distance when check collision of two GameControlBase objects.
	byte _HitSize = 0;

	bool _IsEnabled = true;	
	bool _IsDeleted = false;	
protected:
	virtual void start() = 0;
	virtual void update(unsigned long tick) = 0;
private:
	bool checkCollisionWith(GameControlBase *control);
public:
	signed char x = 0;
	signed char y = 0;
public:
	GameControlBase *checkCollision();

	int getID() { return _ID; }
	void setID(int value) { _ID = value; }

	int getX() { return x; }
	void setX(int value) { x = value; }
		
	int getY() { return y; }
	void setY(int value) { y = value; }

	bool getEnabled() { return _IsEnabled; }
	void setEnabled(bool value) { _IsEnabled = value; }

	bool getDeleted() { return _IsDeleted; }
	void setDeleted(bool value) { _IsDeleted = value; }

	friend class GameEngine;
	friend class GameLayer;
};

class GameLayer
{
protected:
	Adafruit_PCD8544 *_LCD;
	GameEngine *_Engine;
protected:
	void start();
	void update(unsigned long tick);
private:
	LinkedList<GameControlBase *> _Controls = LinkedList<GameControlBase *>();
private:
	GameControlBase *checkCollision(GameControlBase *control);
public:
	void addControl(GameControlBase *object);

	friend class GameEngine;
	friend class GameControlBase;
};

class AudioTrack
{
protected:
	void update(unsigned long tick);
private:	
	int _PIN = 0;
	short _Frequency = 0;
	short _Duration = 0;
	LinkedList<short> _Notes = LinkedList<short>();
public:
	AudioTrack(int pin) 
		: _PIN(pin)
	{}

	void clear();

	void playNow(int frequency, int duration);
	void play(int frequency, int duration);
	void play(int frequency);
	void stop();

	/// How many notes remain to play.
	int get_count();

	friend class GameEngine;
};

typedef void (*OnUpdateEvent) (int tick);

class GameEngine
{
private:
	AudioTrack _AudioTrack;
	Adafruit_PCD8544 _LCD;
	GameLayer *_MainLayer;

	unsigned long _OldTick;

	LinkedList<GameLayer *> _Layers = LinkedList<GameLayer *>();

	OnUpdateEvent _OnBeforeUpdate = NULL;
	OnUpdateEvent _OnAfterUpdate = NULL;
public:
	GameEngine(int audio, int8_t SCLK, int8_t DIN, int8_t DC, int8_t CS, int8_t RST) 
		: _AudioTrack(audio), _LCD(SCLK, DIN, DC, CS, RST)
	{
		_MainLayer = addLayer();
	}

	GameLayer *addLayer();

	void addControl(GameControlBase *object);

	void start();
	unsigned long update();

	AudioTrack *getAudioTrack() { return &_AudioTrack; }
	Adafruit_PCD8544 *getLCD() { return &_LCD; }

	void setOnBeforeUpdate(OnUpdateEvent event) { _OnBeforeUpdate = event; }	
	void setOnAfterUpdate(OnUpdateEvent event) { _OnAfterUpdate = event; }
};


#endif // RYUGAME_H
#endif