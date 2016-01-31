public class PolynomialAdditionLL {

	public Node_poly add2Poly(Node_poly n1, Node_poly n2) {
		Node_poly start = null;
		Node_poly end = null;
		
		while(n1 != null && n2 != null) {
			Node_poly n = new Node_poly();
			if(n1.poly == n2.poly) {
				n.poly = n1.poly;
				n.item = n1.item + n2.item;
				n1 = n1.next;
				n2 = n2.next;
			} else if(n1.poly > n2.poly) {
				n.poly = n1.poly;
				n.item = n1.item;
				n1 = n1.next;
			} else {
				n.poly = n2.poly;
				n.item = n2.item;
				n2 = n2.next;
			}
			n.next = null;
			if(start == null) {
				start = n;
				end = n;
			} else {
				end.next = n;
				end = n;
			}
		}
		
		while(n1 != null) {
			
		}
		
		while(n2 != null) {
			
		}
		return start;
	}
	
	public static void main(String[] args) {
		PolynomialAdditionLL p = new PolynomialAdditionLL();
		Node_poly temp = new Node_poly();
		temp.item = 3;
		temp.poly = 1;
		temp.next = null;
		
		Node_poly temp1 = new Node_poly();
		temp1.item = 2;
		temp1.poly = 2;
		temp1.next = temp;
		
		Node_poly temp2 = new Node_poly();
		temp2.item = 1;
		temp2.poly = 4;
		temp2.next = temp1;
		
		Node_poly n1 = temp2;
		Node_poly start1 = n1;
		while(n1 != null) {
			System.out.print(n1.item+"x^"+n1.poly+" ");
			n1 = n1.next;
		}
		
		Node_poly temp3 = new Node_poly();
		temp3.item = 2;
		temp3.poly = 1;
		temp3.next = null;
		
		Node_poly temp4 = new Node_poly();
		temp4.item = 10;
		temp4.poly = 3;
		temp4.next = temp3;
		
		Node_poly temp5 = new Node_poly();
		temp5.item = 1;
		temp5.poly = 5;
		temp5.next = temp4;
		
		System.out.println("\n");
		Node_poly n2 = null;
		n2 = temp5;
		Node_poly start2 = n2;
		while(n2 != null) {
			System.out.print(n2.item+"x^"+n2.poly+" ");
			n2 = n2.next;
		}
				
		System.out.println("\n");
		Node_poly start = p.add2Poly(start1, start2);
		while(start != null) {
			System.out.print(start.item+"x^"+start.poly+" ");
			start = start.next;
		}
	}

}

class Node_poly {
	int item;
	int poly;
	Node_poly next;
}
