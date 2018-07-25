

#ifndef __CONFIG_H__
#define __CONFIG_H__
#include "Types.h"

#define EXPORT_STATE_SPACE	
#define CORE_2_1	
#define TIMED_REBECA	

#if (defined DEBUG || defined EXPORT_STATE_SPACE)
	#define ENABLE_STATE_ID
#endif


#define NEW_STATE 1




#ifdef TTS
#define NO_ATOMIC_EXECUTION
#endif
#define TIME_TYPE int
#define MAX_TIME 0x7FFFFFFF

class DeadlineMissedException: public Exception {
public:
	DeadlineMissedException(string message) : Exception(message) {}
	~DeadlineMissedException() throw() {}
};


#endif