#ifndef GLOBALS_H
#define GLOBALS_H

#include <RyuGame.h>
#include "sound_effect.h"


void sound_effect_game_start(AudioTrack *audioTrack)
{
	audioTrack->clear();

	audioTrack->play(784, 400);
	audioTrack->play(884, 200);
	audioTrack->play(784, 200);
	audioTrack->play(687, 200);
	audioTrack->play(659, 200);
	audioTrack->play(519, 400);
}

void sound_effect_game_end(AudioTrack *audioTrack)
{
	audioTrack->clear();

	audioTrack->play(note_Bb5, 300);
	audioTrack->play(0, 50);

	audioTrack->play(note_C6, 300);
	audioTrack->play(0, 50);

	audioTrack->play(note_Ab5, 300); 
	audioTrack->play(0, 50);

	audioTrack->play(note_Ab4, 300);
	audioTrack->play(0, 50);

	audioTrack->play(note_Eb5, 500);
	audioTrack->play(0, 500);

	audioTrack->play(note_Bb4, 300);
	audioTrack->play(0, 100);

	audioTrack->play(note_C5, 300);
	audioTrack->play(0, 100);

	audioTrack->play(note_Ab4, 300);
	audioTrack->play(0, 100);

	audioTrack->play(note_Ab3, 300);
	audioTrack->play(0, 100);

	audioTrack->play(note_Eb4, 500);
	audioTrack->play(0, 500);

	audioTrack->play(note_Bb3, 300);
	audioTrack->play(0, 200);

	audioTrack->play(note_C4, 300);
	audioTrack->play(0, 200);

	audioTrack->play(note_Ab3, 300);
	audioTrack->play(0, 500);

	audioTrack->play(note_Ab2, 300);
	audioTrack->play(0, 550);

	audioTrack->play(note_Eb3, 300);
}

void sound_effect_fire(AudioTrack *audioTrack)
{
	audioTrack->clear();
	audioTrack->play(100, 20);
}

void sound_effect_bang(AudioTrack *audioTrack)
{
	audioTrack->play(note_E5, 50);
	audioTrack->play(note_E4, 50);
}

void sound_effect_coin(AudioTrack *audioTrack)
{
	audioTrack->play(note_B5, 100);
	audioTrack->play(0, 100);
	audioTrack->play(note_E6, 850);
	audioTrack->play(0, 800);
}

void sound_effect_1_up(AudioTrack *audioTrack)
{
	audioTrack->play(note_E6, 125);
	audioTrack->play(0, 130);
	audioTrack->play(note_G6, 125);
	audioTrack->play(0, 130);
	audioTrack->play(note_E7, 125);
	audioTrack->play(0, 130);
	audioTrack->play(note_C7, 125);
	audioTrack->play(0, 130);
	audioTrack->play(note_D7, 125);
	audioTrack->play(0, 130);
	audioTrack->play(note_G7, 125);
	audioTrack->play(0, 125);
}

void sound_effect_get_item(AudioTrack *audioTrack)
{
	audioTrack->play(note_G4, 35);
	audioTrack->play(0, 35);
	audioTrack->play(note_G5, 35);
	audioTrack->play(0, 35);
	audioTrack->play(note_G6, 35);
	audioTrack->play(0, 35);
}


#endif // GLOBALS_H
