   #include <iostream>
   #include <time.h> 
   #include <fstream>
   #include <conio.h>                   
   #include <cstdio>
   #include <stdlib.h>                                                               //HAIL HYDRA 
   using namespace std ;        
                            
     /* Change logs: 
                      Version 1: Got program running, lots of bugs
                      Version 2: Got the logic up, works for single words only    //(These versions do not contain classes or structures)
                      Version 3: Multi Word sentences now supported
                      Version 4: Fixed many bugs
                      Version 4.5: Fixed issues with player winning by re-entering already entered words and raising score to threshhold.
                      Version 5: Stable condition. Full release.
                      
                      Version 5.1: Implemented Classes and arranged the functions. Optimised program. 
                      Version 5.2: Final bug fixes underway.
                      To come: Version 6: Database with words.
                      
                      Version 6 Beta: Implemented Word Database. Randomisation next.
                      Version 6 Release: Finished game. UNCRASHABLE. Enjoy!
                                _______
                                |     |
                                |     0
                                |    /|\
                                |     |
                                |    / \          
                                |
                                |_________  */
                                


char key(char ch){
        
       return ch  ;          //Cool little function i made.

}

struct words
{ 
  int r, n;  
  string name;
  string word, clue ;
  string clas, division ;
  



}   ;

class game
{                                
   private: 
        int mistakes, n, j, i, k , w , count , z, y,  flag2, score, hscore;        //Ignore warnings here
        words x ;
             
       string clue, Word;
       char ch, guess, reveal[] ;
       
               
                                    
       void hangman(int mistakes)
    {   
        
        if (mistakes == 0)
            cout<<endl<<"_______\n|     |\n|\n|\n|\n|\n|\n|\n________\n\n\n" ;
        else if(mistakes == 1)
            cout<<endl<<"_______"<<endl<<"|     |"<<endl<<"|     0"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<"________"<<endl<<endl<<endl;
        else if(mistakes == 2)
            cout<<endl<<"_______"<<endl<<"|     |"<<endl<<"|     0"<<endl<<"|     |"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<"________"<<endl<<endl<<endl;
      else if(mistakes == 3)
            cout<<endl<<"_______"<<endl<<"|     |"<<endl<<"|     0"<<endl<<"|    /|"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<"________"<<endl<<endl<<endl;
      else if(mistakes == 4)
            cout<<endl<<"_______"<<endl<<"|     |"<<endl<<"|     |  " <<endl<<"|     0"<<endl<<"|    /|\\"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<"________"<<endl<<endl<<endl;
      else if(mistakes == 5)
            cout<<endl<<"_______"<<endl<<"|     |"<<endl<<"|     |  " <<endl<<"|     0"<<endl<<"|    /|\\"<<endl<<"|     |"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<"________"<<endl<<endl<<endl;
      else if(mistakes == 6)
            cout<<endl<<"_______"<<endl<<"|     |"<<endl<<"|     |  " <<endl<<"|     0"<<endl<<"|    /|\\"<<endl<<"|     |"<<endl<<"|    /"<<endl<<"|"<<endl<<"|"<<"________"<<endl<<endl<<endl;
      else if (mistakes == 7)
            cout<<endl<<" _______"
                <<endl<<" |     |   " 
                <<endl<<" |     |  " 
                <<endl<<" |     0  "
                <<endl<<" |    /|\\"
                <<endl<<" |     |"
                <<endl<<" |    / \\"
                <<endl<<" |         "
                <<endl<<" |       "  
                <<endl<<" |"<<"__________\n!...........!\n\n\n\n"   ;
      

            //AAAAAAGGGHHHHH!
    }
       
    
    //This function handles the game things.
    void gameprocess(string, int , char b[], int, string, string clas = "XII", string division = "A", string name = "Admin"); 
   
