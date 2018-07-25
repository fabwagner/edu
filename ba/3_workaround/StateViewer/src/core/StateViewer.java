package core;

import java.io.File;
import java.io.IOException;

import ui.StateViewerWindow2;

public class StateViewer {

	private static StateViewerWindow2 stateViewer = null;
	public static StateLoader SL = new StateLoader();;
	
	public static void main(String[] a) throws IOException {
	
		SL.load(new File("statespace.xml"));
		
		
//		stateViewer = new StateViewerWindow();
//		// stateViewer.xmlSetUp();
//		stateViewer.createUI();
		stateViewer = new StateViewerWindow2();
		stateViewer.createUI();
	}
}
