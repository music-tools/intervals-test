#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char* randInterval(void)
{
    int y;
    y=rand()%7; /*7 different intervals(no octave:P)*/
	switch (y)
	{
		case 0:
			{
				return ("major 2nd");
			}
		case 1:
			{
				return ("major 3rd");
			}
		case 2:
			{
				return ("perfect 4th");
			}
		case 3:
			{
				return ("perfect 5th");
			}
		case 4:
			{
				return ("major 6th");
			}
		case 5:
			{
				return ("major 7th");
			}
		case 6:
			{
				return ("major 9th");
			}
		default:
			{
				return ("ERROR(in randInterval)");
			}
	}
}

char* randKeySignature(void)
{
	int k;
    k=rand()%15; /*15 different key signatures*/
	switch (k)
	{
		case 0:
			{
				return ("C");
			}
		case 1:
			{
                return ("C#");
			}
		case 2:
			{
				return ("Db");
			}
		case 3:
			{
                return ("D");
			}
		case 4:
			{
                return ("Eb");
			}
		case 5:
			{
                return ("E");
			}
		case 6:
			{
				return ("F");
			}
		case 7:
			{
                return ("F#");
			}
		case 8:
			{
                return ("Gb");
			}
		case 9:
			{
                return ("G");
			}
		case 10:
			{
                return ("Ab");
			}
		case 11:
			{
                return ("A");
			}
		case 12:
			{
                return ("Bb");
			}
		case 13:
			{
                return ("B");
			}
		case 14:
			{
                return ("Cb");
			}
		default:
			{
				return ("ERROR(in randKey)");
			}
	}
}

char* findInterval(char* keySignature,char* interval,char* ret)
{
    char Notes[40][6]={"B#/C","C#/Db","D","D#/Eb","E/Fb","E#/F","F#/Gb","G","G#/Ab","A","A#/Bb","B/Cb","B#/C","C#/Db","D","D#/Eb","E/Fb","E#/F","F#/Gb","G","G#/Ab","A","A#/Bb","B/Cb","B#/C","C#/Db","D","D#/Eb","E/Fb","E#/F","F#/Gb","G","G#/Ab","A","A#/Bb","B/Cb"};
	int k=0,rootPos,interPos,semitones;
	char sharpy[2];
	char flatty[2];
	
	
	/*find root in Notes[]*/
	while (k<40)
	{
		if (strlen(Notes[k])!=1) /*2 options(sharp/flat)*/
		{
			if (Notes[k][1]=='#')
	        {
				sharpy[0]=Notes[k][0];
	            sharpy[1]=Notes[k][1];
	            
	            printf(" \n THIS IS %s THAT IS %s\n",sharpy,keySignature);
	            printf("\n 1)%c <> %c \n 2)%c <> %c \n 3)%c <> %c \n",sharpy[0],keySignature[0],sharpy[1],keySignature[1],sharpy[2],keySignature[2]);
	            if (Notes[k][4]=='b')
				{
					flatty[0]=Notes[k][3];
		            flatty[1]=Notes[k][4];
				}
				else
				{
		            flatty[0]=Notes[k][3];
				}
			}
			else
			{
	            sharpy[0]=Notes[k][0];

	            flatty[0]=Notes[k][2];
		        flatty[1]=Notes[k][3];
			}
			
            printf(" \n !THIS IS %s THAT IS %s\n",sharpy,keySignature);
	        printf("\n !1)%c <> %c \n 2)%c <> %c \n 3)%c <> %c \n",sharpy[0],keySignature[0],sharpy[1],keySignature[1],sharpy[2],keySignature[2]);

			printf("\n result of strcmp = == = %d OR OR %d \n",strcmp(sharpy,keySignature),strcmp(flatty,keySignature));
            if ( (strcmp(flatty,keySignature)==0) || (strcmp(sharpy,keySignature)==0) )
			    break;
		}
		else /*All pure*/
		{
            
            if (strcmp(Notes[k],keySignature)==0)
			    break;
		}
		k++;
	}
	rootPos=k;
	printf("\n ****");
	printf(" root =%d || %s **** \n",rootPos,Notes[rootPos]);
	
	
	/*calculate No of semitones from root*/
	if (strcmp(interval,"major 2nd")==0)
	{
        semitones=2;
	}
	else if (strcmp(interval,"major 3rd")==0)
	{
        semitones=4;
	}
	else if (strcmp(interval,"perfect 4th")==0)
	{
        semitones=5;
	}
	else if (strcmp(interval,"perfect 5th")==0)
	{
        semitones=7;
	}
	else if (strcmp(interval,"major 6th")==0)
	{
        semitones=9;
	}
	else if (strcmp(interval,"major 7th")==0)
	{
        semitones=11;
	}
	else if (strcmp(interval,"major 9th")==0)
	{
        semitones=14;
	}
    printf("\n **** semitones = %d **** \n",semitones);
	
	interPos=rootPos+semitones;
	
	printf("\n **** interPos =%d || %s **** \n",interPos,Notes[interPos]);
	
	
	if (strlen(Notes[interPos])!=1)
	{
        if (Notes[interPos][1]=='#')
        {
			sharpy[0]=Notes[interPos][0];
            sharpy[1]=Notes[interPos][1];
            printf("\n sharpy[2]=%c",sharpy[2]);
            
            if (Notes[interPos][4]=='b')
			{
				flatty[0]=Notes[interPos][3];
	            flatty[1]=Notes[interPos][4];
			}
			else
			{
	            flatty[0]=Notes[interPos][3];
	            flatty[1]='_';
			}
			printf("\n interPos--->%s \n",Notes[interPos]);
			printf("\n sharpy--->%s \n flatty--->%s \n",sharpy,flatty);
		}
		else
		{
            sharpy[0]=Notes[interPos][0];
            sharpy[1]='_';
            printf("\n sharpy[2]=%c",sharpy[2]);
            
            flatty[0]=Notes[interPos][2];
	        flatty[1]=Notes[interPos][3];
	        
	        printf("\n interPos--->%s \n",Notes[interPos]);
	        printf("\n sharpy--->%s \n flatty--->%s \n",sharpy,flatty);
		}


        
        if ( (keySignature[1]=='b') || (strcmp(keySignature,"F")==0) )
        {
            strcpy(ret,flatty);
			return ret;
		}
		else
		{
		    strcpy(ret,sharpy);
			return ret;
		}
	}
	else /*just return note*/
	{
  		strcpy(ret,Notes[interPos]);
		return ret;
	}
	
}


int main(void)
{
	char c,t;
    char temp[2];
	char interval[13]="gogogogogo";
	char keySignature[5]="A#/Bb";
	
	printf("-------------------------ENHARMONIC INTERVALS TEST----------------------- \n \n \n");

    srand(time(NULL));
    
    while ( (c=getchar()) != 'Z' )
    {

		/*Decide interval to be identified(only diatonic major intervals)*/
        strcpy(interval,randInterval());
        
        /*Decide key signature*/
		strcpy(keySignature,randKeySignature());
		
		printf("---------------------------------------------- \n");
		printf("Which note forms a %s interval above %s ? \n",interval,keySignature);
	
	    /*
	    t=getchar();
		
		printf("\n            The correct answer is ----> %s \n",findInterval(keySignature,interval,temp));
		printf("---------------------------------------------- \n \n");
		*/
	
	}
	return 1;
}







