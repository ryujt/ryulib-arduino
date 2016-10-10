#ifndef MUSIC_H
#define MUSIC_H


#include <RyuGame.h>
#include <sound_effect.h>


const int notes[] PROGMEM = {
	note_E3,
	note_B3,
	note_C3,
	note_D3,
	note_C3,
	note_B3,
	note_A3,
	note_A3,
	note_B3,
	note_E3,
	note_D3,
	note_C3,
	note_B3,
	note_B3,
	note_C3,
	note_D3,
	note_E3,
	note_C3,
	note_A3,
	note_A3,
	note_D3,
	note_D3,
	note_F3,
	note_A4,
	note_G3,
	note_F3,
	note_E3,
	note_E3,
	note_C3,
	note_E3,
	note_D3,
	note_C3,
	note_B3,
	note_B3,
	note_C3,
	note_D3,
	note_E3,
	note_C3,
	note_A3,
	note_A3
};

const int delays[] PROGMEM = {
	2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,2,2,2,4,
	2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,2,2,2,4
};

const int last_index = sizeof(notes) / sizeof(int);
const int play_speed = 200;

class Music : public GameControlBase
{
private:  
	int _index;
public:
	void start()
	{
		_index = 0;
	}

	void update(unsigned long tick)
	{
		while (_Engine->getAudioTrack()->get_count() < 3) {
			_Engine->getAudioTrack()->play(pgm_read_word_near(notes + _index), pgm_read_word_near(delays + _index) * play_speed);

			_index = _index + 1;
			if (_index >= last_index) _index = 0;
		}
	} 
};

#endif // MUSIC_H

