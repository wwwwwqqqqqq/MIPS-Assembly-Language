//  main.c
//  CSI 333
//  Spring 2019
//  Project4
//  ZR1702
//  2017215126 2017215141
//  Qin Weiwei Gao Yifeng
//  Qin Weiwei writes main(),findtxt(),v(),findv(),Input(),struct,test and find the problem
//  Gao Yifeng writes seg(),finb(),b(),finddata(),solve the problem from testing
//  Created by 秦玮蔚、高艺峰 on 2019/4/29.
//  Copyright © 2019 Qin Weiwei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
    char a[100][100];
    char linetext[100][100];
    int sum;
    char text[100][100];
    char data[100][100];
    char b[100];
    char variable[100][100];
    char biaoqian[10];
    char biaoqianb[10];
} node;
FILE *output;
FILE *input;
FILE *fin,*font;

void Input(){
    int i = 0;
    //font = fopen("out.text","wb");
    while(1){
        if (fin == NULL){
            fprintf (output,"%s","Error opening file");
            break;
        }
        else {
            if ( fgets (node.b , 100 , fin) != NULL )
                //puts (node.a[i]);
                for(int j = 0;j < 100;j ++)
                {
                    if(node.b != NULL){
                        node.a[i][j] = node.b[j];
                    }
                    else break;
                    
                }
            else break;
        }
        
        i++;
    }
    
    fclose(fin);
    //fclose(font);
}
void seg(){
    FILE *fin,*font;
    char str[100][100];
    char *f;
    int i = 0,sum = 0,sum1 = 0;
    for(int m = 0;m < 100;m ++)
    {
        for(int n = 0;n < 100;n ++)
        {
            str[m][n] = node.a[m][n];
        }
    }
    /*fin = fopen("input.asm","rb");
     //font = fopen("out.text","wb");
     while(1){
     if (fin== NULL){
     perror ("Error opening file");
     break;
     }
     else {
     if ( fgets (b , 100 , fin) != NULL ){
     for(int j=0;j<100;j++){
     if(b[j]!=NULL){
     str[i][j]=b[j];
     }
     else break;
     }
     }
     else break;
     }
     i++;
     }
     */
    char *end_str;
    for(i = 0;i<100;i ++){
        f = strstr(str[i],".text");
        if(f != NULL)
        {
            sum = i;
            
        }
        char *b = strstr(str[i],".data");
        if(b != NULL)
        {
            sum1=i;
        }
    }
    for(int i = 0;i < sum;i ++){
        for(int m = 0;m < 100;m ++)
            node.data[i][m] = str[i][m];
    }
    int n = 0;
    for(int i = sum;i < 100;i ++){
        for(int m = 0;m < 100;m ++)
            node.text[n][m] = str[i][m];
        n ++;
    }
}

void findb(char var[],char variable[]){
    char *c = strstr(var,variable);
    if(c != NULL)
    {
        fprintf(output,"%s",var);
    }
}

void b(char biaoqian[]){
    fprintf(output,"Flow Control - %s -\n",biaoqian);
    for(int i = 0;i < 100;i ++)
        if(i != node.sum)
            findb(node.text[i],biaoqian);
}

void finddata(){
    for(int i = 0;i < 100;i ++){
        char *d = strstr(node.text[i],":");
        node.sum = i;
        if(d != NULL)
        {
            for(int j = 0;j < 10;j ++){
                if(node.text[i][j] != ':')
                    node.biaoqianb[j] = node.text[i][j];
                else break;
            }
            b(node.biaoqianb);
        }
        for(int i = 0;i < 10;i ++)
            node.biaoqianb[i] = NULL;
        d = NULL;
    }
}

void findv(char var[],char variable[]){
    char *c = strstr(var,variable);
    if(c != NULL)
    {
        fprintf(output,"%s",var);
    }
}

void v(char biaoqian[]){
    fprintf(output,"Variable ID - %s -\n",biaoqian);
    for(int i = 0;i < 100;i ++)
        findv(node.text[i],biaoqian);
}

void findtext(){
    for(int i = 0;i < 100;i ++){
        char *d = strstr(node.data[i],":");
        if(d != NULL)
        {
            for(int j = 0;j < 10;j ++){
                if(node.data[i][j] != ':')
                    node.biaoqian[j] = node.data[i][j];
                else break;
            }
            v(node.biaoqian);
        }
        for(int i = 0;i < 10;i ++)
            node.biaoqian[i] = NULL;
        d = NULL;
    }
}

