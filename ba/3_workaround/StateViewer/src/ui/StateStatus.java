package ui;

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import data.Message;
import data.State;
import data.rebecs.StationController;
import data.rebecs.TrackElement;
import data.rebecs.Train;

public class StateStatus extends JPanel {

	JList<StationController> lstStations = new JList<StationController>();
	JList<TrackElement> lstTracks = new JList<TrackElement>();
	JList<Train> lstTrains = new JList<Train>();

	JList<Message> lstStationsM = new JList<Message>();
	JList<Message> lstTracksM = new JList<Message>();
	JList<Message> lstTrainsM = new JList<Message>();
	JList<String> lstVars = new JList<String>();


	JLabel lblStations = new JLabel("Stations");
	JLabel lblTracks = new JLabel("Tracks");
	JLabel lblTrains = new JLabel("Trains");
	JLabel lblVars = new JLabel("Vars");


	List<String> filterRebecs = new ArrayList<>();
	List<String> filterVars = new ArrayList<>();
	boolean filterAllRebecs = true;
	boolean filterAllVars = true;

	String var = null;

	public StateStatus() {
		//GridLayout gl = new GridLayout(1, 0);

		this.setLayout(new FlowLayout(FlowLayout.CENTER));

		GridBagLayout gbl = new GridBagLayout();
		GridBagConstraints gbc = new GridBagConstraints();

		JPanel pnlMid = new JPanel(gbl);


		gbc.gridx = 0;
		gbc.gridy = 0;
		gbc.gridheight = 1;
		gbc.insets = new Insets(10,20,0,0);		
		pnlMid.add(lblStations, gbc);

		gbc.gridx = 1; 
		pnlMid.add(lblTracks, gbc);

		gbc.gridx = 2;
		pnlMid.add(lblTrains, gbc);

		gbc.gridx = 3;
		pnlMid.add(lblVars, gbc);

		gbc.gridy = 1;
		gbc.gridx = 0;
		JScrollPane scroll1 = new JScrollPane(lstStations);
		scroll1.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		scroll1.setPreferredSize(new Dimension(300, 500));
		pnlMid.add(scroll1, gbc);

		gbc.gridx = 1;
		JScrollPane scroll2 = new JScrollPane(lstTracks);
		scroll2.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		scroll2.setPreferredSize(new Dimension(300, 500));
		pnlMid.add(scroll2, gbc);

		gbc.gridx = 2;
		JScrollPane scroll3 = new JScrollPane(lstTrains);
		scroll3.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		scroll3.setPreferredSize(new Dimension(300, 500));
		pnlMid.add(scroll3, gbc);

		gbc.gridx = 3;
		gbc.gridheight = 2;
		JScrollPane scroll4 = new JScrollPane(lstVars);
		scroll4.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		scroll4.setPreferredSize(new Dimension(300, 700));
		pnlMid.add(scroll4, gbc);

		gbc.gridheight = 1;
		gbc.gridy = 2;
		gbc.gridx = 0;
		pnlMid.add(lstStationsM, gbc);

		gbc.gridx = 1;
		pnlMid.add(lstTracksM, gbc);

		gbc.gridx = 2;
		pnlMid.add(lstTrainsM, gbc);

		this.add(pnlMid);


		//		lstStations.setPreferredSize(new Dimension(300, 500));
		//		lstTracks.setPreferredSize(new Dimension(300, 500));
		//		lstTrains.setPreferredSize(new Dimension(300, 500));

		lstStationsM.setPreferredSize(new Dimension(300, 300));
		lstTracksM.setPreferredSize(new Dimension(300, 300));
		lstTrainsM.setPreferredSize(new Dimension(300, 300));
	}

