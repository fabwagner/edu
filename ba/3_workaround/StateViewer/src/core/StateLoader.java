
package core;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import data.Message;
import data.State;
import data.rebecs.StationController;
import data.rebecs.TrackElement;
import data.rebecs.Train;

public class StateLoader {

	private Map<Integer, State> states = new HashMap<Integer, State>();

	public void load(File stateFile) throws IOException {
		System.out.println("begin state load...");

		BufferedReader in = new BufferedReader(new FileReader(stateFile));
		String line;
		int count = 0;
		State state = null;

		List<StationController> scs = new ArrayList<StationController>();
		StationController sc = null;
		List<Train> trs = new ArrayList<Train>();
		Train tr = null;
		List<TrackElement> ts = new ArrayList<TrackElement>();
		TrackElement t = null;
		String rebec_name = null;
		
		int rebec_type = 0;
		int statenumber = 0;


		while ((line = in.readLine()) != null) {
			line = line.replaceAll("\\s", "");
			//System.out.println(line);
			if (line.startsWith("<state") && !line.startsWith("<statev")) {
				line = line.substring(line.indexOf("id=") + 4);
				line = line.substring(0, line.indexOf("\""));
//				//System.out.println(line);
//				try {
//					
//					line = Integer.parseInt(line) + "";
//				}catch(Exception e) {
//					statenumber++;
//					
//				}
//				
//				
				statenumber ++;
				state = new State(statenumber+"");
				//System.out.println("new state "+ line);
			}

			if (line.startsWith("<rebec")) {
				String name;
				line = line.substring(line.indexOf("name=") + 6);
				line = line.substring(0, line.indexOf("\""));
				name = line;
				rebec_name = name;
				if (name.startsWith("sc")) {
					rebec_type = 1; //Station Controller
					sc = new StationController(name);
					scs.add(sc);
				} else 
					if (name.startsWith("tr")) {
						rebec_type = 2; //Train
						tr = new Train(name);
						trs.add(tr);
					} else
						if(name.startsWith("t")) {
							rebec_type = 3; //TrackElement
							t = new TrackElement(name);
							ts.add(t);
						}
			}

			if (line.startsWith("<variable")) {
				String vname = line;
				vname = vname.substring(vname.indexOf("name=") + 6);
				vname = vname.substring(0, vname.indexOf("\""));					
				//System.out.print(vname+"=");

				String value = line;
				value = value.substring(value.indexOf(">") + 1);
				value = value.substring(0, value.indexOf("<"));

				if (rebec_type == 1) {	
					//System.out.println(value);
					switch (vname) {
					case "wait_for_s" : 
						sc.wait_for_s = value;
						break;
					case "wait_for_w" : 
						sc.wait_for_w = value;
						break;
					case "wait_for_n" : 
						sc.wait_for_n = value;
						break;
					case "wait_for_e" : 
						sc.wait_for_e = value;
						break;
					case "train":
						sc.train = value;
						break;
					case "anbieten_sent":
						sc.anbieten_sent = value;
						break;
					}

				} else
					if(rebec_type == 2) {
						//System.out.println(value);
						switch (vname) {
						case "station" : 
							tr.station = value;
							break;
						case "track" : 
							tr.track = value;
							break;
						case "next" : 
							tr.next = value;
							break;
						case "dest" : 
							tr.dest = value;
							break;
						case "s":
							tr.s = value;
							break;
						case "id":
							tr.id = value;
							break;	
						case "drive_status":
							tr.drive_status = value;
							break;
						case "schedule":
							tr.schedule = value;
							break;
						}

					} else
						if (rebec_type == 3) {
							switch (vname) {
							case "signal" : 
								t.signal = value;
								break;
							case "block" : 
								t.block = value;
								break;
							case "preStation" : 
								t.preStation = value;
								break;
							case "station" : 
								t.station = value;
								break;
							case "onTrack":
								t.onTrack = value;
								break;
							case "verschluss":
								t.verschluss = value;
								break;	
							}
						}


			} //end variables

			if (line.startsWith("<message")) {
				String sender = line;
				sender = sender.substring(sender.indexOf("sender=") + 8);
				sender = sender.substring(0, sender.indexOf("\""));		

				//System.out.println(sender);
				String value = line;
				value = value.substring(value.indexOf(">") + 1);
				value = value.substring(0, value.indexOf("<"));
				//System.out.println(value);
				Message m = new Message(rebec_name, sender, value);

				if (rebec_type == 1) {
					sc.addMessageToQueue(m);
				} else if (rebec_type == 2) {
					tr.addMessageToQueue(m);
				} else if (rebec_type == 3){
					t.addMessageToQueue(m);
				}

			}

			if (line.startsWith("</state") && !line.startsWith("</statev")) {
				rebec_type = 0;
				state.setStationControllers(scs);
				state.setTracks(ts);
				state.setTrains(trs);
				scs = new ArrayList<StationController>();
				ts = new ArrayList<TrackElement>();
				trs = new ArrayList<Train>();
				states.put(state.getID(), state);
				//System.out.println(state);
				//System.out.println("end state");
			}
		}
		//System.out.println(scs);
		in.close();
		System.out.println("end state load");
	}

	public State getState(int id) {
		return states.get(id);
	}
	
	public static void main(String[] a) throws IOException {
		StateLoader s = new StateLoader();
		s.load(new File("statespace.xml"));

	}
}
