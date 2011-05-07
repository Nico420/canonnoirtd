import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client_http {

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		while (true) {
			/*
			InetAddress ia = InetAddress
					.getByName("localhost");
			Socket soc = new Socket(ia, 50099);
			InputStreamReader ins = new InputStreamReader(soc.getInputStream());
			BufferedReader br = new BufferedReader(ins);
			OutputStreamWriter output = new OutputStreamWriter(soc
					.getOutputStream());*/
			ServerSocket sSocket = null;
			Socket cSocket = null;
			try{
				sSocket = new ServerSocket(4444);
			}
			catch(IOException e){
				System.out.println("bla");
			}
			try{
				cSocket = sSocket.accept();
			}
			catch(IOException e){
				System.out.println("bla");
			}
			InputStreamReader ins = new InputStreamReader(cSocket.getInputStream());
			BufferedReader br = new BufferedReader(ins);
			OutputStreamWriter output = new OutputStreamWriter(cSocket
					.getOutputStream());
			
			output.write("GET /index.html /HTTP/1.1");
			output.flush();
		}
	}

}
