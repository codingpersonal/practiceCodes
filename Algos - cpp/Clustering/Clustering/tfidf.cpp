#include "tfidf.h"

#include<math.h>
#include<iostream>


using namespace std;

tfidf::tfidf(int docCount):numOfDocs(docCount){
}

tfidf::~tfidf(){
}

double tfidf::computeIdf(int docWithSearchTerm)
{
	if(docWithSearchTerm == 0)
		return -1;
	else
		return(log(double(numOfDocs)/docWithSearchTerm));
}

int tfidf::docsWithSearchQuery(string word){
	int count = 0;
	vector< map<string,double> >::const_iterator it = wordToFreq.begin();
	map<string,double> currWordList;

	while(it != wordToFreq.end()){
		currWordList.empty();
		currWordList = (*it);
		if(currWordList.count(word) > 0){
			count++;
		}
		it++;
	}
	return count;
}

void tfidf::computeTfidfForAllWords(mapsi &wordToAllDocumentFreqMap){
	vector< map<string,double> >::iterator it = wordToFreq.begin();
	map<string,double> norFreqMap;
	map<string,double> idfMap;
	multimap<double,string> tfidfMap;

	while(it != wordToFreq.end()){
		
		//resetting these temp maps here
		idfMap.clear();
		tfidfMap.clear();
		norFreqMap.clear();

		norFreqMap = (*it);
		
		//after this function, the idfmap will contain all the idf values for all the words in the currWordList Map
	 	populateIdfMapForCurrDoc(norFreqMap,wordToAllDocumentFreqMap);

		//call this fn to update the tfidf map using norFreqMap and idfMap
		populateTfIdfMapForCurrDoc(norFreqMap, wordToAllDocumentFreqMap, tfidfMap);

		//updating the vector now containing the multimaps of all docs[tfidf- word]
		tfidfVec.push_back(tfidfMap);

		it++;
	}
}

void tfidf::populateIdfMapForCurrDoc(map<string,double>norFreqMap, map<string,double>&idfMap){
	map<string,double>::iterator it = norFreqMap.begin();
	while(it != norFreqMap.end()){
		string word = it->first;
		int occurence = idfMap[word];

		//It updates the incoming map with the idf. Incoming map is a global map containing the [word-occurence in how many docs] map
		double idf = computeIdf(occurence);
		idfMap[word] = idf;

		it++;
	}
}

void tfidf::populateTfIdfMapForCurrDoc(map<string,double>norFreqMap, map<string,double>idfMap, multimap<double,string>&tfidfMap){
	map<string,double>::const_iterator it = norFreqMap.begin();
	while(it != norFreqMap.end()){
		std::string word = it->first;
		double norFreq = it->second;
		double idf = idfMap[word];

		//calculate the tfidf val and push in the tfidf map
		double tfidf = norFreq * idf;
		tfidfMap.insert(std::pair<double,string>(tfidf,word));

		it++;
	}
}

void tfidf::storeIdfInVectorForSearchQuery(string word, double idf,  map<string,double>&outMap){
	outMap[word] = idf;
}

void tfidf::addURLInfo(mapsi wordsFreq, docInfo documentDetail, int docId){
	wordToFreq.push_back(wordsFreq);

	IdToDocInfo[docId] = documentDetail;
}

void tfidf::generateIdf(string word, map<string,double>&outMap){

	////finds out the number of docs having word in it
	//int count = docsWithSearchQuery(word);

	////calcualtes the odf value for the word
	//double idf = computeIdf(count);

	//storeIdfInVectorForSearchQuery(word,idf,outMap);
}

void tfidf::printIdfMap(){
	ofstream outfile;
	outfile.open ("E:\\Learning\\C++\\Clustering\\OutputFiles\\idf.txt");
	vector<map<string,double>>::const_iterator it = idfVec.begin();
	map<string,double> outMap;

	while(it != idfVec.end()){
		outMap.clear();
		outMap = *it;
		map<string,double>::const_iterator it1 = outMap.begin();
		outfile<<"\n\n";
		while(it1 != outMap.end()){
			outfile<<it1->first<<"->"<<it1->second<<"\n";
			it1++;
		}
		it++;
	}
}

void tfidf::printTfidfMap(){
	/*ofstream outfile;
	outfile.open ("E:\\Learning\\C++\\Clustering\\OutputFiles\\tfidf.txt");
	vector<multimap<double,string>>::iterator it = tfidfVec.begin();
	multimap<double,string> outMap;

	while(it != tfidfVec.end()){
		outMap.clear();
		outMap = *it;
		map<double,string>::iterator it1 = outMap.begin();
		outfile<<"\n\n";
		while(it1 != outMap.end()){
			outfile<<it1->first<<"->"<<it1->second<<"\n";
			it1++;
		}
		it++;
	}*/
}