package executionservice;

import java.io.Serializable;

/**
 * 
 * Represents a computation that returns a long.
 * 
 */
public interface Task extends Serializable {
	/**
	 * Executes computation.
	 *  
	 * @return the result 
	 */
	long execute();
}
