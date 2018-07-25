package ui;

import java.awt.BorderLayout;

import javax.swing.JFrame;
import javax.swing.JTextField;

public class StateViewerWindow2 {

	private JFrame frame;
	
	public StateViewerWindow2() {
		frame = new JFrame("State Viewer Window 1.0");
		frame.setSize(1500, 1000);
	}
	
	public void createUI() {
		StateStatus sstatus = new StateStatus();
		StateChooser schosser = new StateChooser(sstatus);
		
		
		
		frame.getContentPane().add(schosser, BorderLayout.NORTH);
		frame.getContentPane().add(sstatus, BorderLayout.CENTER);
		
		frame.setVisible(true);
	}
}
