#include "sound_effect.h"
#include <Arduino.h>

void beep(int speaker_pin, float note_frequency, long note_duration) {
	int x;
	// Convert the frequency to microseconds
	float microsecondsPerWave = 1000000 / note_frequency;
	// Calculate how many milliseconds there are per HIGH/LOW cycles.
	float millisecondsPerCycle = 1000 / (microsecondsPerWave * 2);
	// Multiply note_duration * number or cycles per millisecond
	float loopTime = note_duration * millisecondsPerCycle;
	// Play the note for the calculated loopTime.
	for (x = 0; x < loopTime; x++) {
		digitalWrite(speaker_pin, HIGH);
		delayMicroseconds(microsecondsPerWave);
		digitalWrite(speaker_pin, LOW);
		delayMicroseconds(microsecondsPerWave);
	}
}

void seR2D2(int pin_no) {
	beep(pin_no, note_A7, 100); // A
	beep(pin_no, note_G7, 100); // G
	beep(pin_no, note_E7, 100); // E
	beep(pin_no, note_C7, 100); // C
	beep(pin_no, note_D7, 100); // D
	beep(pin_no, note_B7, 100); // B
	beep(pin_no, note_F7, 100); // F
	beep(pin_no, note_C8, 100); // C
	beep(pin_no, note_A7, 100); // A
	beep(pin_no, note_G7, 100); // G
	beep(pin_no, note_E7, 100); // E
	beep(pin_no, note_C7, 100); // C
	beep(pin_no, note_D7, 100); // D
	beep(pin_no, note_B7, 100); // B
	beep(pin_no, note_F7, 100); // F
	beep(pin_no, note_C8, 100); // C
}

void seCloseEncounters(int pin_no) {
	beep(pin_no, note_Bb5, 300); // B b
	delay(50);
	beep(pin_no, note_C6, 300); // C
	delay(50);
	beep(pin_no, note_Ab5, 300); // A b
	delay(50);
	beep(pin_no, note_Ab4, 300); // A b
	delay(50);
	beep(pin_no, note_Eb5, 500); // E b
	delay(500);
	beep(pin_no, note_Bb4, 300); // B b
	delay(100);
	beep(pin_no, note_C5, 300); // C
	delay(100);
	beep(pin_no, note_Ab4, 300); // A b
	delay(100);
	beep(pin_no, note_Ab3, 300); // A b
	delay(100);
	beep(pin_no, note_Eb4, 500); // E b
	delay(500);
	beep(pin_no, note_Bb3, 300); // B b
	delay(200);
	beep(pin_no, note_C4, 300); // C
	delay(200);
	beep(pin_no, note_Ab3, 300); // A b
	delay(500);
	beep(pin_no, note_Ab2, 300); // A b
	delay(550);
	beep(pin_no, note_Eb3, 500); // E b
}

void seAriel(int pin_no) {
	beep(pin_no, note_C6, 300); // C
	delay(50);
	beep(pin_no, note_D6, 300); // D
	delay(50);
	beep(pin_no, note_Eb6, 600); // D#
	delay(250);

	beep(pin_no, note_D6, 300); // D
	delay(50);
	beep(pin_no, note_Eb6, 300); // D#
	delay(50);
	beep(pin_no, note_F6, 600); // F
	delay(250);

	beep(pin_no, note_C6, 300); // C
	delay(50);
	beep(pin_no, note_D6, 300); // D
	delay(50);
	beep(pin_no, note_Eb6, 500); // D#
	delay(50);
	beep(pin_no, note_D6, 300); // D
	delay(50);
	beep(pin_no, note_Eb6, 300); // D#
	delay(50);
	beep(pin_no, note_D6, 300); // D
	delay(50);
	beep(pin_no, note_Eb6, 300); // D#
	delay(50);
	beep(pin_no, note_F6, 600); // F
	delay(50);
}