   public:
    game() {
    n = 0 ; score = 0; k = 0; w = 0 ;
    string& a = Word ;
    }
    void Database(){
    fstream database    ;
          x.name = "Admin"  ;
          x.clas = "XII"    ;
          x.division = "A1" ;
          cout<<"Enter Word = " ;
           getline(cin,Word,'\n');
          n = Word.length()  ;
          cout<<"Number of letters to show = " ;
          cin>> k ;
          for(i = 0; i< k; i++ )
          cin>>reveal[i] ;
          cout<<"Enter clue = " ;
          cin>>x.clue ;
         
          database.open("Word_Database.txt", ios::out | ios::app)   ;
                            
          database <<endl<< x.clas<<' ' << x.clue<<' ' << x.division<< ' ' << x.name<< ' ' << k << ' ' << (n)<< ' ' ; 
          for(int i = 0; i< k; i++)
            database << reveal[i] << ' '  ;
                                                                                   //Format:
            database<<Word<<' ' ;                       //Class, clue, division, name, reveal size, word size, reveal letters, sentence
          
          cout<< " \nboop\n "    ;
          database.close() ; 
    }     ;
    
    
       void intro1()
{
hangman(7) ;
                cout<<"WELCOME TO HANG MAN!\n____________________    - Made with C++ Programming language and Codeblocks.  Press Enter"<<endl ;
            

getch() ; system("CLS") ; //clrscr() doesnt work.
        
                cout<<endl<<endl<<endl<<"Player 1 Inputs a Sentence\n"  ;
                cout<<"Player 2 then has 7 CHANCES to get it right.\n Press Enter."  ;
                            
getch() ; system("CLS") ;
        
                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                
}
       
void startgame1(){
           
           start:
           
           cout<<endl<<"Turn around, Player 2! " ;
           cout<<"\n\nEnter the Sentence  =  ";
        
        getline(cin,Word,'\n');
        n = Word.length() -1 ;         //I dont know why I did this. Dont change it.
                   
        if (n < 0)                              //If person doesn't enter a word..
            goto start ;

        char reveal[n]  ;
        cout<<endl<<"**Number** of letters to show: " ;
        cin>> k;       //k is later used as the number of letters found.

       if(k!=0)
       {
        cout<<endl<<"Enter those letter[s] one at a time = " ;
        for (j=0; j<n; j++){
            { 
              if (j < k)
            cin>>reveal[j];
            else reveal[j] = '`'  ;
            }    //Garbage values mess with not assigning to an array. hence need some value for empty array cell
        }
       }
    cout<<endl<<"ONE word clue = "<<endl ;
    cin>>clue ;
    cout<<endl<<"The Sentence is: " << Word ;
        
    cout<<"\n\n\nEnter your name for stats = " ;
    cin>> x.name ;
    system("CLS")     ;
    cout<<"Tell Player 2 to Turn around. Press Enter To Begin." ;
    system("CLS")     ;
    cout<<"Player 2 Press Enter to Begin! " ; 
    getch() ;
            
            gameprocess(Word, n +1 ,  reveal, k, clue) ;
   {
        //Database Prompt                                                       Had issues with variables, hence not seperate function.
            char ch ;
       
                                                                      ;
      cout << "Can I add your word to single player mode? [Y/N]"  ;
      ch = key(getch()) ;
      x.clas = '1'  ;
      x.division = 'b' ;
      
      cout<< "okay\n"     ;//Eh keep it, dont touch it.
      if(key(getch())=='y') 
      { cout<<endl<< "Enter your details: " ;                //No choice lol, was kidding.
          cout<<"\nWhat is your class and division = " ; cin>> x.clas >> x.division ; 
      }
          
          fstream database    ;
          
          database.open("Word_Database.txt", ios::out | ios::app)   ;
                            
          database <<endl<< x.clas<<' ' << clue<<' ' << x.division<< ' ' << x.name<< ' ' << k << ' ' << (n+1)<< ' ' ; 
          for(int i = 0; i< k; i++)
            database << reveal[i] << ' '  ;
                                                                                   //Format:
            database<<Word<<' ' ;                       //Class, clue, division, name, reveal size, word size, reveal letters, sentence
          
          cout<< " \nboop\n "    ;
          database.close() ; 
          cout<<"\n Thank you for contributing, your Word will now appear in One player Mode with your name! " ;
      

      getch() ;
        
      cout<<"\n\n\nHope you liked the game!"<<endl<<"-Sandeep Pillai "  ;
     
      getch() ;
        }
       
       
}
  void logo() { hangman(7) ; }        