int main(int argc, char *argv[])
{
    char *command;
    char *inputfile, *outputfile;
    command = argv[1];
    inputfile = argv[2];
    outputfile = argv[3];
    output = fopen(outputfile, "a");
    fin = fopen(inputfile,"r");
    Input();
    seg();
    if (strcmp(command, "-v") == 0)
    {
        findtext();
    }
    if (strcmp(command, "-f") == 0)
    {
        finddata();
    }
    if (strcmp(command, "-b") == 0)
    {
        findtext();
        finddata();
    }
    //Close the files
    fclose(input);
    fclose(output);
    return 0;
}

/*
#define NUM 4
#define MAX 10000

struct{
    char array[100][100];
    char v[20][10];
    int f[20];
    int l[10][10];
}array;

*/

/*
 struct data{
 char array[10][10];
 char v[10][10];
 struct data *next;
 }array;
 */

/*
FILE *finp, *foutp;

char a[10];
char line[MAX];
int num = 0;
int i = 0;
*/

/*
void toArray(){
    for(int a = 0;a < 10;a ++){
        for(int b = 0;b < 10;b ++){
            array.l[a][b] = 0;
        }
    }
}
*/

/*
void toArray(){
    int j = strstr(line,":") - line;
    strncpy(a,line,j);
    a[j] = '\0';
    
    strcpy(array.v[i],a);
    array.f[i] = num;
    
    i ++;
}

void readFile(char *inputfile,char *outputfile){
    int data = 0;
    int text = 0;
    int size = 0;
    
    finp = fopen(inputfile,"r");
    foutp = fopen(outputfile,"w");
    
    // Strings argv[1] and argv[2] are assumed to specify
    // the names of the input and output files respectively.
    // Open the input file for reading.
    if (finp == NULL) {
        // Open failed.
        printf("Could not open file %s for reading.\n",inputfile);
        exit(1);
    }
    
    // Open the output file for writing.
    if (foutp == NULL) {
        // Open failed.
        printf("Could not open file %s for writing.\n",outputfile);
        exit(1);
    }
    
    while(fgets(line,sizeof(line),finp) != NULL){
        num ++;
        if(strstr(line,".data") != NULL){
            data = 1;
            text = 0;
        }
        if(strstr(line,".text") != NULL){
            text = 1;
            data = 0;
        }
        if(data == 1){
            if(strstr(line,":") != NULL){
                toArray();
            }
        }
        if(text == 1){
            if((strstr(line,":") != NULL)){
                toArray();
            }
            for(int j = 0;j < i;j ++){
                if(strstr(line,array.v[j]) != NULL){
                    for(int k = 0;k < 10;k ++){
                        if(num != array.f[k]){
                            if(array.l[j][k] == 0){
                                array.l[j][k] = num;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    
    fclose(finp);
    
    FILE *fread = fopen(inputfile,"r");
    if(fread){
        while(fgets(array.array[size],256,fread) != NULL){
            size ++;
        }
    }
    
    /*
    if(finp){
        while(fgets(node.array[size],255,foutp) != NULL){
            if(strstr(node.array[size],"end") != NULL){
                if(size != 8){
                    for(int l = 0;l < 5;l ++){
                        if(node.array[3][l] == 0){
                            node.array[3][l] = size + 1;
                            break;
                        }
                    }
                }
                size ++;
            }
        }
    }
 
}
*/

/*
int read(char *inputfile){
    int line;
    char *p;
    char buff[MAX];
    char flag[4];
    
    for(line = 1;fgets(buff,MAX,finp) != NULL;++ line){
        if((p = strchr(buff,'\n')) == NULL){
            p = buff + strlen(buff);
            if(p = strchr(buff,'.') != NULL){
                p ++;
                while(!= '\n')
            }
        }
        if(p > buff && p[-1] == 'r'){
            -- p;
        }
        *p = '\0';
        for(p = buff;*p != '\0' && isspace((int)*p);p ++){
            ;
        }
        if(*p == )
    }
}

*/

