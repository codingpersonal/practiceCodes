import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

public class ProcessAnagrams {

	public ArrayList<ArrayList<String>> getAnagramsGroup(List<String> words) {
		HashMap<String, HashMap<Character, Integer>> wordMapsList = new HashMap<String, HashMap<Character, Integer>>();
		ArrayList<ArrayList<String>> groupedList = new ArrayList<>();

		for (int i = 0; i < words.size(); i++) {
			HashMap<Character, Integer> map = new HashMap<Character, Integer>();
			String currWord = words.get(i);
			map = parseWord(currWord);
			wordMapsList.put(currWord, map);
		}

		groupedList = formGroups(wordMapsList);
		return groupedList;
	}

	private HashMap<Character, Integer> parseWord(String word) {
		HashMap<Character, Integer> charToFreq = new HashMap<Character, Integer>();
		for (int index = 0; index < word.length(); index++) {
			char c = word.charAt(index);
			if (charToFreq.containsKey(c)) {
				int freq = charToFreq.get(c);
				freq += 1;
				charToFreq.put(c, freq);
			} else {
				charToFreq.put(c, 1);
			}
		}
		return charToFreq;
	}

	// ip is map from word to the hashmap of its char frequencies
	// e.g., key is "car", value is { ('c',1) , ('a', 1), ('r', 1) }
	
	// TODO: densify the hash map. Array of 26 elements can also be taken
	private ArrayList<ArrayList<String>> formGroups(HashMap<String, HashMap<Character, Integer>> ip) {

		ArrayList<ArrayList<String>> op = new ArrayList<>();

		while (!ip.isEmpty()) {
			ArrayList<String> group = new ArrayList<String>();

			// get the iterator first
			Iterator<Entry<String, HashMap<Character, Integer>>> iter = ip.entrySet().iterator();

			// get the first entry from iter and its hash
			Entry<String, HashMap<Character, Integer>> entry = iter.next();

			// get the first key and value
			String key = entry.getKey();
			HashMap<Character, Integer> value = entry.getValue();

			// remove that first element using iterator.
			group.add(key);
			iter.remove();

			while (iter.hasNext()) {
				// get all strings which match the key
				Entry<String, HashMap<Character, Integer>> itr = iter.next();
				String key_1 = itr.getKey();
				HashMap<Character, Integer> value_1 = itr.getValue();

				if (value.equals(value_1)) {
					group.add(key_1);
					iter.remove();
				}
			}
			op.add(group);
		}
		return op;
	}
}
