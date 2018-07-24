                                    

#include "Types.h"
#include "LightActor.h"
#include <stdio.h>
#include <string.h>

// location counters (values stored in messageQueue[0])
/* There can be more than one location counter for each msgsrv when we
   want to have non-atomic message servers.
   Notice that values 0 and 1 are reserved for EMPTY and INITIAL, respectively.*/
#define ON 1
#define OFF 2


// knownrebecs (those to whom message can be sent)
// the following format allows to use them as variables --> the ID of the rebec
#define _ref_sender (rebecs[senderQueue[0]])
#define _ref_self (dynamic_cast<LightActor*>(rebecs[myID]))
        	#define _ref_tl (dynamic_cast<TrafficLightActor*>(rebecs[known[1]]))
	            

LightActor::LightActor(byte myID, char* myName, int maxQueueLength, int maxParamLength, vector<AbstractActor*>& rebecsRef
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
						






					, 6, hashmapSize
				)
				{

    messageNames = new char *[2 + 1];
	messageNames[0] = (char*)"Empty";

                messageNames[1] = (char*)"ON";
                    messageNames[2] = (char*)"OFF";
            
				






			if (table == (byte**)0xFFFFFFFF) {	// avoid reinitialization
		table = new byte* [1 << hashmapSize];
        memset (table, 0, sizeof(byte*)*(1 << hashmapSize));
	}

		
	queueTail = 0;
}

LightActor::~LightActor (){
	delete [] messageNames;
	delete [] messageQueue;
	delete [] senderQueue;
}


void LightActor::exportStateVariablesInXML(ostream &out, string tab) {
	out << tab << "<statevariables>" << endl;
            	    	out << tab << '\t' << "<variable name=\"on\" type=\"byte\">" <<  
	    		((int)_ref_on) << "</variable>" << endl;
			    	out << tab << '\t' << "<variable name=\"color\" type=\"byte\">" <<  
	    		((int)_ref_color) << "</variable>" << endl;
				out << tab << "</statevariables>" << endl;
}

void LightActor::exportAMessageInXML(ostream &out, string tab, int cnt) {
        int i = 0;
        switch (messageQueue[cnt]) {
	                    case ON: {
                                            
                    out << "on("
                                << ")";
                break;
               }
	                    case OFF: {
                                            
                    out << "off("
                                << ")";
                break;
               }
	            	}

}

char* LightActor::getClassName() {
    return (char*)"Light";
}

void LightActor::marshalActorToArray(byte* array) {
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

                            			            
                                    
                            memcpy(&array [marshalIndex], &_ref_on, (1 * BYTE_SIZE));
                marshalIndex += (1 * BYTE_SIZE);
                                			            
                                    
                            memcpy(&array [marshalIndex], &_ref_color, (1 * BYTE_SIZE));
                marshalIndex += (1 * BYTE_SIZE);
                            
        
    
    #ifdef NO_ATOMIC_EXECUTION
    	memcpy(&array [marshalIndex], &__pc, 4);
    	//array[marshalIndex++] = __pc;
    #endif

}

void LightActor::unmarshalActorFromArray(byte* array) {

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

                            			                        
                                    
                            memcpy(&_ref_on, &array [index], (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                                			                        
                                    
                            memcpy(&_ref_color, &array [index], (1 * BYTE_SIZE));
                index += (1 * BYTE_SIZE);
                                    
        
    #ifdef NO_ATOMIC_EXECUTION
    	memcpy(&__pc, &array [index], 4);
    	//__pc = array[index++];
    #endif
}

/*#ifdef DEBUG
void LightActor::printStateContent(long stateNo) {
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
long LightActor::execute() {
			AbstractActor::execute();
	    switch (messageQueue[0]) {

                    case ON:
                {
                    int i = 0;
                                                
                        return msgsrvon(
                                                );
                }
                    case OFF:
                {
                    int i = 0;
                                                
                        return msgsrvoff(
                                                );
                }
            }
    return -1;   // if queue empty, we have no transitions
}

    long LightActor::constructorLight (byte creatorId 
    			    	        ,
	    	        		byte
	         _ref_c
	        	            ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "Light";
		#endif

		{
			(_ref_color=_ref_c);
			(_ref_on=0);
		}
		shift = 0;
		return 0;

	}


    void LightActor::_msg_on (byte senderId
        	    ){
        queueTail = 0;
        enqueue(messageQueue, ON);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}
    void LightActor::_msg_off (byte senderId
        	    ){
        queueTail = 0;
        enqueue(messageQueue, OFF);
        enqueue(senderQueue, senderId);
        
        if (maxParamLength != 0) {
            int index = 0;
            byte paramsValues[maxParamLength];
            memset(paramsValues, 0, maxParamLength);
                                
        
                enqueue(paramQueue, paramsValues, maxParamLength);
        }
}

			






		
	byte** LightActor::table = (byte**)0xFFFFFFFF;

	byte** LightActor::getTable() {
		return table;
	}
	
    long LightActor::msgsrvon (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "on";
		#endif

		{
			if ((_ref_sender==_ref_tl)) {
				{
					(_ref_on=1);
					_ref_tl->_msg_update(myID, _ref_color, 1);
				}
}
		}
		return 0;

}
    long LightActor::msgsrvoff (
    		    ) {
    			shift = 1;
		#ifdef SAFE_MODE
			string reactiveClassName = this->getName();
			string methodName = "off";
		#endif

		{
			if ((_ref_sender==_ref_tl)) {
				{
					(_ref_on=0);
					_ref_tl->_msg_update(myID, _ref_color, 0);
				}
}
		}
		return 0;

}
