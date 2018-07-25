#include "AbstractTimedRebecaAnalyzer.h"

			#define _ref_sc1 (dynamic_cast<StationControllerActor*>(rebecs[0]))
	    			#define _ref_sc2 (dynamic_cast<StationControllerActor*>(rebecs[1]))
	    			#define _ref_sc3 (dynamic_cast<StationControllerActor*>(rebecs[2]))
	    			#define _ref_sc4 (dynamic_cast<StationControllerActor*>(rebecs[3]))
	    			#define _ref_sc5 (dynamic_cast<StationControllerActor*>(rebecs[4]))
	    			#define _ref_sc6 (dynamic_cast<StationControllerActor*>(rebecs[5]))
	    			#define _ref_t1 (dynamic_cast<SignalPairActor*>(rebecs[6]))
	    			#define _ref_t2 (dynamic_cast<SignalPairActor*>(rebecs[7]))
	    			#define _ref_t3 (dynamic_cast<SignalPairActor*>(rebecs[8]))
	    			#define _ref_t4 (dynamic_cast<SignalPairActor*>(rebecs[9]))
	    			#define _ref_t5 (dynamic_cast<SignalPairActor*>(rebecs[10]))
	    			#define _ref_t6 (dynamic_cast<SignalPairActor*>(rebecs[11]))
	    			#define _ref_t7 (dynamic_cast<SignalPairActor*>(rebecs[12]))
	    			#define _ref_t8 (dynamic_cast<SignalPairActor*>(rebecs[13]))
	    			#define _ref_t9 (dynamic_cast<SignalPairActor*>(rebecs[14]))
	    			#define _ref_t10 (dynamic_cast<SignalPairActor*>(rebecs[15]))
	    			#define _ref_t11 (dynamic_cast<SignalPairActor*>(rebecs[16]))
	    			#define _ref_t12 (dynamic_cast<SignalPairActor*>(rebecs[17]))
	    			#define _ref_t13 (dynamic_cast<SignalPairActor*>(rebecs[18]))
	    			#define _ref_t14 (dynamic_cast<SignalPairActor*>(rebecs[19]))
	    			#define _ref_t15 (dynamic_cast<SignalPairActor*>(rebecs[20]))
	    			#define _ref_t16 (dynamic_cast<SignalPairActor*>(rebecs[21]))
	    			#define _ref_t17 (dynamic_cast<SignalPairActor*>(rebecs[22]))
	    			#define _ref_t18 (dynamic_cast<SignalPairActor*>(rebecs[23]))
	    			#define _ref_t19 (dynamic_cast<SignalPairActor*>(rebecs[24]))
	    			#define _ref_t20 (dynamic_cast<SignalPairActor*>(rebecs[25]))
	    			#define _ref_t21 (dynamic_cast<SignalPairActor*>(rebecs[26]))
	    			#define _ref_t22 (dynamic_cast<SignalPairActor*>(rebecs[27]))
	    			#define _ref_t23 (dynamic_cast<SignalPairActor*>(rebecs[28]))
	    			#define _ref_t24 (dynamic_cast<SignalPairActor*>(rebecs[29]))
	    			#define _ref_t25 (dynamic_cast<SignalPairActor*>(rebecs[30]))
	    			#define _ref_t26 (dynamic_cast<SignalPairActor*>(rebecs[31]))
	    			#define _ref_t27 (dynamic_cast<SignalPairActor*>(rebecs[32]))
	    			#define _ref_t28 (dynamic_cast<SignalPairActor*>(rebecs[33]))
	    			#define _ref_t29 (dynamic_cast<SignalPairActor*>(rebecs[34]))
	    			#define _ref_t30 (dynamic_cast<SignalPairActor*>(rebecs[35]))
	    			#define _ref_t31 (dynamic_cast<SignalPairActor*>(rebecs[36]))
	    			#define _ref_t32 (dynamic_cast<SignalPairActor*>(rebecs[37]))
	    			#define _ref_t33 (dynamic_cast<SignalPairActor*>(rebecs[38]))
	    			#define _ref_tn1 (dynamic_cast<SignalPairActor*>(rebecs[39]))
	    			#define _ref_tn2 (dynamic_cast<SignalPairActor*>(rebecs[40]))
	    			#define _ref_tn3 (dynamic_cast<SignalPairActor*>(rebecs[41]))
	    			#define _ref_tn4 (dynamic_cast<SignalPairActor*>(rebecs[42]))
	    			#define _ref_tn5 (dynamic_cast<SignalPairActor*>(rebecs[43]))
	    			#define _ref_tn6 (dynamic_cast<SignalPairActor*>(rebecs[44]))
	    			#define _ref_tr1 (dynamic_cast<TrainActor*>(rebecs[45]))
	    			#define _ref_tr2 (dynamic_cast<TrainActor*>(rebecs[46]))
	    		
		
			#undef _ref_sc1
			#undef _ref_sc2
			#undef _ref_sc3
			#undef _ref_sc4
			#undef _ref_sc5
			#undef _ref_sc6
			#undef _ref_t1
			#undef _ref_t2
			#undef _ref_t3
			#undef _ref_t4
			#undef _ref_t5
			#undef _ref_t6
			#undef _ref_t7
			#undef _ref_t8
			#undef _ref_t9
			#undef _ref_t10
			#undef _ref_t11
			#undef _ref_t12
			#undef _ref_t13
			#undef _ref_t14
			#undef _ref_t15
			#undef _ref_t16
			#undef _ref_t17
			#undef _ref_t18
			#undef _ref_t19
			#undef _ref_t20
			#undef _ref_t21
			#undef _ref_t22
			#undef _ref_t23
			#undef _ref_t24
			#undef _ref_t25
			#undef _ref_t26
			#undef _ref_t27
			#undef _ref_t28
			#undef _ref_t29
			#undef _ref_t30
			#undef _ref_t31
			#undef _ref_t32
			#undef _ref_t33
			#undef _ref_tn1
			#undef _ref_tn2
			#undef _ref_tn3
			#undef _ref_tn4
			#undef _ref_tn5
			#undef _ref_tn6
			#undef _ref_tr1
			#undef _ref_tr2
	
