









#ifndef __STATIONCONTROLLER_ACTOR_H__
#define __STATIONCONTROLLER_ACTOR_H__

#include "SignalPairActor.h"
class SignalPairActor;
#include "TrainActor.h"
class TrainActor;

#include "AbstractTimedActor.h"

class StationControllerActor :
		public AbstractTimedActor
{

public:
    StationControllerActor(byte myID, char* myName, int maxQueueLength, int maxParamLength, vector<AbstractActor*>& rebecsRef
		#ifdef DEBUG_LEVEL_2 
			, ostream &out
		#endif
    				






					, int hashmapSize
				






					






			    );
	~StationControllerActor();
	
	long execute();
	
    char* getClassName();
    
	virtual void exportStateVariablesInXML(ostream &out, string tab);
	virtual void exportAMessageInXML(ostream &out, string tab, int cnt);

    virtual void marshalActorToArray(byte* array);
    virtual void unmarshalActorFromArray(byte* array);

        	int _ref_nTrains;
int _ref_size;
int _ref_iid;
int _ref_anbieten_sent;

        	byte _ref_debug;

        	TrainActor* _ref_train;
TrainActor* _ref_wait_for_e;
TrainActor* _ref_wait_for_w;
TrainActor* _ref_wait_for_n;
TrainActor* _ref_wait_for_s;

    
			long constructorStationController(byte creatorID
				    	        ,
	    	        		int
	         _ref_idd
	        	        , 
	        	        		int
	         _ref_s
	        	        		);
	
            void _msg_handle_drive_in(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                );
        long msgsrvhandle_drive_in(
            		    	        		TrainActor*
	         _ref_tr
	        	                );
            void _msg_set_train(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                );
        long msgsrvset_train(
            		    	        		TrainActor*
	         _ref_tr
	        	                );
            void _msg_handle_drive_out(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		byte
	         _ref_dir
	        	                );
        long msgsrvhandle_drive_out(
            		    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		byte
	         _ref_dir
	        	                );
            void _msg_anbieten(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                );
        long msgsrvanbieten(
            		    	        		TrainActor*
	         _ref_tr
	        	                );
            void _msg_check_status(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		StationControllerActor*
	         _ref_dest
	        	                );
        long msgsrvcheck_status(
            		    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		StationControllerActor*
	         _ref_dest
	        	                );
            void _msg_check_status_for_drive_out(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		byte
	         _ref_dir
	        	                );
        long msgsrvcheck_status_for_drive_out(
            		    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		byte
	         _ref_dir
	        	                );
            void _msg_revert_anbieten(byte senderId
            	        );
        long msgsrvrevert_anbieten(
            	        );
            void _msg_annehmen(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_pre
	        	                );
        long msgsrvannehmen(
            		    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_pre
	        	                );
            void _msg_ask_for_drive_out(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                );
        long msgsrvask_for_drive_out(
            		    	        		TrainActor*
	         _ref_tr
	        	                );
            void _msg_train_drove_out(byte senderId
            	        );
        long msgsrvtrain_drove_out(
            	        );
            void _msg_rueckmeldung(byte senderId
            	        );
        long msgsrvrueckmeldung(
            	        );
            void _msg_ask_for_drive_in(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                );
        long msgsrvask_for_drive_in(
            		    	        		TrainActor*
	         _ref_tr
	        	                );
    
				






			protected:
	    static byte** table;
		virtual byte** getTable();
			






			protected:
	    static vector<TimeFrame>** hashtableTimeExtension;
		virtual vector<TimeFrame>** getHashtableTimeExtension();
			






		public:
            void _timed_msg_handle_drive_in(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_set_train(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_handle_drive_out(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		byte
	         _ref_dir
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_anbieten(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_check_status(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		StationControllerActor*
	         _ref_dest
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_check_status_for_drive_out(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		byte
	         _ref_dir
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_revert_anbieten(byte senderId
            	        , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_annehmen(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	        , 
	        	        		SignalPairActor*
	         _ref_pre
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_ask_for_drive_out(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_train_drove_out(byte senderId
            	        , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_rueckmeldung(byte senderId
            	        , TIME_TYPE executionTime, TIME_TYPE deadline);
            void _timed_msg_ask_for_drive_in(byte senderId
            		    	        ,
	    	        		TrainActor*
	         _ref_tr
	        	                , TIME_TYPE executionTime, TIME_TYPE deadline);
    	protected:
    };

#endif