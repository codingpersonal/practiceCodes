
public class MidElementLL {
	public void findMidElement(Node start){
		Node master = start;
		Node slave = start;
		if(start != null) {
			while(master.next != null && master.next.next != null) {
				master = master.next.next;
				slave = slave.next;
			}
			System.out.println("Mid element is:"+slave.value);
		} else {
			System.out.println("empty list.");
		}
	}
	
	public static void main(String[] args) {
		Node startNode = null;
		CreateLL cll = new CreateLL(startNode);
		
		int val1[]={1};
		for(int i=0; i< val1.length; i++) {
			startNode= cll.addElement(val1[i]);
		}
		
		MidElementLL m = new MidElementLL();
		m.findMidElement(null);
	}

}
