package data;

public class Message {
	private String sender;
	private String value;
	private String rebec;
	public Message(String rebec, String sender, String value) {
		this.sender = sender;
		this.value = value;
		this.rebec = rebec;
	}
	
	public String toString() {
		return rebec+ "." + value + " from " + sender;
	}
}
