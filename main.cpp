#include <iostream> //library for cout cin and input output streams
#include <vector> //Library for using vectors instead of arrays
#include <windows.h> //Library for using Windows System Colours
#include <mmsystem.h> //Library for accessing windows multimedia method
#pragma comment(lib, "winmm.lib"); //USE PRAGMA TO ACCESS THE WINDOWS MEDIA LIBRARIES FOR PLAYSOUND

using namespace std;

//////////////////////////////////
////////Function Prototypes///////
//////////////////////////////////
void flash();
void screen();
void font();
void greetingfont();
void cursoroff();
void toUpper();
//////////////////////
//General Flash Function///// 
////////////////////
void flash(){
  
    int counter = 10;
    for(int i=1; i<=counter; i++){
    system("COLOR 1");
    Sleep(30);
    system("COLOR 2");
    Sleep(30);
    system("COLOR 3");
    Sleep(30);
    system("COLOR 4");
    
    }
}

void screen(){
     //Maximize the terminal window requires the windows.h library
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
    
}

void font(){
    
    //Change The Font Type and Size In the Console
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 24;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_BOLD;
    std::wcscpy(cfi.FaceName, L"ComicSans"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void greetingfont(){
    
    //Change The Font Type and Size In the Console
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 40;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_BOLD;
    std::wcscpy(cfi.FaceName, L"ComicSans"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
//////Function to turn off the blinking cursor in the terminal
void cursoroff(){
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}

void toUpper(basic_string<char>& choice) {
   for (basic_string<char>::iterator p = choice.begin();
        p != choice.end(); ++p) {
      *p = toupper(*p); // toupper is for char
   }
}

int main() {
 
    screen();
    
    font();
    
    system("COLOR 2");

    string greeting ={};
    
    string baloontxt ={};
    
    unsigned char block = 254;
   
    cout << "Please enter your greeting: " << endl;
    
    getline(cin,greeting);
   
    toUpper(greeting);
    
    vector<char> output(greeting.begin(), greeting.end());
    
    system("CLS"); 
    
    //Turn the terminal flashing cursor off
    cursoroff();  
    
    greetingfont();
    
    cout << "\n\n\n\n\n\n\n\n";
    cout << "        ";
    cout << block;    
    Sleep(200);
    //The \b switch deletes the previous character from the cout display, thus with a 
    //sleep it creates a pause and when placed in the below for loop creates a 
    //flashing block using the ascii character 254
    cout << "\b";
    
    PlaySound(TEXT("C://Users//jonat//Workspaces//GreetingApp//GreetingApp//cursor.wav"),NULL,SND_ASYNC);    
    
        for(size_t i=0; i<output.size(); i++){
            cout << output[i];
            cout << block;
            Sleep(130);
            cout << "\b";
            cout << " ";
            Sleep(130);
            cout << "\b";
            
            baloontxt+=output[i];
        }
    
    Sleep(1200);
    
    system("CLS");
    
    font();    
    
    cout << baloontxt << endl;
    
    cout << R"(        ,,,,,,,,,,,,,
    .;;;;;;;;;;;;;;;;;;;,.
  .;;;;;;;;;;;;;;;;;;;;;;;;,
.;;;;;;;;;;;;;;;;;;;;;;;;;;;;.
;;;;;@;;;;;;;;;;;;;;;;;;;;;;;;' .............
;;;;@@;;;;;;;;;;;;;;;;;;;;;;;;'.................
;;;;@@;;;;;;;;;;;;;;;;;;;;;;;;'...................
`;;;;@;;;;;;;;;;;;;;;@;;;;;;;'.....................
 `;;;;;;;;;;;;;;;;;;;@@;;;;;'..................;.... 
   `;;;;;;;;;;;;;;;;@@;;;;'....................;;...
     `;;;;;;;;;;;;;@;;;;'...;.................;;....
        `;;;;;;;;;;;;'   ...;;...............;.....
           `;;;;;;'        ...;;..................
              ;;              ..;...............
              `                  ............
             `                      ......
            `                         ..
           `                           '
          `                           '
         `                           '
        `                           `
        `                           `,
        `.)";
    flash();
    
    system("COLOR 1");
        
    Sleep(1200);
    
    system("CLS");
    
    cout << "\n\n";
    
    cout << "HAPPY 21ST BIRTHDAY JESSICA LOVE BUBBLES XX" << endl;
    
    cout << R"(                         
                 _uP~"b          d"u,
                dP'   "b       ,d"  "o
               d"    , `b     d"'    "b
              l] [    " `l,  d"       lb
              Ol ?     "  "b`"=uoqo,_  "l
            ,dBb "b        "b,    `"~~TObup,_
          ,d" (db.`"         ""     "tbc,_ `~"Yuu,_
        .d" l`T'  '=                      ~     `""Yu,
      ,dO` gP,                           `u,   b,_  "b7
     d?' ,d" l,                           `"b,_ `~b  "1
   ,8i' dl   `l                 ,ggQOV",dbgq,._"  `l  lb
  .df' (O,    "             ,ggQY"~  , @@@@@d"bd~  `b "1
 .df'   `"           -=@QgpOY""     (b  @@@@P db    `Lp"b,
.d(                  _               "ko "=d_,Q`  ,_  "  "b,
Ql         .         `"qo,._          "tQo,_`""bo ;tb,    `"b,
qQ         |L           ~"QQQgggc,_.,dObc,opooO  `"~~";.   __,7,
qp         t\io,_           `~"TOOggQV""""        _,dg,_ =PIQHib.
`qp        `Q["tQQQo,_                          ,pl{QOP"'   7AFR`
  `         `tb  '""tQQQg,_             p" "b   `       .;-.`Vl'
             "Yb      `"tQOOo,__    _,edb    ` .__   /`/'|  |b;=;.__
                           `"tQQQOOOOP""`"\QV;qQObob"`-._`\_~~-._
                                """"    ._        /   | |oP"\_   ~\ ~\_~\
                                        `~"\ic,qggddOOP"|  |  ~\   `\~-._
                                          ,qP`"""|"   | `\ `;   `\   `\
                               _        _,p"     |    |   `\`;    |    |
                               "boo,._dP"       `\_  `\    `\|   `\   ;
                                 `"7tY~'            `\  `\    `|_   |
                                                      `~\  |)";
      

    system("COLOR 2");
    
    Sleep(4000);
    
    return 0;    
}
