#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tells the compiler not to add padding for these structs. This may
   be useful when reading/writing to binary files.
   http://stackoverflow.com/questions/3318410/pragma-pack-effect
*/

struct bmp_fileheader
{
    unsigned char  fileMarker1; /* 'B' */
    unsigned char  fileMarker2; /* 'M' */
    unsigned int   bfSize; /* File's size */
    unsigned short unused1;
    unsigned short unused2;
    unsigned int   imageDataOffset; /* Offset to the start of image data */
};

struct bmp_infoheader
{
    unsigned int   biSize; /* Size of the info header - 40 bytes */
    signed int     width; /* Width of the image */
    signed int     height; /* Height of the image */
    unsigned short planes;
    unsigned short bitPix;
    unsigned int   biCompression;
    unsigned int   biSizeImage; /* Size of the image data */
    int            biXPelsPerMeter;
    int            biYPelsPerMeter;
    unsigned int   biClrUsed;
    unsigned int   biClrImportant;
};

struct pixel
{
	unsigned char B, G, R;
};

struct coordonate	//retine coordonate pentru cifrele ce vor ramane in fisier 
{
	int apare;
	struct pixel culoare;
	int lin, col;
	int id;
};


int is_white(struct pixel pix)		//verifica pixel
{
	if( pix.B == 255 && pix.G == 255 && pix.R == 255)
		return 1;
	return 0;
}

char zero[5][5] = {	
	"xxxxx",
	"x...x",
	"x...x",
	"x...x",
	"xxxxx"
};
char unu[5][5] = {
	"....x",
	"....x",
	"....x",
	"....x",
	"....x"
};
char doi[5][5] = {
	"xxxxx",
	"x....",
	"xxxxx",
	"....x",
	"xxxxx"
};
char trei[5][5] = {
	"xxxxx",
	"....x",
	"xxxxx",
	"....x",
	"xxxxx"
};
char patru[5][5] = {
	"....x",
	"....x",
	"xxxxx",
	"x...x",
	"x...x"
};
char cinci[5][5] = {
	"xxxxx",
	"....x",
	"xxxxx",
	"x....",
	"xxxxx"
};
char sase[5][5] = {
	"xxxxx",
	"x...x",
	"xxxxx",
	"x....",
	"xxxxx"
};
char sapte[5][5] = {
	"....x",
	"....x",
	"....x",
	"....x",
	"xxxxx"
};
char opt[5][5] = {
	"xxxxx",
	"x...x",
	"xxxxx",
	"x...x",
	"xxxxx"
};
char noua[5][5] = {
	"xxxxx",
	"....x",
	"xxxxx",
	"x...x",
	"xxxxx"
};

void add0( struct pixel bitmap[100][100], int h, int w, struct pixel color)		//adauga cifra 0 in bitmap
{
	for( int m = 0; m < 5; m++ )
		for( int n = 0; n < 5; n++ )
			if( m == 0 || m == 4 || n == 0 || n == 4 )
			{
				bitmap[ h + m ][ w + n ].B = color.B;
				bitmap[ h + m ][ w + n ].G = color.G;
				bitmap[ h + m ][ w + n ].R = color.R;
			}
			else 
			{
				bitmap[ h + m ][ w + n ].B = 255;
				bitmap[ h + m ][ w + n ].G = 255;
				bitmap[ h + m ][ w + n ].R = 255;
			}
}


void add1( struct pixel bitmap[100][100], int h, int w, struct pixel color)
{
	for( int m = 0; m < 5; m++ )
		for( int n = 0; n < 5; n++ )
		{
			if( n == 4)
			{
				bitmap[ h + m ][ w + n ].B = color.B;
				bitmap[ h + m ][ w + n ].G = color.G;
				bitmap[ h + m ][ w + n ].R = color.R;
			}
			else 
			{
				bitmap[ h + m ][ w + n ].B = 255;
				bitmap[ h + m ][ w + n ].G = 255;
				bitmap[ h + m ][ w + n ].R = 255;
			}				
		}
}

void add2( struct pixel bitmap[100][100], int h, int w, struct pixel color)
{
	for( int m = 0; m < 5; m++ )
		for( int n = 0; n < 5; n++ )
		{
			if( m == 0 || m == 2 || m == 4 || ( m == 1 && n == 0) || ( m == 3 && n == 4))
			{
				bitmap[ h + m ][ w + n ].B = color.B;
				bitmap[ h + m ][ w + n ].G = color.G;
				bitmap[ h + m ][ w + n ].R = color.R;
			}
			else 
			{
				bitmap[ h + m ][ w + n ].B = 255;
				bitmap[ h + m ][ w + n ].G = 255;
				bitmap[ h + m ][ w + n ].R = 255;
			}				
		}
}

