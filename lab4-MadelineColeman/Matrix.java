import java.util.Arrays;
import java.util.stream.IntStream;

public class Matrix {
	private int[][] matrixData;
	private int rowsNum;
	private int colsNum;

	public Matrix(int row, int col) {
		if(row <= 0) {// assign number of rows, if 0 assign 3
			this.rowsNum = 3;
		} else {
			this.rowsNum = row;
		}
		
		if(col <= 0) {// assign number of cols, if 0 assign 3
			this.colsNum = 3;
		} else {
			this.colsNum = col;
		}

		this.matrixData = new int[this.rowsNum][this.colsNum];

	}

	public Matrix(int[][] table) {

		int i, j;
		// get num of rows and columns in table
		rowsNum = table.length;
		colsNum = table[0].length;
		matrixData = new int[rowsNum][colsNum];

		// construct new matrix
		for (i = 0; i < rowsNum; i++) {
			for (j = 0; j < colsNum; j++) {
				matrixData[i][j] = table[i][j];
			}
		}
	}

	public int getElement(int i, int j) throws IndexOutOfBoundsException {

		if ((i < 0 || i >= this.rowsNum) || (j < 0 || j >= this.colsNum)) {// checks if input is valid index
			throw new IndexOutOfBoundsException("Invalid indexes.");
		}

		return this.matrixData[i][j];
	}

	public boolean setElement(int x, int i, int j) {

		if ((i < 0 || i >= this.rowsNum) || (j < 0 || j >= this.colsNum)) {// checks if input is valid index
			return false;
		}

		this.matrixData[i][j] = x; // assigns x to position if it is a valid index

		return true;
	}

	public Matrix copy() {

		Matrix copy = new Matrix(this.rowsNum, this.colsNum);// creates matrix of same size

		for (int i = 0; i < this.rowsNum; i++) {
			for (int j = 0; j < this.colsNum; j++) {
				copy.matrixData[i][j] = this.matrixData[i][j];// copies values into new matrix
			}
		}

		return copy;
	}

	public void addTo(Matrix m) throws ArithmeticException {

		if (this.colsNum != m.colsNum || this.rowsNum != m.rowsNum) {// checks if matrix dimensions are the same
			throw new ArithmeticException("Invalid operation");
		}

		for (int i = 0; i < this.rowsNum; i++) {// iterates through matrix
			for (int j = 0; j < this.colsNum; j++) {
				this.matrixData[i][j] += m.getElement(i, j); // adds matrix elements together
			}
		}
	}

	public Matrix subMatrix(int i, int j) throws ArithmeticException {

		if ((i < 0 || i >= this.rowsNum) || (j < 0 || j >= this.colsNum)) {// checks if input is valid index
			throw new ArithmeticException("Submatrix not defined");
		}

		Matrix subM = new Matrix(i + 1, j + 1);

		for (int a = 0; a < i + 1; a++) {
			for (int b = 0; b < j + 1; b++) {
				subM.matrixData[a][b] = this.matrixData[a][b];// copies values into new matrix
			}
		}

		return subM;

	}

	public int getsizeofrows() {

		return this.rowsNum;
	}

	public int getsizeofcols() {

		return this.colsNum;
	}

	public boolean isUpperTr() {

		int i, j;

		for (i = 1; i < this.rowsNum; i++) {// iterates through lower half of matrix and checks if they are all 0
			for (j = 0; j < i && j < this.colsNum; j++) {
				if (this.matrixData[i][j] != 0) {
					return false;
				}
			}
		}

		return true;
	}

	public static Matrix sum(Matrix[] matArray) throws ArithmeticException {

		Matrix superMatrix = new Matrix(matArray[0].rowsNum, matArray[0].colsNum);

		for (Matrix m : matArray) {// sums all matrices in matArray
			superMatrix.addTo(m);
		}

		return superMatrix;
	}

	public String toString() {

		String output = new String();

		int i, j;
		for (i = 0; i < this.rowsNum; i++) {// iterates through each row
			for (j = 0; j < this.colsNum; j++) {// iterates through each column
				output += this.matrixData[i][j] + " ";
			}
			output += "\n";// creates new row
		}

		return output;
	}

}