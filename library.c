#include <string.h>
#include <stdio.h>
#include <ctype.h>

int encoder(char buffer[], char morsebuffer[]){

    switch(tolower(buffer[0]))
        {
        case 'a':
        strcpy(morsebuffer,".- ");
        break;
        case 'b':
        strcpy(morsebuffer,"-... ");
        break;
        case 'c':
        strcpy(morsebuffer,"-.-. ");
        break;
        case 'd':
        strcpy(morsebuffer,"-.. ");
        break;
        case 'e':
        strcpy(morsebuffer,". ");
        break;
        case 'f':
        strcpy(morsebuffer,"..-. ");
        break;
        case 'g':
        strcpy(morsebuffer,"--. ");
        break;
        case 'h':
        strcpy(morsebuffer,".... ");
        break;
        case 'i':
        strcpy(morsebuffer,".. ");
        break;
        case 'j':
        strcpy(morsebuffer,".--- ");
        break;
        case 'k':
        strcpy(morsebuffer,"-.- ");
        break;
        case 'm':
        strcpy(morsebuffer,"-- ");
        break;
        case 'l':
        strcpy(morsebuffer,".-.. ");
        break;
        case 'n':
        strcpy(morsebuffer,"-. ");
        break;
        case 'o':
        strcpy(morsebuffer,"--- ");
        break;
        case 'p':
        strcpy(morsebuffer,".--. ");
        break;
        case 'q':
        strcpy(morsebuffer,"--.- ");
        break;
        case 'r':
        strcpy(morsebuffer,".-. ");
        break;
        case 's':
        strcpy(morsebuffer,"... ");
        break;
        case 't':
        strcpy(morsebuffer,"- ");
        break;
        case 'u':
        strcpy(morsebuffer,"..- ");
        break;
        case 'v':
        strcpy(morsebuffer,"...- ");
        break;
        case 'w':
        strcpy(morsebuffer,".-- ");
        break;
        case 'x':
        strcpy(morsebuffer,"-..- ");
        break;
        case 'y':
        strcpy(morsebuffer,"-.-- ");
        break;
        case 'z':
        strcpy(morsebuffer,"--.. ");
        break;
        case '0':
        strcpy(morsebuffer,"----- ");
        break;
        case '1':
        strcpy(morsebuffer,".---- ");
        break;
        case '2':
        strcpy(morsebuffer,"..--- ");
        break;
        case '3':
        strcpy(morsebuffer,"...-- ");
        break;
        case '4':
        strcpy(morsebuffer,"....- ");
        break;
        case '5':
        strcpy(morsebuffer,"..... ");
        break;
        case '6':
        strcpy(morsebuffer,"-.... ");
        break;
        case '7':
        strcpy(morsebuffer,"--... ");
        break;
        case '8':
        strcpy(morsebuffer,"---.. ");
        break;
        case '9':
        strcpy(morsebuffer,"----. ");
        break;
        case '.':
        strcpy(morsebuffer,".-.-.- ");
        break;
        case ',':
        strcpy(morsebuffer,"--..-- ");
        break;
        case ':':
        strcpy(morsebuffer,"--.. ");
        break;
        case '?':
        strcpy(morsebuffer,"..--.. ");
        break;
       // case '´':
       // strcpy(morsebuffer,".----. ");
       // break;
        case '-':
        strcpy(morsebuffer,"-....- ");
        break;
        case '/':
        strcpy(morsebuffer,"-..-. ");
        break;
        case '(':
        strcpy(morsebuffer,"-.--.- ");
        break;
        case '"':
        strcpy(morsebuffer,".-..-. ");
        break;
        case ' ':
        strcpy(morsebuffer,"...-.. ");
        break;
        case '\n':
        strcpy(morsebuffer,"..-.- ");
        break;
        default:
        strcpy(morsebuffer,"........ ");
        printf("unknown character\n");
        break;
    }

return 0;
}

