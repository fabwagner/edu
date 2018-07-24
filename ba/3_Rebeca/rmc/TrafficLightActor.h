









#ifndef __TRAFFICLIGHT_ACTOR_H__
#define __TRAFFICLIGHT_ACTOR_H__

#include "LightActor.h"
class LightActor;

#include "AbstractActor.h"

class TrafficLightActor :
		public AbstractActor
{

public:
    TrafficLightActor(byte myID, char* myName, int maxQueueLength, int maxParamLength, vector<AbstractActor*>& rebecsRef
		#ifdef DEBUG_LEVEL_2 
			, ostream &out
		#endif
    				






					, int hashmapSize
		    );
	~TrafficLightActor();
	
	long execute();
	
    char* getClassName();
    
	virtual void exportStateVariablesInXML(ostream &out, string tab);
	virtual void exportAMessageInXML(ostream &out, string tab, int cnt);

    virtual void marshalActorToArray(byte* array);
    virtual void unmarshalActorFromArray(byte* array);

        	byte _ref_state;

    
			long constructorTrafficLight(byte creatorID
					);
	
            void _msg_initial(byte senderId
            	        );
        long msgsrvinitial(
            	        );
            void _msg_update(byte senderId
            		    	        ,
	    	        		byte
	         _ref_color
	        	        , 
	        	        		byte
	         _ref_on
	        	                );
        long msgsrvupdate(
            		    	        		byte
	         _ref_color
	        	        , 
	        	        		byte
	         _ref_on
	        	                );
    
				






			protected:
	    static byte** table;
		virtual byte** getTable();
	protected:
    };

#endif