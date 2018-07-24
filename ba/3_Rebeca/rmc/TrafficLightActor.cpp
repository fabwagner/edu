                                    

#include "Types.h"
#include "TrafficLightActor.h"
#include <stdio.h>
#include <string.h>

// location counters (values stored in messageQueue[0])
/* There can be more than one location counter for each msgsrv when we
   want to have non-atomic message servers.
   Notice that values 0 and 1 are reserved for EMPTY and INITIAL, respectively.*/
#define INITIAL 1
#define UPDATE 2


// knownrebecs (those to whom message can be sent)
// the following format allows to use them as variables --> the ID of the rebec
#define _ref_sender (rebecs[senderQueue[0]])
#define _ref_self (dynamic_cast<TrafficLightActor*>(rebecs[myID]))
        	#define _ref_green (dynamic_cast<LightActor*>(rebecs[known[1]]))
	            	#define _ref_red (dynamic_cast<LightActor*>(rebecs[known[2]]))
	            

TrafficLightActor::TrafficLightActor(byte myID, char* myName, int maxQueueLength, int maxParamLength, vector<AbstractActor*>& rebecsRef
		#ifdef DEBUG_LEVEL_2 
			, ostream &out
		#endif
				






					, int hashmapSize
		)
	:
			AbstractActor (myID, myName, maxQueueLength, maxParamLength, rebecsRef
			#ifdef DEBUG_LEVEL_2 
				, out
			#endif
						






					, 5, hashmapSize
				)
				{

    messageNames = new char *[2 + 1];
	messageNames[0] = (char*)"Empty";

                messageNames[1] = (char*)"INITIAL";
                    messageNames[2] = (char*)"UPDATE";
            
				






			if (table == (byte**)0xFFFFFFFF) {	// avoid reinitialization
		table = new byte* [1 << hashmapSize];
        memset (table, 0, sizeof(byte*)*(1 << hashmapSize));
	}

		
	queueTail = 0;
}

TrafficLightActor::~TrafficLightActor (){
	delete [] messageNames;
	delete [] messageQueue;
	delete [] senderQueue;
}


void TrafficLightActor::exportStateVariablesInXML(ostream &out, string tab) {
	out << tab << "<statevariables>" << endl;
            	    	out << tab << '\t' << "<variable name=\"state\" type=\"byte\">" <<  
	    		((int)_ref_state) << "</variable>" << endl;
				out << tab << "</statevariables>" << endl;
}

void TrafficLightActor::exportAMessageInXML(ostream &out, string tab, int cnt) {
        int i = 0;
        switch (messageQueue[cnt]) {
	                    case INITIAL: {
                                            
                    out << "initial("
                                << ")";
                break;
               }
	                    case UPDATE: {
                                        			                        	byte _ref_color;
                        
                                    
                            memcpy(&_ref_color, &paramQueue[cnt] [i], (1 * BYTE_SIZE));
                i += (1 * BYTE_SIZE);
                                			                        	byte _ref_on;
                        
                                    
                            memcpy(&_ref_on, &paramQueue[cnt] [i], (1 * BYTE_SIZE));
                i += (1 * BYTE_SIZE);
                                    
                    out << "update("
                                	<< ((int)_ref_color)
                						<< ", "
					                                	<< ((int)_ref_on)
                	                                << ")";
                break;
               }
	            	}

}

char* TrafficLightActor::getClassName() {
    return (char*)"TrafficLight";
}

void TrafficLightActor::marshalActorToArray(byte* array) {
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

                            			            
                                    
                            memcpy(&array [marshalIndex], &_ref_state, (1 * BYTE_SIZE));
                marshalIndex += (1 * BYTE_SIZE);
                            
        
    
    #ifdef NO_ATOMIC_EXECUTION
    	memcpy(&array [marshalIndex], &__pc, 4);
    	//array[marshalIndex++] = __pc;
    #endif

}

void TrafficLightActor::unmarshalActorFromArray(byte* array) {

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

                            			                        
                                    
                            memcpy(&_ref_state, &array [index], (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                                    
        
    #ifdef NO_ATOMIC_EXECUTION
    	memcpy(&__pc, &array [index], 4);
    	//__pc = array[index++];
    #endif
}

/*#ifdef DEBUG
void TrafficLightActor::printStateContent(long stateNo) {
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
long TrafficLightActor::execute() {
			AbstractActor::execute();
	    switch (messageQueue[0]) {

                    case INITIAL:
                {
                    int i = 0;
                                                
                        return msgsrvinitial(
                                                );
                }
                    case UPDATE:
                {
                    int i = 0;
                                            			                        	byte _ref_color;
                        
                                    
                            memcpy(&_ref_color, &paramQueue[0] [i], (1 * BYTE_SIZE));
                i += (1 * BYTE_SIZE);
                                			                        	byte _ref_on;
                        
                                    
                            memcpy(&_ref_on, &paramQueue[0] [i], (1 * BYTE_SIZE));
                i += (1 * BYTE_SIZE);
                                    
                        return msgsrvupdate(
                            	                        _ref_color
	        	        , 
	                            _ref_on
	                                        );
                }
            }
    return -1;   // if queue empty, we have no transitions
}

    long TrafficLightActor::constructorTrafficLight (byte creatorId 
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "TrafficLight";
		#endif

		{
			(_ref_state=0);
			_ref_self->_msg_initial(myID);
		}
		shift = 0;
		return 0;

	}


    void TrafficLightActor::_msg_initial (byte senderId
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
    void TrafficLightActor::_msg_update (byte senderId
        		    	        ,
	    	        		byte
	         _ref_color
	        	        , 
	        	        		byte
	         _ref_on
	        	            ){
        queueTail = 0;
        enqueue(messageQueue, UPDATE);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                    			            
                                    
                            memcpy(&paramsValues [index], &_ref_color, (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                                			            
                                    
                            memcpy(&paramsValues [index], &_ref_on, (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                            
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}

			






		
	byte** TrafficLightActor::table = (byte**)0xFFFFFFFF;

	byte** TrafficLightActor::getTable() {
		return table;
	}
	
    long TrafficLightActor::msgsrvinitial (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "initial";
		#endif

		{
			_ref_red->_msg_on(myID);
		}
		return 0;

}
    long TrafficLightActor::msgsrvupdate (
    			    	        		byte
	         _ref_color
	        	        , 
	        	        		byte
	         _ref_on
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "update";
		#endif

		{
			if ((_ref_state==0)) {
				{
					if (((_ref_color==2)&&(_ref_on==1))) {
						{
							(_ref_state=1);
							_ref_green->_msg_on(myID);
						}
}
				}
}
			else {
				if ((_ref_state==1)) {
					{
						if (((_ref_color==1)&&(_ref_on==1))) {
							{
								(_ref_state=2);
								_ref_red->_msg_off(myID);
							}
}
					}
}
				else {
					if ((_ref_state==2)) {
						{
							if (((_ref_color==2)&&(_ref_on==0))) {
								{
									(_ref_state=3);
									_ref_red->_msg_on(myID);
								}
}
						}
}
					else {
						if ((_ref_state==3)) {
							{
								if (((_ref_color==2)&&(_ref_on==1))) {
									{
										(_ref_state=4);
										_ref_green->_msg_off(myID);
									}
}
							}
}
						else {
							if ((_ref_state==4)) {
								{
									if (((_ref_color==1)&&(_ref_on==0))) {
										{
											(_ref_state=1);
											_ref_green->_msg_on(myID);
										}
}
								}
}}}}}
		}
		return 0;

}
