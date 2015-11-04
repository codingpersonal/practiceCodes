#include "FileUtils.h"
#include<conio.h>

int main()
{
	string line;
	FileUtils f_obj("C:\\Users\\somya\\Downloads\\input.txt");
	while(f_obj.readNextLine(line))
	{
		std::cout<<line<<"\n";
	}

	getch();
	return 0;
}