void seLaugh(int pin_no) {
	int i;

	for (i = 1000; i < 2000; i = i * 1.10) {
		beep(pin_no, i, 10);
	}
	delay(50);
	for (i = 1000; i > 500; i = i * .90) {
		beep(pin_no, i, 10);
	}
	delay(50);
	for (i = 1000; i < 2000; i = i * 1.10) {
		beep(pin_no, i, 10);
	}
	delay(50);
	for (i = 1000; i > 500; i = i * .90) {
		beep(pin_no, i, 10);
	}
	delay(50);
	for (i = 1000; i < 2000; i = i * 1.10) {
		beep(pin_no, i, 10);
	}
	delay(50);
	for (i = 1000; i > 500; i = i * .90) {
		beep(pin_no, i, 10);
	}
	delay(50);
	for (i = 1000; i < 2000; i = i * 1.10) {
		beep(pin_no, i, 10);
	}
	delay(50);
	for (i = 1000; i > 500; i = i * .90) {
		beep(pin_no, i, 10);
	}
	delay(50);
}

void seLaugh2(int pin_no) {
	beep(pin_no, note_C6, 200); // C
	beep(pin_no, note_E6, 200); // E
	beep(pin_no, note_G6, 200); // G
	beep(pin_no, note_C7, 200); // C
	beep(pin_no, note_C6, 200); // C
	delay(50);
	beep(pin_no, note_C6, 200); // C
	beep(pin_no, note_E6, 200); // E
	beep(pin_no, note_G6, 200); // G
	beep(pin_no, note_C7, 200); // C
	beep(pin_no, note_C6, 200); // C
	delay(50);
	beep(pin_no, note_C6, 50); // C
	delay(50);
	beep(pin_no, note_C6, 50); // C
	delay(50);
	beep(pin_no, note_C6, 50); // C
	delay(50);
	beep(pin_no, note_C6, 50); // C
	delay(50);
	beep(pin_no, note_C6, 50); // C
	delay(50);
	beep(pin_no, note_C6, 50); // C
	delay(50);
	beep(pin_no, note_C6, 50); // C
}

void seSqueak(int pin_no) {
	int i;

	for (i = 100; i < 5000; i = i * 1.45) {
		beep(pin_no, i, 60);
	}
	delay(10);
	for (i = 100; i < 6000; i = i * 1.5) {
		beep(pin_no, i, 20);
	}
}

void seWaka(int pin_no) {
	int i;

	for (i = 1000; i < 3000; i = i * 1.05) {
		beep(pin_no, i, 10);
	}
	delay(100);
	for (i = 2000; i > 1000; i = i * .95) {
		beep(pin_no, i, 10);
	}
	for (i = 1000; i < 3000; i = i * 1.05) {
		beep(pin_no, i, 10);
	}
	delay(100);
	for (i = 2000; i > 1000; i = i * .95) {
		beep(pin_no, i, 10);
	}
	for (i = 1000; i < 3000; i = i * 1.05) {
		beep(pin_no, i, 10);
	}
	delay(100);
	for (i = 2000; i > 1000; i = i * .95) {
		beep(pin_no, i, 10);
	}
	for (i = 1000; i < 3000; i = i * 1.05) {
		beep(pin_no, i, 10);
	}
	delay(100);
	for (i = 2000; i > 1000; i = i * .95) {
		beep(pin_no, i, 10);
	}
}

void seCatcall(int pin_no) {
	int i;

	for (i = 1000; i < 5000; i = i * 1.05) {
		beep(pin_no, i, 10);
	}
	delay(300);

	for (i = 1000; i < 3000; i = i * 1.03) {
		beep(pin_no, i, 10);
	}
	for (i = 3000; i > 1000; i = i * .97) {
		beep(pin_no, i, 10);
	}
}

void seOhhh(int pin_no) {
	int i;

	for (i = 1000; i < 2000; i = i * 1.02) {
		beep(pin_no, i, 10);
	}
	for (i = 2000; i > 1000; i = i * .98) {
		beep(pin_no, i, 10);
	}
}

void seUhoh(int pin_no) {
	int i;

	for (i = 1000; i < 1244; i = i * 1.01) {
		beep(pin_no, i, 30);
	}
	delay(200);
	for (i = 1244; i > 1108; i = i * .99) {
		beep(pin_no, i, 30);
	}
}

void seChang(int pin_no) {
	int i, j;

	for (j = 1; j < 5; j++) {
		for (i = 2000; i > 50; i = i - 400) {
			beep(pin_no, i, 11);
		}
	}
}

