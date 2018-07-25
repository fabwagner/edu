                                    

#include "Types.h"
#include "StationControllerActor.h"
#include <stdio.h>
#include <string.h>

// location counters (values stored in messageQueue[0])
/* There can be more than one location counter for each msgsrv when we
   want to have non-atomic message servers.
   Notice that values 0 and 1 are reserved for EMPTY and INITIAL, respectively.*/
#define HANDLE_DRIVE_IN 1
#define SET_TRAIN 2
#define HANDLE_DRIVE_OUT 3
#define ANBIETEN 4
#define CHECK_STATUS 5
#define CHECK_STATUS_FOR_DRIVE_OUT 6
#define REVERT_ANBIETEN 7
#define ANNEHMEN 8
#define ASK_FOR_DRIVE_OUT 9
#define TRAIN_DROVE_OUT 10
#define RUECKMELDUNG 11
#define ASK_FOR_DRIVE_IN 12


// knownrebecs (those to whom message can be sent)
// the following format allows to use them as variables --> the ID of the rebec
#define _ref_sender (rebecs[senderQueue[0]])
#define _ref_self (dynamic_cast<StationControllerActor*>(rebecs[myID]))
        	#define _ref_dest_s (dynamic_cast<StationControllerActor*>(rebecs[known[1]]))
	            	#define _ref_dest_w (dynamic_cast<StationControllerActor*>(rebecs[known[2]]))
	            	#define _ref_dest_n (dynamic_cast<StationControllerActor*>(rebecs[known[3]]))
	            	#define _ref_dest_e (dynamic_cast<StationControllerActor*>(rebecs[known[4]]))
	                	#define _ref_t (dynamic_cast<SignalPairActor*>(rebecs[known[5]]))
	            	#define _ref_pre_s (dynamic_cast<SignalPairActor*>(rebecs[known[6]]))
	            	#define _ref_pre_w (dynamic_cast<SignalPairActor*>(rebecs[known[7]]))
	            	#define _ref_pre_n (dynamic_cast<SignalPairActor*>(rebecs[known[8]]))
	            	#define _ref_pre_e (dynamic_cast<SignalPairActor*>(rebecs[known[9]]))
	            

