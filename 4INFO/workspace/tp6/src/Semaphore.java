public class Semaphore {

	public int counter;

	public Semaphore(int a) {
		counter = a;
	}

	synchronized void P() throws InterruptedException {
		while (counter == 0) {
			this.wait();
		}
		counter--;
		System.out.println(counter);
	}

	synchronized void V() throws InterruptedException {
		if (counter == 0) {
			this.notify();
		}
		counter++;
		System.out.println(counter);
	}
	
	public static void main(String[] args) throws InterruptedException{
		Semaphore test = new Semaphore(2);
		test.P();
		test.P();
		test.P();
		test.V();
	}
}