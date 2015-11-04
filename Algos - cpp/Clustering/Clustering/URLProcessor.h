#include<vector>
#include"FileUtils.h"
#include<map>
#include<string>

using namespace std;
typedef map<string, double> mapsi;

struct docInfo
{
	string docURL;
	int wordCount;
};

class URLProcessor
{
public:
	//constructor of the class
	URLProcessor(string URLPath);		//currently, its file path

	//destructor of the class
	~URLProcessor();

	//fills the map having word to frequency mapping and generates the info for the struct as well
	void generateNormalizedWordFrequency(mapsi &currDocWordFreqMap, docInfo &outURLInfo, mapsi &wordToAllDocumentFreqMap);

private:
	string URLPath;
	int totalWordsCount;

	//populates the map for word to the frequency
	void populateWordToFreqMap(mapsi &outMap,mapsi &wordToAllDocumentFreqMap);

	//updates the map to store the normalised freq for each word
	//normalised freq = freq of the word/ no of words in that document.
	void updateMapToStoreNormalisedFreq(mapsi &outMap);
};