	public void setState(State state) {
		
		Train[] trs = state.getTrains();
		StationController[] scs = state.getStations();
		TrackElement[] ts = state.getTracks();

		ArrayList<StationController> lscs = new ArrayList<>();
		ArrayList<TrackElement> lts = new ArrayList<>();
		ArrayList<Train> ltrs = new ArrayList<>();

		ArrayList<Message> m1 = new ArrayList<>();
		ArrayList<Message> m2 = new ArrayList<>();
		ArrayList<Message> m3 = new ArrayList<>();


		for(int i = 0; i< scs.length; i++) {
			if (filterRebecs.contains(scs[i].name) || filterAllRebecs) {
				lscs.add(scs[i]);
				Message[] ms = scs[i].getQueue();
				for(int j = 0; j<ms.length; j++) {
					m1.add(ms[j]);
				}
			}
		}
		for(int i = 0; i< ts.length; i++) {
			if (filterRebecs.contains(ts[i].name) || filterAllRebecs) {
				lts.add(ts[i]);
				Message[] ms = ts[i].getQueue();
				for(int j = 0; j<ms.length; j++) {
					m2.add(ms[j]);
				}	
			}
		}
		for(int i = 0; i< trs.length; i++) {
			if (filterRebecs.contains(trs[i].name) || filterAllRebecs) {
				ltrs.add(trs[i]);
				Message[] ms = trs[i].getQueue();
				for(int j = 0; j<ms.length; j++) {
					m3.add(ms[j]);
				}
			}
		}


		lstStations.setListData(lscs.toArray(new StationController[lscs.size()]));
		lstTracks.setListData(lts.toArray(new TrackElement[lts.size()]));
		lstTrains.setListData(ltrs.toArray(new Train[ltrs.size()]));


		lstStationsM.setListData(m1.toArray(new Message[m1.size()]));
		lstTracksM.setListData(m2.toArray(new Message[m2.size()]));
		lstTrainsM.setListData(m3.toArray(new Message[m3.size()]));

		lstStations.addListSelectionListener(new ListSelectionListener() {

			@Override
			public void valueChanged(ListSelectionEvent e) {	
				try {
				int index = lstStations.getSelectedIndex();
				StationController sc = lstStations.getModel().getElementAt(index);
				var = sc.name;
				lblVars.setText("Vars from "+var);

				String[] vars = null;
				ArrayList<String> lvars = new ArrayList<>();
				if (filterAllVars){
					lvars.add("wait_for_s= " + sc.wait_for_s);
					lvars.add("wait_for_w= " + sc.wait_for_w);
					lvars.add("wait_for_n= " + sc.wait_for_n);
					lvars.add("wait_for_e= " + sc.wait_for_e);
					lvars.add("Train= " + sc.train);
					lvars.add("anbieten_sent= "+sc.anbieten_sent);
				} else
					for(String v : filterVars) {
						switch(v) {
						case "wait_for_s" : 
							lvars.add("wait_for_s= " + sc.wait_for_s);
							break;
						case "wait_for_w" : 
							lvars.add("wait_for_w= " + sc.wait_for_w);
							break;
						case "wait_for_n" : 
							lvars.add("wait_for_n= " + sc.wait_for_n);
							break;
						case "wait_for_e" : 
							lvars.add("wait_for_e= " + sc.wait_for_e);
							break;
						case "train":
							lvars.add("Train= " + sc.train);
							break;
						case "anbieten_sent":
							lvars.add("anbieten_sent= "+sc.anbieten_sent);
							break;
						}

					}
				vars = lvars.toArray(new String[lvars.size()]);
				lstVars.setListData(vars);
				} catch(Exception err) {}
			}
		});
		lstTracks.addListSelectionListener(new ListSelectionListener() {

			@Override
			public void valueChanged(ListSelectionEvent e) {		
				try {
				int index = lstTracks.getSelectedIndex();
				TrackElement t = lstTracks.getModel().getElementAt(index);
				var = t.name;
				lblVars.setText("Vars from "+var);
				
				String[] vars = null;
				ArrayList<String> lvars = new ArrayList<>();
				if (filterAllVars){
					lvars.add("signal= " + t.signal);
					lvars.add("block= " + t.block);
					lvars.add("preStation= " + t.preStation);
					lvars.add("station= " + t.station);
					lvars.add("onTrack= " + t.onTrack);
					lvars.add("verschluss= "+t.verschluss);
				} else
					for(String v : filterVars) {
						switch (v) {
						case "signal" : 
							lvars.add("signal= " + t.signal);
							break;
						case "block" : 
							lvars.add("block= " + t.block);
							break;
						case "preStation" : 
							lvars.add("preStation= " + t.preStation);
							break;
						case "station" : 
							lvars.add("station= " + t.station);
							break;
						case "onTrack":
							lvars.add("onTrack= " + t.onTrack);
							break;
						case "verschluss":
							lvars.add("verschluss= "+t.verschluss);
							break;	
						}

					}
				vars = lvars.toArray(new String[lvars.size()]);
				lstVars.setListData(vars);
				} catch(Exception err) {}
			}
		});
		
		
		lstTrains.addListSelectionListener(new ListSelectionListener() {

			@Override
			public void valueChanged(ListSelectionEvent e) {		
				try {
				int index = lstTrains.getSelectedIndex();
				Train tr = lstTrains.getModel().getElementAt(index);
				var = tr.name;
				lblVars.setText("Vars from "+var);
				
				String[] vars = null;
				ArrayList<String> lvars = new ArrayList<>();
				if (filterAllVars){
					lvars.add("station= " + tr.station);
					lvars.add("track= " + tr.track);
					lvars.add("next= " + tr.next);
					lvars.add("dest= " + tr.dest);
					lvars.add("s= " + tr.s);
					lvars.add("id= "+tr.id);
					lvars.add("drive_status= "+tr.drive_status);
					lvars.add("schedule= "+tr.schedule);
				} else
					for(String v : filterVars) {
						switch (v) {
						case "station" : 
							lvars.add("station= " + tr.station);
							break;
						case "track" : 
							lvars.add("track= " + tr.track);
							break;
						case "next" : 
							lvars.add("next= " + tr.next);
							break;
						case "dest" : 
							lvars.add("dest= " + tr.dest);
							break;
						case "s":
							lvars.add("s= " + tr.s);
							break;
						case "id":
							lvars.add("id= "+tr.id);
							break;	
						case "drive_status":
							lvars.add("drive_status= "+tr.drive_status);
							break;
						case "schedule":
							lvars.add("schedule= "+tr.schedule);
							break;
						}

					}
				vars = lvars.toArray(new String[lvars.size()]);
				lstVars.setListData(vars);
				} catch(Exception err) {}
			}
		});
	}

	public void setFilterRebecs(String filter) {
		if (filter.equals("*")) {
			filterAllRebecs = true;
			return;
		}
		filterAllRebecs = false;
		String[] f = filter.split(",");
		filterRebecs.clear();
		for(int i = 0; i<f.length; i++)
			filterRebecs.add(f[i]);
	}

	public void setFilterVars (String filter) {
		if (filter.equals("*")) {
			filterAllVars = true;
			return;
		}
		filterAllVars = false;
		String[] f = filter.split(",");
		filterVars.clear();
		for(int i = 0; i<f.length; i++)
			filterVars.add(f[i]);
	}

}

