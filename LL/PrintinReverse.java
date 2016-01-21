public class PrintinReverse {
	
	public void printInReverse(Node node) {
		if(node.next != null) {
			printInReverse(node.next);
		}
		System.out.print(node.value + " ");
	}

	public static void main(String args[]) {
		Node startNode = null;
		CreateLL cll = new CreateLL(startNode);
		int val1[]={1,2,3,4,5};
		for(int i=0; i< val1.length; i++) {
			startNode= cll.addElement(val1[i]);
		}
		System.out.println("Original LL:");
		cll.printLL(startNode);
		
		System.out.println("\nReverse LL:");
		PrintinReverse p = new PrintinReverse();
		p.printInReverse(startNode);
	}
}