bool operator > (const OpenBorderNode& node1, const OpenBorderNode& node2) {
    return node1.currentTime > node2.currentTime;
}

AbstractTimedRebecaAnalyzer::AbstractTimedRebecaAnalyzer(ostream &outStream, int hashmapSize) : analysisOutputStream(outStream){

	this->hashmapSize = hashmapSize;
	current.state = NULL;
}


void AbstractTimedRebecaAnalyzer::unmarshalRebecs(TimedRebecStateIndexType* node, TIME_TYPE *shift) {
	int i;
	for (i = 0; i < REBEC_COUNT; i++) {
        rebecs[i]->unmarshalActor(node[i], shift[i]);   // uncompress all states of all rebecs
    }
}

void AbstractTimedRebecaAnalyzer::marshalRebecs(TimedRebecStateIndexType* node, TIME_TYPE *shift) {
	int i;
	for (i=0; i<REBEC_COUNT; i++){
		node[i] = rebecs[i]->marshalActor(shift[i]);
	}
}

OpenBorderNode AbstractTimedRebecaAnalyzer::storeRecentlyCreatedState (byte &result,
	TIME_TYPE &shift, TimedBFSState* parent, int parentBundleIndex, int executedRebecIndex) {

    numberOfTransitions++;

	TimedBFSState temp;
    RebecsShiftTime rebecsLocalShift;
    OpenBorderNode node;
    node.stateActiveBundleNumber = 0;

    marshalRebecs(temp.rebsIndex, rebecsLocalShift.shift);
    #ifdef DEBUG_LEVEL_2
	    analysisOutputStream << "State is marshalled to these values [";
	    for (int cnt2 = 0; cnt2 < REBEC_COUNT; cnt2++) {
	    	analysisOutputStream << "<" << (long)temp.rebsIndex[cnt2].tableIndex << "," << (int)rebecsLocalShift.shift[cnt2] << ">, ";
	    }
	    analysisOutputStream << "]" << endl;
	#endif    
	result = NEW_STATE;
	if ((node.state = bfsStorage->exists(temp)) != null) {
	    #ifdef DEBUG_LEVEL_2
	        analysisOutputStream << "Untimed part of the state is found in the hash table." << endl;
	    #endif
        bool uniformShift = false;
		#ifdef DEBUG_LEVEL_2
        	analysisOutputStream <<"new state: [";
			for(int cnt = 0; cnt < REBEC_COUNT; cnt++) {
				analysisOutputStream <<(int)rebecsLocalShift.shift[cnt] << ",";
			}
			analysisOutputStream <<"]" << endl;
		#endif
		for (std::vector<RebecsShiftTime>::iterator it = node.state->shiftTimes.begin() ; (it != (node.state->shiftTimes.end())) && !uniformShift; ++it) {
            shift = 0;
            boolean first = true;
			uniformShift = true;
            #ifdef DEBUG_LEVEL_2
            	analysisOutputStream << "timed bundle " << (int)node.stateActiveBundleNumber << ": [";
				for(int cnt = 0; cnt < REBEC_COUNT; cnt++) {
					analysisOutputStream << (int)(*it).shift[cnt] << ",";
				}
				analysisOutputStream << "}" << endl;
            #endif
			for(int cnt = 0; cnt < REBEC_COUNT; cnt++) {
				if (!rebecs[cnt]->messageQueue[0])
					continue;
				if (first) {
					first = false;
					shift = rebecsLocalShift.shift[cnt] - (*it).shift[cnt];
				}
				else if (shift != rebecsLocalShift.shift[cnt] - (*it).shift[cnt]) {
					uniformShift = false;
					break;
				}
			}
			if (!uniformShift) {
				node.stateActiveBundleNumber++;
			}
		}

		if (uniformShift) {
		    #ifdef DEBUG_LEVEL_2
		        analysisOutputStream << "Uniform shift is found between this state and state \"" << node.state->stateID << "_" << (int)node.stateActiveBundleNumber << "\"."<< endl;
		    #endif
			result = ~NEW_STATE;
		} else {
		    #ifdef DEBUG_LEVEL_2
		        analysisOutputStream << "New time bundle is attached." << endl;
		    #endif
			shift = 0;
			numberOfStates++;
            numberOfTimedBundles++;
            node.state->shiftTimes.push_back(rebecsLocalShift);
	    	//node.state->stateID = numberOfStates;
        }
	}
	else {
	    #ifdef DEBUG_LEVEL_2
	        analysisOutputStream << "This state has new untimed part." << endl;
	    #endif
        shift = 0;
        node.state = bfsStorage->put(temp, parent, executedRebecIndex, rebecsLocalShift);
        numberOfStates++;
        node.state->stateID = numberOfStates;
        node.state->parents.front().timeBundleIndex = parentBundleIndex;
        numberOfTimedBundles++;
	}
	return node;
}

