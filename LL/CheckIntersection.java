public class CheckIntersection {

	Node first;
	Node second;
	
	public CheckIntersection(Node first, Node second) {
		this.first = first;
		this.second = second;
	}
	
	/*Checks if two LL intersects.
	 Two cases are possible:
	 1. They make \ such that only one node is common (last one)
	 			  /
	 2. They make \___ such that more than 1 nodes are common
	 			  /
	 Approach 1: Traverse the 1 LL and stores its nodes in a set.
	 Traverse LL 2 and check if each node in LL2 lies in set (LL1)
	 Problem is that it takes an additional space O(n)
	 
	 Approach2: Traverse LL 1 to the end. Traverse LL 2 in the end.
	 If they intersect , in both cases they will point to the same end node.
	 They share a common end node here
	 */
	public void checkIntersection() {
		Node tfirst, tsecond;
		tfirst = first;
		tsecond = second;
		
		if((tfirst == null)|| (tsecond == null)){
			System.out.println("One of the LL is empty!");
			return;
		}
		while(tfirst.next != null)
			tfirst = tfirst.next;
		while(tsecond.next != null)
			tsecond = tsecond.next;
		
		if(tfirst == tsecond)
			System.out.println("These linked lists are linked! They intersect.");
		else
			System.out.println("They are not linked or intersecting");
	}
	
	//assuming that 2 LL intersect each other. Find the starting point where the LL intersection starts.
	public Node findStartIntersectionPoint() {
		//find the length of first LL
		Node tfirst = first;
		Node tsecond = second;
		int count_1 = 0; 
		int count_2 = 0;
		
		int diff = 0;
		int longer = 0;
		
		while(tfirst != null){
			count_1++;
			tfirst = tfirst.next;
		}
		
		//find the length of second LL
		while(tsecond != null){
			count_2++;
			tsecond = tsecond.next;
		}
		
		if(count_1 > count_2) {
			diff = count_1 - count_2;
			longer = 1;
		} else {
			diff = count_2 - count_1;
			longer = 2;
		}
		
		tfirst = first;
		tsecond = second;
		
		if(longer == 1) {
			while(diff != 0) {
				tfirst = tfirst.next;
				diff--;
			}
		} else if(longer == 2) {
			while(diff != 0) {
				tsecond = tsecond.next;
				diff--;
			}
		}
		
		while(tfirst != null || tsecond != null) {
			if(tfirst == tsecond) {
				return tfirst;
			} else {
				tfirst = tfirst.next;
				tsecond = tsecond.next;
			}
		}
		
		return null;
	}
	
	public static void main(String args[]) {
		/*Driver for Intersecting LL*/
		//n1 will contain the start of ll-1
		Node n1 = null,n2 = null, n3 = null;
		CreateLL c1 = new CreateLL(n1);
		CreateLL c2 = new CreateLL(n2);
		CreateLL c3 = new CreateLL(n3);

		//input two sorted LL and gives a merged sorted output list.
		int val1[]={1,3,5};
		int val2[] = {2,3,4};
		int val3[] = {10};
		
		for(int i=0; i< val1.length; i++) {
			n1= c1.addElement(val1[i]);
		}
		
		for(int i=0; i< val2.length; i++) {
			n2= c2.addElement(val2[i]);
		}
		
		for(int i=0; i< val3.length; i++) {
		n3= c3.addElement(val3[i]);
	}

		Node t1,t2;
		t1 = n1;
		t2 = n2;
		
		while(t1.next != null)
			t1 = t1.next;
		
		while(t2.next != null)
			t2 = t2.next;
		
		t1.next = n3;
		t2.next = n3;
		
		CheckIntersection c = new CheckIntersection(n1, n2);
		c.checkIntersection();
		System.out.println(c.findStartIntersectionPoint().value);
	}
}