void add3( struct pixel bitmap[100][100], int h, int w, struct pixel color)
{
	for( int m = 0; m < 5; m++ )
		for( int n = 0; n < 5; n++ )
		{
			if( m == 0 || m == 2 || m == 4 || n == 4)
			{
				bitmap[ h + m ][ w + n ].B = color.B;
				bitmap[ h + m ][ w + n ].G = color.G;
				bitmap[ h + m ][ w + n ].R = color.R;
			}
			else 
			{
				bitmap[ h + m ][ w + n ].B = 255;
				bitmap[ h + m ][ w + n ].G = 255;
				bitmap[ h + m ][ w + n ].R = 255;
			}				
		}
}

void add4( struct pixel bitmap[100][100], int h, int w, struct pixel color)
{
	for( int m = 0; m < 5; m++ )
		for( int n = 0; n < 5; n++ )
		{
			if( n == 4 || m == 2 || m == 4 || ( m == 3 && n == 0) || ( m == 4 && n == 0))
			{
				bitmap[ h + m ][ w + n ].B = color.B;
				bitmap[ h + m ][ w + n ].G = color.G;
				bitmap[ h + m ][ w + n ].R = color.R;
			}
			else 
			{
				bitmap[ h + m ][ w + n ].B = 255;
				bitmap[ h + m ][ w + n ].G = 255;
				bitmap[ h + m ][ w + n ].R = 255;
			}				
		}
}

void add5( struct pixel bitmap[100][100], int h, int w, struct pixel color)
{
	for( int m = 0; m < 5; m++ )
		for( int n = 0; n < 5; n++ )
		{
			if( m == 0 || m == 2 || m == 4 || ( m == 1 && n == 4) || ( m == 3 && n == 0))
			{
				bitmap[ h + m ][ w + n ].B = color.B;
				bitmap[ h + m ][ w + n ].G = color.G;
				bitmap[ h + m ][ w + n ].R = color.R;
			}
			else 
			{
				bitmap[ h + m ][ w + n ].B = 255;
				bitmap[ h + m ][ w + n ].G = 255;
				bitmap[ h + m ][ w + n ].R = 255;
			}				
		}
}

void add6( struct pixel bitmap[100][100], int h, int w, struct pixel color)
{
	for( int m = 0; m < 5; m++ )
		for( int n = 0; n < 5; n++ )
		{
			if( m == 0 || m == 2 || m == 4 || n == 0 || ( m == 3 && n == 0))
			{
				bitmap[ h + m ][ w + n ].B = color.B;
				bitmap[ h + m ][ w + n ].G = color.G;
				bitmap[ h + m ][ w + n ].R = color.R;
			}
			else 
			{
				bitmap[ h + m ][ w + n ].B = 255;
				bitmap[ h + m ][ w + n ].G = 255;
				bitmap[ h + m ][ w + n ].R = 255;
			}				
		}
}

void add7( struct pixel bitmap[100][100], int h, int w, struct pixel color)
{
	for( int m = 0; m < 5; m++ )
		for( int n = 0; n < 5; n++ )
		{
			if( m == 4 || n == 4 )
			{
				bitmap[ h + m ][ w + n ].B = color.B;
				bitmap[ h + m ][ w + n ].G = color.G;
				bitmap[ h + m ][ w + n ].R = color.R;
			}
			else 
			{
				bitmap[ h + m ][ w + n ].B = 255;
				bitmap[ h + m ][ w + n ].G = 255;
				bitmap[ h + m ][ w + n ].R = 255;
			}				
		}
}

void add8( struct pixel bitmap[100][100], int h, int w, struct pixel color)
{
	for( int m = 0; m < 5; m++ )
		for( int n = 0; n < 5; n++ )
		{
			if( m == 0 || m == 2 || m == 4 || n == 0 || n == 4)
			{
				bitmap[ h + m ][ w + n ].B = color.B;
				bitmap[ h + m ][ w + n ].G = color.G;
				bitmap[ h + m ][ w + n ].R = color.R;
			}
			else 
			{
				bitmap[ h + m ][ w + n ].B = 255;
				bitmap[ h + m ][ w + n ].G = 255;
				bitmap[ h + m ][ w + n ].R = 255;
			}				
		}
}

