public class LinkListDriver {

	public static void main(String[] args) {
		
		
		
//		Node n = new Node();
//		n = null;
//		CreateLL c = new CreateLL(n);
//		int val[] = {1,2,3,4,5,6,7,8,9};
//		for(int i=0; i < val.length; i++) {
//			c.addElement(val[i]);
//		}
		
//-------------------------------------------------------------------------------------------------------------------------------------		
		
//		int delEle =90;
//		c.deleteElement(delEle);
//		c.printLL();
		
//--------------------------------------------------------------------------------------------------------------------------------------		
		
//		System.out.println("Length of LL:"+c.findLen());
//		c.printLL();
//		
//--------------------------------------------------------------------------------------------------------------------------------------		
		
//		int mid = c.findMid();
//		if(mid == 0) {
//			System.out.println("Link list is empty");
//		}
//		else {
//			System.out.println("Middle element is:"+mid);
//		}
		
//-----------------------------------------------------------------------------------------------------------------------------------------			
		
//		/*Driver for merging two linked lists*/
//		//n1 will contain the start of ll-1
//		Node n1 = null,n2 = null;
//		CreateLL c1 = new CreateLL(n1);
//		CreateLL c2 = new CreateLL(n2);
//		
//		//input two sorted LL and gives a merged sorted output list.
//		int val1[]={1,3,5,7,10};
//		int val2[] = {};
//		
//		for(int i=0; i< val1.length; i++) {
//			n1= c1.addElement(val1[i]);
//		}
//		
//		for(int i=0; i< val2.length; i++) {
//			n2= c2.addElement(val2[i]);
//		}
//		
//		MergeLL m = new MergeLL();
//		Node n3 = m.mergeSortedLL(n1, n2);
//		while(n3 != null) {
//			System.out.println(n3.value);
//			n3 = n3.next;
//		}

//-----------------------------------------------------------------------------------------------------------------------------------------------		
		
//		/*Driver for Intersecting LL*/
//		//n1 will contain the start of ll-1
//		Node n1 = null,n2 = null, n3 = null;
//		CreateLL c1 = new CreateLL(n1);
//		CreateLL c2 = new CreateLL(n2);
//		CreateLL c3 = new CreateLL(n3);
		
//		//input two sorted LL and gives a merged sorted output list.
//		int val1[]={1,3};
//		int val2[] = {2,3,4};
//		int val3[] = {11,12,13};
//		
//		for(int i=0; i< val1.length; i++) {
//			n1= c1.addElement(val1[i]);
//		}
//		
//		for(int i=0; i< val2.length; i++) {
//			n2= c2.addElement(val2[i]);
//		}
//		
//		for(int i=0; i< val3.length; i++) {
//			n3= c3.addElement(val3[i]);
//		}
//		
//		Node t1,t2;
//		t1 = n1;
//		t2 = n2;
//		
//		while(t1.next != null)
//			t1 = t1.next;
//		
//		while(t2.next != null)
//			t2 = t2.next;
//		
//		t1.next = n3;
//		t2.next = n3;
//		
//		CheckIntersection c = new CheckIntersection(n1, n2);
//		c.checkIntersection();
		
//--------------------------------------------------------------------------------------------------------------------------------------------------
		
	//driver for checking a loop and length of the loop
//		Node n1 = null;
//		CreateLL c1 = new CreateLL(n1);
//		
//		int val1[]={1,2,3,4,5,6,7,8};
//
//		for(int i=0; i< val1.length; i++) {
//			n1= c1.addElement(val1[i]);
//		}
//		
//		//moving t till end of the list.
//		Node t;
//		t= n1;
//		
//		while(t.next != null) {
//			t= t.next;
//		}
//		
////		t.next = n1;
//		
//		//t1 lies somewhere in the middle.
//		//N1 is start
//		//t is at the end
//		Node t1 = n1;
//		t1 = t1.next;
//		t1 = t1.next;
//		t1 = t1.next;
//		t1 = t1.next;
//		
//		t.next = t1;
//		
//		
//		LLLoop l = new LLLoop();
//		l.checkLoop(n1);
//		
//		
		
//-------------------------------------------------------------------------------------------------------------------------------------------------
		
		LLReverse rev = new LLReverse();
		Node startNode = null;

		CreateLL cll = new CreateLL(startNode);
		
		int val1[]={1,2,3,4,5};

		for(int i=0; i< val1.length; i++) {
			startNode= cll.addElement(val1[i]);
		}
		System.out.println("Original LL:");
		cll.printLL(startNode);
		
		Node newStart = rev.reverseList(startNode);
		
		System.out.println("\nReversed LL:");
		cll.printLL(newStart);
	}

}
