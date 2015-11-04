#include<iostream>
#include<string>
#include"URLProcessor.h"

using namespace std;

URLProcessor::URLProcessor(string inURLPath):URLPath(inURLPath), totalWordsCount(0) {
}

void URLProcessor::generateNormalizedWordFrequency(mapsi &outMap, docInfo &outURLInfo,mapsi &wordToAllDocumentFreqMap){

	//populates the word to its frequency mapping for the current document
	populateWordToFreqMap(outMap,wordToAllDocumentFreqMap);

	//update the frequency to store the normalised frequency now
	updateMapToStoreNormalisedFreq(outMap);

	//populates the strcuture of the document info
	outURLInfo.docURL = URLPath;
	outURLInfo.wordCount = totalWordsCount;
}

void URLProcessor::populateWordToFreqMap(mapsi &outMap,mapsi &wordToAllDocumentFreqMap){
	outMap.clear();

	float freq;
	std::string word;

	FileUtils f_obj(URLPath);
	while(f_obj.readNextWord(word,totalWordsCount)){

		//removing non alpha numeric chars from this word
		f_obj.removeNonAlphaNumChars(word);

		//convert incoming chars to lowercase so as no duplicate copy is created
		f_obj.convertToLower(word);

		//checking if it does exist already
		if(outMap.count(word) > 0){
			outMap[word]++;
		}
		else{
			//adding the entry in the map
			outMap[word] = 1;
			if(wordToAllDocumentFreqMap.count(word) > 0) {
				wordToAllDocumentFreqMap[word]++;
			} else {
				wordToAllDocumentFreqMap[word] = 1;
			}
			
		}
	}
}

void URLProcessor::updateMapToStoreNormalisedFreq(mapsi &outMap){

	//iterate the map for the currDoc to update the frequency of each word
	map<string,double>::iterator it = outMap.begin();
	while(it != outMap.end()){
		it->second = (it->second) / totalWordsCount;
		it++;
	}
}

URLProcessor::~URLProcessor(){
}