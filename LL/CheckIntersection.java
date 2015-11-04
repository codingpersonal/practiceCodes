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
}
