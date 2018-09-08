#include<iostream>
#include<fstream>
#include <string>
#include<stdlib.h>

using namespace std;

enum tokenType{
    FUNCTION, BEGIN , END , VAR , INTEGER , FLOAT , IF , ELSE, WHILE , FOR, TRUE , FALSE , ID ,
    LPARN , RPARN , LESSEQUAL , LESS , EQUAL , GREATER , GREATEREQUAL , NOTEQUAL , PLUS , MINUS, DIV ,MULTI,
    COMMA , SEMICOL, COLON, ASSIGN , ERROR , ENDSOURCE , NUMBER ,ARG
};

enum nodeType{
    UNDEFINED, START, FUNCTIONN, PROGRAMN, BEGINN , ENDN , TYPEN, IDN, ARGLISTN, ARGN, STMTN,  DECLARATIONN,
    IDENTLISTN, FORSTMTN, WHILESTMTN, EXPRN, IFSTMTN, COMPOUNDSTMTN, FORN, OPTEXPRN, WHILEN, IFN, ELSEPARTN, ELSEN,
    STMTLISTN, RVALUEN, COMPAREN, MEGN, TERMN, FACTORN, VARN , INTEGERN , FLOATN , TRUEN , FALSEN , LPARNN ,
    RPARNN , LESSEQUALN , LESSN , EQUALN , GREATERN , GREATEREQUALN , NOTEQUALN , PLUSN , MINUSN, DIVN,
    MULTIN , COMMAN , SEMICOLN, COLONN, ASSIGNN ,COMSEQN,COMSEQTAILN,SIMEXPRN,SIMEXPRTAILN,ELEMENTN,NUMBERN,ARGLISTTAILN
};
//*****************************************
class Token{
public :
    tokenType type;
    string name;
    Token(){
        type = ERROR;
        name="";
    }
};
//*****************************************
class Node{
public:
    nodeType type;
    string Lexeme;
    Node* child[8];		// array of pointers (6 pointers)
    Node(){
        for(int i=0;i<8;i++){
            child[i]=NULL;
        }
    }
    ~Node(){
        for(int i=0;i<8;i++)
            delete child[i];
        }
};
//*****************************************
Node * root;			// pointer that pointing to the root node
//*****************************************
class Parser{
private:
    fstream f;
    Token currentToken;				//currentToken>>class>>(type,name)

