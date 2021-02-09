public class UpperTriangularMatrix {
	private int n;
	private int[] array;

	public UpperTriangularMatrix(int n) {
		if (n <= 0) {
			this.n = 1;
			array = new int[this.n];
		} else {
			this.n = n;
		}
		this.array = new int[this.n * (this.n + 1) / 2];

	}

	public UpperTriangularMatrix(Matrix upTriM) throws IllegalArgumentException {

		if (upTriM.isUpperTr() == true && upTriM.getsizeofcols() == upTriM.getsizeofrows()) {// checks if matrix is
																								// upper triangular and
																								// square
			this.n = upTriM.getsizeofrows();
			this.array = new int[this.n * (this.n + 1) / 2];
			int count = 0;
			for (int i = 0; i < this.n; i++) {// puts upper triangular values in array
				for (int j = i; j < this.n; j++) {
					this.array[count] = upTriM.getElement(i, j);
					count++;

				}
			}
		} else {
			throw new IllegalArgumentException("Not an upper triangular Matrix");
		}
	}

	public int getDim() {

		return this.n;
	}

	public int getElement(int i, int j) throws IndexOutOfBoundsException {

		if ((i < 0 || i >= n) || (j < 0 || j >= n)) {// checks if input is valid
			throw new IndexOutOfBoundsException("Invalid indexes");
		}
		return this.array[i * this.n - i * i / 2 + i / 2 + j - i];
	}

	public void setElement(int x, int i, int j) throws IndexOutOfBoundsException, IllegalArgumentException {
		if ((i < 0 || i >= this.n) || (j < 0 || j >= this.n)) {// checks if input is valid
			throw new IndexOutOfBoundsException("Invalid index");
		}
		if (j < i) {
			if (x != 0) {
				throw new IllegalArgumentException("Incorrect argument");
			}
			return; // returns if j<i since lower half of matrix should not be changed
		}

		this.array[i * this.n - i * i / 2 + i / 2 + j - i] = x;
	}

	public Matrix fullMatrix() {

		int[][] full = new int[this.n][this.n]; // creates new 2d array

		for (int i = 0; i < this.n; i++)
			for (int j = 0; j < this.n; j++)
				full[i][j] = this.getElement(i, j);// assigns values to new matrix

		return new Matrix(full); // returns full as a Matrix object
	}

	public String toString() {
		String output = "";

		for (int i = 0; i < this.n; i++) {// iterates through matrix
			for (int j = 0; j < this.n; j++) {
				if (j < i) {
					output += "0 "; // prints 0 if element is lower half
				} else {
					output += getElement(i, j) + " "; // prints upper elements
				}
			}
			output += "\n"; // creates new row/line
		}

		return output;
	}

	public int getDet() {
		int det = 1;

		for (int i = 0; i < this.n; i++)
			det *= this.getElement(i, i); // multiplies diagonal elements to get determinant

		return det;
	}

	public double[] effSolve(double[] b) throws IllegalArgumentException {

		if (b.length != this.n) {// checks if matrix is proper dimensions
			throw new IllegalArgumentException("The dimension of the matrix is not defined for operation");
		}

		int det = 1;

		for (int i = 0; i < this.n; i++) {// calculates determinant
			det *= this.array[i * this.n - i * i / 2 + i / 2];
		}
		
		if (det == 0) {// checks if determinant is 0
			throw new IllegalArgumentException("The determinant of the matrix is 0");
		}

		double[] sol = new double[b.length];
		sol[sol.length - 1] = b[b.length - 1] / this.array[this.array.length - 1];

		int k = 0, j = 1, i;
		
		//solve using back substitution 
		for (i = this.array.length - 2; i >= 0; i--) {
			if (k >= j) {
				sol[sol.length - 1 - j] = b[b.length - 1 - j] / this.array[i];
				j++;
				k = 0;
			} else {
				k++;
				b[b.length - 1 - j] -= this.array[i] * sol[sol.length - k];
			}
		}
		return sol;
	}
}