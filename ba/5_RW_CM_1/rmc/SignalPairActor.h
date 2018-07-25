









#ifndef __SIGNALPAIR_ACTOR_H__
#define __SIGNALPAIR_ACTOR_H__

#include "StationControllerActor.h"
class StationControllerActor;
#include "TrainActor.h"
class TrainActor;

#include "AbstractTimedActor.h"

class SignalPairActor :
		public AbstractTimedActor
{

public:
    SignalPairActor(byte myID, char* myName, int maxQueueLength, int maxParamLength, vector<AbstractActor*>& rebecsRef
		#ifdef DEBUG_LEVEL_2 
			, ostream &out
		#endif
    				






					, int hashmapSize
				






					






			    );
	~SignalPairActor();
	
	long execute();
	
    char* getClassName();
    
	virtual void exportStateVariablesInXML(ostream &out, string tab);
	virtual void exportAMessageInXML(ostream &out, string tab, int cnt);

    virtual void marshalActorToArray(byte* array);
    virtual void unmarshalActorFromArray(byte* array);

        	byte _ref_signal;
byte _ref_station;
byte _ref_block;
byte _ref_preStation;

        	TrainActor* _ref_onTrack;

        	SignalPairActor* _ref_verschluss;

    
			long constructorSignalPair(byte creatorID
				    	        ,
	    	        		byte
	         _ref_st
	        	        , 
	        	        		byte
	         _ref_pre
	        	        		);
	
            void _msg_gegenfahrschutz(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                );
        long msgsrvgegenfahrschutz(
            		    	        		TrainActor*
	         _ref_tr
	        	                );
            void _msg_free(byte senderId
            	        );
        long msgsrvfree(
            	        );
            void _msg_drive_out(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                );
        long msgsrvdrive_out(
            		    	        		TrainActor*
	         _ref_tr
	        	                );
            void _msg_drive_in(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_prev
	        	                );
        long msgsrvdrive_in(
            		    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_prev
	        	                );
            void _msg_vorblock(byte senderId
            	        );
        long msgsrvvorblock(
            	        );
            void _msg_rueckblock(byte senderId
            	        );
        long msgsrvrueckblock(
            	        );
            void _msg_set_green(byte senderId
            	        );
        long msgsrvset_green(
            	        );
            void _msg_set_red(byte senderId
            	        );
        long msgsrvset_red(
            	        );
            void _msg_occupy(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_last
	        	                );
        long msgsrvoccupy(
            		    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_last
	        	                );
    
				






			protected:
	    static byte** table;
		virtual byte** getTable();
			






			protected:
	    static vector<TimeFrame>** hashtableTimeExtension;
		virtual vector<TimeFrame>** getHashtableTimeExtension();
			






		public:
            void _timed_msg_gegenfahrschutz(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_free(byte senderId
            	        , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_drive_out(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_drive_in(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_prev
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_vorblock(byte senderId
            	        , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_rueckblock(byte senderId
            	        , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_set_green(byte senderId
            	        , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_set_red(byte senderId
            	        , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_occupy(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_last
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
    	protected:
    };

#endif