    void intro2(){
            
            hangman(7) ;
        cout<<"Hangman Single Player mode"<<endl ;
            

        getch() ; system("CLS") ; //clrscr() doesnt work.
        cout<<endl<<endl<<endl<<"A sentence will be selected randomly, contributed by other players.\n\nYou have 7 chances to Save your stupid friend or he will be HANGED! " ;
        
                  getch() ;        
            
        } 
        
        void startgame2(){
                int pos = 0, w  ;
                
                fstream files         ;
                files.open("Word_Database.txt", ios::in) ;
                 while(!files.eof())
                   {                                   //Number of lines in a text file.
                    getline(files, x.name)  ; pos++ ;
                     }                                                   
               files.seekg(0, ios::beg)       ;
                srand(time(NULL));
                
                w = rand()%(pos)       ;            //Randomising word selection
                
                
                for(i = 0; i< w ; i++)
                    getline(files, x.name)   ;
                       ;
                    files >> x.clas >> x.clue >> x.division >> x.name >>  x.r >> x.n  ;
                for(w = 0 ; w < x.r; w++ )
                    files>> reveal[w] ;
                for( w = x.r ;w < x.n ; w++)
                        reveal[w] = '0' ;                   //Store word data in words struct
                getline(files,x.word,'\n');
                files.close() ;
               
               
                    
                cout<< " \nboop\n "    ;
                for(i = 0; i< 100; i++) 
                cout<< " Abracadabra!\n\n "    ;
                gameprocess(x.word, x.n +1, reveal, x.r, x.clue, x.clas, x.division, x.name)  ;
        }       
} ;
                                                    //Handles the game. Used to not be part of the class. Hence arguments
   void game::gameprocess(string a, int n, char b[], int i, string clue, string clas, string division, string name)
{
     
     
    mistakes = 0,
    system("CLS") ;
          


           
    int temp = i ; char mist[8] ;


        while (mistakes<=7)
            {   hscore = 1  ;          //When hscore remains constant, all letters are found..
                
            word:
            system("CLS") ; //CLRSCR() doesn't work apparently..
            hangman(mistakes);
            if(x.name!="Admin")
        cout<<endl<<"This word is contributed by: " <<x.name<<" | "<<x.clas<<' '<<x.division<<endl ;
        cout<<"Guess the WORD!\n\n" ; 
        if(mistakes>0)
        {
            cout<<"Mistake Letters: " ; 
            for(j = 0; j < mistakes ; j++ )
            cout<< mist[j]<<' ' ;
            if(mistakes == 6) 
                cout<<"   LAST CHANCE!"    ;
        }
        
        
/////////////////////////////////////////////////////////////////////////////////////////
// Display the Word                                                                    //
// Check the Word                                                                      //
/////////////////////////////////////////////////////////////////////////////////////////       
       
        cout<<"\nTHE WORD IS : \n " ;
            for(j = 0; j<n; j++)  //Prints the word like (exa_p_e)...
                {
                    flag2 = 0 ;
                    if (a[j] == char(32)) //32 = spacebar
                    { cout<<"   " ;     //leaves space for next word
                        flag2++ ;  //When hscore = Word[], all the spaces are filled - game won.
                    }

                    else  {
                        for (z = 0; z<n; z++)
                        {
                         if(a[j] == b[z])
                          {                                   // [If letter is in found array, print it]
                            cout<<" "<<b[z] ;
                            flag2++ ;
                          }
                            else continue ;
                        }

                          }
                if (flag2 == 0)             //When no occourance of Word[] found in reveal[], a blank "_" is printed.
                {
                    cout<<" _" ;
                    hscore = 0 ;
                } 
                }
                
if (mistakes == 7)
    { score = 7 ;
                         goto end ;
    }
if (hscore == 1)                  //Checks if game won or lost. [Fail conditions] 
    {
        score = mistakes ;
        mistakes = 10 ;
        goto end ;
    }
               
               
    cout<<"\n\n\n\nYou can give up by hitting ']'\nThe clue for the Word[s] is: "<<clue;
    cout<<endl<<endl<<"Enter a letter to guess :" ;
    while(1){
        guess = key(getch()) ;
        if(isalnum(guess))
            break ;
        if(guess == ']')
           {mistakes = 7 ; goto end;}
    }
    int conflict = 0 ;
                 
    for(j = 0; j<n; j++)
        {
            for(y = 0; y<n; y++)
            {
            if (guess == b[y])
            conflict++ ;                    //This checks if letter already given
            }
            if (conflict == 0)
            { 
             for(y = 0; y<n; y++)
                {
                if (guess == a[y])                           //This checks if letter is correct
                    {
                        cout<<"\nCorrect Letter!" ;
                        score++;  b[i] = guess ; i++;  goto loop  ;
                    }
                else continue ;

                }
                cout<<endl<<"\nWRONG LETTER!";
                mist[mistakes] = guess ; mistakes++ ; goto loop;

            }
        else {cout<<endl<<"\nLETTER ALREADY GIVEN!" ;
        goto loop   ;
             }

        }
        
    loop:
    cout<<"\n\nPress any key ONCE" ; 
    getch();
        

}
end:                                       //END GAME
 system("CLS") ; 
 hangman(score) ;
 
    if (mistakes == 7)
   {
    cout<<endl<<endl<<"GAME OVER!"<<endl<<"You Lose!" <<endl <<"The Word was: \n\n"  ;
     for(i = 0; i<n; i++)
        cout<<" "<<a[i] ;
        cout<<" !" ;
   }
    else {   for(i = 0; i<n; i++)
    cout<<" "<<a[i] ;
    cout<<endl<<endl<<"Good job!"<<endl<<" You win!" <<endl<<"Your Score = "<<(7 - score)*n*100<<endl<<endl ;         
    }
    
    cout<<endl<<"\n\nThanks for Playing! Check out Single Player mode!"<<endl ;
    getch() ;
}              
  




