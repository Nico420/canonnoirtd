package executionservice.impl;

import java.util.Random;

import executionservice.Task;

class PiTask implements Task {

	private static final long serialVersionUID = 1L;
	
	private long n;
	private long seed;

	public PiTask(long l, long seed) {
		this.n = l;
		this.seed = seed;
	}

	public long execute() {
		long res = 0;
		Random prng = new Random(seed);

		// Generate n random points in the unit square and count how many are
		// in the unit circle

		// INSERT CODE HERE
		for (int i = 0; i < n; i++) {
			double x = prng.nextDouble();
			double y = prng.nextDouble();
			if ((x * x + y * y) <= 1) {
				res++;
			}
		}

		return res;
	}

}