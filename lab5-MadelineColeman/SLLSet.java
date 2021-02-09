
public class SLLSet {
	private int size;
	private SLLNode head;

	public SLLSet() {// constructs empty set
		this.size = 0;
		this.head = null;

	}

	public SLLSet(int[] sortedArray) {
		if (sortedArray.length > 0) {// checks if there are elements in the array
			SLLNode element = new SLLNode(sortedArray[0], null);
			this.size = sortedArray.length;
			this.head = element;
			for (int i = 1; i < sortedArray.length; i++) {
				element.next = new SLLNode(sortedArray[i], null);
				element = element.next;
			}
		} else {// runs if array is empty
			this.size = 0;
			this.head = null;
		}

	}

	public int getSize() {

		return size;
	}

	public SLLSet copy() {
		int[] list = new int[size];// create new empty list
		int i = 0;
		SLLNode element = head;
		while (element != null) {// copy list one item at a time
			list[i] = element.value;
			element = element.next;
			i++;
		}
		SLLSet set = new SLLSet(list);
		set.size = size;

		return set;
	}

	public boolean isIn(int v) {
		SLLNode element = head;
		while (element != null) {// iterates through array
			if (element.value == v) {// checks if v is in array
				return true;
			}
			element = element.next;
		}
		return false;
	}

	public void add(int v) {
		SLLNode p = head;
		if (this.isIn(v) == false) { // checks if v is already present
			if (head == null) {
				head = new SLLNode(v, null);
			} else if (head.value > v) { // deals with case where list is empty before add
				head = new SLLNode(v, head);
			} else {
				int x;
				while (p.next != null) {// sorts list so x is in correct spot
					x = p.next.value;
					if (v < x && v > p.value) {
						p.next = new SLLNode(v, p.next);
					}
					p = p.next;
				}
				if (v > p.value) {
					p.next = new SLLNode(v, null);
				}
			}
			size++;
		}
	}

	public void remove(int v) {
		SLLNode p = head;
		if (isIn(v)) {// checks if v is in list
			size--;
			if (p.value == v) { // changes head if v is first value
				this.head = p.next;
			} else {
				while (p != null) { // rearranges list/moves items behind v up a spot
					if (p.next == null) {
						break;
					} else if (p.next.value == v) {
						p.next = p.next.next;
						break;
					}
					p = p.next;
				}
			}
		}
	}

	public SLLSet union(SLLSet s) {
		SLLSet union = this.copy();
		SLLNode j = s.head;

		if (s.head != null) {
			while (j != null) {
				union.add(j.value); // use add function to add each value of j to union
				j = j.next;
			}
		}

		return union;
	}

	public SLLSet intersection(SLLSet s) {
		SLLSet inter = new SLLSet(); // create list to store intersecting value
		SLLNode p = this.head;
		SLLNode q = s.head;

		if (q != null || p != null) {
			while (p != null) {
				q = s.head;
				while (q != null) {
					if (p.value == q.value) {
						inter.add(p.value); // add value to inter if it is in both lists
					}
					q = q.next;
				}
				p = p.next;
			}
		}

		return inter;
	}

	public SLLSet difference(SLLSet s) {

		if (this.head == null || s.head == null)
			return this;
		SLLSet ss = copy();

		for (SLLNode e = s.head; e != null; e = e.next)// Remove all values that are in both lists
			ss.remove(e.value);

		return ss;
	}

	public static SLLSet union(SLLSet[] sArray) {
		SLLSet ss = new SLLSet();

		for (int i = 0; i < sArray.length; i++) {
			ss = ss.union(sArray[i]);
		}

		return ss;
	}

	@Override
	public String toString() {
		SLLNode elmt = head;
		String s = "";

		while (elmt != null) {// iterates through array
			s += elmt.value;// prints each element
			elmt = elmt.next;
			if (elmt != null) {
				s += ", ";
			}
		}

		return s;
	}

}
