                                    

#include "Types.h"
#include "SignalPairActor.h"
#include <stdio.h>
#include <string.h>

// location counters (values stored in messageQueue[0])
/* There can be more than one location counter for each msgsrv when we
   want to have non-atomic message servers.
   Notice that values 0 and 1 are reserved for EMPTY and INITIAL, respectively.*/
#define GEGENFAHRSCHUTZ 1
#define FREE 2
#define DRIVE_OUT 3
#define DRIVE_IN 4
#define VORBLOCK 5
#define RUECKBLOCK 6
#define SET_GREEN 7
#define SET_RED 8
#define OCCUPY 9


// knownrebecs (those to whom message can be sent)
// the following format allows to use them as variables --> the ID of the rebec
#define _ref_sender (rebecs[senderQueue[0]])
#define _ref_self (dynamic_cast<SignalPairActor*>(rebecs[myID]))
        	#define _ref_sc (dynamic_cast<StationControllerActor*>(rebecs[known[1]]))
	                	#define _ref_t_prev (dynamic_cast<SignalPairActor*>(rebecs[known[2]]))
	            	#define _ref_t_next (dynamic_cast<SignalPairActor*>(rebecs[known[3]]))
	            

SignalPairActor::SignalPairActor(byte myID, char* myName, int maxQueueLength, int maxParamLength, vector<AbstractActor*>& rebecsRef
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
						






					, 200, hashmapSize
				






					






					)
					, AbstractActor (myID, myName, maxQueueLength, maxParamLength, rebecsRef
		#ifdef DEBUG_LEVEL_2 
			, out
		#endif
					






					, 200, hashmapSize
				






					






				)
	{

    messageNames = new char *[9 + 1];
	messageNames[0] = (char*)"Empty";

                messageNames[1] = (char*)"GEGENFAHRSCHUTZ";
                    messageNames[2] = (char*)"FREE";
                    messageNames[3] = (char*)"DRIVE_OUT";
                    messageNames[4] = (char*)"DRIVE_IN";
                    messageNames[5] = (char*)"VORBLOCK";
                    messageNames[6] = (char*)"RUECKBLOCK";
                    messageNames[7] = (char*)"SET_GREEN";
                    messageNames[8] = (char*)"SET_RED";
                    messageNames[9] = (char*)"OCCUPY";
            
				






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

SignalPairActor::~SignalPairActor (){
	delete [] messageNames;
	delete [] messageQueue;
	delete [] senderQueue;
}


void SignalPairActor::exportStateVariablesInXML(ostream &out, string tab) {
	out << tab << "<statevariables>" << endl;
            	    	out << tab << '\t' << "<variable name=\"signal\" type=\"byte\">" <<  
	    		((int)_ref_signal) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"station\" type=\"byte\">" <<  
	    		((int)_ref_station) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"block\" type=\"byte\">" <<  
	    		((int)_ref_block) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"preStation\" type=\"byte\">" <<  
	    		((int)_ref_preStation) << "</variable>" << endl;
			        	    	out << tab << '\t' << "<variable name=\"onTrack\" type=\"Train\">" <<  
	    		(_ref_onTrack == NULL ? "NULL" : _ref_onTrack->getName()) << "</variable>" << endl;
			        	    	out << tab << '\t' << "<variable name=\"verschluss\" type=\"SignalPair\">" <<  
	    		(_ref_verschluss == NULL ? "NULL" : _ref_verschluss->getName()) << "</variable>" << endl;
				out << tab << "</statevariables>" << endl;
}

void SignalPairActor::exportAMessageInXML(ostream &out, string tab, int cnt) {
        int i = 0;
        switch (messageQueue[cnt]) {
	                    case GEGENFAHRSCHUTZ: {
                                        			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "gegenfahrschutz("
                                	<< (_ref_tr == NULL ? "NULL" : _ref_tr->getName())
                	                                << ")";
                break;
               }
	                    case FREE: {
                                            
                    out << "free("
                                << ")";
                break;
               }
	                    case DRIVE_OUT: {
                                        			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "drive_out("
                                	<< (_ref_tr == NULL ? "NULL" : _ref_tr->getName())
                	                                << ")";
                break;
               }
	                    case DRIVE_IN: {
                                        			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	SignalPairActor* _ref_prev;
                        
                                    
                            memcpy(&_ref_prev, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "drive_in("
                                	<< (_ref_tr == NULL ? "NULL" : _ref_tr->getName())
                						<< ", "
					                                	<< (_ref_prev == NULL ? "NULL" : _ref_prev->getName())
                	                                << ")";
                break;
               }
	                    case VORBLOCK: {
                                            
                    out << "vorblock("
                                << ")";
                break;
               }
	                    case RUECKBLOCK: {
                                            
                    out << "rueckblock("
                                << ")";
                break;
               }
	                    case SET_GREEN: {
                                            
                    out << "set_green("
                                << ")";
                break;
               }
	                    case SET_RED: {
                                            
                    out << "set_red("
                                << ")";
                break;
               }
	                    case OCCUPY: {
                                        			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	SignalPairActor* _ref_last;
                        
                                    
                            memcpy(&_ref_last, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "occupy("
                                	<< (_ref_tr == NULL ? "NULL" : _ref_tr->getName())
                						<< ", "
					                                	<< (_ref_last == NULL ? "NULL" : _ref_last->getName())
                	                                << ")";
                break;
               }
	            	}

}

char* SignalPairActor::getClassName() {
    return (char*)"SignalPair";
}

void SignalPairActor::marshalActorToArray(byte* array) {
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

                            			            
                                    
                            memcpy(&array [marshalIndex], &_ref_signal, (1 * BYTE_SIZE));
                marshalIndex += (1 * BYTE_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_station, (1 * BYTE_SIZE));
                marshalIndex += (1 * BYTE_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_block, (1 * BYTE_SIZE));
                marshalIndex += (1 * BYTE_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_preStation, (1 * BYTE_SIZE));
                marshalIndex += (1 * BYTE_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_onTrack, (1 * REACTIVE_CLASS_SIZE));
                marshalIndex += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_verschluss, (1 * REACTIVE_CLASS_SIZE));
                marshalIndex += (1 * REACTIVE_CLASS_SIZE);
                            
        
    
    #ifdef NO_ATOMIC_EXECUTION
    	memcpy(&array [marshalIndex], &__pc, 4);
    	//array[marshalIndex++] = __pc;
    #endif

}

void SignalPairActor::unmarshalActorFromArray(byte* array) {

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

                            			                        
                                    
                            memcpy(&_ref_signal, &array [index], (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                                			                        
                                    
                            memcpy(&_ref_station, &array [index], (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                                			                        
                                    
                            memcpy(&_ref_block, &array [index], (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                                			                        
                                    
                            memcpy(&_ref_preStation, &array [index], (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                                			                        
                                    
                            memcpy(&_ref_onTrack, &array [index], (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			                        
                                    
                            memcpy(&_ref_verschluss, &array [index], (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                    
        
    #ifdef NO_ATOMIC_EXECUTION
    	memcpy(&__pc, &array [index], 4);
    	//__pc = array[index++];
    #endif
}

/*#ifdef DEBUG
void SignalPairActor::printStateContent(long stateNo) {
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
long SignalPairActor::execute() {
			AbstractTimedActor::execute();
	    switch (messageQueue[0]) {

                    case GEGENFAHRSCHUTZ:
                {
                    int i = 0;
                                            			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvgegenfahrschutz(
                            	                        _ref_tr
	                                        );
                }
                    case FREE:
                {
                    int i = 0;
                                                
                        return msgsrvfree(
                                                );
                }
                    case DRIVE_OUT:
                {
                    int i = 0;
                                            			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvdrive_out(
                            	                        _ref_tr
	                                        );
                }
                    case DRIVE_IN:
                {
                    int i = 0;
                                            			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	SignalPairActor* _ref_prev;
                        
                                    
                            memcpy(&_ref_prev, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvdrive_in(
                            	                        _ref_tr
	        	        , 
	                            _ref_prev
	                                        );
                }
                    case VORBLOCK:
                {
                    int i = 0;
                                                
                        return msgsrvvorblock(
                                                );
                }
                    case RUECKBLOCK:
                {
                    int i = 0;
                                                
                        return msgsrvrueckblock(
                                                );
                }
                    case SET_GREEN:
                {
                    int i = 0;
                                                
                        return msgsrvset_green(
                                                );
                }
                    case SET_RED:
                {
                    int i = 0;
                                                
                        return msgsrvset_red(
                                                );
                }
                    case OCCUPY:
                {
                    int i = 0;
                                            			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	SignalPairActor* _ref_last;
                        
                                    
                            memcpy(&_ref_last, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvoccupy(
                            	                        _ref_tr
	        	        , 
	                            _ref_last
	                                        );
                }
            }
    return -1;   // if queue empty, we have no transitions
}

    long SignalPairActor::constructorSignalPair (byte creatorId 
    			    	        ,
	    	        		byte
	         _ref_st
	        	        , 
	        	        		byte
	         _ref_pre
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "SignalPair";
		#endif

	#ifdef TTS
	#endif

		{
			(_ref_signal=1);
			(_ref_onTrack=null);
			(_ref_station=_ref_st);
			(_ref_block=0);
			(_ref_preStation=_ref_pre);
			if ((_ref_preStation==1)) {
				{
					(_ref_signal=0);
				}
}
			(_ref_verschluss=null);
		}
		shift = 0;
		queueTail = 0;
		while(messageQueue[queueTail]) {applyPolicy(false);queueTail++;}
		return 0;

	}


    void SignalPairActor::_msg_gegenfahrschutz (byte senderId
        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, GEGENFAHRSCHUTZ);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_tr, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void SignalPairActor::_msg_free (byte senderId
        	    ){
        queueTail = 0;
        enqueue(messageQueue, FREE);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void SignalPairActor::_msg_drive_out (byte senderId
        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, DRIVE_OUT);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_tr, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void SignalPairActor::_msg_drive_in (byte senderId
        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_prev
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, DRIVE_IN);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_tr, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&paramsValues [index], &_ref_prev, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void SignalPairActor::_msg_vorblock (byte senderId
        	    ){
        queueTail = 0;
        enqueue(messageQueue, VORBLOCK);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void SignalPairActor::_msg_rueckblock (byte senderId
        	    ){
        queueTail = 0;
        enqueue(messageQueue, RUECKBLOCK);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void SignalPairActor::_msg_set_green (byte senderId
        	    ){
        queueTail = 0;
        enqueue(messageQueue, SET_GREEN);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void SignalPairActor::_msg_set_red (byte senderId
        	    ){
        queueTail = 0;
        enqueue(messageQueue, SET_RED);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void SignalPairActor::_msg_occupy (byte senderId
        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_last
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, OCCUPY);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_tr, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&paramsValues [index], &_ref_last, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}

			






		
	byte** SignalPairActor::table = (byte**)0xFFFFFFFF;

	byte** SignalPairActor::getTable() {
		return table;
	}
			






		
	vector<TimeFrame>** SignalPairActor::hashtableTimeExtension = (vector<TimeFrame>**)0xFFFFFFFF;
	
	vector<TimeFrame>** SignalPairActor::getHashtableTimeExtension() {
		return hashtableTimeExtension;
	}
			






		
		    void SignalPairActor::_timed_msg_gegenfahrschutz (byte senderId
	        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_gegenfahrschutz (senderId
	            	    	        ,
	                        _ref_tr
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void SignalPairActor::_timed_msg_free (byte senderId
	        	, TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_free (senderId
	            );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void SignalPairActor::_timed_msg_drive_out (byte senderId
	        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_drive_out (senderId
	            	    	        ,
	                        _ref_tr
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void SignalPairActor::_timed_msg_drive_in (byte senderId
	        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_prev
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_drive_in (senderId
	            	    	        ,
	                        _ref_tr
	        	        , 
	                            _ref_prev
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void SignalPairActor::_timed_msg_vorblock (byte senderId
	        	, TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_vorblock (senderId
	            );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void SignalPairActor::_timed_msg_rueckblock (byte senderId
	        	, TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_rueckblock (senderId
	            );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void SignalPairActor::_timed_msg_set_green (byte senderId
	        	, TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_set_green (senderId
	            );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void SignalPairActor::_timed_msg_set_red (byte senderId
	        	, TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_set_red (senderId
	            );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void SignalPairActor::_timed_msg_occupy (byte senderId
	        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_last
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_occupy (senderId
	            	    	        ,
	                        _ref_tr
	        	        , 
	                            _ref_last
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		
    long SignalPairActor::msgsrvgegenfahrschutz (
    			    	        		TrainActor*
	         _ref_tr
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "gegenfahrschutz";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_block==0)) {
				{
					(_ref_block=1);
					(_ref_verschluss=_ref_self);
					(_ref_signal=0);
					_ref_sc->_timed_msg_annehmen(myID, _ref_tr, _ref_self, 1 + _ref_now, MAX_TIME);
				}
}
		}
		return 0;

}
    long SignalPairActor::msgsrvfree (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "free";
		#endif

	#ifdef TTS
	#endif

		{
			if (((_ref_sender==_ref_t_prev)||(_ref_sender==_ref_t_next))) {
				{
					if ((_ref_block==0)) {
						{
							(_ref_onTrack=null);
							(_ref_signal=1);
							(_ref_verschluss=null);
						}
}
					else {
						{
							_timed_msg_free(myID, _ref_now, MAX_TIME);
						}
}
				}
}
			if (((_ref_preStation==1)&&(_ref_sender==_ref_sc))) {
				{
					(_ref_block=0);
					(_ref_verschluss=null);
				}
}
		}
		return 0;

}
    long SignalPairActor::msgsrvdrive_out (
    			    	        		TrainActor*
	         _ref_tr
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "drive_out";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_sender==_ref_sc)) {
				{
					if ((_ref_block==0)) {
						{
							(_ref_block=1);
							(_ref_signal=1);
							_ref_tr->_timed_msg_drive(myID, _ref_now, MAX_TIME);
						}
}
					else {
						{
							_ref_sc->_timed_msg_ask_for_drive_out(myID, _ref_tr, _ref_now, MAX_TIME);
						}
}
				}
}
			else {
				{
					if ((_ref_preStation==1)) {
						{
							if ((_ref_signal==1)) {
								{
									_ref_tr->_timed_msg_drive_out(myID, _ref_self, _ref_now, MAX_TIME);
								}
}
							else {
								if ((_ref_signal==0)) {
									{
										_ref_sc->_timed_msg_ask_for_drive_out(myID, _ref_tr, _ref_now, MAX_TIME);
									}
}}
						}
}
				}
}
		}
		return 0;

}
    long SignalPairActor::msgsrvdrive_in (
    			    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_prev
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "drive_in";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_sender==_ref_sc)) {
				{
					if ((_ref_block==0)) {
						{
							(_ref_signal=1);
							_ref_tr->_timed_msg_drive(myID, _ref_now, MAX_TIME);
						}
}
					else {
						{
							_ref_sc->_timed_msg_ask_for_drive_in(myID, _ref_tr, 1 + _ref_now, MAX_TIME);
						}
}
				}
}
			else {
				{
					if ((_ref_preStation==1)) {
						{
							if ((_ref_prev!=null)) {
								_ref_prev->_timed_msg_rueckblock(myID, _ref_now, MAX_TIME);}
							if ((_ref_signal==1)) {
								{
									_ref_sc->_timed_msg_handle_drive_in(myID, _ref_tr, 1 + _ref_now, MAX_TIME);
									(_ref_signal=0);
								}
}
							else {
								if ((_ref_signal==0)) {
									{
										_ref_sc->_timed_msg_ask_for_drive_in(myID, _ref_tr, 1 + _ref_now, MAX_TIME);
									}
}}
						}
}
				}
}
		}
		return 0;

}
    long SignalPairActor::msgsrvvorblock (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "vorblock";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_preStation==1)) {
				{
				}
}
			else {
				{
					if ((_ref_sender==_ref_t_prev)) {
						{
							(_ref_block=1);
							(_ref_signal=1);
							(_ref_verschluss=_ref_t_prev);
						}
}
					if ((_ref_sender==_ref_t_next)) {
						{
							(_ref_block=1);
							(_ref_signal=1);
							(_ref_verschluss=_ref_t_next);
						}
}
				}
}
		}
		return 0;

}
    long SignalPairActor::msgsrvrueckblock (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "rueckblock";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_preStation==1)) {
				{
					(_ref_block=0);
					(_ref_verschluss=null);
					(_ref_signal=0);
				}
}
			else {
				if ((_ref_block==1)) {
					{
						(_ref_block=0);
						(_ref_signal=1);
						(_ref_verschluss=null);
					}
}}
		}
		return 0;

}
    long SignalPairActor::msgsrvset_green (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "set_green";
		#endif

	#ifdef TTS
	#endif

		{
			if (((_ref_block==0)&&(_ref_sender==_ref_self))) {
				{
					(_ref_signal=1);
				}
}
			else {
				{
					if ((_ref_sender==_ref_self)) {
						{
							_timed_msg_set_green(myID, _ref_now, MAX_TIME);
						}
}
				}
}
		}
		return 0;

}
    long SignalPairActor::msgsrvset_red (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "set_red";
		#endif

	#ifdef TTS
	#endif

		{
			if (((_ref_block==0)&&(_ref_sender==_ref_self))) {
				{
					(_ref_signal=0);
				}
}
			else {
				{
					if ((_ref_sender==_ref_self)) {
						{
							_timed_msg_set_red(myID, _ref_now, MAX_TIME);
						}
}
				}
}
		}
		return 0;

}
    long SignalPairActor::msgsrvoccupy (
    			    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_last
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "occupy";
		#endif

	#ifdef TTS
	#endif

		{
			byte _ref_dir = 0;

			if ((_ref_last==_ref_t_next)) {
				{
					(_ref_dir=2);
				}
}
			if ((_ref_last==_ref_t_prev)) {
				{
					(_ref_dir=1);
				}
}
			if ((_ref_signal==1)) {
				{
					if ((_ref_preStation==1)) {
						{
							(_ref_signal=0);
							if ((_ref_dir==1)) {
								{
									_ref_t_next->_timed_msg_vorblock(myID, _ref_now, MAX_TIME);
									_ref_tr->_timed_msg_track_occupied(myID, _ref_t_next, _ref_now, MAX_TIME);
								}
}
							else {
								if ((_ref_dir==2)) {
									{
										_ref_t_prev->_timed_msg_vorblock(myID, _ref_now, MAX_TIME);
										_ref_tr->_timed_msg_track_occupied(myID, _ref_t_prev, _ref_now, MAX_TIME);
									}
}}
							_ref_sc->_timed_msg_train_drove_out(myID, _ref_now, MAX_TIME);
						}
}
					else {
						if ((_ref_preStation==0)) {
							{
								if ((_ref_verschluss==_ref_t_prev)) {
									{
										(_ref_signal=0);
										_ref_t_next->_timed_msg_vorblock(myID, _ref_now, MAX_TIME);
										_ref_t_prev->_timed_msg_rueckblock(myID, _ref_now, MAX_TIME);
										_ref_tr->_timed_msg_track_occupied(myID, _ref_t_next, _ref_now, MAX_TIME);
									}
}
								else {
									if ((_ref_verschluss==_ref_t_next)) {
										{
											(_ref_signal=0);
											_ref_t_prev->_timed_msg_vorblock(myID, _ref_now, MAX_TIME);
											_ref_t_next->_timed_msg_rueckblock(myID, _ref_now, MAX_TIME);
											_ref_tr->_timed_msg_track_occupied(myID, _ref_t_prev, _ref_now, MAX_TIME);
										}
}
									else {
										{
											_timed_msg_occupy(myID, _ref_tr, _ref_last, 3 + _ref_now, MAX_TIME);
										}
}}
							}
}
						else {
							{
								_ref_tr->_timed_msg_drive(myID, _ref_now, MAX_TIME);
							}
}}
				}
}
			else {
				{
					_ref_tr->_timed_msg_drive(myID, _ref_now, MAX_TIME);
				}
}
		}
		return 0;

}
