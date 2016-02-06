
public class FlattenLL {
	LLNode head;

	public static void main(String[] args) {
		/*Input driver taken from internet*/
		FlattenLL L = new FlattenLL();
		L.head = L.push(L.head, 30);
        L.head = L.push(L.head, 8);
        L.head = L.push(L.head, 7);
        L.head = L.push(L.head, 5);
 
        L.head.right = L.push(L.head.right, 20);
        L.head.right = L.push(L.head.right, 10);

        L.head.right.right = L.push(L.head.right.right, 50);
        L.head.right.right = L.push(L.head.right.right, 22);
        L.head.right.right = L.push(L.head.right.right, 19);
 
        L.head.right.right.right = L.push(L.head.right.right.right, 45);
        L.head.right.right.right = L.push(L.head.right.right.right, 40);
        L.head.right.right.right = L.push(L.head.right.right.right, 35);
        L.head.right.right.right = L.push(L.head.right.right.right, 20);
        
        L.head = L.flatten(L.head);
        LLNode temp = L.head;
        while (temp != null)
        {
            System.out.print(temp.item + " ");
            temp = temp.right;
        }
        System.out.println();        
	}
	
	/*Input driver taken from internet*/
	 LLNode push(LLNode head_ref, int data)
	    {
	        /* 1 & 2: Allocate the Node &
	                  Put in the data*/
	        LLNode new_node = new LLNode(data);
	 
	        /* 3. Make next of new Node as head */
	        new_node.down = head_ref;
	 
	        /* 4. Move the head to point to new Node */
	        head_ref = new_node;
	 
	        /*5. return to link it back */
	        return head_ref;
	    }
	 
	 //it merges two LL, where a is a down LL and b is a right LL
	 //both LL are sorted, merge back in a sorted manner too.
	 //returns the head of the merged LL in the right hand side manner.
	 public LLNode merge(LLNode a, LLNode b) {
		 LLNode start = null;
		 if(a == null) {
			 return b;
		 } 
		 
		 //then simply convert the down LL to right LL
		 else if(b == null) {
			 start = a;
			 while(a != null) {
				 a.right = a.down;
				 a = a.down;
			 }
			 //now all the nodes still do have down pointers set.
			 //reset them back to null
			 a = start;
			 while(a != null) {
				 a.down = null;
				 a = a.right;
			 }
			 return start;
			 
			 //if both the lists are present
		 } else {
			 LLNode n;
			 start = null;
			 LLNode currNode = null;
			 while(a != null && b != null) {
				 if(a.item >= b.item) {
					n = new LLNode(b.item);
					 b = b.right;
					 if(start == null) {
						 start = n;
						 currNode = n;
					 }
					 else {
						 currNode.right = n;
						 currNode = n;
					 }
				 } else {
					 n = new LLNode(a.item);
					 a = a.down;
					 if(start == null)
						 start = n;
					 else
						 currNode.right = n;
					 currNode = n;
				 }
			 }
			 
			 while(a != null) {
				 n = new LLNode(a.item);
				 a = a.down;
				 currNode.right = n;
				 currNode = n;
			 }
			 
			 while(b != null){
				 n = new LLNode(b.item);
				 b = b.right;
				 currNode.right = n;
				 currNode = n;
			 }
		 }
		return start;
	 }
	 
	 public LLNode flatten(LLNode head) {
		 if(head == null) {
			 return head;
		 }
		 head.right = flatten(head.right);
		 head = merge(head,head.right);
		 return head;
	 }
}

class LLNode {
	int item;
	LLNode right;
	LLNode down;
	LLNode(int data)
     {
         this.item = data;
         right = null;
         down = null;
     }
}
