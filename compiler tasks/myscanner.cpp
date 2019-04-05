#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;
////////////////////////////////////////////////////////////////////
int isKeyword(char buffer[])
{
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    int flag = 0;
    for(int i = 0; i < 32; i++)
    {
        if((strcmp(keywords[i], buffer)) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
////////////////////////////////////////////////////////////////////
int isoperator(int c)
{
    char operators[] = "+-*/%=><";
    for( int i = 0; i < strlen(operators); i++)
    {
        if(c == operators[i])
            return 1;
    }
    return 0;
}
////////////////////////////////////////////////////////////////////
int isspecialchar(int c)
{
    char specialchar[] = "#;,(){}";
    int i;
    for( i = 0; i < strlen(specialchar); i++)
    {
        if(c == specialchar[i])
            return 1;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////
int iscomment(int c , int prevch)
{
    if (c == '*' && prevch =='/')
    {
        return 1;
    }
    else if (c =='/' && prevch =='/')
    {
        return 2;
    }

    return 0;
}
////////////////////////////////////////////////////////////////////////
int main()
{
    char ch, buffernum[20] , bufferchar[20] ;
    int i,jnum=0 , jchar=0, index = 0;
    char lexemes [200][20];
    char tokens [200][20];
    char temp[1];

    ifstream myfile("program.txt");

    if(!myfile.is_open())
    {
        cout<<"error while opening the file\n";
        exit(0);
    }

    while(!myfile.eof())
    {
        ch = myfile.get();

        if ((isdigit(ch)||ch == '.') && jchar == 0)
        {
            buffernum[jnum] = ch;
            jnum++;
            continue;
        }
        else if( ( !isdigit(ch)  ) && (jnum != 0))
        {
            buffernum[jnum] = '\0';
            jnum = 0;
            strcpy(lexemes[index],buffernum);
            strcpy(tokens[index],"numeric value");
            index++;
            //cout<<buffernum<<" is numeric value\n";
        }
///////////////////////////////////////////////////////////////////////////////////////
        if((isalnum(ch) || ch == '_')||(ch =='.'))
           {
               bufferchar[jchar] = ch;
               jchar++;
               continue;
           }
           else if((ch == ' ' || ch == '\n' || ch == '\t' || isoperator(ch)|| isspecialchar(ch) ) && (jchar != 0))
           {
                   bufferchar[jchar] = '\0';
                   jchar = 0;

                   if(isKeyword(bufferchar))
                   {
                        strcpy(lexemes[index],bufferchar);
                        strcpy(tokens[index],"keyword");
                        index++;
                        //cout<<bufferchar<<" is keyword\n";
                   }

                   else
                   {
                        strcpy(lexemes[index],bufferchar);
                        strcpy(tokens[index],"indentifier");
                        index++;
                       //cout<<bufferchar<<" is indentifier\n";
                   }

           }
//////////////////////////////////////////////////////////////////////////////////////
        if(isoperator(ch))
        {

            temp[0]=ch;
            temp[1]='\0';
            int commentindecator = iscomment(ch,lexemes[index-1][0]);
            switch(commentindecator)
            {
            case 1:
                index--;
                bufferchar[0]='/';
                bufferchar[1]='*';
                jchar=2;
                while((ch = myfile.get())!='/' && (bufferchar[jchar-1]!='*'||jchar==2) )
                    bufferchar[jchar++]=ch;

                bufferchar[jchar++]='/';
                bufferchar[jchar]='\0';
                jchar=0;
                strcpy(lexemes[index],bufferchar);
                strcpy(tokens[index++],"multiline comment");
                //cout<<bufferchar<<" is multiline comment\n";
                break;

            case 2:
                index--;
                bufferchar[0]='/';
                bufferchar[1]='/';
                jchar=2;
                while((ch = myfile.get())!='\n')
                    bufferchar[jchar++]=ch;
                bufferchar[jchar]='\0';
                jchar = 0;
                strcpy(lexemes[index],bufferchar);
                strcpy(tokens[index++],"single line comment");
                //cout<<bufferchar<<" is multiline comment\n";
                break;

            default:
                //cout<<ch<<" is operator\n";
                strcpy(lexemes[index],temp);
                strcpy(tokens[index++],"operator");
                continue;
            }
        }

//////////////////////////////////////////////////////////////////////////////////////
        if (isspecialchar(ch))
        {
            //cout<<ch<<" is special character\n";
            temp[0]=ch;
            temp[1]='\0';
            strcpy(lexemes[index],temp);
            strcpy(tokens[index],"special char");

            index++;

            continue;
        }
    }
////////////////////////////////////////////////////////////////////////////////////

    lexemes[index][0]='\0';
    for ( i = 0; lexemes[i][0]!='\0'; i++)
    {
        cout<<lexemes[i]<<" is "<<tokens[i]<<"\n";
    }

    myfile.close();
    system("pause");
    return 0;
}