void AbstractTimedRebecaAnalyzer::changeOrder(int rebecId, int alternativesCounter) {
	for(int shiftQueue = alternativesCounter; shiftQueue > 0; shiftQueue--) {
		typedSwap(rebecs[rebecId]->executionTime[shiftQueue], rebecs[rebecId]->executionTime[shiftQueue - 1], TIME_TYPE)
		typedSwap(rebecs[rebecId]->deadline[shiftQueue], rebecs[rebecId]->deadline[shiftQueue - 1], TIME_TYPE)
		typedSwap(rebecs[rebecId]->messageQueue[shiftQueue], rebecs[rebecId]->messageQueue[shiftQueue - 1], byte)
		typedSwap(rebecs[rebecId]->senderQueue[shiftQueue], rebecs[rebecId]->senderQueue[shiftQueue - 1], byte)
		typedSwap(rebecs[rebecId]->paramQueue[shiftQueue], rebecs[rebecId]->paramQueue[shiftQueue - 1], byte*)
	}
}

int AbstractTimedRebecaAnalyzer::getNumberOfAlternatives(int rebecId, TIME_TYPE executionTime) {
	int numberOfAlternatives = 1;
    //while((numberOfAlternatives < rebecs[rebecId]->maxQueueLength) &&
    //		(rebecs[rebecId]->messageQueue[numberOfAlternatives]) &&
    //		(max(rebecs[rebecId]->getNow(), rebecs[rebecId]->executionTime[numberOfAlternatives])) == executionTime) {
    //	numberOfAlternatives++;
    //}
	long baseTime = rebecs[rebecId]->executionTime[0];
    while((numberOfAlternatives < rebecs[rebecId]->maxQueueLength) &&
		(rebecs[rebecId]->messageQueue[numberOfAlternatives]) &&
		(rebecs[rebecId]->executionTime[numberOfAlternatives] == baseTime)) {
    	numberOfAlternatives++;
    }
    
    return numberOfAlternatives;
}

TIME_TYPE AbstractTimedRebecaAnalyzer::prepareWithNewState() {
    current = openBorderQueue.top();
    openBorderQueue.pop();
    unmarshalRebecs(current.state->rebsIndex, 
    		current.state->shiftTimes[current.stateActiveBundleNumber].shift);
    return current.currentTime;
}

