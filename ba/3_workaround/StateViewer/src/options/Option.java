package options;

import java.util.HashMap;

public abstract class Option {
		protected HashMap<String, String> options = new HashMap<String, String>();
		
		public Option() {
			init();
		}
		
		protected abstract void init();
		
		public String get(String key) {
			return options.get(key);
		}
}