/*
void V(){
    for(int j = 0;j < i;j ++){
        if(strcmp(array.v[j], "begin") != 0 && strcmp(array.v[j], "end") != 0 &&
           strcmp(array.v[j], "main") != 0 && strcmp(array.v[j], "yes_part") != 0 && strcmp(array.v[j], "no_part") != 0){
            fprintf(foutp,"Variable ID –%s-\n",array.v[j]);
            for(int k = 0;k < 5;k ++){
                if(array.l[j][k] != 0){
                    int temp = array.l[j][k];
                    //fprintf(foutp,"%d",array.l[j][k]);
                    fprintf(foutp,"%s",array.array[temp - 1]);
                }
            }
            //fprintf(foutp,"\n");
        }
    }
}

 */
/*
void V(){
    for(int i = 0;i < 10;i ++){
        fprintf(foutp,"Variable ID -%s-",array.array[i]);
        for(int j = 0;j < 5;j ++){
            int temp = array.array[i][j];
            fprintf(foutp,"%s",array.v[temp - 1]);
        }
        fprintf(foutp,"\n");
    }
}

*/

/*
void F(){
    for(int j = 0;j < i;j ++){
        if(strcmp(array.v[j], "begin") == 0 || strcmp(array.v[j], "end") == 0 || strcmp(array.v[j], "main") == 0 || strcmp(array.v[j], "yes_part") == 0 || strcmp(array.v[j], "no_part") == 0){
            fprintf(foutp,"Flow Control ID -%s-",array.v[j]);
            fprintf(foutp,"\n");
            for(int k = 0;k < 5;k ++){
                if(array.l[j][k] != 0){
                    int temp = array.l[j][k];
                    fprintf(foutp,"%s",array.array[temp - 1]);
                }
            }
        }
    }
    fprintf(foutp,"\n");
}
*/

/*
void F(){
    for(int i = 0;i < 10;i ++){
        fprintf(foutp,"Flow Control ID -%s-",array.array[i]);
        for(int j = 0;j < 5;j ++){
            int temp = array.array[i][j];
            fprintf(foutp,"%s",array.v[temp - 1]);
        }
        fprintf(foutp,"\n");
    }
}
*/

/*
int main(int argc,char *argv[]){
    char *cmd;
    char *inputfile;
    char *outputfile;
    
    cmd = argv[1];
    inputfile = argv[2];
    outputfile = argv[3];

    // The command line must specify the input file, the output file
    // and the pattern -- a total of NUMARG arguments.
    if(argc != NUM){
        printf("ERROR.\n");
        exit(1);
    }
    
    //FILE *finp, *foutp; //Pointers for input and output files
    
    readFile(inputfile,outputfile);
    
    /*
    char file[MAX];
    char *check;
    char temp[] = "";
    int i = 0;
    int j = 0;
    //struct array *p = (struct array *)malloc(sizeof(struct array));
    
    char *p;
    while(fgets(file,MAX,finp) != NULL){
        
        p = strchr(check,'.');
        p ++;
        while(j < 5){
            temp[j] = &p;
            p ++;
            j ++;
        }
        
        while(strcmp(temp,"data") == 0){
            i ++;
            putc(temp[i],foutp);
        }
        
        while(strcmp(temp,"text") == 0){
            i ++;
            putc(temp[i],foutp);
        }
     
    }
*/
    /* Both the files have been opened successfully.  */
    /* The pattern is given by the string argv[3].  Read one line at a time */
    /* from the input file, check if the pattern occurs in the line, and    */
    /* if so, write the line to the output file.                            */
    /* The string library function strstr is used for checking the  */
    /* occurrence of pattern in the line that has been read in.     */
    //while (fgets(f1, MAX, finp) != NULL) {
        //if (strstr(f1, argv[IN]) != NULL) { /* Successful match. */
            //fputs(f1, foutp);
/*
            if(strcmp(cmd,"-v") == 0){
                V();
            }
            
            else if(strcmp(cmd,"-f") == 0){
                F();
            }
            
            else if(strcmp(cmd,"-b") == 0){
                V();
                F();
            }
    
    fclose(finp);
    fclose(foutp);
    /* Close the files and stop.
    if (fclose(finp) == EOF) { /* Error in closing input file
        printf("Error in closing file input.dat.\n");
    }
    if (fclose(foutp) == EOF) { /* Error in closing output file
        printf("Error in closing file output.dat.\n");
    }
 
    return 0;
}
*/
