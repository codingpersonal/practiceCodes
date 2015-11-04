using namespace std;
#include <iostream>

void findPos(char c,int *x, int*y, int totCol)
{
	c = c - 'a';
	*x = c/totCol;
	*y = c%totCol;
}

/*It gives the total number of rows/cols for a given col/row
totalAl = total number of alphabets in the langugae.
rowcol = row/col value for which col/row needs to be find out 
totalNumberCol = total number of cols in which user has decided to partition.
*/
int getTotalRCForCurrentCR(int totalAl, int rowcol, int totalNumberCol, int flag)
{
	int fullyFilledRowsCount = totalAl/ totalNumberCol;
	int lastRowElemCount = totalAl % totalNumberCol;
	if(flag) // If flag is true then rowcol = col value and then return the number of rows
	{
		if(!lastRowElemCount)
			return fullyFilledRowsCount;
		else if(rowcol < lastRowElemCount)
			return (fullyFilledRowsCount + 1);
		else return fullyFilledRowsCount;
	}
	else // rowcol = row value and then return the number of cols
	{
		if(rowcol < fullyFilledRowsCount)
			return totalNumberCol;
		else
			return lastRowElemCount;
	}
}

/*Gives the least number of steps to go from one row/col to other row/col
maxSegLen is the total number of rows or columns*/
int getShortestCountInDir(int maxSegLen, int pos1, int pos2)
{
	if(pos2 > maxSegLen)
		return 999;
	int count_1, count_2;
	count_1 = abs(pos1 - pos2);
	count_2 = maxSegLen - count_1;

	if(count_1 <= count_2)
		return count_1;
	else
		return count_2;
}

int getDistance(char c1, char c2, int totalNumberCol, int totalAl)
{
	int row_1, col_1;
	int row_2, col_2;

	findPos(c1,&row_1,&col_1, totalNumberCol);
	findPos(c2, &row_2,&col_2, totalNumberCol);

	//cout<<"\nrow1 = "<<row_1;
	//cout<<"\ncol1 = "<<col_1;

	//cout<<"\n\nrow2 = "<<row_2;
	//cout<<"\ncol2 = "<<col_2;

	int NoOfRowsInSrcCol = getTotalRCForCurrentCR(totalAl, col_1, totalNumberCol,1 );
	int NoOfRowsInDesCol = getTotalRCForCurrentCR(totalAl, col_2, totalNumberCol,1 );

	int NoOfColsInSrcRow = getTotalRCForCurrentCR(totalAl, row_1, totalNumberCol, 0);
	int NoOfColsInDesRow = getTotalRCForCurrentCR(totalAl,row_2, totalNumberCol, 0);

	//cout<<"\nNoOfRowsInSrcCol="<<NoOfRowsInSrcCol;
	//cout<<"\nNoOfRowsInDesCol="<<NoOfRowsInDesCol;
	//cout<<"\nNoOfColsInSrcRow="<<NoOfColsInSrcRow;
	//cout<<"\nNoOfColsInDesRow="<<NoOfColsInDesRow;

	int row_count = 0, col_count = 0;

	cout<<"\nRow and column movements both are possible, move any first.";
	int count1, count2;

	count1 = getShortestCountInDir(NoOfRowsInSrcCol, row_1, row_2) + getShortestCountInDir(NoOfColsInDesRow, col_1, col_2);
	count2 = getShortestCountInDir(NoOfColsInSrcRow, col_1, col_2) + getShortestCountInDir(NoOfRowsInDesCol, row_1, row_2);

	cout<<count1<<" "<<count2;

	if(count1 <= count2)
		return count1;
	else
		return count2;
}

int main_shortest()
{
	char c1,c2;
	int count = 0, count_1 = 0;
	int totalAl = 28;
	int totalNumberCol = 5;

	char *input = new char(10);
	cout<<"\nEnter a string:";
	cin>> input;

	int len = strlen(input);
	cout<<"\nString entered by the user is: "<<input<<" of length: "<<len;

	count = getDistance('a', input[0], totalNumberCol, totalAl);
	cout<<"\nSteps from a to "<<input[0]<<" is: "<<count;

	for(int index = 0; index < (len - 1); index++)
	{
		count_1 =getDistance(input[index], input[index + 1], totalNumberCol, totalAl);
		cout<<"\nSteps from "<<input[index]<<" to "<<input[index + 1]<<" is: "<<count_1;
		count += count_1;
	}

	cout<<"\n\n\nNo. of steps is:"<<count<<"\n\n\n";
	return 0;
}