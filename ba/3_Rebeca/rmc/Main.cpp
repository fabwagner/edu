                                          







#include "Types.h"
#include "Config.h"

#include "CommandLineParser.h"

			#include "CoreRebecaModelChecker.h"
		int maxDepth;

#include <signal.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;


			#ifdef EXPORT_STATE_SPACE
		ofstream statespace;
		#endif
		CoreRebecaModelChecker *analyzer;
	
void segmentationFaultHandler(int signum) {
	analyzer->segmentationFault();
	exit(0);
}

#ifdef PROGRESS_REPORT
#include <thread> 
#include <chrono> 
ostream *progressReportStream;
boolean continueReportProgress;
void progressReport() {
	while(continueReportProgress) {
		analyzer->progressReport(*progressReportStream);
	    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
}
#endif

int BOOLEAN_SIZE, BYTE_SIZE, SHORT_SIZE, INT_SIZE, FLOAT_SIZE, DOUBLE_SIZE, REACTIVE_CLASS_SIZE;
int main(int argc, char* argv[]) {

	BOOLEAN_SIZE = sizeof(boolean);
	BYTE_SIZE = sizeof(byte);
	SHORT_SIZE = sizeof(short);
	INT_SIZE = sizeof(int);
	FLOAT_SIZE = sizeof(float);
	DOUBLE_SIZE = sizeof(double);
	REACTIVE_CLASS_SIZE = sizeof(void*);
	
	signal(SIGSEGV, segmentationFaultHandler);

	CommandLineParser parser;
	parser.addOption('h', "help", "Print this message.");
	parser.addOption('s', "hashmapSize", "Set the size of the hashmap to \"2^value\" (default size is 20 and the value should be bigger that 20).", "value");
	parser.addOption('o', "exportResult", "Exporting the model checking result in file \"fileName\".", "fileName");
	#ifdef PROGRESS_REPORT
		parser.addOption('g', "progress", "Report progress in file \"fileName\".", "fileName");
	#endif
	
		#ifdef MONTE_CARLO
	parser.addOption('e', "error", "Error value of the calculated results", "value");
	parser.addOption('d', "delta", "Confidence value of the calculated results", "fileName");
	#endif
	
		    #ifdef EXPORT_STATE_SPACE	
		parser.addOption('x', "exportStatespace", "Exporting the state space in file \"fileName\".", "fileName");
		#endif
		parser.addOption('p', "propertyName", "The name of the property which model must be checked against it", "property name");
	parser.addOption('d', "searchDepth", "The depth of search in DFS based model checking algorithm or the size of the open border in BFS based model checking", "maximum search depth");
	    
	try {
		parser.parse(argc, argv);
	} catch (Exception e) {
		cout << e.getMessage() << endl;
		parser.printHelp();
		exit(0);
	}
	if (parser.hasOption('h')) {
		parser.printHelp();
		exit(0);
	}
	
    int hashmapSize = 24;
	ostream *result = &cout;

	if (parser.hasOption('s')) {
		int newSize = atoi(parser.getOptionValue('s').c_str());
		hashmapSize = newSize > hashmapSize ? newSize : hashmapSize;
	}
	if (parser.hasOption('o')) {
		result = new ofstream(parser.getOptionValue('o').c_str(), ofstream::out|ofstream::trunc);
	}
	#ifdef PROGRESS_REPORT
		if (parser.hasOption('g')) {
			progressReportStream = new ofstream(parser.getOptionValue('g').c_str(), ofstream::out|ofstream::trunc);
		}
	#endif

	for (list<string>::iterator it = parser.getEnvironmentVariables().begin(); it != parser.getEnvironmentVariables().end(); ++it) {
		string envVar = *it;
		int index = envVar.find("=");
		if (index == string::npos || index == 0 || index == envVar.length() - 1)
			continue;
		string name = envVar.substr(0, index);
		string value = envVar.substr(index + 1, envVar.length());
		    }
				#ifdef EXPORT_STATE_SPACE
		if (parser.hasOption('x')) {
			statespace.open(parser.getOptionValue('x').c_str(), ofstream::out|ofstream::trunc);
		} else {
			statespace.open("statespace.xml", ofstream::out|ofstream::trunc);
			#ifdef DEBUG_LEVEL_2 
			cout.rdbuf(statespace.rdbuf());
			#endif
			
		}
		#endif
		maxDepth = parser.hasOption('d') ? atoi(parser.getOptionValue('d').c_str()) : 10000;
		string propertyName;
		if (parser.hasOption('p')) {
			propertyName = parser.getOptionValue('p');
		}
		analyzer = new CoreRebecaModelChecker(*result
	    	#ifdef EXPORT_STATE_SPACE
	    		, statespace
			#endif
			, hashmapSize
			);
		#ifdef PROGRESS_REPORT
			continueReportProgress = true;
			std::thread t1(progressReport);
		#endif
		analyzer->doModelChecking(propertyName, "LTL");
		#ifdef PROGRESS_REPORT
			continueReportProgress = false;
			t1.join();
		#endif
		
		
    if (parser.hasOption('o')) {
        ((ofstream*)result)->close();
    }
    return 0;
}
