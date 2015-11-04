#include "tfidf.h"

#include<math.h>
#include<string>
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
	vector< map<string,float> >::const_iterator it = wordToFreq.begin();
	map<string,float> currWordList;

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

void tfidf::storeIdfInVectorForSearchQuery(string word, double idf,  map<string,double>&outMap){
	outMap[word] = idf;
}

void tfidf::addURLInfo(mapsi wordsFreq, docInfo documentDetail, int docId){
	wordToFreq.push_back(wordsFreq);

	IdToDocInfo[docId] = documentDetail;
}

void tfidf::generateIdf(string word, map<string,double>&outMap){

	//finds out the number of docs having word in it
	int count = docsWithSearchQuery(word);

	//calcualtes the odf value for the word
	double idf = computeIdf(count);

	storeIdfInVectorForSearchQuery(word,idf,outMap);
}