void AbstractTimedRebecaAnalyzer::instantiationPart() {
	vector<AbstractActor*>* referenceToRebecs = new vector<AbstractActor*>();
	byte maxRebecID = 0;
        	StationControllerActor* _ref_sc1 = new StationControllerActor(maxRebecID++, "sc1", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_sc1);
        referenceToRebecs->push_back(_ref_sc1);
	    	StationControllerActor* _ref_sc2 = new StationControllerActor(maxRebecID++, "sc2", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_sc2);
        referenceToRebecs->push_back(_ref_sc2);
	    	StationControllerActor* _ref_sc3 = new StationControllerActor(maxRebecID++, "sc3", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_sc3);
        referenceToRebecs->push_back(_ref_sc3);
	    	StationControllerActor* _ref_sc4 = new StationControllerActor(maxRebecID++, "sc4", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_sc4);
        referenceToRebecs->push_back(_ref_sc4);
	    	StationControllerActor* _ref_sc5 = new StationControllerActor(maxRebecID++, "sc5", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_sc5);
        referenceToRebecs->push_back(_ref_sc5);
	    	StationControllerActor* _ref_sc6 = new StationControllerActor(maxRebecID++, "sc6", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_sc6);
        referenceToRebecs->push_back(_ref_sc6);
	    	SignalPairActor* _ref_t1 = new SignalPairActor(maxRebecID++, "t1", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t1);
        referenceToRebecs->push_back(_ref_t1);
	    	SignalPairActor* _ref_t2 = new SignalPairActor(maxRebecID++, "t2", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t2);
        referenceToRebecs->push_back(_ref_t2);
	    	SignalPairActor* _ref_t3 = new SignalPairActor(maxRebecID++, "t3", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t3);
        referenceToRebecs->push_back(_ref_t3);
	    	SignalPairActor* _ref_t4 = new SignalPairActor(maxRebecID++, "t4", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t4);
        referenceToRebecs->push_back(_ref_t4);
	    	SignalPairActor* _ref_t5 = new SignalPairActor(maxRebecID++, "t5", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t5);
        referenceToRebecs->push_back(_ref_t5);
	    	SignalPairActor* _ref_t6 = new SignalPairActor(maxRebecID++, "t6", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t6);
        referenceToRebecs->push_back(_ref_t6);
	    	SignalPairActor* _ref_t7 = new SignalPairActor(maxRebecID++, "t7", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t7);
        referenceToRebecs->push_back(_ref_t7);
	    	SignalPairActor* _ref_t8 = new SignalPairActor(maxRebecID++, "t8", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t8);
        referenceToRebecs->push_back(_ref_t8);
	    	SignalPairActor* _ref_t9 = new SignalPairActor(maxRebecID++, "t9", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t9);
        referenceToRebecs->push_back(_ref_t9);
	    	SignalPairActor* _ref_t10 = new SignalPairActor(maxRebecID++, "t10", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t10);
        referenceToRebecs->push_back(_ref_t10);
	    	SignalPairActor* _ref_t11 = new SignalPairActor(maxRebecID++, "t11", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t11);
        referenceToRebecs->push_back(_ref_t11);
	    	SignalPairActor* _ref_t12 = new SignalPairActor(maxRebecID++, "t12", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t12);
        referenceToRebecs->push_back(_ref_t12);
	    	SignalPairActor* _ref_t13 = new SignalPairActor(maxRebecID++, "t13", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t13);
        referenceToRebecs->push_back(_ref_t13);
	    	SignalPairActor* _ref_t14 = new SignalPairActor(maxRebecID++, "t14", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t14);
        referenceToRebecs->push_back(_ref_t14);
	    	SignalPairActor* _ref_t15 = new SignalPairActor(maxRebecID++, "t15", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t15);
        referenceToRebecs->push_back(_ref_t15);
	    	SignalPairActor* _ref_t16 = new SignalPairActor(maxRebecID++, "t16", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t16);
        referenceToRebecs->push_back(_ref_t16);
	    	SignalPairActor* _ref_t17 = new SignalPairActor(maxRebecID++, "t17", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t17);
        referenceToRebecs->push_back(_ref_t17);
	    	SignalPairActor* _ref_t18 = new SignalPairActor(maxRebecID++, "t18", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t18);
        referenceToRebecs->push_back(_ref_t18);
	    	SignalPairActor* _ref_t19 = new SignalPairActor(maxRebecID++, "t19", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t19);
        referenceToRebecs->push_back(_ref_t19);
	    	SignalPairActor* _ref_t20 = new SignalPairActor(maxRebecID++, "t20", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t20);
        referenceToRebecs->push_back(_ref_t20);
	    	SignalPairActor* _ref_t21 = new SignalPairActor(maxRebecID++, "t21", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t21);
        referenceToRebecs->push_back(_ref_t21);
	    	SignalPairActor* _ref_t22 = new SignalPairActor(maxRebecID++, "t22", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t22);
        referenceToRebecs->push_back(_ref_t22);
	    	SignalPairActor* _ref_t23 = new SignalPairActor(maxRebecID++, "t23", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t23);
        referenceToRebecs->push_back(_ref_t23);
	    	SignalPairActor* _ref_t24 = new SignalPairActor(maxRebecID++, "t24", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t24);
        referenceToRebecs->push_back(_ref_t24);
	    	SignalPairActor* _ref_t25 = new SignalPairActor(maxRebecID++, "t25", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t25);
        referenceToRebecs->push_back(_ref_t25);
	    	SignalPairActor* _ref_t26 = new SignalPairActor(maxRebecID++, "t26", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t26);
        referenceToRebecs->push_back(_ref_t26);
	    	SignalPairActor* _ref_t27 = new SignalPairActor(maxRebecID++, "t27", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t27);
        referenceToRebecs->push_back(_ref_t27);
	    	SignalPairActor* _ref_t28 = new SignalPairActor(maxRebecID++, "t28", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t28);
        referenceToRebecs->push_back(_ref_t28);
	    	SignalPairActor* _ref_t29 = new SignalPairActor(maxRebecID++, "t29", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t29);
        referenceToRebecs->push_back(_ref_t29);
	    	SignalPairActor* _ref_t30 = new SignalPairActor(maxRebecID++, "t30", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t30);
        referenceToRebecs->push_back(_ref_t30);
	    	SignalPairActor* _ref_t31 = new SignalPairActor(maxRebecID++, "t31", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t31);
        referenceToRebecs->push_back(_ref_t31);
	    	SignalPairActor* _ref_t32 = new SignalPairActor(maxRebecID++, "t32", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t32);
        referenceToRebecs->push_back(_ref_t32);
	    	SignalPairActor* _ref_t33 = new SignalPairActor(maxRebecID++, "t33", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_t33);
        referenceToRebecs->push_back(_ref_t33);
	    	SignalPairActor* _ref_tn1 = new SignalPairActor(maxRebecID++, "tn1", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_tn1);
        referenceToRebecs->push_back(_ref_tn1);
	    	SignalPairActor* _ref_tn2 = new SignalPairActor(maxRebecID++, "tn2", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_tn2);
        referenceToRebecs->push_back(_ref_tn2);
	    	SignalPairActor* _ref_tn3 = new SignalPairActor(maxRebecID++, "tn3", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_tn3);
        referenceToRebecs->push_back(_ref_tn3);
	    	SignalPairActor* _ref_tn4 = new SignalPairActor(maxRebecID++, "tn4", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_tn4);
        referenceToRebecs->push_back(_ref_tn4);
	    	SignalPairActor* _ref_tn5 = new SignalPairActor(maxRebecID++, "tn5", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_tn5);
        referenceToRebecs->push_back(_ref_tn5);
	    	SignalPairActor* _ref_tn6 = new SignalPairActor(maxRebecID++, "tn6", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_tn6);
        referenceToRebecs->push_back(_ref_tn6);
	    	TrainActor* _ref_tr1 = new TrainActor(maxRebecID++, "tr1", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_tr1);
        referenceToRebecs->push_back(_ref_tr1);
	    	TrainActor* _ref_tr2 = new TrainActor(maxRebecID++, "tr2", 10, 16, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_tr2);
        referenceToRebecs->push_back(_ref_tr2);
	
	        	_ref_sc1->known = new byte[MAX_KNOWN];
    	    	_ref_sc1->known[0] = _ref_sc1->myID;
    	 _ref_sc1->known[1] = _ref_sc6->myID;
    				 _ref_sc1->known[2] = _ref_sc1->myID;
    				 _ref_sc1->known[3] = _ref_sc1->myID;
    				 _ref_sc1->known[4] = _ref_sc2->myID;
    				 _ref_sc1->known[5] = _ref_t1->myID;
    				 _ref_sc1->known[6] = _ref_t33->myID;
    				 _ref_sc1->known[7] = _ref_tn1->myID;
    				 _ref_sc1->known[8] = _ref_tn1->myID;
    				 _ref_sc1->known[9] = _ref_t2->myID;
    				
						_ref_sc1->constructorStationController(INITIAL_SENDER
	        	        , 1
	        	        , 3
	        		);
        	    	_ref_sc2->known = new byte[MAX_KNOWN];
    	    	_ref_sc2->known[0] = _ref_sc2->myID;
    	 _ref_sc2->known[1] = _ref_sc5->myID;
    				 _ref_sc2->known[2] = _ref_sc1->myID;
    				 _ref_sc2->known[3] = _ref_sc2->myID;
    				 _ref_sc2->known[4] = _ref_sc3->myID;
    				 _ref_sc2->known[5] = _ref_t8->myID;
    				 _ref_sc2->known[6] = _ref_t24->myID;
    				 _ref_sc2->known[7] = _ref_t7->myID;
    				 _ref_sc2->known[8] = _ref_tn2->myID;
    				 _ref_sc2->known[9] = _ref_t9->myID;
    				
						_ref_sc2->constructorStationController(INITIAL_SENDER
	        	        , 2
	        	        , 2
	        		);
        	    	_ref_sc3->known = new byte[MAX_KNOWN];
    	    	_ref_sc3->known[0] = _ref_sc3->myID;
    	 _ref_sc3->known[1] = _ref_sc4->myID;
    				 _ref_sc3->known[2] = _ref_sc2->myID;
    				 _ref_sc3->known[3] = _ref_sc3->myID;
    				 _ref_sc3->known[4] = _ref_sc3->myID;
    				 _ref_sc3->known[5] = _ref_t12->myID;
    				 _ref_sc3->known[6] = _ref_t13->myID;
    				 _ref_sc3->known[7] = _ref_t11->myID;
    				 _ref_sc3->known[8] = _ref_tn3->myID;
    				 _ref_sc3->known[9] = _ref_tn3->myID;
    				
						_ref_sc3->constructorStationController(INITIAL_SENDER
	        	        , 3
	        	        , 1
	        		);
        	    	_ref_sc4->known = new byte[MAX_KNOWN];
    	    	_ref_sc4->known[0] = _ref_sc4->myID;
    	 _ref_sc4->known[1] = _ref_sc4->myID;
    				 _ref_sc4->known[2] = _ref_sc5->myID;
    				 _ref_sc4->known[3] = _ref_sc3->myID;
    				 _ref_sc4->known[4] = _ref_sc4->myID;
    				 _ref_sc4->known[5] = _ref_t16->myID;
    				 _ref_sc4->known[6] = _ref_tn4->myID;
    				 _ref_sc4->known[7] = _ref_t17->myID;
    				 _ref_sc4->known[8] = _ref_t15->myID;
    				 _ref_sc4->known[9] = _ref_tn4->myID;
    				
						_ref_sc4->constructorStationController(INITIAL_SENDER
	        	        , 4
	        	        , 4
	        		);
        	    	_ref_sc5->known = new byte[MAX_KNOWN];
    	    	_ref_sc5->known[0] = _ref_sc5->myID;
    	 _ref_sc5->known[1] = _ref_sc5->myID;
    				 _ref_sc5->known[2] = _ref_sc6->myID;
    				 _ref_sc5->known[3] = _ref_sc2->myID;
    				 _ref_sc5->known[4] = _ref_sc4->myID;
    				 _ref_sc5->known[5] = _ref_t20->myID;
    				 _ref_sc5->known[6] = _ref_tn5->myID;
    				 _ref_sc5->known[7] = _ref_t25->myID;
    				 _ref_sc5->known[8] = _ref_t21->myID;
    				 _ref_sc5->known[9] = _ref_t19->myID;
    				
						_ref_sc5->constructorStationController(INITIAL_SENDER
	        	        , 5
	        	        , 3
	        		);
        	    	_ref_sc6->known = new byte[MAX_KNOWN];
    	    	_ref_sc6->known[0] = _ref_sc6->myID;
    	 _ref_sc6->known[1] = _ref_sc6->myID;
    				 _ref_sc6->known[2] = _ref_sc6->myID;
    				 _ref_sc6->known[3] = _ref_sc1->myID;
    				 _ref_sc6->known[4] = _ref_sc5->myID;
    				 _ref_sc6->known[5] = _ref_t30->myID;
    				 _ref_sc6->known[6] = _ref_tn6->myID;
    				 _ref_sc6->known[7] = _ref_tn6->myID;
    				 _ref_sc6->known[8] = _ref_t31->myID;
    				 _ref_sc6->known[9] = _ref_t29->myID;
    				
						_ref_sc6->constructorStationController(INITIAL_SENDER
	        	        , 6
	        	        , 2
	        		);
        	    	_ref_t1->known = new byte[MAX_KNOWN];
    	    	_ref_t1->known[0] = _ref_t1->myID;
    	 _ref_t1->known[1] = _ref_sc1->myID;
    				 _ref_t1->known[2] = _ref_t1->myID;
    				 _ref_t1->known[3] = _ref_t1->myID;
    				
						_ref_t1->constructorSignalPair(INITIAL_SENDER
	        	        , 1
	        	        , 0
	        		);
        	    	_ref_t2->known = new byte[MAX_KNOWN];
    	    	_ref_t2->known[0] = _ref_t2->myID;
    	 _ref_t2->known[1] = _ref_sc1->myID;
    				 _ref_t2->known[2] = _ref_t1->myID;
    				 _ref_t2->known[3] = _ref_t3->myID;
    				
						_ref_t2->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_t3->known = new byte[MAX_KNOWN];
    	    	_ref_t3->known[0] = _ref_t3->myID;
    	 _ref_t3->known[1] = _ref_sc1->myID;
    				 _ref_t3->known[2] = _ref_t2->myID;
    				 _ref_t3->known[3] = _ref_t4->myID;
    				
						_ref_t3->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 0
	        		);
        	    	_ref_t4->known = new byte[MAX_KNOWN];
    	    	_ref_t4->known[0] = _ref_t4->myID;
    	 _ref_t4->known[1] = _ref_sc1->myID;
    				 _ref_t4->known[2] = _ref_t3->myID;
    				 _ref_t4->known[3] = _ref_t5->myID;
    				
						_ref_t4->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 0
	        		);
        	    	_ref_t5->known = new byte[MAX_KNOWN];
    	    	_ref_t5->known[0] = _ref_t5->myID;
    	 _ref_t5->known[1] = _ref_sc1->myID;
    				 _ref_t5->known[2] = _ref_t4->myID;
    				 _ref_t5->known[3] = _ref_t6->myID;
    				
						_ref_t5->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 0
	        		);
        	    	_ref_t6->known = new byte[MAX_KNOWN];
    	    	_ref_t6->known[0] = _ref_t6->myID;
    	 _ref_t6->known[1] = _ref_sc2->myID;
    				 _ref_t6->known[2] = _ref_t5->myID;
    				 _ref_t6->known[3] = _ref_t7->myID;
    				
						_ref_t6->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 0
	        		);
        	    	_ref_t7->known = new byte[MAX_KNOWN];
    	    	_ref_t7->known[0] = _ref_t7->myID;
    	 _ref_t7->known[1] = _ref_sc2->myID;
    				 _ref_t7->known[2] = _ref_t6->myID;
    				 _ref_t7->known[3] = _ref_t8->myID;
    				
						_ref_t7->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_t8->known = new byte[MAX_KNOWN];
    	    	_ref_t8->known[0] = _ref_t8->myID;
    	 _ref_t8->known[1] = _ref_sc2->myID;
    				 _ref_t8->known[2] = _ref_t8->myID;
    				 _ref_t8->known[3] = _ref_t8->myID;
    				
						_ref_t8->constructorSignalPair(INITIAL_SENDER
	        	        , 1
	        	        , 0
	        		);
        	    	_ref_t9->known = new byte[MAX_KNOWN];
    	    	_ref_t9->known[0] = _ref_t9->myID;
    	 _ref_t9->known[1] = _ref_sc2->myID;
    				 _ref_t9->known[2] = _ref_t8->myID;
    				 _ref_t9->known[3] = _ref_t10->myID;
    				
						_ref_t9->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_t10->known = new byte[MAX_KNOWN];
    	    	_ref_t10->known[0] = _ref_t10->myID;
    	 _ref_t10->known[1] = _ref_sc3->myID;
    				 _ref_t10->known[2] = _ref_t9->myID;
    				 _ref_t10->known[3] = _ref_t11->myID;
    				
						_ref_t10->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 0
	        		);
        	    	_ref_t11->known = new byte[MAX_KNOWN];
    	    	_ref_t11->known[0] = _ref_t11->myID;
    	 _ref_t11->known[1] = _ref_sc3->myID;
    				 _ref_t11->known[2] = _ref_t10->myID;
    				 _ref_t11->known[3] = _ref_t12->myID;
    				
						_ref_t11->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_t12->known = new byte[MAX_KNOWN];
    	    	_ref_t12->known[0] = _ref_t12->myID;
    	 _ref_t12->known[1] = _ref_sc3->myID;
    				 _ref_t12->known[2] = _ref_t12->myID;
    				 _ref_t12->known[3] = _ref_t12->myID;
    				
						_ref_t12->constructorSignalPair(INITIAL_SENDER
	        	        , 1
	        	        , 0
	        		);
        	    	_ref_t13->known = new byte[MAX_KNOWN];
    	    	_ref_t13->known[0] = _ref_t13->myID;
    	 _ref_t13->known[1] = _ref_sc3->myID;
    				 _ref_t13->known[2] = _ref_t12->myID;
    				 _ref_t13->known[3] = _ref_t14->myID;
    				
						_ref_t13->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_t14->known = new byte[MAX_KNOWN];
    	    	_ref_t14->known[0] = _ref_t14->myID;
    	 _ref_t14->known[1] = _ref_sc3->myID;
    				 _ref_t14->known[2] = _ref_t13->myID;
    				 _ref_t14->known[3] = _ref_t15->myID;
    				
						_ref_t14->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 0
	        		);
        	    	_ref_t15->known = new byte[MAX_KNOWN];
    	    	_ref_t15->known[0] = _ref_t15->myID;
    	 _ref_t15->known[1] = _ref_sc4->myID;
    				 _ref_t15->known[2] = _ref_t14->myID;
    				 _ref_t15->known[3] = _ref_t16->myID;
    				
						_ref_t15->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_t16->known = new byte[MAX_KNOWN];
    	    	_ref_t16->known[0] = _ref_t16->myID;
    	 _ref_t16->known[1] = _ref_sc4->myID;
    				 _ref_t16->known[2] = _ref_t16->myID;
    				 _ref_t16->known[3] = _ref_t16->myID;
    				
						_ref_t16->constructorSignalPair(INITIAL_SENDER
	        	        , 1
	        	        , 0
	        		);
        	    	_ref_t17->known = new byte[MAX_KNOWN];
    	    	_ref_t17->known[0] = _ref_t17->myID;
    	 _ref_t17->known[1] = _ref_sc4->myID;
    				 _ref_t17->known[2] = _ref_t16->myID;
    				 _ref_t17->known[3] = _ref_t18->myID;
    				
						_ref_t17->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_t18->known = new byte[MAX_KNOWN];
    	    	_ref_t18->known[0] = _ref_t18->myID;
    	 _ref_t18->known[1] = _ref_sc4->myID;
    				 _ref_t18->known[2] = _ref_t17->myID;
    				 _ref_t18->known[3] = _ref_t19->myID;
    				
						_ref_t18->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 0
	        		);
        	    	_ref_t19->known = new byte[MAX_KNOWN];
    	    	_ref_t19->known[0] = _ref_t19->myID;
    	 _ref_t19->known[1] = _ref_sc5->myID;
    				 _ref_t19->known[2] = _ref_t18->myID;
    				 _ref_t19->known[3] = _ref_t20->myID;
    				
						_ref_t19->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_t20->known = new byte[MAX_KNOWN];
    	    	_ref_t20->known[0] = _ref_t20->myID;
    	 _ref_t20->known[1] = _ref_sc5->myID;
    				 _ref_t20->known[2] = _ref_t20->myID;
    				 _ref_t20->known[3] = _ref_t20->myID;
    				
						_ref_t20->constructorSignalPair(INITIAL_SENDER
	        	        , 1
	        	        , 0
	        		);
        	    	_ref_t21->known = new byte[MAX_KNOWN];
    	    	_ref_t21->known[0] = _ref_t21->myID;
    	 _ref_t21->known[1] = _ref_sc5->myID;
    				 _ref_t21->known[2] = _ref_t20->myID;
    				 _ref_t21->known[3] = _ref_t22->myID;
    				
						_ref_t21->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_t22->known = new byte[MAX_KNOWN];
    	    	_ref_t22->known[0] = _ref_t22->myID;
    	 _ref_t22->known[1] = _ref_sc5->myID;
    				 _ref_t22->known[2] = _ref_t21->myID;
    				 _ref_t22->known[3] = _ref_t23->myID;
    				
						_ref_t22->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 0
	        		);
        	    	_ref_t23->known = new byte[MAX_KNOWN];
    	    	_ref_t23->known[0] = _ref_t23->myID;
    	 _ref_t23->known[1] = _ref_sc5->myID;
    				 _ref_t23->known[2] = _ref_t22->myID;
    				 _ref_t23->known[3] = _ref_t24->myID;
    				
						_ref_t23->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 0
	        		);
        	    	_ref_t24->known = new byte[MAX_KNOWN];
    	    	_ref_t24->known[0] = _ref_t24->myID;
    	 _ref_t24->known[1] = _ref_sc2->myID;
    				 _ref_t24->known[2] = _ref_t23->myID;
    				 _ref_t24->known[3] = _ref_t8->myID;
    				
						_ref_t24->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_t25->known = new byte[MAX_KNOWN];
    	    	_ref_t25->known[0] = _ref_t25->myID;
    	 _ref_t25->known[1] = _ref_sc5->myID;
    				 _ref_t25->known[2] = _ref_t20->myID;
    				 _ref_t25->known[3] = _ref_t26->myID;
    				
						_ref_t25->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_t26->known = new byte[MAX_KNOWN];
    	    	_ref_t26->known[0] = _ref_t26->myID;
    	 _ref_t26->known[1] = _ref_sc5->myID;
    				 _ref_t26->known[2] = _ref_t25->myID;
    				 _ref_t26->known[3] = _ref_t27->myID;
    				
						_ref_t26->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 0
	        		);
        	    	_ref_t27->known = new byte[MAX_KNOWN];
    	    	_ref_t27->known[0] = _ref_t27->myID;
    	 _ref_t27->known[1] = _ref_sc5->myID;
    				 _ref_t27->known[2] = _ref_t26->myID;
    				 _ref_t27->known[3] = _ref_t28->myID;
    				
						_ref_t27->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 0
	        		);
        	    	_ref_t28->known = new byte[MAX_KNOWN];
    	    	_ref_t28->known[0] = _ref_t28->myID;
    	 _ref_t28->known[1] = _ref_sc6->myID;
    				 _ref_t28->known[2] = _ref_t27->myID;
    				 _ref_t28->known[3] = _ref_t29->myID;
    				
						_ref_t28->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 0
	        		);
        	    	_ref_t29->known = new byte[MAX_KNOWN];
    	    	_ref_t29->known[0] = _ref_t29->myID;
    	 _ref_t29->known[1] = _ref_sc6->myID;
    				 _ref_t29->known[2] = _ref_t28->myID;
    				 _ref_t29->known[3] = _ref_t30->myID;
    				
						_ref_t29->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_t30->known = new byte[MAX_KNOWN];
    	    	_ref_t30->known[0] = _ref_t30->myID;
    	 _ref_t30->known[1] = _ref_sc6->myID;
    				 _ref_t30->known[2] = _ref_t30->myID;
    				 _ref_t30->known[3] = _ref_t30->myID;
    				
						_ref_t30->constructorSignalPair(INITIAL_SENDER
	        	        , 1
	        	        , 0
	        		);
        	    	_ref_t31->known = new byte[MAX_KNOWN];
    	    	_ref_t31->known[0] = _ref_t31->myID;
    	 _ref_t31->known[1] = _ref_sc6->myID;
    				 _ref_t31->known[2] = _ref_t30->myID;
    				 _ref_t31->known[3] = _ref_t32->myID;
    				
						_ref_t31->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_t32->known = new byte[MAX_KNOWN];
    	    	_ref_t32->known[0] = _ref_t32->myID;
    	 _ref_t32->known[1] = _ref_sc6->myID;
    				 _ref_t32->known[2] = _ref_t31->myID;
    				 _ref_t32->known[3] = _ref_t33->myID;
    				
						_ref_t32->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 0
	        		);
        	    	_ref_t33->known = new byte[MAX_KNOWN];
    	    	_ref_t33->known[0] = _ref_t33->myID;
    	 _ref_t33->known[1] = _ref_sc1->myID;
    				 _ref_t33->known[2] = _ref_t32->myID;
    				 _ref_t33->known[3] = _ref_t1->myID;
    				
						_ref_t33->constructorSignalPair(INITIAL_SENDER
	        	        , 0
	        	        , 1
	        		);
        	    	_ref_tn1->known = new byte[MAX_KNOWN];
    	    	_ref_tn1->known[0] = _ref_tn1->myID;
    	 _ref_tn1->known[1] = _ref_sc1->myID;
    				 _ref_tn1->known[2] = _ref_t1->myID;
    				 _ref_tn1->known[3] = _ref_t1->myID;
    				
						_ref_tn1->constructorSignalPair(INITIAL_SENDER
	        	        , (-1)
	        	        , 0
	        		);
        	    	_ref_tn2->known = new byte[MAX_KNOWN];
    	    	_ref_tn2->known[0] = _ref_tn2->myID;
    	 _ref_tn2->known[1] = _ref_sc2->myID;
    				 _ref_tn2->known[2] = _ref_t8->myID;
    				 _ref_tn2->known[3] = _ref_t8->myID;
    				
						_ref_tn2->constructorSignalPair(INITIAL_SENDER
	        	        , (-1)
	        	        , 0
	        		);
        	    	_ref_tn3->known = new byte[MAX_KNOWN];
    	    	_ref_tn3->known[0] = _ref_tn3->myID;
    	 _ref_tn3->known[1] = _ref_sc3->myID;
    				 _ref_tn3->known[2] = _ref_t12->myID;
    				 _ref_tn3->known[3] = _ref_t12->myID;
    				
						_ref_tn3->constructorSignalPair(INITIAL_SENDER
	        	        , (-1)
	        	        , 0
	        		);
        	    	_ref_tn4->known = new byte[MAX_KNOWN];
    	    	_ref_tn4->known[0] = _ref_tn4->myID;
    	 _ref_tn4->known[1] = _ref_sc4->myID;
    				 _ref_tn4->known[2] = _ref_t16->myID;
    				 _ref_tn4->known[3] = _ref_t16->myID;
    				
						_ref_tn4->constructorSignalPair(INITIAL_SENDER
	        	        , (-1)
	        	        , 0
	        		);
        	    	_ref_tn5->known = new byte[MAX_KNOWN];
    	    	_ref_tn5->known[0] = _ref_tn5->myID;
    	 _ref_tn5->known[1] = _ref_sc5->myID;
    				 _ref_tn5->known[2] = _ref_t20->myID;
    				 _ref_tn5->known[3] = _ref_t20->myID;
    				
						_ref_tn5->constructorSignalPair(INITIAL_SENDER
	        	        , (-1)
	        	        , 0
	        		);
        	    	_ref_tn6->known = new byte[MAX_KNOWN];
    	    	_ref_tn6->known[0] = _ref_tn6->myID;
    	 _ref_tn6->known[1] = _ref_sc6->myID;
    				 _ref_tn6->known[2] = _ref_t30->myID;
    				 _ref_tn6->known[3] = _ref_t30->myID;
    				
						_ref_tn6->constructorSignalPair(INITIAL_SENDER
	        	        , (-1)
	        	        , 0
	        		);
        	    	_ref_tr1->known = new byte[MAX_KNOWN];
    	    	_ref_tr1->known[0] = _ref_tr1->myID;
    	 _ref_tr1->known[1] = _ref_sc1->myID;
    				
						_ref_tr1->constructorTrain(INITIAL_SENDER
	        	        , 1
	        		);
        	    	_ref_tr2->known = new byte[MAX_KNOWN];
    	    	_ref_tr2->known[0] = _ref_tr2->myID;
    	 _ref_tr2->known[1] = _ref_sc1->myID;
    				
						_ref_tr2->constructorTrain(INITIAL_SENDER
	        	        , 2
	        		);
        	
	numberOfStates = 0;
	numberOfTransitions = 0;
    numberOfTimedBundles = 0;

    #ifdef DEBUG
    	analysisOutputStream << "Rebecs are instanciated successfully." << endl;
    #endif

}

