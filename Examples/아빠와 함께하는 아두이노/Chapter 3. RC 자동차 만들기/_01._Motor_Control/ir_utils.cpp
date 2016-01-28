#include <IRremote.h>
#include "ir_utils.h"

IRrecv *ir_rec = NULL;

void start_ir(int pin)
{
	ir_rec = new IRrecv(pin);
	ir_rec->enableIRIn();
}

void stop_ir()
{
	delete ir_rec;
	ir_rec = NULL;
}

unsigned long get_ir_code()
{
	unsigned long result = 0;

	decode_results results;
	if (ir_rec->decode(&results)) {
		result = results.value;
		irrecv->resume();
	}

  return result;
}