int main() {
    char ch ;
    start:   system("CLS")     ;
    cout<<"\n\n	H A N G M A N  2\n	________________\n" ;
while(1){
    game player ;
    cout<<endl<<"\n********************************\n(1) Enter 'A' for Two players\n(2) Enter 'S' for One player"<<endl ;
    cout<<"(3) Enter '?' for Instructions\n(4) Enter 'D' for Game Details\n(5) Enter 'Q' to Exit the Game!\n********************************\n" ;
    repeat:
    ch = tolower(key(getch())) ;
    if(ch == 's')
    {   system("CLS") ;
	player.intro2() ;
	player.startgame2() ;
	break ;
    }
    else if(ch == 'a')
    {  	system("CLS") ;
	player.intro1() ;
	player.startgame1() ;
	break ;
    }
    else if(ch == 'q')
	return 0 ;
    else if(ch == 'd')
    {   system("CLS");
	cout<<"\nGame Details: \n Game made by Sandeep Pillai and Gautham Panicker\n XII A1\n" ;
	cout<<"\n Concepts used: classes, structures, Files.\n" ;
	cout<<"\n Single Player mode generates a random word from a list contributed by people who play multiplayer player mode, which is stored in a text file." ;
    }
    else if(ch == '/')
       { system("CLS") ;
	cout<<"\nInstructions: \n A half filled Sentence is given to you.\n It is up to you to guess the missing letters.\n If you make more than SEVEN (7) mistakes, you lose and your friend dies.. \n" ;
	}
    else if(ch == '0')
    { system("CLS")     ;
      cout<<"Developer console, dont touch!\n" ;
      player.Database() ;
    }
    else goto start;
}

cout<<"\nPress S to Play again! Any other key to exit!" ;
  if(tolower(getch()) == 's') goto start ;
return 0 ;
}                           
                                                                                                     //Sandeep Pillai