void seCoo(int pin_no) {
	int i;

	for (i = 0; i < 150; i = i + 10) {
		beep(pin_no, 1295 - i, 22);
		beep(pin_no, 1295 + i, 22);
	}
}

void seOh(int pin_no) {
	int i;

	for (i = 800; i < 2000; i = i + 100) {
		beep(pin_no, i, 11);
	}
	for (i = 2000; i > 50; i = i - 100) {
		beep(pin_no, i, 11);
	}
}

void sePhone(int pin_no) {
	int i;

	for (i = 1; i < 10; i++) {
		beep(pin_no, 1195, 22);
		beep(pin_no, 2571, 22);
	}
}

void seSiren(int pin_no) {
	int i;

	for (i = 1; i < 3; i++) {
		beep(pin_no, 550, 494);
		beep(pin_no, 400, 494);
	}
}

void seSpace1(int pin_no) {
	int i;

	for (i = 1000; i > 40; i = i - 20) {
		beep(pin_no, i, 11);
	}
}

void seSpace2(int pin_no) {
	int i;

	for (i = 10000; i > 500; i = i - 500) {
		beep(pin_no, i, 11);
	}
}

void seFanfare(int pin_no) {
	int i;

	for (i = 1200; i > 350; i = i - 50) {
		beep(pin_no, i, 33);
	}
}

void seAlarm(int pin_no) {
	int i, j;

	for (j = 1; j < 10; j++) {
		for (i = 300; i < 1800; i = i + 40) {
			beep(pin_no, i, 11);
		}
	}
}

void seMaschinengewehr(int pin_no) {
	int i;

	for (i = 1; i > 20; i++) {
		beep(pin_no, 40, 33);
		delayMicroseconds(55);
	}
}

void seTelefone(int pin_no) {
	int i, j;

	for (j = 1; j < 4; j++) {
		for (i = 1; i < 25; i++) {
			beep(pin_no, 540, 33);
			beep(pin_no, 650, 27);
		}
		delayMicroseconds(2000);
	}
}

void seTonarkade(int pin_no) {
	int i, j;

	for (j = 1; j < 8; j++) {
		for (i = 600; i < 750; i = i + 8) {
			beep(pin_no, i, 11);
		}
	}
}

void seTonarkade2(int pin_no) {
	int i;

	for (i = 1250; i > 600; i = i - 8) {
		beep(pin_no, i, 11);
	}
}

void seSad(int pin_no) {
	beep(pin_no, 784, 500);
	beep(pin_no, 738, 500);
	beep(pin_no, 684, 500);
	beep(pin_no, 644, 1000);
}

void seVictory(int pin_no) {
	beep(pin_no, 523, 200);
	delayMicroseconds(1000 - 200);

	beep(pin_no, 523, 200);
	delayMicroseconds(1000 - 200);

	beep(pin_no, 523, 200);
	delayMicroseconds(1000 - 200);

	beep(pin_no, 659, 700);
	beep(pin_no, 784, 500);

	beep(pin_no, 523, 200);
	delayMicroseconds(1000 - 200);

	beep(pin_no, 523, 200);
	delayMicroseconds(1000 - 200);

	beep(pin_no, 523, 200);
	delayMicroseconds(1000 - 200);

	beep(pin_no, 659, 700);

	beep(pin_no, 784, 500);
	delayMicroseconds(800 - 500);

	beep(pin_no, 784, 400);
	beep(pin_no, 884, 200);
	beep(pin_no, 784, 200);
	beep(pin_no, 687, 200);
	beep(pin_no, 659, 200);
	beep(pin_no, 519, 400);
}

void seAssorted(int pin_no) {
	beep(pin_no, 600, 165);
	beep(pin_no, 50, 83);
	beep(pin_no, 600, 165);
	beep(pin_no, 50, 83);
	beep(pin_no, 650, 165);
	beep(pin_no, 600, 165);
	beep(pin_no, 50, 83);
	beep(pin_no, 600, 165);
	beep(pin_no, 700, 275);
	beep(pin_no, 800, 275);
	beep(pin_no, 900, 110);
}
