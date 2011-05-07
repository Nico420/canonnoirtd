package chat;

import java.net.MalformedURLException;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.rmi.AlreadyBoundException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Vector;

/**
*   This class provides an implementation for the server
*/

public class ChatServerImpl extends UnicastRemoteObject implements ChatServer{
	/**
	* This Vector object holds all the messages in the list
	*/

	
	protected Vector<ChatClientImpl> allClients;

	/**
	*   Creates and initialised the server object
	*/

	public ChatServerImpl() throws RemoteException {
		this.allClients = new Vector();
	}


	/**
	*   Implementation of the remote method by which the client
	*   retrieves the list of all messages
	*/


	/**
	*   Implementation of the remote method by which the client
	*   adds a new message to the list
	*/


	public static void main(String[] args) {
		String url;

		// If the user did not provide as a command-line argument the URL
		// where the server should be registered, let's display an error message
		// and exit the program
		try {
		  url = "rmi://"+ InetAddress.getLocalHost()
		    .getHostAddress() + "/simpleChatServer";
		} catch (UnknownHostException e) {
		  return;
		}

		// Creates the server object
		try {
			ChatServerImpl theServer = new ChatServerImpl();
			// To avoir to start ./registry
			LocateRegistry.createRegistry(1099);
			Naming.bind(url, theServer);
			System.out.println("Server started and registered with URL " + url);
		} catch (MalformedURLException e) {
			System.out.println("The following URL is not valid: " + url);
		} catch (AlreadyBoundException e) {
			System.out.println(
				"Another server is already registered with URL " + url);
		} catch (RemoteException e) {
			System.out.println("Error, the server could not be launched: " + e);
		}

		return;
	}


	@Override
	public void connect(ChatClientImpl ref) throws RemoteException {
		this.allClients.add(ref);
	}


	@Override
	public void disconnect(ChatClientImpl ref) throws RemoteException {
		this.allClients.remove(ref);
	}


	@Override
	public void sendmsg(String m) throws RemoteException {
		for(ChatClientImpl c : this.allClients){
			c.msg(m);
		}
	}
}
