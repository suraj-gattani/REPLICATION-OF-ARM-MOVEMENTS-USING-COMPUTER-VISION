#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include "SerialClass.h"	// Library described above
#include <string>

// application reads from the specified serial port and reports the collected data
int _tmain()
{
	printf("Welcome to the serial test app!\n\n");

	Serial* SP = new Serial("COM3");    // adjust as needed

	if (SP->IsConnected())
		printf("We're connected\n");
	else
	{
		printf("Serial not connected... continuing without\n");
		//return -1;
	}
	BOOL bDirection = 0;
	BYTE iDegree = 0;
	UCHAR ang = 0;
	UINT j = 0;
	int i = 0;
	
	while (SP->IsConnected())
	{
		
		char degree[10] = "";
		//_itoa_s(iDegree, degree, 10);
		//printf("degree : %s\n", degree);
        //SP->WriteData(degree, strlen (degree));
		
		/*while (0 == SP->ReadData((char *)&ang, 1))
		{
			// printf("waiting for data...\n");
		}
		printf("angle returned %d\n", ang);*/
		/*if (bDirection)
			iDegree -= 10;
		else
			iDegree += 10;
		if (iDegree == 180)
		{
			bDirection = 1;
		}
		else if (iDegree == 0)
		{
			bDirection = 0;
		}*/
		while (1)
		{
			if ( i==0)
			{
				iDegree =180;
				
				Sleep(1000);
				i = 1;
				printf("degree : %d\n", iDegree);
			}
			else if (i==1)
			{
				iDegree = 72;
				Sleep(1000);
				i = 2;
				
				printf("degree : %d\n", iDegree);
			}
			else if (i==2)
			{
				iDegree = 172;
				Sleep(1000);
				i = 3;
				
				printf("degree : %d\n", iDegree);
			}
			else if (i==3)
			{
				iDegree = 42;
				Sleep(1000);
				i = 4;
				
				printf("degree : %d\n", iDegree);
			}
			else if(i==4)
			{
				iDegree = 142;
				Sleep(1000);
				i = 0;
				printf("degree : %d\n", iDegree);
			}
			SP->WriteData((char *)&iDegree, 1);
		}
	}
	return 0;
}