int decoder(char morsebuffer[], char buffer[]){

        if (strcmp(morsebuffer,".-")==0){
        strcpy(buffer,"a");
        } else if (strcmp(morsebuffer,"-...")==0){
        strcpy(buffer,"b");
        } else if (strcmp(morsebuffer,"-.-.")==0){
        strcpy(buffer,"c");
        } else if (strcmp(morsebuffer,"-..")==0){
        strcpy(buffer,"d");
        } else if (strcmp(morsebuffer,".")==0){
        strcpy(buffer,"e");
        } else if (strcmp(morsebuffer,"..-.")==0){
        strcpy(buffer,"f");
        } else if (strcmp(morsebuffer,"--.")==0){
        strcpy(buffer,"g");
        }else if (strcmp(morsebuffer,"....")==0){
        strcpy(buffer,"h");
        } else if (strcmp(morsebuffer,"..")==0){
        strcpy(buffer,"i");
        } else if (strcmp(morsebuffer,".---")==0){
        strcpy(buffer,"j");
        } else if (strcmp(morsebuffer,"--")==0){
        strcpy(buffer,"m");
        } else if (strcmp(morsebuffer,"-.-")==0){
        strcpy(buffer,"k");
        } else if (strcmp(morsebuffer,".-..")==0){
        strcpy(buffer,"l");
        } else if (strcmp(morsebuffer,"-.")==0){
        strcpy(buffer,"n");
        } else if (strcmp(morsebuffer,"---")==0){
        strcpy(buffer,"o");
        } else if (strcmp(morsebuffer,".--.")==0){
        strcpy(buffer,"p");
        } else if (strcmp(morsebuffer,"--.-")==0){
        strcpy(buffer,"q");
        } else if (strcmp(morsebuffer,".-.")==0){
        strcpy(buffer,"r");
        } else if (strcmp(morsebuffer,"...")==0){
        strcpy(buffer,"s");
        } else if (strcmp(morsebuffer,"-")==0){
        strcpy(buffer,"t");
        } else if (strcmp(morsebuffer,"..-")==0){
        strcpy(buffer,"u");
        } else if (strcmp(morsebuffer,"...-")==0){
        strcpy(buffer,"v");
        } else if (strcmp(morsebuffer,".--")==0){
        strcpy(buffer,"w");
        } else if (strcmp(morsebuffer,"-..-")==0){
        strcpy(buffer,"x");
        } else if (strcmp(morsebuffer,"-.--")==0){
        strcpy(buffer,"y");
        } else if (strcmp(morsebuffer,"--..")==0){
        strcpy(buffer,"z");
        } else if (strcmp(morsebuffer,"-----")==0){
        strcpy(buffer,"0");
        } else if (strcmp(morsebuffer,".----")==0){
        strcpy(buffer,"1");
        } else if (strcmp(morsebuffer,"..---")==0){
        strcpy(buffer,"2");
        } else if (strcmp(morsebuffer,"...--")==0){
        strcpy(buffer,"3");
        } else if (strcmp(morsebuffer,"....-")==0){
        strcpy(buffer,"4");
        } else if (strcmp(morsebuffer,".....")==0){
        strcpy(buffer,"5");
        } else if (strcmp(morsebuffer,"-....")==0){
        strcpy(buffer,"6");
        } else if (strcmp(morsebuffer,"--...")==0){
        strcpy(buffer,"7");
        } else if (strcmp(morsebuffer,"---..")==0){
        strcpy(buffer,"8");
        } else if (strcmp(morsebuffer,"----.")==0){
        strcpy(buffer,"9");
        } else if (strcmp(morsebuffer,".-.-.-")==0){
        strcpy(buffer,".");
        } else if (strcmp(morsebuffer,"--..--")==0){
        strcpy(buffer,",");
        } else if (strcmp(morsebuffer,"--..")==0){
        strcpy(buffer,":");
        } else if (strcmp(morsebuffer,"..--..")==0){
        strcpy(buffer,"?");
        } else if (strcmp(morsebuffer,"-....-")==0){
        strcpy(buffer,"-");
        } else if (strcmp(morsebuffer,"-..-.")==0){
        strcpy(buffer,"/");
        } else if (strcmp(morsebuffer,".-..-.")==0){
        strcpy(buffer,"\"");
        } else if (strcmp(morsebuffer,"..-.-")==0){
        strcpy(buffer,"\n");
        }else if (strcmp(morsebuffer,"...-..")==0) {
        strcpy(buffer," ");
        } else {
        strcpy(buffer,"_");
        }


return 0;
}
