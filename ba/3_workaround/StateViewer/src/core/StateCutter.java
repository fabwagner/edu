package core;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;


public class StateCutter {

	public void load(File stateFile) throws IOException {
		System.out.println("begin state load...");

		BufferedReader in = new BufferedReader(new FileReader(stateFile));
		BufferedWriter out = new BufferedWriter(new FileWriter(new File(stateFile.getAbsolutePath()+"_cutted")));
		String line;
		int statenumber = 0;


		while ((line = in.readLine()) != null) {
		
			//System.out.println(line);
			if (line.startsWith("<state") && !line.startsWith("<statev")) {	
				statenumber ++;
			}
			if (statenumber < 400) {
				out.write(line + "\n");
				out.flush();
			} else {
				out.write("</transitionsystem>");
				break;
			}
			//System.out.println("end state");
		}
		//System.out.println(scs);
		out.close();
		in.close();
		System.out.println("end state load");
	}

	
	public static void main(String[] a) throws IOException {
		StateCutter s = new StateCutter();
		s.load(new File("/home/fwagner/ba/rebeca/statespace.xml"));

	}
}
