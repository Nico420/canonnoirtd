package chat;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
*   This is the remote interface that describes the methods
*   that the client can call on the server
*/

public interface ChatServer extends Remote {

	public void connect(ChatClientImpl ref) throws RemoteException;
    public void disconnect(ChatClientImpl ref) throws RemoteException;
    public void sendmsg(String m) throws RemoteException;
	/**
	*   The client retrieves all the messages that are on the server
	*/
    //public String[] getAllMessages() throws RemoteException;

	/**
	*   The client adds a new message to the list
	*/
    //public void addNewMessage(String m) throws RemoteException;

}
