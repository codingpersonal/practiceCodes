
public class Solution {

	static String findMostFrequentChar(String inputString) {
		// assuming only ascii characters. In case of unicode, map needs to be
		// used instead of dense array
		int[] char_freq = new int[125]; // dense array to store the frequency of
										// every char
		int top_char = -1;
		char op_char = 0;
		int itr = 0;

		while (itr < inputString.length()) {
			char curr_char_offset = inputString.charAt(itr);
			char_freq[curr_char_offset] = char_freq[curr_char_offset] + 1;
			if (top_char == -1) {
				top_char = 1;
				op_char = curr_char_offset;
			} else {
				if(top_char < char_freq[curr_char_offset]) {
					top_char = char_freq[curr_char_offset];
					op_char = curr_char_offset;
				}
			}
			itr++;
		}
		return Character.toString((char) op_char);
	}

	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.findMostFrequentChar("SSomya"));
	}

}
