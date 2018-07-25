package data;

import java.util.ArrayList;
import java.util.List;

public class Rebec {
	public String name;
	private List<Message> queue = new ArrayList<>();
	
	public void addMessageToQueue(Message m) {
		queue.add(m);
	}
	
	public Message[] getQueue() {
		Message[] q = queue.toArray(new Message[queue.size()]);
		return q;
	}
	
	public String toString() {
		return name;
	}
}
