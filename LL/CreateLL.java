public class CreateLL {
	public Node start;

	CreateLL(Node start) {
		this.start = start;
	}

//It adds an element in the LL in the sorted order.
	public Node addElement(int val) {
		Node newNode = createANode(val);

		// Linked list is empty
		if (start == null) {
			start = newNode;
		} else {
			Node temp = new Node();
			temp = start;
			
			// Insert in the beginning
			if (temp.value >= val) {
				newNode.next = temp;
				start = newNode;
			}

			// Insert somewhere in the middle or end
			else {
				boolean flag = false;
				// Iterate till you get a location
				while ((temp.value < val) && (temp.next != null)) {
					if(temp.next.value > val) {
						//inserting node here in the middle
						newNode.next = temp.next;
						temp.next = newNode;
						flag = true;
						break;
					}
					//not found location, move ahead.
					else
					{
						temp = temp.next;
					}
				}
				//Means insert node in the end now.
				if(!flag) {
					temp.next = newNode;
				}
			}
		}
		return start;
	}

//Function for printing the LL
	public void printLL() {
		Node temp = new Node();
		temp = start;

		while (temp != null) {
			System.out.println(temp.value + " ");
			temp = temp.next;
		}
	}

//Handles deletion of first node separately. Middle and end node deletion are handled together.
	public void deleteElement(int val) {
		Node temp = new Node();
		temp = start;
		
		//check if it is the first node 
		if(temp.value == val) {
			start = temp.next;
			temp.next = null;
			temp = null;
			return;
		}
		
		boolean found = false;
		Node prev = new Node();
		while(temp != null) {
			if(temp.value != val) {
				prev = temp;
				temp = temp.next;
			}
			else {
				prev.next = temp.next;
				temp = null;
				found = true;
				break;
			}
		}
		
		if(!found)
			System.out.println("Node not found\n");
		
	}

	//creates a new node with val
	private Node createANode(int val) {
		Node temp = new Node();
		temp.value = val;
		temp.next = null;
		return temp;
	}
	
	//iterates the LL and returns the length of a LL assuming no loops.
	public int findLen() {
		int count = 0;
		Node temp = new Node();
		temp = start;
		
		while(temp != null) {
			count ++;
			temp = temp.next;
		}
		return count;
	}
	
	/*It find the middle element.
	 Approach 1: Find the length in O(n) and then traverse till length/2.
	 Problem is that LL traversal will happen twice here.
	 
	 Approach 2: Take two pointers, one will be a normal one to traverse a LL
	 Other Pointer will always point to the half length to where first is pointing.
	 Such that when 1 reaches end, 2 reaches mid of LL.*/
	public int findMid(){
		Node temp = new Node();
		Node mid = new Node();
		int count = 0;
		float midv = 0;
		
		temp = start;
		mid = start;
		
		if(temp == null) {
			return 0;
		}
		while(temp != null) {
			
			//count will store the length of the LL
			count++;
			
			//update mid value according to the count
			if(count %2 == 0){
				midv = count/2;
			}
			else {
				midv = count/2+1;
				if(midv != 1)
					mid = mid.next;
			}
			
			temp = temp.next;
		}
		return mid.value;
	}

}
