                                    

#include "Types.h"
#include "TrainActor.h"
#include <stdio.h>
#include <string.h>

// location counters (values stored in messageQueue[0])
/* There can be more than one location counter for each msgsrv when we
   want to have non-atomic message servers.
   Notice that values 0 and 1 are reserved for EMPTY and INITIAL, respectively.*/
#define INITIAL 1
#define DRIVE 2
#define TRACK_OCCUPIED 3
#define RED_SIGNAL 4
#define READY 5
#define HANDLE_DRIVE_OUT 6
#define DRIVE_IN 7
#define DRIVE_OUT 8


// knownrebecs (those to whom message can be sent)
// the following format allows to use them as variables --> the ID of the rebec
#define _ref_sender (rebecs[senderQueue[0]])
#define _ref_self (dynamic_cast<TrainActor*>(rebecs[myID]))
        	#define _ref_homeStation (dynamic_cast<StationControllerActor*>(rebecs[known[1]]))
	            

TrainActor::TrainActor(byte myID, char* myName, int maxQueueLength, int maxParamLength, vector<AbstractActor*>& rebecsRef
		#ifdef DEBUG_LEVEL_2 
			, ostream &out
		#endif
				






					, int hashmapSize
				






					






			)
	:
			AbstractTimedActor (myID, myName, maxQueueLength, maxParamLength, rebecsRef
			#ifdef DEBUG_LEVEL_2 
				, out
			#endif
						






					, 232, hashmapSize
				






					






					)
					, AbstractActor (myID, myName, maxQueueLength, maxParamLength, rebecsRef
		#ifdef DEBUG_LEVEL_2 
			, out
		#endif
					






					, 232, hashmapSize
				






					






				)
	{

    messageNames = new char *[8 + 1];
	messageNames[0] = (char*)"Empty";

                messageNames[1] = (char*)"INITIAL";
                    messageNames[2] = (char*)"DRIVE";
                    messageNames[3] = (char*)"TRACK_OCCUPIED";
                    messageNames[4] = (char*)"RED_SIGNAL";
                    messageNames[5] = (char*)"READY";
                    messageNames[6] = (char*)"HANDLE_DRIVE_OUT";
                    messageNames[7] = (char*)"DRIVE_IN";
                    messageNames[8] = (char*)"DRIVE_OUT";
            
				






			if (table == (byte**)0xFFFFFFFF) {	// avoid reinitialization
		table = new byte* [1 << hashmapSize];
        memset (table, 0, sizeof(byte*)*(1 << hashmapSize));
	}

			






			if (hashtableTimeExtension == (vector<TimeFrame>**)0xFFFFFFFF) {	// avoid reinitialization
        hashtableTimeExtension = new vector<TimeFrame>*[1 << hashmapSize];
        memset (hashtableTimeExtension, 0, sizeof(vector<TimeFrame>*)*(1 << hashmapSize));
	}
			






			
		
	queueTail = 0;
}

TrainActor::~TrainActor (){
	delete [] messageNames;
	delete [] messageQueue;
	delete [] senderQueue;
}


void TrainActor::exportStateVariablesInXML(ostream &out, string tab) {
	out << tab << "<statevariables>" << endl;
            	    	out << tab << '\t' << "<variable name=\"station\" type=\"StationController\">" <<  
	    		(_ref_station == NULL ? "NULL" : _ref_station->getName()) << "</variable>" << endl;
			        	    	out << tab << '\t' << "<variable name=\"track\" type=\"SignalPair\">" <<  
	    		(_ref_track == NULL ? "NULL" : _ref_track->getName()) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"next\" type=\"SignalPair\">" <<  
	    		(_ref_next == NULL ? "NULL" : _ref_next->getName()) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"dest\" type=\"SignalPair\">" <<  
	    		(_ref_dest == NULL ? "NULL" : _ref_dest->getName()) << "</variable>" << endl;
			        	    	out << tab << '\t' << "<variable name=\"counter\" type=\"int\">" <<  
	    		((int)_ref_counter) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"s\" type=\"int\">" <<  
	    		((int)_ref_s) << "</variable>" << endl;
			        	    	out << tab << '\t' << "<variable name=\"id\" type=\"byte\">" <<  
	    		((int)_ref_id) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"drive_status\" type=\"byte\">" <<  
	    		((int)_ref_drive_status) << "</variable>" << endl;
			        	    	out << tab << '\t' << "<variable name=\"schedule\" type=\"byte[10]\">" <<  
	    		"[" << ((int)_ref_schedule[0]) << ", " << ((int)_ref_schedule[1]) << ", " << ((int)_ref_schedule[2]) << ", " << ((int)_ref_schedule[3]) << ", " << ((int)_ref_schedule[4]) << ", " << ((int)_ref_schedule[5]) << ", " << ((int)_ref_schedule[6]) << ", " << ((int)_ref_schedule[7]) << ", " << ((int)_ref_schedule[8]) << ", " << ((int)_ref_schedule[9]) << ", " << "]" << "</variable>" << endl;
				out << tab << "</statevariables>" << endl;
}

