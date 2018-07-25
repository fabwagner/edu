package ui;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import core.StateViewer;
import data.State;

public class StateChooser extends JPanel {

	JTextField tfState = new JTextField(10);
	JButton btnPrev = new JButton("prev");
	JButton btnNext = new JButton("next");
	JButton btnGoto = new JButton("goto");
	JLabel lblObserve = new JLabel("Observe Rebecs");
	JTextField tfObserve = new JTextField(30);
	JLabel lblObserveVars = new JLabel("Observe Vars");
	JTextField tfObserveVars = new JTextField(30);
	
	StateStatus ss = null;
	static int currentState = 0;
	
	public StateChooser(StateStatus ss) {
		this.ss = ss;
		
		FlowLayout fl = new FlowLayout(FlowLayout.LEFT);
		fl.setVgap(10);
		fl.setHgap(10);
		
		this.setLayout(fl);
		this.add(tfState);
		this.add(btnPrev);
		this.add(btnNext);
		this.add(btnGoto);
		this.add(lblObserve);
		this.add(tfObserve);
		this.add(lblObserveVars);
		this.add(tfObserveVars);
		
		tfObserve.setText("*");
		tfObserveVars.setText("*");
		
		this.btnGoto.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				String sid = tfState.getText();
				try {
					int id = Integer.parseInt(sid);
					currentState = id;
				
					
					String filter = tfObserve.getText();
					filter = filter.replaceAll("\\s", "");		
					ss.setFilterRebecs(filter);
					
					filter = tfObserveVars.getText();
					filter = filter.replaceAll("\\s", "");		
					ss.setFilterVars(filter);
					
					State state = StateViewer.SL.getState(currentState);
					ss.setState(state);
					//System.out.println(state);
				} catch (Exception err) {
					
				}
			}
		});
		
		this.btnNext.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
	
				try {
					currentState++;
					tfState.setText(currentState + "");
					
					
					String filter = tfObserve.getText();
					filter = filter.replaceAll("\\s", "");		
					ss.setFilterRebecs(filter);
					
					filter = tfObserveVars.getText();
					filter = filter.replaceAll("\\s", "");		
					ss.setFilterVars(filter);
					
					State state = StateViewer.SL.getState(currentState);
					ss.setState(state);
				} catch (Exception err) {
					System.out.println(err.toString());
					int id = 0;
					
					tfState.setText(id + "");
					
				
					
					String filter = tfObserve.getText();
					filter = filter.replaceAll("\\s", "");		
					ss.setFilterRebecs(filter);
					
					filter = tfObserveVars.getText();
					filter = filter.replaceAll("\\s", "");		
					ss.setFilterVars(filter);
					
					State state = StateViewer.SL.getState(currentState);
					ss.setState(state);
					
				}
			}
		});
		
	this.btnPrev.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
			
				try {
					currentState--;
					tfState.setText(currentState + "");
					
				
					
					String filter = tfObserve.getText();
					filter = filter.replaceAll("\\s", "");		
					ss.setFilterRebecs(filter);
					
					filter = tfObserveVars.getText();
					filter = filter.replaceAll("\\s", "");		
					ss.setFilterVars(filter);
					
					State state = StateViewer.SL.getState(currentState);
					ss.setState(state);
				} catch (Exception err) {
					int id = 0;
					
					tfState.setText(id + "");
					
				
					
					String filter = tfObserve.getText();
					filter = filter.replaceAll("\\s", "");		
					ss.setFilterRebecs(filter);
					
					filter = tfObserveVars.getText();
					filter = filter.replaceAll("\\s", "");		
					ss.setFilterVars(filter);
					
					State state = StateViewer.SL.getState(currentState);
					ss.setState(state);
				}
				
			}
		});
		
		
	}
}
