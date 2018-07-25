package options;

public class StartUpOptions extends Option {

	public StartUpOptions() {
		super();
	}
	
	
	@Override
	protected void init() {
		options.put("DEFAULT_HOME_PATH", "/home/fwagner/ba/rebeca");
	}

}