void AbstractTimedRebecaAnalyzer::exportState(OpenBorderNode &current, ostream& outStream) {
	outStream << "<state id=\"" << current.state->stateID << "_" << 
		(int)current.stateActiveBundleNumber << "\" ";
		outStream << "atomicpropositions=\""; 
		outStream << "\" ";
	outStream << ">" << endl;
	#ifndef SIMPLIFIED_STATESPACE
	for (int cnt = 0; cnt < REBEC_COUNT; cnt++)
		rebecs[cnt]->exportStateInXML(outStream, "\t");
	#endif
	outStream << "</state>" << endl;
}

void AbstractTimedRebecaAnalyzer::exportTransition(OpenBorderNode &source, OpenBorderNode &destination, 
		string sender, string owner, string label, TIME_TYPE executionTime, TIME_TYPE shift, ostream& outStream) {
    outStream << "<transition source=\"" << source.state->stateID << "_" << 
		(int)source.stateActiveBundleNumber << "\" destination=\"" << 
		destination.state->stateID << "_" << (int)destination.stateActiveBundleNumber <<
    	"\" executionTime=\"" << (int)executionTime << "\" shift=\"" << (int) shift << 
    	"\"> <messageserver sender=\"" << sender << "\" owner=\"" << 
    	owner << "\" title=\"" << label << "\"/></transition>" << endl;
}