    Token getToken(){				// ( >>>>>>>>>>>>>>>>>>>>>>>> (type:LPARN , name:"(")
	    char ch;
	    Token t;
	    f.get(ch);
	    while(isspace(ch)){
	        f.get(ch);
	        if(f.eof())
	        {
	            t.name="$$";
	            t.type=ENDSOURCE;
	            return t;
	        }
	    }

	    if(f.eof()){
	            t.name="$$";
	            t.type=ENDSOURCE;
	    }
	    else if(ch=='('){t.name=ch ;  t.type=LPARN;}		//t.name="(";
	    else if(ch==')'){t.name=ch ; t.type= RPARN;}
	    else if(ch=='+'){t.name=ch; t.type= PLUS;}
	    else if(ch=='-'){t.name=ch; t.type=MINUS ;}
	    else if(ch=='*'){t.name=ch; t.type=MULTI ;}
	    else if(ch=='/'){t.name=ch; t.type= DIV;}
	    else if(ch==';'){t.name=ch ; t.type= SEMICOL;}
	    else if(ch=='='){t.name=ch ; t.type= EQUAL;}
	    else if(ch==','){t.name=ch ; t.type= COMMA;}

	    else if(ch=='<')
	        {
	            t.name=ch ;
	            f.get(ch);
	            if(ch=='>'){
	                t.name+=ch;		//t.name="<>";
	                t.type=NOTEQUAL;
	            }
	            else if(ch=='='){
	                t.name+=ch;		//t.name = "<=";
	                t.type=LESSEQUAL;
	            }
	            else{
	                f.putback(ch);
	                t.type=LESS;	//t.name = "<";		return t >> t(name="<" , type=LESS)
	            }
	        }
	    else if(ch=='>')
	        {
	            t.name=ch ;
	            f.get(ch);
	            if(ch=='='){
	                t.name+=ch;
	                t.type=GREATEREQUAL;
	            }
	            else{
	                f.putback(ch);
	                t.type=GREATER;
	            }
	        }
	        else if(ch==':'){
	            t.name=ch;
	            f.get(ch);
	            if(ch=='='){
	                t.name+=ch;
	                t.type=ASSIGN;
	            }
	            else{
	                f.putback(ch);
	                t.type=COLON;
	            }
	        }
	        else if(isalpha(ch)){
	            t.name=ch;
	            f.get(ch);
	            while(isalnum(ch)){
	                t.name+=ch;
	                f.get(ch);
	            }
	            f.putback(ch);
	            return checkReserved(t);
	        }
	        else if(isdigit(ch)){
	            t.name=ch;
	            f.get(ch);
	            while(isdigit(ch)){
	                t.name+=ch;
	                f.get(ch);
	            }
	            f.putback(ch);
	            t.type=NUMBER;
	        }
	        else{
	                t.name="ERROR !";
	                t.type=ERROR;
	        }

   //must be executed
	        return t;
}
//*****************************************
  Token checkReserved(Token t){
    if(t.name=="function") t.type=FUNCTION;
    else if(t.name== "begin") t.type=BEGIN;
    else if(t.name== "end") t.type=END;
    else if(t.name== "integer") t.type=INTEGER;
    else if(t.name== "float") t.type=FLOAT;
    else if(t.name== "if") t.type=IF;
    else if(t.name== "else") t.type=ELSE;
    else if(t.name== "while") t.type=WHILE;
    else if(t.name== "for") t.type=FOR;
    else if(t.name== "true") t.type=TRUE;
    else if(t.name== "false") t.type=FALSE;
    else t.type=ID;
    return t;
}


//*****************************************

void match(tokenType type){
    if(currentToken.type==type){
        cout<<currentToken.name<<" is matched\n";
    }
    else{
        syntaxError(currentToken);
    }
    if(type!=ENDSOURCE)
        currentToken=getToken();
}
//*****************************************
void syntaxError(Token t){
    cout<<t.name<<" isn't expected\n";
}
//*****************************************/Grammer Rules/*****************************************
/// <function> ::= <type> id <arglist> <compoundstmt>
Node* function(){
    Node* ptr= new Node();
    ptr->type=FUNCTIONN;
    ptr->child[0]=type();
    if(currentToken.type==ID){
        ptr->child[1]=new Node();
        ptr->child[1]->Lexeme=currentToken.name;
        ptr->child[1]->type=IDN;
    }
    match(ID);
    ptr->child[2]=argList();
    ptr->child[3]=compoundstmt();
    return ptr;
}
///****************************************
Node* compoundstmt(){



}
//*****************************************
/// <arglis> ::= <arg> , <arglist> | <arg>
Node*  argList(){
    Node* ptr=new Node();
    ptr->type=ARGLISTN;
    ptr->child[0]=arg();
    ptr->child[1]=argList();
    return ptr;
}
//*****************************************
/// <declaration> ::= type id ;
Node*  declare(){
    Node* ptr=new Node();
    ptr->type=DECLARATIONN;
    ptr->child[0]=type();
    if(currentToken.type==ID){
        ptr->child[1]=new Node();
        ptr->child[1]->Lexeme=currentToken.name;
        ptr->child[1]->type=IDN;
    }
    match(ID);
    ptr->child[2]=type();
    if(currentToken.type==SEMICOL){
        ptr->child[2]=new Node();
        ptr->child[2]->Lexeme=currentToken.name;
        ptr->child[2]->type=SEMICOLN;
    }
    match(SEMICOL);
    return ptr;
}
//*****************************************
/// <type> ::= integer | float
Node* type(){
    Node* ptr=new Node();
    ptr->type=TYPEN;
    switch(currentToken.type){
    case INTEGER:
        ptr->child[0]=new Node();
        ptr->child[0]->Lexeme=currentToken.name;
        ptr->child[0]->type=INTEGERN;
        match(INTEGER);
        break;
    case FLOAT:
        ptr->child[0]=new Node();
        ptr->child[0]->Lexeme=currentToken.name;
        ptr->child[0]->type=FLOATN;
        match(FLOAT);
        break;
    default:
        syntaxError(currentToken);
    }
    return ptr;
}
//*****************************************
/// <arg> ::= <type> id
Node*  arg(){
    Node* ptr=new Node();
    ptr->type=ARGN;
    ptr->child[0]=type();
    if(currentToken.type==ID){
        ptr->child[1]=new Node();
        ptr->child[1]->Lexeme=currentToken.name;
        ptr->child[1]->type=IDN;
    }
    match(ID);
    return ptr;
}

//*****************************************
/// <identlist> ::= ID , <identlist>
Node*  identlist(){
    Node* ptr=new Node();
    ptr->type=IDENTLISTN;
    ptr->child[0]=new Node();
    ptr->child[0]->type=IDN;
    ptr->child[0]->Lexeme=currentToken.name;
    match(ID);
    if(currentToken.type==COMMA){
        ptr->child[1]=new Node();
        ptr->child[1]->Lexeme=currentToken.name;
        ptr->child[1]->type=COMMAN;
    }
    match(COMMA);
    ptr->child[2]=identlist();
    return ptr;
}
//*****************************************
/// <compare> ::= < | <= | <> | = | > | >=
Node*  compare(){
    Node* ptr=new Node();
    ptr->type=COMPAREN;
    switch(currentToken.type){
    case LESS:
        ptr->child[0]=new Node();
        ptr->child[0]->type=LESSN;
        ptr->child[0]->Lexeme=currentToken.name;
        match(LESS);
        break;
    case LESSEQUAL:
        ptr->child[0]=new Node();
        ptr->child[0]->type=LESSEQUALN;
        ptr->child[0]->Lexeme=currentToken.name;
        match(LESSEQUAL);
        break;
    case EQUAL:
        ptr->child[0]=new Node();
        ptr->child[0]->type=EQUALN;
        ptr->child[0]->Lexeme=currentToken.name;
        match(EQUAL);
        break;
    case NOTEQUAL:
        ptr->child[0]=new Node();
        ptr->child[0]->type=NOTEQUALN;
        ptr->child[0]->Lexeme=currentToken.name;
        match(NOTEQUAL);
        break;
    case GREATER:
        ptr->child[0]=new Node();
        ptr->child[0]->type=GREATERN;
        ptr->child[0]->Lexeme=currentToken.name;
        match(GREATER);
        break;
    case GREATEREQUAL:
        ptr->child[0]=new Node();
        ptr->child[0]->type=GREATEREQUALN;
        ptr->child[0]->Lexeme=currentToken.name;
        match(GREATEREQUAL);
        break;
    default:
        syntaxError(currentToken);
    }
    return ptr;
}
//*****************************************
/// <expr> ::= id = expr
Node*  expr(){
    Node* ptr= new Node();
    ptr->type=EXPRN;
    ptr->child[0]=new Node();
    ptr->child[0]->type=IDN;
    ptr->child[0]->Lexeme=currentToken.name;
    match(ID);
    if(currentToken.type== EQUAL){
        ptr->child[1]=new Node();
        ptr->child[1]->Lexeme=currentToken.name;
        ptr->child[1]->type=EQUALN;
    }
    match(EQUAL);
    ptr->child[2]=expr();
    return ptr;
}

//***************************************************************************************************************************
//***************************************** END OF PRIVATE MEMBERS **********************************************************
//***************************************************************************************************************************
public:
    Parser(string fileName){
		f.open(fileName.c_str());
			 if (!f)
		     {
		          cout<<"Unable to open file"<<endl; //system("pause");
		          //exit(1);
		     }
	}
//*****************************************
    ~Parser(){
		f.close();
	}
//*****************************************
//<sampleParser> ::= <function> eof
void  sampleParser(){
	    Node* ptr = new Node();									//START
	    root=ptr;

	    ptr->type=START;
	    currentToken=getToken();
	    ptr->child[0]=function();
	    if(currentToken.type==ENDSOURCE){
	        ptr->child[1]=new Node();
	        ptr->child[1]->Lexeme=currentToken.name;
	    }
	    match(ENDSOURCE);
}

//******************************************
void displayTree(Node* Tree){		//Tree = root
    if(Tree){
        cout<<"|||| " <<Tree->Lexeme<<endl;
        displayTree(Tree->child[0]);
        displayTree(Tree->child[1]);
        displayTree(Tree->child[2]);
        displayTree(Tree->child[3]);
        displayTree(Tree->child[4]);
        displayTree(Tree->child[5]);
    }
}
//*****************************************

//*****************************************
};	// Class Ending

int main(){
	string filename;
	cout<<"Enter Filename: ";
	cin>>filename;
    Parser in(filename);
    in.sampleParser();
    in.displayTree(root);
    system("pause");
    return 0;
}
