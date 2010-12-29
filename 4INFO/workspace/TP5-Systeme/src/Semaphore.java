import java.util.ArrayList;

public class Semaphore {

	private int counter;
	private ArrayList<Thread> ar;
	public static int nbPlacesParking = 1;

	public Semaphore(int a) {
		counter = a;
		ar = new ArrayList<Thread>();
	}

	synchronized void P() throws InterruptedException {
		while (--counter == 0) {
			Thread o = new Thread();
			ar.add(o);
			System.out.println("taille :"+ar.size());
			o.wait();
		}
		System.out.println(counter);
	}

	synchronized void V() throws InterruptedException {
		if (counter == 0) {
			ar.get(0).notify();
			ar.remove(0);
		}
		counter++;
		System.out.println(counter);
	}
	
	public static void main(String[] args) throws InterruptedException{
		Semaphore test = new Semaphore(nbPlacesParking);
		test.P();
		test.V();
	}
}
