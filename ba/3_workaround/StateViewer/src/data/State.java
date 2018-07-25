package data;

import java.util.List;

import data.rebecs.StationController;
import data.rebecs.TrackElement;
import data.rebecs.Train;

public class State {
	
	private int id;
	
	private Train[] trains;
	private StationController[] stations;
	private TrackElement[] tracks;
	
	public State(String id) {
		this.id = Integer.parseInt(id);
	}
	
	public void setTrains(List<Train> list) {
		trains = list.toArray(new Train[list.size()]);
	}
	
	public void setStationControllers(List<StationController> list) {
		stations = list.toArray(new StationController[list.size()]);
	}
	
	public void setTracks(List<TrackElement> list) {
		tracks = list.toArray(new TrackElement[list.size()]);
	}
	
	public Train[] getTrains() {
		return trains;
	}
	
	public StationController[] getStations() {
		return stations;
	}
	
	public TrackElement[] getTracks() {
		return tracks;
	}
	
	public int getID() {
		return id;
	}
	
	public String toString() {
		return id + " " + stations.length + " " + tracks.length + " " + trains.length  ;
	}
}
