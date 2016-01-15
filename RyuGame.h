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

	signed char _X = 0;
	signed char _Y = 0;

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
	GameControlBase *checkCollision();

	int getID() { return _ID; }
	void setID(int value) { _ID = value; }

	int getX() { return _X; }
	void setX(int value) { _X = value; }
		
	int getY() { return _Y; }
	void setY(int value) { _Y = value; }

	bool getIsEnabled() { return _IsEnabled; }
	void setIsEnabled(bool value) { _IsEnabled = value; }

	bool getIsDeleted() { return _IsDeleted; }
	void setIsDeleted(bool value) { _IsDeleted = value; }

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

	void play(int frequency, int duration);
	void play(int frequency);
	void stop();

	friend class GameEngine;
};

typedef void (*OnUpdateEvent) (int tick);

class GameEngine
{
private:
	AudioTrack _AudioTrack;
	Adafruit_PCD8544 _LCD;

	unsigned long _OldTick;

	LinkedList<GameLayer *> _Layers = LinkedList<GameLayer *>();

	OnUpdateEvent _OnBeforeUpdate = NULL;
	OnUpdateEvent _OnAfterUpdate = NULL;
public:
	GameEngine(int audio, int8_t SCLK, int8_t DIN, int8_t DC, int8_t CS, int8_t RST) 
		: _AudioTrack(audio), _LCD(SCLK, DIN, DC, CS, RST)
	{}

	GameLayer *addLayer();

	void start();
	void update();

	AudioTrack *getAudioTrack() { return &_AudioTrack; }

	void setOnBeforeUpdate(OnUpdateEvent event) { _OnBeforeUpdate = event; }	
	void setOnAfterUpdate(OnUpdateEvent event) { _OnAfterUpdate = event; }
};


#endif // RYUGAME_H
