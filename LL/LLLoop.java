public class LLLoop {
	
	/*To check the loop in the LL.
	 Take 2 pointers, one will be master, other is slave.
	 Master will move at a normal speed.
	 Slave will move at half the speed, ie it will lie in the mid of where master is.
	 
	 If loop exists, at some point of time, they will meet.
	 If not, LL will end as master.next = null.
	 */
	public void checkLoop(Node start) {
		Node temp;
		Node mid;
		int count = 0;
		float midv = 0;
		boolean loop = false;
		
		temp = start;
		mid = start;
		
		while(temp != null) {
			//special case
			if(temp.next == temp) {
				System.out.println("Self loop exists. Loop found of length 1");
				return;
			}
			temp = temp.next;
			
			//count will store the current length of the LL and position of temp
			count++;
			
			//update mid value according to the count
			if(count %2 == 0){
				midv = count/2;
			}
			else {
				//midv lays at half of count and position of mid
				midv = count/2+1;
				if(midv != 1)
					mid = mid.next;
			}
			
			if(temp == mid) {
				int length = lenLoop(temp,mid);
				System.out.println("Loop exists of length:"+length);
				loop = true;
				break;
			}
		}
		if(!loop)
			System.out.println("No Loop exists in this LL");
	}
	
	/*When A and B meets, one waits there and other goes a complete round and comes back.
	 Count the length when it meets B again.
	 That will be the length of the loop*/
	public int lenLoop(Node temp, Node mid) {
		int count = 1;
		while(temp.next != mid) {
			temp = temp.next;
			count++;
		}
		return count;
	}
}
