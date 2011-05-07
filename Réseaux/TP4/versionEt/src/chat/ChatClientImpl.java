package chat;

import java.net.MalformedURLException;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.io.*;

/**
 * This class describes the client object that handles the communications with
 * the server
 */

public class ChatClientImpl extends Thread {
	/**
	 * The name of the user who sends messages using this client
	 */

	protected String user;

	/**
	 * Remote reference to the server
	 */

	protected ChatServer theServer;

	/**
	 * We create and initialise an object for user <code>user</code> in order to
	 * speak to the server which can be found at the URL passed as a second
	 * parameter
	 */

	public ChatClientImpl(String user, ChatServer server)
			throws RemoteException {
		this.user = user;
		this.theServer = server;
		theServer.connect(this);
		this.sendMessage();
	}

	public static void main(String[] args) {
		String url;
		String server_name;
		String user;
		String adresseClient;
		String ad_server = " ";
		// Checks the arguments passed on the command line and prints out
		// a help message if there are not enough arguments (2)
		if (args.length < 2) {
			System.out.println("Usage: client <server URL> <username>");
			return;
		} else {
			server_name = args[0];
			user = args[1];
		}
		try {
			System.out.println(" ad_server " + ad_server);
			ad_server = InetAddress.getByName(server_name).getHostAddress();
		} catch (UnknownHostException e) {
			return;
		}

		url = "rmi://" + ad_server + "/simpleChatServer";
		// Tries to connect to the server
		try {
			// Lookups up the server object using the rmiregistry
			ChatServer server = (ChatServer) Naming.lookup(url);
			if (server != null) {
				System.out.println("Server found at URL " + url);

				// Server is found, let's create the client object
				ChatClientImpl theClient = new ChatClientImpl(user, server);
			} else {
				System.out.println("No server found at URL " + url);
			}
		} catch (MalformedURLException e) {
			System.out.println("URL is not a valid one: " + url);
		} catch (NotBoundException e) {
			System.out.println("No server bound with this URL: " + url);
		} catch (RemoteException e) {
			System.out.println("Error, client cannot find server: " + e);
		}

		return;
	}

	/**
	 * Get all the messages from the server and asks the user interface to
	 * display them nb_msg nombre de messages déjà consultes Permet de
	 * déterminer quels sont les nouveaux messages
	 * 
	 * @throws RemoteException
	 */

	/**
	 * Adds a new message to the server
	 */

	protected void sendMessage() {
		String line;
		BufferedReader clavier = new BufferedReader(new InputStreamReader(
				System.in));
		while (true) {

			try {
				System.out.println("Tape une ligne ");
				line = clavier.readLine();

				line = "[" + this.user + "] " + line;

				// Remote call
				this.theServer.sendmsg(line);
			} catch (RemoteException e) {
				System.out
						.println("Problem while sending a message to the server: "
								+ e);
			} catch (IOException ex) {
				System.err.println("IO Problem " + ex);
			}
		}
	}

	public void msg(String m){
		System.out.println(m);
	}
}
