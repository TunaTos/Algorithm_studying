import java.io.BufferedReader;
import java.io.IOException;
import java.util.*;
import java.io.*;


public class Main {

	interface myInterface 
	{
		void run() throws IOException;
	}
	
	
	public static void main(String[] args) {
		myInterface f = () -> {
			int num1, num2;
			String buffer = new String();
			
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			buffer = br.readLine();
			
			StringTokenizer st = new StringTokenizer(buffer);
			
			num1 = Integer.parseInt(st.nextToken());
			num2 = Integer.parseInt(st.nextToken());

			if (num1 > num2)
				System.out.println(">");
			else if (num1 < num2)
				System.out.println("<");
			else if (num1 == num2)
				System.out.println("==");
		};
		
		try {
			f.run();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