StationControllerActor::StationControllerActor(byte myID, char* myName, int maxQueueLength, int maxParamLength, vector<AbstractActor*>& rebecsRef
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
						






					, 237, hashmapSize
				






					






					)
					, AbstractActor (myID, myName, maxQueueLength, maxParamLength, rebecsRef
		#ifdef DEBUG_LEVEL_2 
			, out
		#endif
					






					, 237, hashmapSize
				






					






				)
	{

    messageNames = new char *[12 + 1];
	messageNames[0] = (char*)"Empty";

                messageNames[1] = (char*)"HANDLE_DRIVE_IN";
                    messageNames[2] = (char*)"SET_TRAIN";
                    messageNames[3] = (char*)"HANDLE_DRIVE_OUT";
                    messageNames[4] = (char*)"ANBIETEN";
                    messageNames[5] = (char*)"CHECK_STATUS";
                    messageNames[6] = (char*)"CHECK_STATUS_FOR_DRIVE_OUT";
                    messageNames[7] = (char*)"REVERT_ANBIETEN";
                    messageNames[8] = (char*)"ANNEHMEN";
                    messageNames[9] = (char*)"ASK_FOR_DRIVE_OUT";
                    messageNames[10] = (char*)"TRAIN_DROVE_OUT";
                    messageNames[11] = (char*)"RUECKMELDUNG";
                    messageNames[12] = (char*)"ASK_FOR_DRIVE_IN";
            
				






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

StationControllerActor::~StationControllerActor (){
	delete [] messageNames;
	delete [] messageQueue;
	delete [] senderQueue;
}


void StationControllerActor::exportStateVariablesInXML(ostream &out, string tab) {
	out << tab << "<statevariables>" << endl;
            	    	out << tab << '\t' << "<variable name=\"nTrains\" type=\"int\">" <<  
	    		((int)_ref_nTrains) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"size\" type=\"int\">" <<  
	    		((int)_ref_size) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"iid\" type=\"int\">" <<  
	    		((int)_ref_iid) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"anbieten_sent\" type=\"int\">" <<  
	    		((int)_ref_anbieten_sent) << "</variable>" << endl;
			        	    	out << tab << '\t' << "<variable name=\"debug\" type=\"byte\">" <<  
	    		((int)_ref_debug) << "</variable>" << endl;
			        	    	out << tab << '\t' << "<variable name=\"train\" type=\"Train\">" <<  
	    		(_ref_train == NULL ? "NULL" : _ref_train->getName()) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"wait_for_e\" type=\"Train\">" <<  
	    		(_ref_wait_for_e == NULL ? "NULL" : _ref_wait_for_e->getName()) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"wait_for_w\" type=\"Train\">" <<  
	    		(_ref_wait_for_w == NULL ? "NULL" : _ref_wait_for_w->getName()) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"wait_for_n\" type=\"Train\">" <<  
	    		(_ref_wait_for_n == NULL ? "NULL" : _ref_wait_for_n->getName()) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"wait_for_s\" type=\"Train\">" <<  
	    		(_ref_wait_for_s == NULL ? "NULL" : _ref_wait_for_s->getName()) << "</variable>" << endl;
				out << tab << "</statevariables>" << endl;
}

void StationControllerActor::exportAMessageInXML(ostream &out, string tab, int cnt) {
        int i = 0;
        switch (messageQueue[cnt]) {
	                    case HANDLE_DRIVE_IN: {
                                        			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "handle_drive_in("
                                	<< (_ref_tr == NULL ? "NULL" : _ref_tr->getName())
                	                                << ")";
                break;
               }
	                    case SET_TRAIN: {
                                        			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "set_train("
                                	<< (_ref_tr == NULL ? "NULL" : _ref_tr->getName())
                	                                << ")";
                break;
               }
	                    case HANDLE_DRIVE_OUT: {
                                        			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	byte _ref_dir;
                        
                                    
                            memcpy(&_ref_dir, &paramQueue[cnt] [i], (1 * BYTE_SIZE));
                i += (1 * BYTE_SIZE);
                                    
                    out << "handle_drive_out("
                                	<< (_ref_tr == NULL ? "NULL" : _ref_tr->getName())
                						<< ", "
					                                	<< ((int)_ref_dir)
                	                                << ")";
                break;
               }
	                    case ANBIETEN: {
                                        			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "anbieten("
                                	<< (_ref_tr == NULL ? "NULL" : _ref_tr->getName())
                	                                << ")";
                break;
               }
	                    case CHECK_STATUS: {
                                        			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	StationControllerActor* _ref_dest;
                        
                                    
                            memcpy(&_ref_dest, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "check_status("
                                	<< (_ref_tr == NULL ? "NULL" : _ref_tr->getName())
                						<< ", "
					                                	<< (_ref_dest == NULL ? "NULL" : _ref_dest->getName())
                	                                << ")";
                break;
               }
	                    case CHECK_STATUS_FOR_DRIVE_OUT: {
                                        			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	byte _ref_dir;
                        
                                    
                            memcpy(&_ref_dir, &paramQueue[cnt] [i], (1 * BYTE_SIZE));
                i += (1 * BYTE_SIZE);
                                    
                    out << "check_status_for_drive_out("
                                	<< (_ref_tr == NULL ? "NULL" : _ref_tr->getName())
                						<< ", "
					                                	<< ((int)_ref_dir)
                	                                << ")";
                break;
               }
	                    case REVERT_ANBIETEN: {
                                            
                    out << "revert_anbieten("
                                << ")";
                break;
               }
	                    case ANNEHMEN: {
                                        			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	SignalPairActor* _ref_pre;
                        
                                    
                            memcpy(&_ref_pre, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "annehmen("
                                	<< (_ref_tr == NULL ? "NULL" : _ref_tr->getName())
                						<< ", "
					                                	<< (_ref_pre == NULL ? "NULL" : _ref_pre->getName())
                	                                << ")";
                break;
               }
	                    case ASK_FOR_DRIVE_OUT: {
                                        			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "ask_for_drive_out("
                                	<< (_ref_tr == NULL ? "NULL" : _ref_tr->getName())
                	                                << ")";
                break;
               }
	                    case TRAIN_DROVE_OUT: {
                                            
                    out << "train_drove_out("
                                << ")";
                break;
               }
	                    case RUECKMELDUNG: {
                                            
                    out << "rueckmeldung("
                                << ")";
                break;
               }
	                    case ASK_FOR_DRIVE_IN: {
                                        			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[cnt] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                    out << "ask_for_drive_in("
                                	<< (_ref_tr == NULL ? "NULL" : _ref_tr->getName())
                	                                << ")";
                break;
               }
	            	}

}

char* StationControllerActor::getClassName() {
    return (char*)"StationController";
}

void StationControllerActor::marshalActorToArray(byte* array) {
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

                            			            
                                    
                            memcpy(&array [marshalIndex], &_ref_nTrains, (1 * INT_SIZE));
                marshalIndex += (1 * INT_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_size, (1 * INT_SIZE));
                marshalIndex += (1 * INT_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_iid, (1 * INT_SIZE));
                marshalIndex += (1 * INT_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_anbieten_sent, (1 * INT_SIZE));
                marshalIndex += (1 * INT_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_debug, (1 * BYTE_SIZE));
                marshalIndex += (1 * BYTE_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_train, (1 * REACTIVE_CLASS_SIZE));
                marshalIndex += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_wait_for_e, (1 * REACTIVE_CLASS_SIZE));
                marshalIndex += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_wait_for_w, (1 * REACTIVE_CLASS_SIZE));
                marshalIndex += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_wait_for_n, (1 * REACTIVE_CLASS_SIZE));
                marshalIndex += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_wait_for_s, (1 * REACTIVE_CLASS_SIZE));
                marshalIndex += (1 * REACTIVE_CLASS_SIZE);
                            
        
    
    #ifdef NO_ATOMIC_EXECUTION
    	memcpy(&array [marshalIndex], &__pc, 4);
    	//array[marshalIndex++] = __pc;
    #endif

}

