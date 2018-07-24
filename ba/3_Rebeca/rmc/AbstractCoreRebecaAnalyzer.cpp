#include "AbstractCoreRebecaAnalyzer.h"

			#define _ref_g (dynamic_cast<LightActor*>(rebecs[0]))
	    			#define _ref_r (dynamic_cast<LightActor*>(rebecs[1]))
	    			#define _ref_tl (dynamic_cast<TrafficLightActor*>(rebecs[2]))
	    		
		
			#undef _ref_g
			#undef _ref_r
			#undef _ref_tl
	
AbstractCoreRebecaAnalyzer::AbstractCoreRebecaAnalyzer(ostream &outStream, int hashmapSize) : analysisOutputStream(outStream){
	this->hashmapSize = hashmapSize;
}

void AbstractCoreRebecaAnalyzer::unmarshalRebecs(long* node) {
	int i;
	for (i = 0; i < REBEC_COUNT; i++) {
        rebecs[i]->unmarshalActor(node[i]);   // uncompress all states of all rebecs
    }
}

void AbstractCoreRebecaAnalyzer::marshalRebecs(long* node) {
	int i;
	for (i=0; i<REBEC_COUNT; i++){
		node[i] = rebecs[i]->marshalActor();
	}
}

State* AbstractCoreRebecaAnalyzer::storeRecentlyCreatedState (byte &result, short int claim, short int fairnessCounter) {

    numberOfTransitions++;
    State *st;
    long sys[REBEC_COUNT];
	marshalRebecs(sys);
		result = NEW_STATE;
	if (st = storage->exists (sys, claim)){
		if (st->isOnStack()){
			result |= ON_STACK;	// used in detecting cycle & stack proviso
		}
		if (st->isVisited(fairnessCounter)){
			result &= ~NEW_STATE;
		}
        	}
	else
    	{
		st = storage->put(sys, claim);	//create the new State
		if (st == NULL) {
	        throw Exception("Not enough memory for continuing the state space generation.");
		}
	    st->stateID = numberOfStates++;
	    #ifdef DEBUG_LEVEL_2
			cout << "State stored successfully with id: " << st->stateID << "." << endl;
		#endif
	}
	return st;
}

void AbstractCoreRebecaAnalyzer::instantiationPart() {
	vector<AbstractActor*>* referenceToRebecs = new vector<AbstractActor*>();
	byte maxRebecID = 0;
        	LightActor* _ref_g = new LightActor(maxRebecID++, "g", 2, 0, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_g);
        referenceToRebecs->push_back(_ref_g);
	    	LightActor* _ref_r = new LightActor(maxRebecID++, "r", 2, 0, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_r);
        referenceToRebecs->push_back(_ref_r);
	    	TrafficLightActor* _ref_tl = new TrafficLightActor(maxRebecID++, "tl", 1, 2, *referenceToRebecs 
    											#ifdef DEBUG_LEVEL_2 
    											, analysisOutputStream 
    											#endif
    											, hashmapSize
    											);
        rebecs.push_back(_ref_tl);
        referenceToRebecs->push_back(_ref_tl);
	
	        	_ref_g->known = new byte[MAX_KNOWN];
    	    	_ref_g->known[0] = _ref_g->myID;
    	 _ref_g->known[1] = _ref_tl->myID;
    				
						_ref_g->constructorLight(INITIAL_SENDER
	        	        , 1
	        		);
        	    	_ref_r->known = new byte[MAX_KNOWN];
    	    	_ref_r->known[0] = _ref_r->myID;
    	 _ref_r->known[1] = _ref_tl->myID;
    				
						_ref_r->constructorLight(INITIAL_SENDER
	        	        , 2
	        		);
        	    	_ref_tl->known = new byte[MAX_KNOWN];
    	    	_ref_tl->known[0] = _ref_tl->myID;
    	 _ref_tl->known[1] = _ref_g->myID;
    				 _ref_tl->known[2] = _ref_r->myID;
    				
						_ref_tl->constructorTrafficLight(INITIAL_SENDER
	        		);
        	
	numberOfStates = 0;
	numberOfTransitions = 0;

    #ifdef DEBUG
    	analysisOutputStream << "Rebecs are instanciated successfully." << endl;
    #endif

}

void AbstractCoreRebecaAnalyzer::exportState(State* current, ostream& outStream) {
	outStream << "<state id=\"" << current->stateID << "\" "; 
		outStream << "atomicpropositions=\""; 
		outStream << "\" ";
	outStream << ">" << endl;
	for (int cnt = 0; cnt < REBEC_COUNT; cnt++)
		rebecs[cnt]->exportStateInXML(outStream, "\t");
	outStream << "</state>" << endl;
}

void AbstractCoreRebecaAnalyzer::exportTransition(State* source, State* destination, 
		string sender, string owner, string label, ostream& outStream) {
    outStream << "<transition source=\"" << source->stateID << "\" destination=\"" << 
		destination->stateID << "\"> <messageserver sender=\"" << sender << 
		"\" owner=\"" << owner << "\" title=\"" << label << "\"/></transition>" << endl;
}