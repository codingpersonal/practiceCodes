
public class LLReverse {

	// this function will return a start connecting to a LL
	Node reverseList(Node startNode) {
		if (startNode == null) {
			return null;
		}
		// assuming newStart is the pointer to the new LL, add the existing node to the end.
		Node newStart = reverseList(startNode.next);

		// this is the first node to be processed
		if (newStart == null) {
			newStart = startNode;
		}
		// else insert in the end
		else {
			Node lastNode = startNode.next; //it will be the last node of the reversed LL
			lastNode.next = startNode;
			startNode.next = null;
		}
		return newStart;
	}

}