void TrainActor::exportAMessageInXML(ostream &out, string tab, int cnt) {
        int i = 0;
        switch (messageQueue[cnt]) {
	                    case INITIAL: {
                                            
                    out << "initial("
                                << ")";
                break;
               }
	                    case DRIVE: {
                                            
                    out << "drive("
                                << ")";
                break;
               }
	                    case TRACK_OCCUPIED: {
                                        			                        	SignalPairActor* _ref_n;
                        
                                    
                            memcpy(&_ref_n, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "track_occupied("
                                	<< (_ref_n == NULL ? "NULL" : _ref_n->getName())
                	                                << ")";
                break;
               }
	                    case RED_SIGNAL: {
                                            
                    out << "red_signal("
                                << ")";
                break;
               }
	                    case READY: {
                                        			                        	StationControllerActor* _ref_sc;
                        
                                    
                            memcpy(&_ref_sc, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	SignalPairActor* _ref_t;
                        
                                    
                            memcpy(&_ref_t, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "ready("
                                	<< (_ref_sc == NULL ? "NULL" : _ref_sc->getName())
                						<< ", "
					                                	<< (_ref_t == NULL ? "NULL" : _ref_t->getName())
                	                                << ")";
                break;
               }
	                    case HANDLE_DRIVE_OUT: {
                                        			                        	SignalPairActor* _ref_n;
                        
                                    
                            memcpy(&_ref_n, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	SignalPairActor* _ref_d;
                        
                                    
                            memcpy(&_ref_d, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "handle_drive_out("
                                	<< (_ref_n == NULL ? "NULL" : _ref_n->getName())
                						<< ", "
					                                	<< (_ref_d == NULL ? "NULL" : _ref_d->getName())
                	                                << ")";
                break;
               }
	                    case DRIVE_IN: {
                                        			                        	StationControllerActor* _ref_sc;
                        
                                    
                            memcpy(&_ref_sc, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	SignalPairActor* _ref_t;
                        
                                    
                            memcpy(&_ref_t, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "drive_in("
                                	<< (_ref_sc == NULL ? "NULL" : _ref_sc->getName())
                						<< ", "
					                                	<< (_ref_t == NULL ? "NULL" : _ref_t->getName())
                	                                << ")";
                break;
               }
	                    case DRIVE_OUT: {
                                        			                        	SignalPairActor* _ref_n;
                        
                                    
                            memcpy(&_ref_n, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "drive_out("
                                	<< (_ref_n == NULL ? "NULL" : _ref_n->getName())
                	                                << ")";
                break;
               }
	            	}

}

char* TrainActor::getClassName() {
    return (char*)"Train";
}

void TrainActor::marshalActorToArray(byte* array) {
    int i,j, marshalIndex = 0;

	for (i = (shift ? 1 : 0); i < maxQueueLength; i++) {
        array[marshalIndex++] = messageQueue[i];
    }

    if (shift) {
        array[marshalIndex++] = 0;
    }
    
	for (i = (shift ? 1 : 0); i < maxQueueLength; i++) {
        array[marshalIndex++] = senderQueue[i];
    }

    if (shift) {
        array[marshalIndex++] = 0;
    }

	if(maxParamLength != 0) {
        for (i = (shift ? 1 : 0); i < maxQueueLength; i++) {
            for (j = 0; j < maxParamLength; j++) {
                array[marshalIndex++] = paramQueue[i][j];
            }
        }
        if (shift) {
            for (j = 0; j < maxParamLength; j++) {
                array[marshalIndex++] = 0;
            }
        }
    }

                            			            
                                    
                            memcpy(&array [marshalIndex], &_ref_station, (1 * REACTIVE_CLASS_SIZE));
                marshalIndex += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_track, (1 * REACTIVE_CLASS_SIZE));
                marshalIndex += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_next, (1 * REACTIVE_CLASS_SIZE));
                marshalIndex += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_dest, (1 * REACTIVE_CLASS_SIZE));
                marshalIndex += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_counter, (1 * INT_SIZE));
                marshalIndex += (1 * INT_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_s, (1 * INT_SIZE));
                marshalIndex += (1 * INT_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_id, (1 * BYTE_SIZE));
                marshalIndex += (1 * BYTE_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_drive_status, (1 * BYTE_SIZE));
                marshalIndex += (1 * BYTE_SIZE);
                                			            
            								                        
                            memcpy(&array [marshalIndex], _ref_schedule, (10 * BYTE_SIZE));
                marshalIndex += (10 * BYTE_SIZE);
                            
        
    
    #ifdef NO_ATOMIC_EXECUTION
    	memcpy(&array [marshalIndex], &__pc, 4);
    	//array[marshalIndex++] = __pc;
    #endif

}

void TrainActor::unmarshalActorFromArray(byte* array) {

    int index = 0, i, j;
    shift = 0;

	for (i = 0; i < maxQueueLength; i++) {
        messageQueue[i] = array[index++];
    }
	
	for (i = 0; i < maxQueueLength; i++) {
        senderQueue[i] = array[index++];
    }
    
	if(maxParamLength != 0) {
        for (i = 0; i < maxQueueLength; i++) {
            for (j = 0; j < maxParamLength; j++) {
                paramQueue[i][j] = array[index++];
            }
        }
    }

                            			                        
                                    
                            memcpy(&_ref_station, &array [index], (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			                        
                                    
                            memcpy(&_ref_track, &array [index], (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			                        
                                    
                            memcpy(&_ref_next, &array [index], (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			                        
                                    
                            memcpy(&_ref_dest, &array [index], (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			                        
                                    
                            memcpy(&_ref_counter, &array [index], (1 * INT_SIZE));
                index += (1 * INT_SIZE);
                                			                        
                                    
                            memcpy(&_ref_s, &array [index], (1 * INT_SIZE));
                index += (1 * INT_SIZE);
                                			                        
                                    
                            memcpy(&_ref_id, &array [index], (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                                			                        
                                    
                            memcpy(&_ref_drive_status, &array [index], (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                                			                        
                                    
                            memcpy(_ref_schedule, &array [index], (10 * BYTE_SIZE));
                index += (10 * BYTE_SIZE);
                                    
        
    #ifdef NO_ATOMIC_EXECUTION
    	memcpy(&__pc, &array [index], 4);
    	//__pc = array[index++];
    #endif
}

/*#ifdef DEBUG
void TrainActor::printStateContent(long stateNo) {
	out << myName << "=>[";
	byte* currentValues = getTable()[stateNo];
	for (int cnt = 0; cnt < STATE_SIZE; cnt++)
		out << (int)currentValues[cnt] << ", ";
	out << "]";
}
#endif
*/

//---------------------------------------------------------
/**
  Checks which action of this rebec is enabled, and executes it. Actions are the
  same as the location-counter defined at the beginning of this file.
  In the case of non-atomic message servers, a location-counter may point to the
  middle of a message server.
  If this action leads to more than one transition (non_det), this method executes
  only one of these transitions. With the help of some static variables, consecutive
  calls to this method execute different transitions caused by this action.
  Local variables must be properly valuated before any call to this method (see marshal()).

  returns: >0 : there are more possible next states (non-det transitions).
		   =0 : no more non_det transitions
		   -1 : no enabled action (empty queue)
		   -2 : Local hash table is full - immediate termination of search
 */
long TrainActor::execute() {
			AbstractTimedActor::execute();
	    switch (messageQueue[0]) {

                    case INITIAL:
                {
                    int i = 0;
                                                
                        return msgsrvinitial(
                                                );
                }
                    case DRIVE:
                {
                    int i = 0;
                                                
                        return msgsrvdrive(
                                                );
                }
                    case TRACK_OCCUPIED:
                {
                    int i = 0;
                                            			                        	SignalPairActor* _ref_n;
                        
                                    
                            memcpy(&_ref_n, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvtrack_occupied(
                            	                        _ref_n
	                                        );
                }
                    case RED_SIGNAL:
                {
                    int i = 0;
                                                
                        return msgsrvred_signal(
                                                );
                }
                    case READY:
                {
                    int i = 0;
                                            			                        	StationControllerActor* _ref_sc;
                        
                                    
                            memcpy(&_ref_sc, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	SignalPairActor* _ref_t;
                        
                                    
                            memcpy(&_ref_t, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvready(
                            	                        _ref_sc
	        	        , 
	                            _ref_t
	                                        );
                }
                    case HANDLE_DRIVE_OUT:
                {
                    int i = 0;
                                            			                        	SignalPairActor* _ref_n;
                        
                                    
                            memcpy(&_ref_n, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	SignalPairActor* _ref_d;
                        
                                    
                            memcpy(&_ref_d, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvhandle_drive_out(
                            	                        _ref_n
	        	        , 
	                            _ref_d
	                                        );
                }
                    case DRIVE_IN:
                {
                    int i = 0;
                                            			                        	StationControllerActor* _ref_sc;
                        
                                    
                            memcpy(&_ref_sc, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	SignalPairActor* _ref_t;
                        
                                    
                            memcpy(&_ref_t, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvdrive_in(
                            	                        _ref_sc
	        	        , 
	                            _ref_t
	                                        );
                }
                    case DRIVE_OUT:
                {
                    int i = 0;
                                            			                        	SignalPairActor* _ref_n;
                        
                                    
                            memcpy(&_ref_n, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvdrive_out(
                            	                        _ref_n
	                                        );
                }
            }
    return -1;   // if queue empty, we have no transitions
}

    long TrainActor::constructorTrain (byte creatorId 
    			    	        ,
	    	        		byte
	         _ref_iid
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "Train";
		#endif

	#ifdef TTS
	#endif

		{
			(_ref_id=_ref_iid);
			(_ref_drive_status=0);
			(_ref_station=null);
			(_ref_next=null);
			(_ref_dest=null);
			(_ref_track=null);
			(_ref_counter=0);
			(_ref_s=0);
			if ((_ref_id==1)) {
				{
					(_ref_schedule[0]=1);
					(_ref_schedule[1]=3);
					(_ref_schedule[2]=1);
					(_ref_schedule[3]=4);
					(_ref_schedule[4]=3);
					(_ref_schedule[5]=2);
					(_ref_schedule[6]=1);
					(_ref_schedule[7]=4);
					(_ref_schedule[8]=4);
					(_ref_schedule[9]=3);
				}
}
			else {
				if ((_ref_id==2)) {
					{
						(_ref_schedule[0]=1);
						(_ref_schedule[1]=3);
						(_ref_schedule[2]=1);
						(_ref_schedule[3]=4);
						(_ref_schedule[4]=3);
						(_ref_schedule[5]=2);
						(_ref_schedule[6]=1);
						(_ref_schedule[7]=4);
						(_ref_schedule[8]=4);
						(_ref_schedule[9]=3);
					}
}
				else {
					if ((_ref_id==101)) {
						{
							(_ref_schedule[0]=4);
							(_ref_schedule[1]=2);
							(_ref_schedule[2]=4);
							(_ref_schedule[3]=2);
							(_ref_schedule[4]=4);
							(_ref_schedule[5]=2);
							(_ref_schedule[6]=4);
							(_ref_schedule[7]=2);
							(_ref_schedule[8]=4);
							(_ref_schedule[9]=2);
						}
}
					else {
						if ((_ref_id==102)) {
							{
								(_ref_schedule[0]=2);
								(_ref_schedule[1]=4);
								(_ref_schedule[2]=2);
								(_ref_schedule[3]=4);
								(_ref_schedule[4]=2);
								(_ref_schedule[5]=4);
								(_ref_schedule[6]=2);
								(_ref_schedule[7]=4);
								(_ref_schedule[8]=2);
								(_ref_schedule[9]=4);
							}
}
						else {
							{
								(_ref_schedule[0]=3);
								(_ref_schedule[1]=3);
								(_ref_schedule[2]=3);
								(_ref_schedule[3]=3);
								(_ref_schedule[4]=3);
								(_ref_schedule[5]=3);
								(_ref_schedule[6]=3);
								(_ref_schedule[7]=3);
								(_ref_schedule[8]=3);
								(_ref_schedule[9]=3);
							}
}}}}
			_timed_msg_initial(myID, _ref_now, MAX_TIME);
		}
		shift = 0;
		queueTail = 0;
		while(messageQueue[queueTail]) {applyPolicy(false);queueTail++;}
		return 0;

	}


    void TrainActor::_msg_initial (byte senderId
        	    ){
        queueTail = 0;
        enqueue(messageQueue, INITIAL);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void TrainActor::_msg_drive (byte senderId
        	    ){
        queueTail = 0;
        enqueue(messageQueue, DRIVE);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void TrainActor::_msg_track_occupied (byte senderId
        		    	        ,
	    	        		SignalPairActor*
	         _ref_n
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, TRACK_OCCUPIED);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_n, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void TrainActor::_msg_red_signal (byte senderId
        	    ){
        queueTail = 0;
        enqueue(messageQueue, RED_SIGNAL);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void TrainActor::_msg_ready (byte senderId
        		    	        ,
	    	        		StationControllerActor*
	         _ref_sc
	        	        , 
	        	        		SignalPairActor*
	         _ref_t
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, READY);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_sc, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&paramsValues [index], &_ref_t, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void TrainActor::_msg_handle_drive_out (byte senderId
        		    	        ,
	    	        		SignalPairActor*
	         _ref_n
	        	        , 
	        	        		SignalPairActor*
	         _ref_d
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, HANDLE_DRIVE_OUT);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_n, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&paramsValues [index], &_ref_d, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void TrainActor::_msg_drive_in (byte senderId
        		    	        ,
	    	        		StationControllerActor*
	         _ref_sc
	        	        , 
	        	        		SignalPairActor*
	         _ref_t
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, DRIVE_IN);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_sc, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&paramsValues [index], &_ref_t, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void TrainActor::_msg_drive_out (byte senderId
        		    	        ,
	    	        		SignalPairActor*
	         _ref_n
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, DRIVE_OUT);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_n, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}

			






		
	byte** TrainActor::table = (byte**)0xFFFFFFFF;

	byte** TrainActor::getTable() {
		return table;
	}
			






		
	vector<TimeFrame>** TrainActor::hashtableTimeExtension = (vector<TimeFrame>**)0xFFFFFFFF;
	
	vector<TimeFrame>** TrainActor::getHashtableTimeExtension() {
		return hashtableTimeExtension;
	}
			






		
		    void TrainActor::_timed_msg_initial (byte senderId
	        	, TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_initial (senderId
	            );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void TrainActor::_timed_msg_drive (byte senderId
	        	, TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_drive (senderId
	            );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void TrainActor::_timed_msg_track_occupied (byte senderId
	        		    	        ,
	    	        		SignalPairActor*
	         _ref_n
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_track_occupied (senderId
	            	    	        ,
	                        _ref_n
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void TrainActor::_timed_msg_red_signal (byte senderId
	        	, TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_red_signal (senderId
	            );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void TrainActor::_timed_msg_ready (byte senderId
	        		    	        ,
	    	        		StationControllerActor*
	         _ref_sc
	        	        , 
	        	        		SignalPairActor*
	         _ref_t
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_ready (senderId
	            	    	        ,
	                        _ref_sc
	        	        , 
	                            _ref_t
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void TrainActor::_timed_msg_handle_drive_out (byte senderId
	        		    	        ,
	    	        		SignalPairActor*
	         _ref_n
	        	        , 
	        	        		SignalPairActor*
	         _ref_d
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_handle_drive_out (senderId
	            	    	        ,
	                        _ref_n
	        	        , 
	                            _ref_d
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void TrainActor::_timed_msg_drive_in (byte senderId
	        		    	        ,
	    	        		StationControllerActor*
	         _ref_sc
	        	        , 
	        	        		SignalPairActor*
	         _ref_t
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_drive_in (senderId
	            	    	        ,
	                        _ref_sc
	        	        , 
	                            _ref_t
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void TrainActor::_timed_msg_drive_out (byte senderId
	        		    	        ,
	    	        		SignalPairActor*
	         _ref_n
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_drive_out (senderId
	            	    	        ,
	                        _ref_n
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		
    long TrainActor::msgsrvinitial (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "initial";
		#endif

	#ifdef TTS
	#endif

		{
			_ref_homeStation->_timed_msg_set_train(myID, _ref_self, _ref_now, MAX_TIME);
		}
		return 0;

}
    long TrainActor::msgsrvdrive (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "drive";
		#endif

	#ifdef TTS
		if (__pc == 0) {__pc = -1; goto __jumpPoint0;}
	#endif

		{
_ref_now += 3;
			if ((_ref_drive_status==1)) {
				{
					_ref_station->_timed_msg_handle_drive_out(myID, _ref_self, _ref_schedule[_ref_s], _ref_now, MAX_TIME);
				}
}
			if ((_ref_drive_status==2)) {
				{
					_ref_next->_timed_msg_drive_out(myID, _ref_self, _ref_now, MAX_TIME);
				}
}
			if ((_ref_drive_status==3)) {
				{
					_ref_next->_timed_msg_occupy(myID, _ref_self, _ref_track, _ref_now, MAX_TIME);
				}
}
			if ((_ref_drive_status==4)) {
				{
					_ref_next->_timed_msg_drive_in(myID, _ref_self, _ref_track, _ref_now, MAX_TIME);
				}
}
		}
		return 0;

}
    long TrainActor::msgsrvtrack_occupied (
    			    	        		SignalPairActor*
	         _ref_n
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "track_occupied";
		#endif

	#ifdef TTS
	#endif

		{
			(_ref_track=_ref_next);
			(_ref_next=_ref_n);
			if (((_ref_next==_ref_dest)&&(_ref_drive_status==3))) {
				{
					(_ref_drive_status=4);
				}
}
			_timed_msg_drive(myID, _ref_now, MAX_TIME);
		}
		return 0;

}
    long TrainActor::msgsrvred_signal (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "red_signal";
		#endif

	#ifdef TTS
	#endif

		{
			_timed_msg_drive(myID, _ref_now, MAX_TIME);
		}
		return 0;

}
    long TrainActor::msgsrvready (
    			    	        		StationControllerActor*
	         _ref_sc
	        	        , 
	        	        		SignalPairActor*
	         _ref_t
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "ready";
		#endif

	#ifdef TTS
		if (__pc == 0) {__pc = -1; goto __jumpPoint0;}
	#endif

		{
			(_ref_track=_ref_t);
			(_ref_station=_ref_sc);
			(_ref_drive_status=1);
			(_ref_next=null);
			(_ref_dest=null);
_ref_now += 10;
			if (((_ref_s<1)||((_ref_id==1)&&(_ref_s<2)))) {
				{
					_timed_msg_drive(myID, _ref_now, MAX_TIME);
				}
}
		}
		return 0;

}
    long TrainActor::msgsrvhandle_drive_out (
    			    	        		SignalPairActor*
	         _ref_n
	        	        , 
	        	        		SignalPairActor*
	         _ref_d
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "handle_drive_out";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_drive_status==1)) {
				{
					(_ref_next=_ref_n);
					(_ref_dest=_ref_d);
					(_ref_drive_status=2);
					(_ref_schedule[_ref_s]=0);
					(_ref_s=(_ref_s+1));
					_timed_msg_drive(myID, _ref_now, MAX_TIME);
				}
}
		}
		return 0;

}
    long TrainActor::msgsrvdrive_in (
    			    	        		StationControllerActor*
	         _ref_sc
	        	        , 
	        	        		SignalPairActor*
	         _ref_t
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "drive_in";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_drive_status==4)) {
				{
					(_ref_next=null);
					(_ref_dest=null);
					_timed_msg_ready(myID, _ref_sc, _ref_t, 1 + _ref_now, MAX_TIME);
				}
}
		}
		return 0;

}
    long TrainActor::msgsrvdrive_out (
    			    	        		SignalPairActor*
	         _ref_n
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "drive_out";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_drive_status==2)) {
				{
					(_ref_next=_ref_n);
					(_ref_drive_status=3);
					_timed_msg_drive(myID, _ref_now, MAX_TIME);
				}
}
		}
		return 0;

}
