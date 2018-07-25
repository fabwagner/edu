package data.rebecs;

import java.util.List;

import data.Rebec;

public class Train extends Rebec {

	public String station;
	public String track;
	public String next;
	public String dest;
	public String s;
	public String id;
	public String drive_status;
	public String schedule;
	
	public Train(String name) {
		this.name = name;
	}
}
