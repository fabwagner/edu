









#ifndef __TRAIN_ACTOR_H__
#define __TRAIN_ACTOR_H__

#include "SignalPairActor.h"
class SignalPairActor;
#include "StationControllerActor.h"
class StationControllerActor;

#include "AbstractTimedActor.h"

class TrainActor :
		public AbstractTimedActor
{

public:
    TrainActor(byte myID, char* myName, int maxQueueLength, int maxParamLength, vector<AbstractActor*>& rebecsRef
		#ifdef DEBUG_LEVEL_2 
			, ostream &out
		#endif
    				






					, int hashmapSize
				






					






			    );
	~TrainActor();
	
	long execute();
	
    char* getClassName();
    
	virtual void exportStateVariablesInXML(ostream &out, string tab);
	virtual void exportAMessageInXML(ostream &out, string tab, int cnt);

    virtual void marshalActorToArray(byte* array);
    virtual void unmarshalActorFromArray(byte* array);

        	StationControllerActor* _ref_station;

        	SignalPairActor* _ref_track;
SignalPairActor* _ref_next;
SignalPairActor* _ref_dest;

        	int _ref_counter;
int _ref_s;

        	byte _ref_id;
byte _ref_drive_status;

        	byte _ref_schedule[10];

    
			long constructorTrain(byte creatorID
				    	        ,
	    	        		byte
	         _ref_iid
	        	        		);
	
            void _msg_initial(byte senderId
            	        );
        long msgsrvinitial(
            	        );
            void _msg_drive(byte senderId
            	        );
        long msgsrvdrive(
            	        );
            void _msg_track_occupied(byte senderId
            		    	        ,
	    	        		SignalPairActor*
	         _ref_n
	        	                );
        long msgsrvtrack_occupied(
            		    	        		SignalPairActor*
	         _ref_n
	        	                );
            void _msg_red_signal(byte senderId
            	        );
        long msgsrvred_signal(
            	        );
            void _msg_ready(byte senderId
            		    	        ,
	    	        		StationControllerActor*
	         _ref_sc
	        	        , 
	        	        		SignalPairActor*
	         _ref_t
	        	                );
        long msgsrvready(
            		    	        		StationControllerActor*
	         _ref_sc
	        	        , 
	        	        		SignalPairActor*
	         _ref_t
	        	                );
            void _msg_handle_drive_out(byte senderId
            		    	        ,
	    	        		SignalPairActor*
	         _ref_n
	        	        , 
	        	        		SignalPairActor*
	         _ref_d
	        	                );
        long msgsrvhandle_drive_out(
            		    	        		SignalPairActor*
	         _ref_n
	        	        , 
	        	        		SignalPairActor*
	         _ref_d
	        	                );
            void _msg_drive_in(byte senderId
            		    	        ,
	    	        		StationControllerActor*
	         _ref_sc
	        	        , 
	        	        		SignalPairActor*
	         _ref_t
	        	                );
        long msgsrvdrive_in(
            		    	        		StationControllerActor*
	         _ref_sc
	        	        , 
	        	        		SignalPairActor*
	         _ref_t
	        	                );
            void _msg_drive_out(byte senderId
            		    	        ,
	    	        		SignalPairActor*
	         _ref_n
	        	                );
        long msgsrvdrive_out(
            		    	        		SignalPairActor*
	         _ref_n
	        	                );
    
				






			protected:
	    static byte** table;
		virtual byte** getTable();
			






			protected:
	    static vector<TimeFrame>** hashtableTimeExtension;
		virtual vector<TimeFrame>** getHashtableTimeExtension();
			






		public:
            void _timed_msg_initial(byte senderId
            	        , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_drive(byte senderId
            	        , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_track_occupied(byte senderId
            		    	        ,
	    	        		SignalPairActor*
	         _ref_n
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_red_signal(byte senderId
            	        , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_ready(byte senderId
            		    	        ,
	    	        		StationControllerActor*
	         _ref_sc
	        	        , 
	        	        		SignalPairActor*
	         _ref_t
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_handle_drive_out(byte senderId
            		    	        ,
	    	        		SignalPairActor*
	         _ref_n
	        	        , 
	        	        		SignalPairActor*
	         _ref_d
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_drive_in(byte senderId
            		    	        ,
	    	        		StationControllerActor*
	         _ref_sc
	        	        , 
	        	        		SignalPairActor*
	         _ref_t
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_drive_out(byte senderId
            		    	        ,
	    	        		SignalPairActor*
	         _ref_n
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
    	protected:
    };

#endif