void StationControllerActor::unmarshalActorFromArray(byte* array) {

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

                            			                        
                                    
                            memcpy(&_ref_nTrains, &array [index], (1 * INT_SIZE));
                index += (1 * INT_SIZE);
                                			                        
                                    
                            memcpy(&_ref_size, &array [index], (1 * INT_SIZE));
                index += (1 * INT_SIZE);
                                			                        
                                    
                            memcpy(&_ref_iid, &array [index], (1 * INT_SIZE));
                index += (1 * INT_SIZE);
                                			                        
                                    
                            memcpy(&_ref_anbieten_sent, &array [index], (1 * INT_SIZE));
                index += (1 * INT_SIZE);
                                			                        
                                    
                            memcpy(&_ref_debug, &array [index], (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                                			                        
                                    
                            memcpy(&_ref_train, &array [index], (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			                        
                                    
                            memcpy(&_ref_wait_for_e, &array [index], (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			                        
                                    
                            memcpy(&_ref_wait_for_w, &array [index], (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			                        
                                    
                            memcpy(&_ref_wait_for_n, &array [index], (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			                        
                                    
                            memcpy(&_ref_wait_for_s, &array [index], (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                    
        
    #ifdef NO_ATOMIC_EXECUTION
    	memcpy(&__pc, &array [index], 4);
    	//__pc = array[index++];
    #endif
}

/*#ifdef DEBUG
void StationControllerActor::printStateContent(long stateNo) {
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
long StationControllerActor::execute() {
			AbstractTimedActor::execute();
	    switch (messageQueue[0]) {

                    case HANDLE_DRIVE_IN:
                {
                    int i = 0;
                                            			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvhandle_drive_in(
                            	                        _ref_tr
	                                        );
                }
                    case SET_TRAIN:
                {
                    int i = 0;
                                            			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvset_train(
                            	                        _ref_tr
	                                        );
                }
                    case HANDLE_DRIVE_OUT:
                {
                    int i = 0;
                                            			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	byte _ref_dir;
                        
                                    
                            memcpy(&_ref_dir, &paramQueue[0] [i], (1 * BYTE_SIZE));
                i += (1 * BYTE_SIZE);
                                    
                        return msgsrvhandle_drive_out(
                            	                        _ref_tr
	        	        , 
	                            _ref_dir
	                                        );
                }
                    case ANBIETEN:
                {
                    int i = 0;
                                            			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvanbieten(
                            	                        _ref_tr
	                                        );
                }
                    case CHECK_STATUS:
                {
                    int i = 0;
                                            			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	StationControllerActor* _ref_dest;
                        
                                    
                            memcpy(&_ref_dest, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvcheck_status(
                            	                        _ref_tr
	        	        , 
	                            _ref_dest
	                                        );
                }
                    case CHECK_STATUS_FOR_DRIVE_OUT:
                {
                    int i = 0;
                                            			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	byte _ref_dir;
                        
                                    
                            memcpy(&_ref_dir, &paramQueue[0] [i], (1 * BYTE_SIZE));
                i += (1 * BYTE_SIZE);
                                    
                        return msgsrvcheck_status_for_drive_out(
                            	                        _ref_tr
	        	        , 
	                            _ref_dir
	                                        );
                }
                    case REVERT_ANBIETEN:
                {
                    int i = 0;
                                                
                        return msgsrvrevert_anbieten(
                                                );
                }
                    case ANNEHMEN:
                {
                    int i = 0;
                                            			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                			                        	SignalPairActor* _ref_pre;
                        
                                    
                            memcpy(&_ref_pre, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvannehmen(
                            	                        _ref_tr
	        	        , 
	                            _ref_pre
	                                        );
                }
                    case ASK_FOR_DRIVE_OUT:
                {
                    int i = 0;
                                            			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvask_for_drive_out(
                            	                        _ref_tr
	                                        );
                }
                    case TRAIN_DROVE_OUT:
                {
                    int i = 0;
                                                
                        return msgsrvtrain_drove_out(
                                                );
                }
                    case RUECKMELDUNG:
                {
                    int i = 0;
                                                
                        return msgsrvrueckmeldung(
                                                );
                }
                    case ASK_FOR_DRIVE_IN:
                {
                    int i = 0;
                                            			                        	TrainActor* _ref_tr;
                        
                                    
                            memcpy(&_ref_tr, &paramQueue[0] [i], (1 * REACTIVE_CLASS_SIZE));
                i += (1 * REACTIVE_CLASS_SIZE);
                                    
                        return msgsrvask_for_drive_in(
                            	                        _ref_tr
	                                        );
                }
            }
    return -1;   // if queue empty, we have no transitions
}

    long StationControllerActor::constructorStationController (byte creatorId 
    			    	        ,
	    	        		int
	         _ref_idd
	        	        , 
	        	        		int
	         _ref_s
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "StationController";
		#endif

	#ifdef TTS
	#endif

		{
			(_ref_nTrains=0);
			(_ref_size=_ref_s);
			(_ref_iid=_ref_idd);
			(_ref_wait_for_e=null);
			(_ref_wait_for_w=null);
			(_ref_wait_for_n=null);
			(_ref_wait_for_s=null);
			(_ref_anbieten_sent=0);
		}
		shift = 0;
		queueTail = 0;
		while(messageQueue[queueTail]) {applyPolicy(false);queueTail++;}
		return 0;

	}


    void StationControllerActor::_msg_handle_drive_in (byte senderId
        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, HANDLE_DRIVE_IN);
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
    void StationControllerActor::_msg_set_train (byte senderId
        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, SET_TRAIN);
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
    void StationControllerActor::_msg_handle_drive_out (byte senderId
        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		byte
	         _ref_dir
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, HANDLE_DRIVE_OUT);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_tr, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&paramsValues [index], &_ref_dir, (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void StationControllerActor::_msg_anbieten (byte senderId
        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, ANBIETEN);
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
    void StationControllerActor::_msg_check_status (byte senderId
        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		StationControllerActor*
	         _ref_dest
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, CHECK_STATUS);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_tr, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&paramsValues [index], &_ref_dest, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void StationControllerActor::_msg_check_status_for_drive_out (byte senderId
        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		byte
	         _ref_dir
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, CHECK_STATUS_FOR_DRIVE_OUT);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_tr, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&paramsValues [index], &_ref_dir, (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void StationControllerActor::_msg_revert_anbieten (byte senderId
        	    ){
        queueTail = 0;
        enqueue(messageQueue, REVERT_ANBIETEN);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void StationControllerActor::_msg_annehmen (byte senderId
        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_pre
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, ANNEHMEN);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_tr, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                                			            
                                    
                            memcpy(&paramsValues [index], &_ref_pre, (1 * REACTIVE_CLASS_SIZE));
                index += (1 * REACTIVE_CLASS_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void StationControllerActor::_msg_ask_for_drive_out (byte senderId
        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, ASK_FOR_DRIVE_OUT);
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
    void StationControllerActor::_msg_train_drove_out (byte senderId
        	    ){
        queueTail = 0;
        enqueue(messageQueue, TRAIN_DROVE_OUT);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void StationControllerActor::_msg_rueckmeldung (byte senderId
        	    ){
        queueTail = 0;
        enqueue(messageQueue, RUECKMELDUNG);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void StationControllerActor::_msg_ask_for_drive_in (byte senderId
        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, ASK_FOR_DRIVE_IN);
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

			






		
	byte** StationControllerActor::table = (byte**)0xFFFFFFFF;

	byte** StationControllerActor::getTable() {
		return table;
	}
			






		
	vector<TimeFrame>** StationControllerActor::hashtableTimeExtension = (vector<TimeFrame>**)0xFFFFFFFF;
	
	vector<TimeFrame>** StationControllerActor::getHashtableTimeExtension() {
		return hashtableTimeExtension;
	}
			






		
		    void StationControllerActor::_timed_msg_handle_drive_in (byte senderId
	        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_handle_drive_in (senderId
	            	    	        ,
	                        _ref_tr
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void StationControllerActor::_timed_msg_set_train (byte senderId
	        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_set_train (senderId
	            	    	        ,
	                        _ref_tr
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void StationControllerActor::_timed_msg_handle_drive_out (byte senderId
	        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		byte
	         _ref_dir
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_handle_drive_out (senderId
	            	    	        ,
	                        _ref_tr
	        	        , 
	                            _ref_dir
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void StationControllerActor::_timed_msg_anbieten (byte senderId
	        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_anbieten (senderId
	            	    	        ,
	                        _ref_tr
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void StationControllerActor::_timed_msg_check_status (byte senderId
	        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		StationControllerActor*
	         _ref_dest
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_check_status (senderId
	            	    	        ,
	                        _ref_tr
	        	        , 
	                            _ref_dest
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void StationControllerActor::_timed_msg_check_status_for_drive_out (byte senderId
	        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		byte
	         _ref_dir
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_check_status_for_drive_out (senderId
	            	    	        ,
	                        _ref_tr
	        	        , 
	                            _ref_dir
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void StationControllerActor::_timed_msg_revert_anbieten (byte senderId
	        	, TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_revert_anbieten (senderId
	            );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void StationControllerActor::_timed_msg_annehmen (byte senderId
	        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_pre
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_annehmen (senderId
	            	    	        ,
	                        _ref_tr
	        	        , 
	                            _ref_pre
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void StationControllerActor::_timed_msg_ask_for_drive_out (byte senderId
	        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_ask_for_drive_out (senderId
	            	    	        ,
	                        _ref_tr
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void StationControllerActor::_timed_msg_train_drove_out (byte senderId
	        	, TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_train_drove_out (senderId
	            );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void StationControllerActor::_timed_msg_rueckmeldung (byte senderId
	        	, TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_rueckmeldung (senderId
	            );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		    void StationControllerActor::_timed_msg_ask_for_drive_in (byte senderId
	        		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , TIME_TYPE executionTime, TIME_TYPE deadline){
	    _msg_ask_for_drive_in (senderId
	            	    	        ,
	                        _ref_tr
	                    );
	    addTimedBundles(senderId, executionTime, deadline);
	}
		
    long StationControllerActor::msgsrvhandle_drive_in (
    			    	        		TrainActor*
	         _ref_tr
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "handle_drive_in";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_tr==_ref_train)) {
				{
					(_ref_nTrains=(_ref_nTrains+1));
					(_ref_train=null);
					_ref_tr->_timed_msg_drive_in(myID, _ref_self, _ref_t, _ref_now, MAX_TIME);
				}
}
			else {
				{
					_timed_msg_handle_drive_in(myID, _ref_tr, 3 + _ref_now, MAX_TIME);
				}
}
		}
		return 0;

}
    long StationControllerActor::msgsrvset_train (
    			    	        		TrainActor*
	         _ref_tr
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "set_train";
		#endif

	#ifdef TTS
		if (__pc == 0) {__pc = -1; goto __jumpPoint0;}
	#endif

		{
			if ((_ref_nTrains<_ref_size)) {
				{
					(_ref_nTrains=(_ref_nTrains+1));
_ref_now += 1;
					_ref_tr->_timed_msg_ready(myID, _ref_self, _ref_t, _ref_now, MAX_TIME);
				}
}
			else {
				{
					_timed_msg_set_train(myID, _ref_tr, _ref_now, MAX_TIME);
				}
}
		}
		return 0;

}
    long StationControllerActor::msgsrvhandle_drive_out (
    			    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		byte
	         _ref_dir
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "handle_drive_out";
		#endif

	#ifdef TTS
		if (__pc == 0) {__pc = -1; goto __jumpPoint0;}
	#endif

		{
_ref_now += 2;
			if ((((_ref_train==null)||(_ref_train==_ref_tr))&&(((((_ref_wait_for_s==null)&&(_ref_dir==1))||((_ref_wait_for_w==null)&&(_ref_dir==2)))||((_ref_wait_for_n==null)&&(_ref_dir==3)))||((_ref_wait_for_e==null)&&(_ref_dir==4))))) {
				{
					(_ref_train=_ref_tr);
					if ((_ref_dir==1)) {
						{
							(_ref_anbieten_sent=1);
							_ref_dest_s->_timed_msg_anbieten(myID, _ref_tr, _ref_now, MAX_TIME);
						}
}
					else {
						if ((_ref_dir==2)) {
							{
								(_ref_anbieten_sent=2);
								_ref_dest_w->_timed_msg_anbieten(myID, _ref_tr, _ref_now, MAX_TIME);
							}
}
						else {
							if ((_ref_dir==3)) {
								{
									(_ref_anbieten_sent=3);
									_ref_dest_n->_timed_msg_anbieten(myID, _ref_tr, _ref_now, MAX_TIME);
								}
}
							else {
								if ((_ref_dir==4)) {
									{
										(_ref_anbieten_sent=4);
										_ref_dest_e->_timed_msg_anbieten(myID, _ref_tr, _ref_now, MAX_TIME);
									}
}}}}
					(_ref_nTrains=(_ref_nTrains-1));
				}
}
			else {
				{
					StationControllerActor* _ref_dest = null;

					if ((_ref_dir==1)) {
						{
							(_ref_dest=_ref_dest_s);
						}
}
					else {
						if ((_ref_dir==2)) {
							{
								(_ref_dest=_ref_dest_w);
							}
}
						else {
							if ((_ref_dir==3)) {
								{
									(_ref_dest=_ref_dest_n);
								}
}
							else {
								if ((_ref_dir==4)) {
									{
										(_ref_dest=_ref_dest_e);
									}
}}}}
					_timed_msg_check_status_for_drive_out(myID, _ref_tr, _ref_dir, _ref_now, MAX_TIME);
				}
}
		}
		return 0;

}
    long StationControllerActor::msgsrvanbieten (
    			    	        		TrainActor*
	         _ref_tr
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "anbieten";
		#endif

	#ifdef TTS
		if (__pc == 0) {__pc = -1; goto __jumpPoint0;}
	#endif

		{
_ref_now += 1;
			int _ref_d = (-1);

			if ((_ref_sender==_ref_dest_s)) {
				(_ref_d=1);}
			if ((_ref_sender==_ref_dest_w)) {
				(_ref_d=2);}
			if ((_ref_sender==_ref_dest_n)) {
				(_ref_d=3);}
			if ((_ref_sender==_ref_dest_e)) {
				(_ref_d=4);}
			if (((_ref_train!=null)&&(_ref_anbieten_sent==_ref_d))) {
				{
					(_ref_d=(_ref_d-2));
					if ((_ref_d==0)) {
						(_ref_d=4);}
					if ((_ref_d==(-1))) {
						(_ref_d=3);}
					if ((_ref_d>_ref_anbieten_sent)) {
						{
							if (((_ref_sender==_ref_dest_s)||(_ref_sender==_ref_pre_s))) {
								{
									_ref_pre_s->_timed_msg_gegenfahrschutz(myID, _ref_tr, _ref_now, MAX_TIME);
									(_ref_wait_for_s=_ref_tr);
									(_ref_train=null);
								}
}
							else {
								if (((_ref_sender==_ref_dest_w)||(_ref_sender==_ref_pre_w))) {
									{
										_ref_pre_w->_timed_msg_gegenfahrschutz(myID, _ref_tr, _ref_now, MAX_TIME);
										(_ref_wait_for_w=_ref_tr);
										(_ref_train=null);
									}
}
								else {
									if (((_ref_sender==_ref_dest_n)||(_ref_sender==_ref_pre_n))) {
										{
											_ref_pre_n->_timed_msg_gegenfahrschutz(myID, _ref_tr, _ref_now, MAX_TIME);
											(_ref_wait_for_n=_ref_tr);
											(_ref_train=null);
										}
}
									else {
										if (((_ref_sender==_ref_dest_e)||(_ref_sender==_ref_pre_e))) {
											{
												_ref_pre_e->_timed_msg_gegenfahrschutz(myID, _ref_tr, _ref_now, MAX_TIME);
												(_ref_wait_for_e=_ref_tr);
												(_ref_train=null);
											}
}}}}
						}
}
					else {
						if ((_ref_d==_ref_anbieten_sent)) {
							{
								if (((_ref_sender==_ref_dest_s)||(_ref_sender==_ref_pre_s))) {
									{
										(_ref_wait_for_s=_ref_tr);
										(_ref_train=null);
									}
}
								else {
									if (((_ref_sender==_ref_dest_w)||(_ref_sender==_ref_pre_w))) {
										{
											(_ref_wait_for_w=_ref_tr);
											(_ref_train=null);
										}
}
									else {
										if (((_ref_sender==_ref_dest_n)||(_ref_sender==_ref_pre_n))) {
											{
												(_ref_wait_for_n=_ref_tr);
												(_ref_train=null);
											}
}
										else {
											if (((_ref_sender==_ref_dest_e)||(_ref_sender==_ref_pre_e))) {
												{
													(_ref_wait_for_e=_ref_tr);
													(_ref_train=null);
												}
}}}}
							}
}
						else {
							{
								if ((_ref_sender==_ref_dest_s)) {
									_ref_dest_s->_timed_msg_revert_anbieten(myID, _ref_now, MAX_TIME);}
								else {
									if ((_ref_sender==_ref_dest_w)) {
										_ref_dest_w->_timed_msg_revert_anbieten(myID, _ref_now, MAX_TIME);}
									else {
										if ((_ref_sender==_ref_dest_n)) {
											_ref_dest_n->_timed_msg_revert_anbieten(myID, _ref_now, MAX_TIME);}
										else {
											if ((_ref_sender==_ref_dest_e)) {
												_ref_dest_e->_timed_msg_revert_anbieten(myID, _ref_now, MAX_TIME);}}}}
							}
}}
				}
}
			else {
				{
					if (((_ref_sender==_ref_dest_s)||(_ref_sender==_ref_pre_s))) {
						{
							if ((_ref_wait_for_s==null)) {
								{
									_ref_pre_s->_timed_msg_gegenfahrschutz(myID, _ref_tr, _ref_now, MAX_TIME);
									(_ref_wait_for_s=_ref_tr);
								}
}
							else {
								{
									(_ref_wait_for_s=_ref_tr);
									_ref_dest_s->_timed_msg_annehmen(myID, _ref_tr, _ref_pre_s, _ref_now, MAX_TIME);
								}
}
						}
}
					else {
						if (((_ref_sender==_ref_dest_w)||(_ref_sender==_ref_pre_w))) {
							{
								if ((_ref_wait_for_w==null)) {
									{
										_ref_pre_w->_timed_msg_gegenfahrschutz(myID, _ref_tr, _ref_now, MAX_TIME);
										(_ref_wait_for_w=_ref_tr);
									}
}
								else {
									{
										(_ref_wait_for_w=_ref_tr);
										_ref_dest_w->_timed_msg_annehmen(myID, _ref_tr, _ref_pre_w, _ref_now, MAX_TIME);
									}
}
							}
}
						else {
							if (((_ref_sender==_ref_dest_n)||(_ref_sender==_ref_pre_n))) {
								{
									if ((_ref_wait_for_n==null)) {
										{
											_ref_pre_n->_timed_msg_gegenfahrschutz(myID, _ref_tr, _ref_now, MAX_TIME);
											(_ref_wait_for_n=_ref_tr);
										}
}
									else {
										{
											(_ref_wait_for_n=_ref_tr);
											_ref_dest_n->_timed_msg_annehmen(myID, _ref_tr, _ref_pre_n, _ref_now, MAX_TIME);
										}
}
								}
}
							else {
								if (((_ref_sender==_ref_dest_e)||(_ref_sender==_ref_pre_e))) {
									{
										if ((_ref_wait_for_n==null)) {
											{
												_ref_pre_e->_timed_msg_gegenfahrschutz(myID, _ref_tr, _ref_now, MAX_TIME);
												(_ref_wait_for_e=_ref_tr);
											}
}
										else {
											{
												(_ref_wait_for_e=_ref_tr);
												_ref_dest_e->_timed_msg_annehmen(myID, _ref_tr, _ref_pre_e, _ref_now, MAX_TIME);
											}
}
									}
}}}}
				}
}
		}
		return 0;

}
    long StationControllerActor::msgsrvcheck_status (
    			    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		StationControllerActor*
	         _ref_dest
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "check_status";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_sender==_ref_self)) {
				{
					int _ref_check_after = 5;

					if ((_ref_dest==_ref_dest_s)) {
						{
							if (((_ref_wait_for_s==null)&&(_ref_train==null))) {
								{
									(_ref_train=_ref_tr);
									_ref_tr->_timed_msg_drive(myID, _ref_now, MAX_TIME);
								}
}
							else {
								{
									_timed_msg_check_status(myID, _ref_tr, _ref_dest, _ref_check_after + _ref_now, MAX_TIME);
								}
}
						}
}
					else {
						if ((_ref_dest==_ref_dest_w)) {
							{
								if (((_ref_wait_for_w==null)&&(_ref_train==null))) {
									{
										(_ref_train=_ref_tr);
										_ref_tr->_timed_msg_drive(myID, _ref_now, MAX_TIME);
									}
}
								else {
									{
										_timed_msg_check_status(myID, _ref_tr, _ref_dest, _ref_check_after + _ref_now, MAX_TIME);
									}
}
							}
}
						else {
							if ((_ref_dest==_ref_dest_n)) {
								{
									if (((_ref_wait_for_n==null)&&(_ref_train==null))) {
										{
											(_ref_train=_ref_tr);
											_ref_tr->_timed_msg_drive(myID, _ref_now, MAX_TIME);
										}
}
									else {
										{
											_timed_msg_check_status(myID, _ref_tr, _ref_dest, _ref_check_after + _ref_now, MAX_TIME);
										}
}
								}
}
							else {
								if ((_ref_dest==_ref_dest_e)) {
									{
										if (((_ref_wait_for_e==null)&&(_ref_train==null))) {
											{
												(_ref_train=_ref_tr);
												_ref_tr->_timed_msg_drive(myID, _ref_now, MAX_TIME);
											}
}
										else {
											{
												_timed_msg_check_status(myID, _ref_tr, _ref_dest, _ref_check_after + _ref_now, MAX_TIME);
											}
}
									}
}}}}
				}
}
		}
		return 0;

}
    long StationControllerActor::msgsrvcheck_status_for_drive_out (
    			    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		byte
	         _ref_dir
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "check_status_for_drive_out";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_sender==_ref_self)) {
				{
					int _ref_check_after = 3;

					if ((_ref_train==null)) {
						{
							_timed_msg_handle_drive_out(myID, _ref_tr, _ref_dir, _ref_now, MAX_TIME);
						}
}
					else {
						{
							_timed_msg_check_status_for_drive_out(myID, _ref_tr, _ref_dir, _ref_check_after + _ref_now, MAX_TIME);
						}
}
				}
}
		}
		return 0;

}
    long StationControllerActor::msgsrvrevert_anbieten (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "revert_anbieten";
		#endif

	#ifdef TTS
	#endif

		{
			int _ref_check_after = 5;

			if ((_ref_anbieten_sent==1)) {
				{
					_timed_msg_check_status(myID, _ref_train, _ref_dest_s, _ref_check_after + _ref_now, MAX_TIME);
				}
}
			else {
				if ((_ref_anbieten_sent==2)) {
					{
						_timed_msg_check_status(myID, _ref_train, _ref_dest_w, _ref_check_after + _ref_now, MAX_TIME);
					}
}
				else {
					if ((_ref_anbieten_sent==3)) {
						{
							_timed_msg_check_status(myID, _ref_train, _ref_dest_n, _ref_check_after + _ref_now, MAX_TIME);
						}
}
					else {
						if ((_ref_anbieten_sent==4)) {
							{
								_timed_msg_check_status(myID, _ref_train, _ref_dest_e, _ref_check_after + _ref_now, MAX_TIME);
							}
}}}}
			(_ref_anbieten_sent=0);
			(_ref_train=null);
		}
		return 0;

}
    long StationControllerActor::msgsrvannehmen (
    			    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_pre
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "annehmen";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_sender==_ref_pre_w)) {
				{
					_ref_dest_w->_timed_msg_annehmen(myID, _ref_tr, _ref_pre_w, _ref_now, MAX_TIME);
				}
}
			else {
				if ((_ref_sender==_ref_pre_e)) {
					{
						_ref_dest_e->_timed_msg_annehmen(myID, _ref_tr, _ref_pre_e, _ref_now, MAX_TIME);
					}
}
				else {
					if ((_ref_sender==_ref_pre_n)) {
						{
							_ref_dest_n->_timed_msg_annehmen(myID, _ref_tr, _ref_pre_n, _ref_now, MAX_TIME);
						}
}
					else {
						if ((_ref_sender==_ref_pre_s)) {
							{
								_ref_dest_s->_timed_msg_annehmen(myID, _ref_tr, _ref_pre_s, _ref_now, MAX_TIME);
							}
}}}}
			if ((_ref_train==_ref_tr)) {
				{
					if (((_ref_sender==_ref_dest_s)&&(_ref_anbieten_sent==1))) {
						{
							(_ref_anbieten_sent=0);
							_ref_tr->_timed_msg_handle_drive_out(myID, _ref_pre_s, _ref_pre, _ref_now, MAX_TIME);
						}
}
					if (((_ref_sender==_ref_dest_w)&&(_ref_anbieten_sent==2))) {
						{
							(_ref_anbieten_sent=0);
							_ref_tr->_timed_msg_handle_drive_out(myID, _ref_pre_w, _ref_pre, _ref_now, MAX_TIME);
						}
}
					if (((_ref_sender==_ref_dest_n)&&(_ref_anbieten_sent==3))) {
						{
							(_ref_anbieten_sent=0);
							_ref_tr->_timed_msg_handle_drive_out(myID, _ref_pre_n, _ref_pre, _ref_now, MAX_TIME);
						}
}
					if (((_ref_sender==_ref_dest_e)&&(_ref_anbieten_sent==4))) {
						{
							(_ref_anbieten_sent=0);
							_ref_tr->_timed_msg_handle_drive_out(myID, _ref_pre_e, _ref_pre, _ref_now, MAX_TIME);
						}
}
				}
}
		}
		return 0;

}
    long StationControllerActor::msgsrvask_for_drive_out (
    			    	        		TrainActor*
	         _ref_tr
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "ask_for_drive_out";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_train==_ref_tr)) {
				{
					if ((_ref_sender==_ref_pre_e)) {
						{
							_ref_pre_e->_timed_msg_drive_out(myID, _ref_tr, _ref_now, MAX_TIME);
						}
}
					else {
						if ((_ref_sender==_ref_pre_w)) {
							{
								_ref_pre_w->_timed_msg_drive_out(myID, _ref_tr, _ref_now, MAX_TIME);
							}
}
						else {
							if ((_ref_sender==_ref_pre_n)) {
								{
									_ref_pre_n->_timed_msg_drive_out(myID, _ref_tr, _ref_now, MAX_TIME);
								}
}
							else {
								if ((_ref_sender==_ref_pre_s)) {
									{
										_ref_pre_s->_timed_msg_drive_out(myID, _ref_tr, _ref_now, MAX_TIME);
									}
}}}}
				}
}
			else {
				{
					_ref_tr->_timed_msg_drive(myID, 10 + _ref_now, MAX_TIME);
				}
}
		}
		return 0;

}
    long StationControllerActor::msgsrvtrain_drove_out (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "train_drove_out";
		#endif

	#ifdef TTS
		if (__pc == 0) {__pc = -1; goto __jumpPoint0;}
	#endif

		{
_ref_now += 2;
			(_ref_train=null);
		}
		return 0;

}
    long StationControllerActor::msgsrvrueckmeldung (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "rueckmeldung";
		#endif

	#ifdef TTS
	#endif

		{
			if ((_ref_sender==_ref_dest_s)) {
				{
					_ref_pre_s->_timed_msg_free(myID, _ref_now, MAX_TIME);
				}
}
			else {
				if ((_ref_sender==_ref_dest_w)) {
					{
						_ref_pre_w->_timed_msg_free(myID, _ref_now, MAX_TIME);
					}
}
				else {
					if ((_ref_sender==_ref_dest_n)) {
						{
							_ref_pre_n->_timed_msg_free(myID, _ref_now, MAX_TIME);
						}
}
					else {
						if ((_ref_sender==_ref_dest_e)) {
							{
								_ref_pre_e->_timed_msg_free(myID, _ref_now, MAX_TIME);
							}
}}}}
		}
		return 0;

}
    long StationControllerActor::msgsrvask_for_drive_in (
    			    	        		TrainActor*
	         _ref_tr
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "ask_for_drive_in";
		#endif

	#ifdef TTS
		if (__pc == 0) {__pc = -1; goto __jumpPoint0;}
		if (__pc == 1) {__pc = -1; goto __jumpPoint1;}
		if (__pc == 2) {__pc = -1; goto __jumpPoint2;}
		if (__pc == 3) {__pc = -1; goto __jumpPoint3;}
	#endif

		{
			if (((_ref_train==null)||(_ref_train==_ref_tr))) {
				{
					(_ref_train=_ref_tr);
					if ((_ref_sender==_ref_pre_e)) {
						{
							if ((_ref_tr==_ref_wait_for_e)) {
								{
									(_ref_wait_for_e=null);
									_ref_dest_e->_timed_msg_rueckmeldung(myID, _ref_now, MAX_TIME);
									_ref_pre_e->_timed_msg_free(myID, _ref_now, MAX_TIME);
_ref_now += 2;
									_ref_pre_e->_timed_msg_drive_in(myID, _ref_tr, null, 1 + _ref_now, MAX_TIME);
									(_ref_nTrains=(_ref_nTrains+1));
									(_ref_train=null);
								}
}
							else {
								{
									_ref_pre_e->_timed_msg_drive_in(myID, _ref_tr, null, 1 + _ref_now, MAX_TIME);
									(_ref_nTrains=(_ref_nTrains+1));
									(_ref_train=null);
								}
}
						}
}
					if ((_ref_sender==_ref_pre_w)) {
						{
							if ((_ref_tr==_ref_wait_for_w)) {
								{
									(_ref_wait_for_w=null);
									_ref_dest_w->_timed_msg_rueckmeldung(myID, _ref_now, MAX_TIME);
									_ref_pre_w->_timed_msg_free(myID, _ref_now, MAX_TIME);
_ref_now += 2;
									_ref_pre_w->_timed_msg_drive_in(myID, _ref_tr, null, 1 + _ref_now, MAX_TIME);
									(_ref_nTrains=(_ref_nTrains+1));
									(_ref_train=null);
								}
}
							else {
								{
									_ref_pre_w->_timed_msg_drive_in(myID, _ref_tr, null, 1 + _ref_now, MAX_TIME);
									(_ref_nTrains=(_ref_nTrains+1));
									(_ref_train=null);
								}
}
						}
}
					if ((_ref_sender==_ref_pre_n)) {
						{
							if ((_ref_tr==_ref_wait_for_n)) {
								{
									(_ref_wait_for_n=null);
									_ref_dest_n->_timed_msg_rueckmeldung(myID, _ref_now, MAX_TIME);
									_ref_pre_n->_timed_msg_free(myID, _ref_now, MAX_TIME);
_ref_now += 2;
									_ref_pre_n->_timed_msg_drive_in(myID, _ref_tr, null, 1 + _ref_now, MAX_TIME);
								}
}
							else {
								{
									_ref_pre_n->_timed_msg_drive_in(myID, _ref_tr, null, 1 + _ref_now, MAX_TIME);
									(_ref_nTrains=(_ref_nTrains+1));
									(_ref_train=null);
								}
}
						}
}
					if ((_ref_sender==_ref_pre_s)) {
						{
							if ((_ref_tr==_ref_wait_for_s)) {
								{
									(_ref_wait_for_s=null);
									_ref_dest_s->_timed_msg_rueckmeldung(myID, _ref_now, MAX_TIME);
									_ref_pre_s->_timed_msg_free(myID, _ref_now, MAX_TIME);
_ref_now += 2;
									_ref_pre_s->_timed_msg_drive_in(myID, _ref_tr, null, 1 + _ref_now, MAX_TIME);
								}
}
							else {
								{
									_ref_pre_s->_timed_msg_drive_in(myID, _ref_tr, null, _ref_now, MAX_TIME);
									(_ref_nTrains=(_ref_nTrains+1));
									(_ref_train=null);
								}
}
						}
}
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
