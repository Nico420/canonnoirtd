import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.util.Date;

public class ServeurUDP {

	DatagramSocket datSoc;
	DatagramPacket datPac;

	public ServeurUDP() {
		datSoc = null;
		datPac = null;
	}

	public ServeurUDP(int port) throws SocketException {
		int length = 256;
		datPac = new DatagramPacket(new byte[length], length);
		datSoc = new DatagramSocket(port);
	}

	public static void main(String[] argv) throws IOException {
		ServeurUDP su = new ServeurUDP(50031);
		while (true) {
			su.datSoc.receive(su.datPac);
			System.out.println(su.datPac);
			Date d = new Date();
			String s = d.toString();// d.getDay()+""+d.getHours()+""+""+d.getMinutes()+""+d.getSeconds();
			int length = s.length();
			byte buffer[] = s.getBytes();

			DatagramPacket dataSent = new DatagramPacket(buffer, s.length(),
					su.datPac.getAddress(), su.datPac.getPort());
			su.datSoc.send(dataSent);

		}
	}

}
