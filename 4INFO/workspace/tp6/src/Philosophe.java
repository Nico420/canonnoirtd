public class Philosophe extends Thread{

	private static int N = 5;
	public static Semaphore Baq[] = new Semaphore[N];
	private Semaphore semG;
	private Semaphore semD;
	private int indice;
	public Semaphore table = new Semaphore(N-1);

	Philosophe(int ind) {
		indice = ind;
	}

	synchronized void philosopher(Integer i) throws InterruptedException {
		//Interblocage	
			table.P();
			Baq[i].P();
			sleep(100);
			Baq[(i+1)%N].P();
			
		/*
		 * if((i%2)==0){
			Baq[i].P();
			sleep(100);
			Baq[(i+1)%N].P();
		}else{
			Baq[(i+1)%N].P();
			sleep(100);
			Baq[i].P();
		}
		Solution 2 : OK, plus d'interblocage !
		 */
		sleep(5); //eat()
		Baq[i].V();
		Baq[(i+1)%N].V();
		table.V();
	}
	
	public void run(){
		while(true){
			try {
				sleep(2); //think()
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			try {
				this.philosopher(indice); // eat()
				System.out.println("eat : "+indice);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	
	public static void main(String[] args) throws InterruptedException{
		
		for (int i = 0; i < N; i++) {
			Baq[i] = new Semaphore(1);
		}
		Philosophe p0 = new Philosophe(0);
		new Thread(p0).start();
		Philosophe p1 = new Philosophe(1);
		new Thread(p1).start();
		Philosophe p2 = new Philosophe(2);
		new Thread(p2).start();
		Philosophe p3 = new Philosophe(3);
		new Thread(p3).start();
		Philosophe p4 = new Philosophe(4);
		new Thread(p4).start();
	}
}

/*
 * Solution 1 : sémaphore à l'accès à la table : empecher d'avoir 5 philosophes.
 * Solution 2 : gaucher et droitier, autre de prise des baguettes, prendre la sienne en dernier
*/