void add9( struct pixel bitmap[100][100], int h, int w, struct pixel color)
{
	for( int m = 0; m < 5; m++ )
		for( int n = 0; n < 5; n++ )
		{
			if( m == 0 || m == 2 || m == 4 || ( m == 3 && n == 0) || n == 4)
			{
				bitmap[ h + m ][ w + n ].B = color.B;
				bitmap[ h + m ][ w + n ].G = color.G;
				bitmap[ h + m ][ w + n ].R = color.R;
			}
			else 
			{
				bitmap[ h + m ][ w + n ].B = 255;
				bitmap[ h + m ][ w + n ].G = 255;
				bitmap[ h + m ][ w + n ].R = 255;
			}				
		}
}


int compare( struct pixel bitmap[100][100], char cifra[5][5], int h, int w )	//verificarea apartenentei unei cifre la matrice
{
	for( int i = 0; i < 5; i++)
		for( int j = 0; j < 5; j++)
		{
			if( ( cifra[i][j] == 'x' && is_white(bitmap[h+i][w+j]) ) || ( cifra[i][j] == '.' && !is_white(bitmap[h+i][w+j]) ) )
				return 0;
		}
		
	return 1;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char line[20];
	
	struct pixel bitmap[100][100], bitmap2[ 100 ][ 100 ];
	struct coordonate cord[20];

	FILE *f = fopen("input.txt", "r");
	
	
	struct bmp_fileheader fileheader;
	struct bmp_infoheader infoheader;
	struct pixel format;
	
	unsigned char npad = 0;
	
	
	int pad;
	fgets( line, 100, f );
	line[strlen(line)-1] = '\0';
	FILE *file = fopen( line, "rb");
	FILE *output = fopen( "captcha.bmp", "wb");
	
	FILE *output3 = fopen( "captchaTask3.bmp", "wb");
		 
	fread( &fileheader, 14, 1, file );
	
	fread( &infoheader, 40, 1, file );
//		Task 1
	fscanf( f, "%d %d %d", &format.B, &format.G, &format.R );
	
	if((infoheader.width * 3) % 4 == 0)			//determinarea padding-ului
		pad=0;
	else if(infoheader.width % 4 == 1)
		pad=3;
	else if( infoheader.width % 4 == 2)
		pad=2;
	else pad = 1;
	
	for( int i = 0; i < infoheader.height; i++ )		//citire din fisier, ignorand padding, Task 1
		{
		
		for( int j = 0; j < infoheader.width; j++)
			fread( &bitmap[i][j], 3, 1, file );
		fseek(file, pad, SEEK_CUR);
		}
		
			
	for( int i = 0; i < infoheader.height; i++ )			//schimbarea culorilor din matrice
		for( int j = 0; j < infoheader.width; j++)
			if(!is_white(bitmap[i][j]))
			{
				bitmap[i][j].B = format.B;
				bitmap[i][j].G = format.G;
				bitmap[i][j].R = format.R;
			}
	
	fwrite( &fileheader, 14, 1, output);
	fwrite( &infoheader, 40, 1, output);
	
	for( int i = 0; i < infoheader.height; i++ )		//crearea fisierului .bmp cu o singura culoare
	{
		for( int j = 0; j < infoheader.width; j++)
			fwrite( &bitmap[i][j], sizeof(struct pixel), 1, output );
		fwrite ( &npad, 1, pad, output );
	}

		fclose(output);
		
		fseek( file, 54, SEEK_SET);
	
	for( int i = 0; i < infoheader.height; i++ )		//citire din fisier, ignorand padding, Task 2, 3
		{
		
		for( int j = 0; j < infoheader.width; j++)
			fread( &bitmap2[i][j], 3, 1, file );
		fseek(file, pad, SEEK_CUR);
		}
	
		
		
	int buffer=0;
	
//		Task 2
			
	FILE *output_task2 = fopen("task2.txt", "w");
	
	for( int j = 0; j < infoheader.width; j++)				//recunoasterea cifrelor din matrice
		for(int i = 0; i < infoheader.height; i++ )
			if(!is_white(bitmap2[i][j]))
			{
				if( compare( bitmap2, zero, i, j) == 1)
				{
					cord[buffer].apare = 1;
					cord[buffer].lin = i;
					cord[buffer].col = j;
					
					cord[buffer].culoare.B = bitmap2[i][j].B;
					cord[buffer].culoare.G = bitmap2[i][j].G;			//retinem informatii pentru task 3
					cord[buffer].culoare.R = bitmap2[i][j].R;
					
					cord[ buffer ].id = 0;
					
					buffer++;
					
					fprintf( output_task2, "0");
					
					if( j+1 <= infoheader.width)
					{
						j++;
						i=-1;
					}
				}
				else if( compare( bitmap2, doi, i, j ) == 1)
				{
					cord[buffer].apare = 1;
					cord[buffer].lin = i;
					cord[buffer].col = j;
					
					cord[buffer].culoare.B = bitmap2[i][j].B;
					cord[buffer].culoare.G = bitmap2[i][j].G;
					cord[buffer].culoare.R = bitmap2[i][j].R;
					
					cord[ buffer ].id = 2;
					
					buffer++;
					
					fprintf( output_task2, "2");
					if( j+1 <= infoheader.width)
					{
						j++;
						i=-1;
					}
				}
				else if( compare( bitmap2, trei, i, j) == 1)
				{
					cord[buffer].apare = 1;
					cord[buffer].lin = i;
					cord[buffer].col = j;
					
					cord[buffer].culoare.B = bitmap2[i][j].B;
					cord[buffer].culoare.G = bitmap2[i][j].G;
					cord[buffer].culoare.R = bitmap2[i][j].R;
					
					cord[ buffer ].id = 3;
					
					buffer++;
					
					fprintf( output_task2, "3");
					if( j+1 <= infoheader.width)
					{
						j++;
						i=-1;
					}
				}			
				else if( i >= 2 && compare( bitmap2, patru, i-2, j) == 1 )
				{
					cord[buffer].apare = 1;
					cord[buffer].lin = i - 2;
					cord[buffer].col = j;
					
					cord[buffer].culoare.B = bitmap2[i][j].B;
					cord[buffer].culoare.G = bitmap2[i][j].G;
					cord[buffer].culoare.R = bitmap2[i][j].R;
					
					cord[ buffer ].id = 4;
					
					buffer++;
					
					fprintf( output_task2, "4");
					if( j+1 <= infoheader.width)
					{
						j++;
						i=-1;
					}
				}
				else if( compare( bitmap2, cinci, i, j) == 1)
				{
					cord[buffer].apare = 1;
					cord[buffer].lin = i;
					cord[buffer].col = j;
					
					cord[buffer].culoare.B = bitmap2[i][j].B;
					cord[buffer].culoare.G = bitmap2[i][j].G;
					cord[buffer].culoare.R = bitmap2[i][j].R;
					
					cord[ buffer ].id = 5;
					
					buffer++;
					
					fprintf( output_task2, "5");
					if( j+1 <= infoheader.width)
					{
						j++;
						i=-1;
					}
				}
				else if( compare( bitmap2, sase, i, j) == 1)
				{
					cord[buffer].apare = 1;
					cord[buffer].lin = i;
					cord[buffer].col = j;
					
					cord[buffer].culoare.B = bitmap2[i][j].B;
					cord[buffer].culoare.G = bitmap2[i][j].G;
					cord[buffer].culoare.R = bitmap2[i][j].R;
					
					cord[ buffer ].id = 6;
					
					buffer++;
					
					fprintf( output_task2, "6");
					if( j+1 <= infoheader.width)
					{
						j++;
						i=-1;
					}
				}
				else if( i>= 4 && compare( bitmap2, sapte, i-4, j) == 1)
				{
					cord[buffer].apare = 1;
					cord[buffer].lin = i-4;
					cord[buffer].col = j;
					
					cord[buffer].culoare.B = bitmap2[i][j].B;
					cord[buffer].culoare.G = bitmap2[i][j].G;
					cord[buffer].culoare.R = bitmap2[i][j].R;
					
					cord[ buffer ].id = 7;
					
					buffer++;
					
					fprintf( output_task2, "7");
					if( j+1 <= infoheader.width)
					{
						j++;
						i=-1;
					}
				}
				else if( compare( bitmap2, opt, i, j) == 1)
				{
					cord[buffer].apare = 1;
					cord[buffer].lin = i;
					cord[buffer].col = j;
					
					cord[buffer].culoare.B = bitmap2[i][j].B;
					cord[buffer].culoare.G = bitmap2[i][j].G;
					cord[buffer].culoare.R = bitmap2[i][j].R;
					
					cord[ buffer ].id = 8;
					
					buffer++;
					
					fprintf( output_task2, "8");
					if( j+1 <= infoheader.width)
					{
						j++;
						i=-1;
					}
				}
				else if( compare( bitmap2, noua, i, j) == 1)
				{
					cord[buffer].apare = 1;
					cord[buffer].lin = i;
					cord[buffer].col = j;
					
					cord[buffer].culoare.B = bitmap2[i][j].B;
					cord[buffer].culoare.G = bitmap2[i][j].G;
					cord[buffer].culoare.R = bitmap2[i][j].R;
					
					cord[ buffer ].id = 9;
					
					buffer++;
					
					fprintf( output_task2, "9");
					if( j+1 <= infoheader.width)
					{
						j++;
						i=-1;
					}
				}
				else if( (j>= 4) && compare( bitmap2, unu, i, j - 4 ))
				{
					cord[buffer].apare = 1;
					cord[buffer].lin = i;
					cord[buffer].col = j - 4;
					
					cord[buffer].culoare.B = bitmap2[i][j].B;
					cord[buffer].culoare.G = bitmap2[i][j].G;
					cord[buffer].culoare.R = bitmap2[i][j].R;
					
					cord[ buffer ].id = 1;
					
					buffer++;
					
					fprintf( output_task2, "1");
					if( j+1 <= infoheader.width)
					{
						j++;
						i=-1;
					}
				}
			}
	
	//	Task 3
	int x;

	 while ( fscanf(f, "%d ", &x) != 0 )		//citire din fisier a cifrelor de eliminat
	 		for( int i=0; i < buffer; i++ )
	 			if( cord[ i ].id == x )
	 				cord[ i ].apare = 0;
	
	fwrite( &fileheader, 14, 1, output3);
	fwrite( &infoheader, 40, 1, output3);

	int gasit;
	
	for( int i = 0; i < buffer - 1; i++)		//modific vectorul de structuri in vederea completarii ulterioare a matricei
	{
		if( cord[ i ].apare == 0)
		{
			cord[ i ].culoare.B = 255;
			cord[ i ].culoare.G = 255;
			cord[ i ].culoare.R = 255;
			
			gasit = 0;
			for( int j = i + 1; j < buffer && gasit == 0; j++)
				if( cord[ j ].apare == 1)
				{
					cord[ i ].apare = 1;
					cord[ j ].apare = 0;
					cord[ i ].id = cord[ j ].id;
					
					cord[ i ].culoare.B = cord[ j ].culoare.B;
					cord[ i ].culoare.G = cord[ j ].culoare.G;
					cord[ i ].culoare.R = cord[ j ].culoare.R;
										
					gasit = 1;
				}
		}
	}
	
				cord[ buffer - 1 ].culoare.B = 255;
				cord[ buffer - 1 ].culoare.G = 255;
				cord[ buffer - 1 ].culoare.R = 255;

	
/*
	for( int i = 0; i < buffer; i++)
		if(cord[ i ].apare == 1)
			printf(" %d %d %d\n", cord[ i ].id, cord[ i ].apare, cord[ i ].culoare.G );
*/
			
	
	for( int j = 0; j < infoheader.width; j++)
		for(int i = 0; i < infoheader.height; i++ )
		{
			bitmap2[ i ][ j ].B = 255;
			bitmap2[ i ][ j ].G = 255;
			bitmap2[ i ][ j ].R = 255;
		}
		
	for( int i = 0; i < buffer; i++)						//modificare bitmap
	{
		if( cord[ i ].id == 0 )
			add0( bitmap2, cord[ i ].lin, cord[ i ].col, cord[ i ].culoare);
			
		else if( cord[ i ].id == 1 )
			add1( bitmap2, cord[ i ].lin, cord[ i ].col, cord[ i ].culoare);
			
		else if( cord[ i ].id == 2 )
			add2( bitmap2, cord[ i ].lin, cord[ i ].col, cord[ i ].culoare);
			
		else if( cord[ i ].id == 3 )
			add3( bitmap2, cord[ i ].lin, cord[ i ].col, cord[ i ].culoare);
			
		else if( cord[ i ].id == 4 )
			add4( bitmap2, cord[ i ].lin, cord[ i ].col, cord[ i ].culoare);
			
		else if( cord[ i ].id == 5 )
			add5( bitmap2, cord[ i ].lin, cord[ i ].col, cord[ i ].culoare);
			
		else if( cord[ i ].id == 6 )
			add6( bitmap2, cord[ i ].lin, cord[ i ].col, cord[ i ].culoare);
			
		else if( cord[ i ].id == 7 )
			add7( bitmap2, cord[ i ].lin, cord[ i ].col, cord[ i ].culoare);
			
		else if( cord[ i ].id == 8 )
			add8( bitmap2, cord[ i ].lin, cord[ i ].col, cord[ i ].culoare);
			
		else if( cord[ i ].id == 9 )
			add9( bitmap2, cord[ i ].lin, cord[ i ].col, cord[ i ].culoare);
	}
		

	for( int i = 0; i < infoheader.height; i++ )
	{
		for( int j = 0; j < infoheader.width; j++)
			fwrite( &bitmap2[i][j], 3, 1, output3 );
		fwrite ( &npad, 1, pad, output3 );
	}
	
	
	fclose(output3);
	fclose(file);
	fclose(f);
	return 0;
	
}
