
public class MergeLL {
	public Node mergeSortedLL(Node first, Node second) {
		Node start = null; //it will point to the start of the new LL
		Node temp = null;
		start = temp;
		
		while((first != null) && (second != null)) {
			Node temp1 = new Node();
			if(first.value <= second.value) {
				temp1.value = first.value;
				first = first.next;
			}
			else {
				temp1.value = second.value;
				second = second.next;
			}
			temp1.next = null;
			
			//check for first node in the LL
			if(temp == null) {
				temp = temp1;
				start = temp;
			}
			else {
				temp.next = temp1;
				temp = temp1;
			}
		}
		
		//One of the LL ends. If its first one, then copy all the remaining nodes to new LL
		if(first != null) {
			while(first != null) {
				Node temp1 = new Node();
				temp1.value = first.value;
				temp1.next = null;
				
				first = first.next;
				//This came will come if second list came to be empty.
				//So here you handling the first node case as well.
				if(temp == null) {
					temp = temp1;
					start = temp;
				}
				else {
					temp.next = temp1;
					temp = temp1;
				}
			}
		}
		
		if(second != null) {
			while(second != null) {
				Node temp1 = new Node();
				temp1.value = second.value;
				temp1.next = null;
				
				second = second.next;
				//This came will come if first list came to be empty.
				//So here you handling the first node case as well.
				if(temp == null) {
					temp = temp1;
					start = temp;
				}
				else {
					temp.next = temp1;
					temp = temp1;
				}
			}
		}
		
		return start;
	}
}
