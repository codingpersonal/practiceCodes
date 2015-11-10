public class StringPerm {

	public static void main(String[] args) {
		String input = "somya";
		char ip[] = input.toCharArray();
		printPermutations(ip, 0, input.length());
		System.out.println("perms are: " +  cc);
	}
		
	static void printString(char[]c , int size) {
		System.out.println(String.valueOf(c));
	}
	static int cc = 0;
	
	static void printPermutations(char[] c, int start, int inputSize) {
		if(start == inputSize -1) {
			cc++;
			printString(c, inputSize);
		}
		else {
			for(int i = start; i < inputSize; i++) {
				
				char temp = c[start];
				c[start] = c[i];
				c[i] = temp;

				printPermutations(c, start + 1, inputSize);

				temp = c[start];
				c[start] = c[i];
				c[i] = temp;
			}
		}
	}
}
