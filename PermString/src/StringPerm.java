public class StringPerm {

	public static void main(String[] args) {
		String input = "somya";
		
		int len = input.length();
		for(int i=0; i < len; i++) {
			String swapInput = swap(input,i);
			System.out.println(swapInput);
			System.out.println(swapInput.charAt(0)+" "+swapInput.substring(1, len));
		}
	}
	
	static String swap(String inp, int index) {
		char[] ch = inp.toCharArray();
		char temp = ch[0];
		ch[0] = ch[index];
		ch[index] = temp;
		String swappedString = new String(ch);
		return swappedString;
	}
	
	static String printPermutations(char c, String perm) {
		if(perm.length() <= 1) {
			return null;
		}
		else if(perm.length() == 2) {
			//swap both these
			char[] ch = perm.toCharArray();

			// Replace with a "swap" function, if desired:
			char temp = ch[0];
			ch[0] = ch[1];
			ch[1] = temp;

			String swappedString = new String(ch);
			perm = swappedString;
			return perm;
			
		}
		else {
			char fix = perm.charAt(0);
			System.out.println(fix+""+printPermutations(fix, perm.substring(1,perm.length())));
			return null;
			
		}
	}

}
