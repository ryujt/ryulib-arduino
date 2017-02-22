// 다음 MCU에서만 동작한다.  NodeMCU와 충돌하여 제한을 둠
#if defined(__AVR_ATmega328P__)  || defined(__AVR_ATmega32U4__)

#include <RyuGame.h>


/* class GameControlBase */
		
bool GameControlBase::checkCollisionWith(GameControlBase *control)
{
	if (_IsEnabled == false) return false;
	if (control->_IsEnabled == false) return false;

	int hit_size = _HitSize + control->_HitSize;

	int x_distance = abs(x - control->x);
	int y_distance = abs(y - control->y);

	if (x_distance > hit_size) return false;
	if (y_distance > hit_size) return false;

	hit_size = hit_size * hit_size;
	x_distance = x_distance * x_distance;
	y_distance = y_distance * y_distance;

	return hit_size >= (x_distance + y_distance);
}

GameControlBase *GameControlBase::checkCollision()
{
	if (_IsEnabled) return _Layer->checkCollision(this);
	else return NULL;
}
			

/* class GameLayer */

void GameLayer::addControl(GameControlBase *control)
{
	 control->_LCD = _LCD;
	 control->_Engine = _Engine;
	 control->_Layer = this;
	 control->start();

	_Controls.add(control);
}

void GameLayer::start()	
{
	for (int i=0; i<_Controls.size(); i++) {
		GameControlBase *control = _Controls.get(i);
		if (control->_IsEnabled) control->start();
	}
}

void GameLayer::update(unsigned long tick)
{
	for (int i=0; i<_Controls.size(); i++) {
		GameControlBase *control = _Controls.get(i);
		if (control->_IsEnabled) control->update(tick);
	}

	for (int i=_Controls.size()-1; i>=0; i--) {
		GameControlBase *control = _Controls.get(i);
		if (control->_IsDeleted) {
			_Controls.remove(i);
			delete control;
		}
	}
}
	
GameControlBase *GameLayer::checkCollision(GameControlBase *object)
{
	for (int i=0; i<_Controls.size(); i++) {
		GameControlBase *control = _Controls.get(i);

		if (control == object) continue;

		if (control->checkCollisionWith(object)) return control;
	}

	return NULL;
}


/* class AudioTrack */
	
void AudioTrack::update(unsigned long tick)
{
	if (_Duration <= 0) {		
		if (_Notes.size() == 0) {
			noTone(_PIN);
			return;
		}

		_Frequency = _Notes.shift();
		_Duration = _Notes.shift();

		if (_Frequency == 0) noTone(_PIN);
		else tone(_PIN, _Frequency);
	}

	_Duration = _Duration - tick;
}
	
void AudioTrack::clear()
{
	_Notes.clear();

	_Frequency = 0;
	_Duration = 0;
}

void  AudioTrack::playNow(int frequency, int duration)
{
	_Duration = 0;

	_Notes.add(0, frequency);
	_Notes.add(0, duration);
}

void AudioTrack::play(int frequency, int duration)
{
	_Notes.add(frequency);
	_Notes.add(duration);
}
	
void AudioTrack::play(int frequency)
{
	tone(_PIN, frequency);
}
	
void AudioTrack::stop()
{
	noTone(_PIN);
	_Duration = 0;
}

int AudioTrack::get_count()
{
	return _Notes.size();
}


/* class GameEngine */

GameLayer *GameEngine::addLayer()
{
	GameLayer *layer = new GameLayer();

	layer->_LCD = &_LCD;
	layer->_Engine = this;

	_Layers.add(layer);

	return layer;
}
	
void GameEngine::addControl(GameControlBase *object)
{
	_MainLayer->addControl(object);
}

void GameEngine::start()
{
	_LCD.begin();
	_LCD.setContrast(50);
	_LCD.clearDisplay();
	_LCD.display();

	_OldTick = millis();

	for (int i=0; i<_Layers.size(); i++) {
		GameLayer *layer = _Layers.get(i);
		layer->start();
	}
}
	
unsigned long GameEngine::update()
{
	unsigned long tick = millis();
	unsigned long term = 0;
	if (tick > _OldTick) term = tick - _OldTick;
	_OldTick = tick;

	if (_OnBeforeUpdate != NULL) _OnBeforeUpdate(term);

	_LCD.clearDisplay();

	for (int i=0; i<_Layers.size(); i++) {
		GameLayer *layer = _Layers.get(i);
		layer->update(term);
	}

	_LCD.display();

	_AudioTrack.update(term);

	if (_OnAfterUpdate != NULL) _OnAfterUpdate(term);

	return term;
}

#endif