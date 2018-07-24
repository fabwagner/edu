









#ifndef __LIGHT_ACTOR_H__
#define __LIGHT_ACTOR_H__

#include "TrafficLightActor.h"
class TrafficLightActor;

#include "AbstractActor.h"

class LightActor :
		public AbstractActor
{

public:
    LightActor(byte myID, char* myName, int maxQueueLength, int maxParamLength, vector<AbstractActor*>& rebecsRef
		#ifdef DEBUG_LEVEL_2 
			, ostream &out
		#endif
    				






					, int hashmapSize
		    );
	~LightActor();
	
	long execute();
	
    char* getClassName();
    
	virtual void exportStateVariablesInXML(ostream &out, string tab);
	virtual void exportAMessageInXML(ostream &out, string tab, int cnt);

    virtual void marshalActorToArray(byte* array);
    virtual void unmarshalActorFromArray(byte* array);

        	byte _ref_on;
byte _ref_color;

    
			long constructorLight(byte creatorID
				    	        ,
	    	        		byte
	         _ref_c
	        	        		);
	
            void _msg_on(byte senderId
            	        );
        long msgsrvon(
            	        );
            void _msg_off(byte senderId
            	        );
        long msgsrvoff(
            	        );
    
				






			protected:
	    static byte** table;
		virtual byte** getTable();
	protected:
    };

#endif