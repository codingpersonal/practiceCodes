import java.util.ArrayList;
import java.util.List;

public class AnagramDriver {

	public static void main(String[] args) {
		ArrayList <String>words = new ArrayList<>();
		ArrayList<ArrayList<String>> op = new ArrayList<>();
		
		words.add("cat");
		words.add("act");
		words.add("car");
		words.add("arc");
		words.add("rac");
		ProcessAnagrams pa = new ProcessAnagrams();
		op = pa.getAnagramsGroup(words);
		for(int i=0; i< op.size(); i++) {
			for(int j=0; j < op.get(i).size(); j++) {
				System.out.println(op.get(i).get(j));
			}
			System.out.println("----");
		}
	}
}
