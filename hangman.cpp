#include <iostream>
#include <time.h>
#include <unistd.h>


using namespace std;
string CLS = "\033[2J\033[1;1H";
string Red = "\033[31;1m";
string Green = "\033[32;1m";
string Yellow = "\033[33;1m";
string Blue = "\033[34;1m";
string Purple = "\033[35;1m";
string Cyan = "\033[36;1m";
string White = "\033[37;1m";
string Default = "\033[0m"; // default gray color & reset background to black

string WhiteOnRed = "\033[41;1m";
string WhiteOnGreen = "\033[42;1m";
string WhiteOnYellow = "\033[43;1m";
string WhiteOnBlue = "\033[44;1m";
string WhiteOnPurple = "\033[45;1m";
string WhiteOnCyan = "\033[46;1m";

int playAgain;
int wins;
int loss;

int main(){
	srand(time(NULL)); //seeding
	do{
		//play music
		system("open music.mp3");
	
		//step 1- intro screen: mythological hangman with a nice image 

	
		//do a white dragonWhite
		cout << White<<"  " << "                                                 /===-_---~~~~~~~~~------____"<< endl;    
		cout << White<<"  " << "                                                |===-~___                _,-'"<< endl;
		cout << White<<"  " << "                 -==\\                         `//~\\   ~~~~`---.___.-~~     "<< endl;   
		cout << White<<"  " << "             ______-==|                         | |  \\           _-~`       "<< endl;
		cout << White<<"  " << "       __--~~~  ,-/-==\\                        | |   `\\        ,'          "<< endl;
		cout << White<<"  " << "    _-~       /'    |  \\                      / /      \\      /            "<< endl;
		cout << White<<"  " << "  .'        /       |   \\                   /' /        \\   /'             "<< endl;
		cout << White<<"  " << " /  ____  /         |    \\`\\.__/-~~ ~\\ _ _/'  /        \\/'               "<< endl;
		cout << White<<"  " << "/-'~    ~~~~~---__  |     ~-/~         ( )   /'        _--~`                 "<< endl;
		cout << White<<"  " << "                  \\_|      /        _)   ;  ),   __--~~                     "<< endl;
		cout << White<<"  " << "                    '~~--_/      _-~/-  / \\   '-~\\                         "<< endl;
		cout << White<<"  " << "                   {\\__--_/}    / \\_>- )<__\\     \\                       "<< endl;
		cout << White<<"  " << "                   /'   (_/  _-~  | |__>--<__|      |                        "<< endl;
		cout << White<<"  " << "                  |0  0 _/) )-~     | |__>--<__|     |                       "<< endl;
		cout << White<<"  " << "                  / /~ ,_/       / /__>---<__/      |                        "<< endl;
		cout << White<<"  " << "                 o o _//        /-~_>---<__-~      /                         "<< endl;
		cout << White<<"  " << "                 (^(~          /~_>---<__-      _-~                          "<< endl;
		cout << Red   <<"  " << "                ,/|   "<< White << "        /__>--<__/     _-~                             "<< endl;
		cout << Red   <<"  " << "             ,//('(   "<< White << "       |__>--<__|     /                  .----_        "<< endl;
		cout << Red   <<"  " << "            ( ( '))   "<< White << "       |__>--<__|    |                 /' _---_~\\     "<< endl;
		cout << Red   <<"  " << "         `-)) )) (    "<< White << "       |__>--<__|    |               /'  /     ~\\`\\  "<< endl;
		cout << Red   <<"  " << "        ,/,'//( (     "<< White << "       \\__>--<__\\  \\            /'  //        ||    "<< endl;
		cout << Red   <<"  " << "      ,( ( ((, ))     "<< White << "         ~-__>--<_~-_  ~--____---~' _/'/        /'     "<< endl;
		cout << Red   <<"  " << "    `~/  )` ) ,/|     "<< White << "            ~-_~>--<_/-__       __-~ _/                "<< endl;
		cout << Red   <<"  " << "  ._-~//( )/ )) |`    "<< White << "                ~~-'_/_/ /~~~~~~~__--~                 "<< endl;              
		cout << Red   <<"  " << "   ;'( ')/ ,)( \\     "<< White << "                       ~~~~~~~~~~                      "<< endl;
		cout << Red   <<"  " << "  ' ') '( (/   \\     "<< White << "                                                       "<< endl;
		cout << Red   <<"  " << "    '   '  `          "<< White << "                                                       "<< endl;
	

		cout << endl;
		cout << endl;
		cout<< Red<<"    ███▄ ▄███▓▓██   ██▓▄▄▄█████▓ ██░ ██  ██▓ ▄████▄   ▄▄▄       ██▓     "<< endl;
		cout<< Red<<"   ▓██▒▀█▀ ██▒ ▒██  ██▒▓  ██▒ ▓▒▓██░ ██▒▓██▒▒██▀ ▀█  ▒████▄    ▓██▒     "<< endl;
		cout<< Red<<"   ▓██    ▓██░  ▒██ ██░▒ ▓██░ ▒░▒██▀▀██░▒██▒▒▓█    ▄ ▒██  ▀█▄  ▒██░     "<< endl;
		cout<< Red<<"   ▒██    ▒██   ░ ▐██▓░░ ▓██▓ ░ ░▓█ ░██ ░██░▒▓▓▄ ▄██▒░██▄▄▄▄██ ▒██░     "<< endl;
		cout<< Red<<"   ▒██▒   ░██▒  ░ ██▒▓░  ▒██▒ ░ ░▓█▒░██▓░██░▒ ▓███▀ ░ ▓█   ▓██▒░██████▒ "<< endl;
		cout<< Red<<"   ░ ▒░   ░  ░   ██▒▒▒   ▒ ░░    ▒ ░░▒░▒░▓  ░ ░▒ ▒  ░ ▒▒   ▓▒█░░ ▒░▓  ░ "<< endl;
		cout<< Red<<"   ░  ░      ░ ▓██ ░▒░     ░     ▒ ░▒░ ░ ▒ ░  ░  ▒     ▒   ▒▒ ░░ ░ ▒  ░ "<< endl;
		cout<< Red<<"   ░      ░    ▒ ▒ ░░    ░       ░  ░░ ░ ▒ ░░          ░   ▒     ░ ░    "<< endl;
		cout<< Red<<"          ░    ░ ░               ░  ░  ░ ░  ░ ░            ░  ░    ░  ░ "<< endl;
		cout<< Red<<"               ░ ░                          ░                           "<< endl;
		cout<< Red<<"    ██░ ██  ▄▄▄       ███▄    █   ▄████  ███▄ ▄███▓ ▄▄▄       ███▄    █ "<< endl;
		cout<< Red<<"   ▓██░ ██▒▒████▄     ██ ▀█   █  ██▒ ▀█▒▓██▒▀█▀ ██▒▒████▄     ██ ▀█   █ "<< endl;
		cout<< Red<<"   ▒██▀▀██░▒██  ▀█▄  ▓██  ▀█ ██▒▒██░▄▄▄░▓██    ▓██░▒██  ▀█▄  ▓██  ▀█ ██▒"<< endl;
		cout<< Red<<"   ░▓█ ░██ ░██▄▄▄▄██ ▓██▒  ▐▌██▒░▓█  ██▓▒██    ▒██ ░██▄▄▄▄██ ▓██▒  ▐▌██▒"<< endl;
		cout<< Red<<"   ░▓█▒░██▓ ▓█   ▓██▒▒██░   ▓██░░▒▓███▀▒▒██▒   ░██▒ ▓█   ▓██▒▒██░   ▓██░"<< endl;
		cout<< Red<<"    ▒ ░░▒░▒ ▒▒   ▓▒█░░ ▒░   ▒ ▒  ░▒   ▒ ░ ▒░   ░  ░ ▒▒   ▓▒█░░ ▒░   ▒ ▒ "<< endl;
		cout<< Red<<"    ▒ ░▒░ ░  ▒   ▒▒ ░░ ░░   ░ ▒░  ░   ░ ░  ░      ░  ▒   ▒▒ ░░ ░░   ░ ▒░"<< endl;
		cout<< Red<<"    ░  ░░ ░  ░   ▒      ░   ░ ░ ░ ░   ░ ░      ░     ░   ▒      ░   ░ ░ "<< endl;
		cout<< Red<<"    ░  ░  ░      ░  ░         ░       ░        ░         ░  ░         ░ "<< endl;
		cout << endl;
		cout << endl;
	
		//instructions
		cout << White;	
		cout << "Welcome! This game is mythical themed hangman. The computer will choose a word and let you know how many characters there are using dots."<< endl;
		cout << "You will have to guess the letters in the phrase. You are allowed 6 incorrect guesses before you lose!" << endl;
		cout << "Each time you get a letter wrong the unicorn get closer to the grim reaper! Let's help to unicorn escape by guessing the phrase! Best of luck!!"<< endl;
	    cout<< Default;                                                                 
 
	
		//enter to start
		cout << endl;
		cout <<White << "Please press enter to start! ";
		cin.ignore();
		cout << CLS;
		cout << CLS;
		cout << endl;
		cout << endl;
	
		//let user choose if they want creatures or objects
		int choice;
		cout << "Would you like to play mythical creature or mythical objects hangman?" << endl;
		cout << "For creatures press 1, or press 2 for mythical objects:  ";
		cin >> choice;
	
		//creatures
		if (choice == 1){
			//step 2- select secret phrase
			string phrases[15]= {"Fire breathing dragon" , "Magical unicorns", "Centaurs", "Flying griffins", "Blood thirsty vampires", "Mischievous faeries", "Enchanting sirens", "Shapeshifting werewolves", "Loch ness monster", "Grim reaper", "Basilisk", "Leprechaun", "One eyed cyclops", "Shikigami", "Manticore" }; 
			string secretPhrase= phrases[rand()%15]; // 0 to 15 number
	
			//step 3- create guessPhrase and fill it with dots
			string guessPhrase=secretPhrase;
			for (int i=0; i < guessPhrase.size(); i++){
				if (guessPhrase[i] != ' '){
					guessPhrase[i]= '.';
				}
			}//dot loop
	
			cout << secretPhrase << endl;
			cout << guessPhrase << endl;
	
			//step 4- declare variables
			string letter;// user guesses
			string lettersRemaining= "abcdefghijklmnopqrstuvwxyz"; // the possible guesses
			int badGuesses=0; // counts the number of incorrect guesses
			int location;
	
			//step 5- game loop that runs as long secret phrase hasn't been guessed and is less than 6 incorrect tries
			while (guessPhrase != secretPhrase && badGuesses < 6){
				//step 6- graphics each bad guess unicorn gets closer!
	
				cout << CLS;
				if (badGuesses==0){
					cout << Red << "                                         .""--..___" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                     _                     []     ````-.._" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                  .'` `'.                  ||__           `-._" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<     ""<<endl; 
					cout << Red << "                 /    ,-.\\                 ||_ ```---..__     `-." << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                /    /:::\\               /|//}          ``--._  `." << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||              |////}                `-. \\" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||             //'///                    `.\\" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                |    |:::||            //  ||'                      `|" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                /    |:::|/      __,-//\\   ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "               /     |:::|-,__,-'   |/  \\  ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "             /;  |   |   ||          \\   | ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "           /    \\   |   ||            |  / ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< White <<       "      \\"<<endl; 
					cout << Red << "         |       |  |   |)            \\ |  ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<White <<       "       \\"<<endl; 
					cout << Red << "        |          \\ |   /      ,.__   \\|  ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<White <<       "        \\"<<endl; 
					cout << Red << "        /                    /`    \\   |   ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<       "        >\\/7"<<endl; 
					cout << Red << "       |                     /        \\  / ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<       "    _.-(6*  \\"<<endl; 
					cout << Red << "       |                     |        | /  ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "   (=___._/; \\"<<endl; 
					cout << Red << "       /         /           |         (   ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "        )  \\ |"<<endl; 
					cout << Red << "      /          .           /          )  ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "       /   / |"<<endl; 
					cout << Red << "     |            \\         |      ________||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<       "      /    > /"<<endl; 
					cout << Red << "    /             |         /        ------||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "     j    < _\\"<<endl; 
					cout << Red << "   |\\           /          |               ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<       " _.-; :      ;;."<<endl; 
					cout << Red << "   \\/`-._       |          /               ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<       " \\ r=._\\        ;."<<endl; 
					cout << Red << "    //   `... /            |               ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "<;\\_  \\         .;-."<<endl; 
					cout << Red << "   //`.      |             \\               ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         " \\ r-7  ;-. ._  , .  ;\\"<<endl; 
					cout << Red << "  ///\\ `-._  )/            |               ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "  \\;,      ;-.;7  7)   )"<<endl; 
					cout << Red << " //// )   .(/               |              ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "   \\/        \\| \\;  / ;-._"<<endl;              
					cout << Red << " ||||  /                    |" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<           "                            ||    .;"<<endl;
					cout << Red << " `\\` /`                    |" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<           "                            \\  ("<<endl; 
					cout << Red << "     |`                     \\" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "                              >\\  >"<<endl;                                 
					cout << Red << "     |_,-.      .-.        _|" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<           "                         ,.-; >.;"<<endl;
					cout << Red << "         `---'`   `'----'`" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<           "                         <._.''"<<endl;
			
				}
				else if (badGuesses==1){
					cout << Red << "                                         .""--..___" << "\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                     _                     []     ````-.._" << "\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                  .'` `'.                  ||__           `-._" << "\t\t\t\t\t\t\t\t\t\t\t"<<     ""<<endl; 
					cout << Red << "                 /    ,-.\\                 ||_ ```---..__     `-." << "\t\t\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                /    /:::\\               /|//}          ``--._  `." << "\t\t\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||              |////}                `-. \\" << "\t\t\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||             //'///                    `.\\" << "\t\t\t\t\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                |    |:::||            //  ||'                      `|" << "\t\t\t\t\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                /    |:::|/      __,-//\\   ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "               /     |:::|-,__,-'   |/  \\  ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "             /;  |   |   ||          \\   | ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "           /    \\   |   ||            |  / ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<White<<       "      \\"<<endl; 
					cout << Red << "         |       |  |   |)            \\ |  ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<White<<       "       \\"<<endl; 
					cout << Red << "        |          \\ |   /      ,.__   \\|  ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<White<<       "        \\"<<endl; 
					cout << Red << "        /                    /`    \\   |   ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<       "        >\\/7"<<endl; 
					cout << Red << "       |                     /        \\  / ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<       "    _.-(6*  \\"<<endl; 
					cout << Red << "       |                     |        | /  ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "   (=___._/; \\"<<endl; 
					cout << Red << "       /         /           |         (   ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "        )  \\ |"<<endl; 
					cout << Red << "      /          .           /          )  ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "       /   / |"<<endl; 
					cout << Red << "     |            \\         |      ________||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<       "      /    > /"<<endl; 
					cout << Red << "    /             |         /        ------||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "     j    < _\\"<<endl; 
					cout << Red << "   |\\           /          |               ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<       " _.-; :      ;;."<<endl; 
					cout << Red << "   \\/`-._       |          /               ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<       " \\ r=._\\        ;."<<endl; 
					cout << Red << "    //   `... /            |               ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "<;\\_  \\         .;-."<<endl; 
					cout << Red << "   //`.      |             \\               ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         " \\ r-7  ;-. ._  , .  ;\\"<<endl; 
					cout << Red << "  ///\\ `-._  )/            |               ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "  \\;,      ;-.;7  7)   )"<<endl; 
					cout << Red << " //// )   .(/               |              ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "   \\/        \\| \\;  / ;-._"<<endl;              
					cout << Red << " ||||  /                    |" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                            ||    .;"<<endl;
					cout << Red << " `\\` /`                    |" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                            \\  ("<<endl; 
					cout << Red << "     |`                     \\" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "                              >\\  >"<<endl;                                 
					cout << Red << "     |_,-.      .-.        _|" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                         ,.-; >.;"<<endl;
					cout << Red << "         `---'`   `'----'`" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                         <._.''"<<endl;
			
			
				}
				else if (badGuesses==2){
					cout << Red << "                                         .""--..___" << "\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                     _                     []     ````-.._" << "\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                  .'` `'.                  ||__           `-._" << "\t\t\t\t\t\t\t\t\t"<<     ""<<endl; 
					cout << Red << "                 /    ,-.\\                 ||_ ```---..__     `-." << "\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                /    /:::\\               /|//}          ``--._  `." << "\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||              |////}                `-. \\" << "\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||             //'///                    `.\\" << "\t\t\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                |    |:::||            //  ||'                      `|" << "\t\t\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                /    |:::|/      __,-//\\   ||" << "\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "               /     |:::|-,__,-'   |/  \\  ||" << "\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "             /;  |   |   ||          \\   | ||" << "\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "           /    \\   |   ||            |  / ||" << "\t\t\t\t\t\t\t\t\t"<<White<<       "      \\"<<endl; 
					cout << Red << "         |       |  |   |)            \\ |  ||" << "\t\t\t\t\t\t\t\t\t"<<White<<       "       \\"<<endl; 
					cout << Red << "        |          \\ |   /      ,.__   \\|  ||" << "\t\t\t\t\t\t\t\t\t"<<White<<       "        \\"<<endl; 
					cout << Red << "        /                    /`    \\   |   ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<       "        >\\/7"<<endl; 
					cout << Red << "       |                     /        \\  / ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<       "    _.-(6*  \\"<<endl; 
					cout << Red << "       |                     |        | /  ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "   (=___._/; \\"<<endl; 
					cout << Red << "       /         /           |         (   ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "        )  \\ |"<<endl; 
					cout << Red << "      /          .           /          )  ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "       /   / |"<<endl; 
					cout << Red << "     |            \\         |      ________||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<       "      /    > /"<<endl; 
					cout << Red << "    /             |         /        ------||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "     j    < _\\"<<endl; 
					cout << Red << "   |\\           /          |               ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<       " _.-; :      ;;."<<endl; 
					cout << Red << "   \\/`-._       |          /               ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<       " \\ r=._\\        ;."<<endl; 
					cout << Red << "    //   `... /            |               ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "<;\\_  \\         .;-."<<endl; 
					cout << Red << "   //`.      |             \\               ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         " \\ r-7  ;-. ._  , .  ;\\"<<endl; 
					cout << Red << "  ///\\ `-._  )/            |               ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "  \\;,      ;-.;7  7)   )"<<endl; 
					cout << Red << " //// )   .(/               |              ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "   \\/        \\| \\;  / ;-._"<<endl;              
					cout << Red << " ||||  /                    |" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                            ||    .;"<<endl;
					cout << Red << " `\\` /`                    |" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                            \\  ("<<endl; 
					cout << Red << "     |`                     \\" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "                              >\\  >"<<endl;                                 
					cout << Red << "     |_,-.      .-.        _|" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                         ,.-; >.;"<<endl;
					cout << Red << "         `---'`   `'----'`" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                         <._.''"<<endl;
			
			
			
				}
				else if (badGuesses==3){
					cout << Red << "                                         .""--..___" << "\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                     _                     []     ````-.._" << "\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                  .'` `'.                  ||__           `-._" << "\t\t\t\t\t\t\t"<<     ""<<endl; 
					cout << Red << "                 /    ,-.\\                 ||_ ```---..__     `-." << "\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                /    /:::\\               /|//}          ``--._  `." << "\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||              |////}                `-. \\" << "\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||             //'///                    `.\\" << "\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                |    |:::||            //  ||'                      `|" << "\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                /    |:::|/      __,-//\\   ||" << "\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "               /     |:::|-,__,-'   |/  \\  ||" << "\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "             /;  |   |   ||          \\   | ||" << "\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "           /    \\   |   ||            |  / ||" << "\t\t\t\t\t\t\t"<<White<<       "      \\"<<endl; 
					cout << Red << "         |       |  |   |)            \\ |  ||" << "\t\t\t\t\t\t\t"<<White<<       "       \\"<<endl; 
					cout << Red << "        |          \\ |   /      ,.__   \\|  ||" << "\t\t\t\t\t\t\t"<<White<<       "        \\"<<endl; 
					cout << Red << "        /                    /`    \\   |   ||" << "\t\t\t\t\t\t\t"<<Cyan<<       "        >\\/7"<<endl; 
					cout << Red << "       |                     /        \\  / ||" << "\t\t\t\t\t\t\t"<<Cyan<<       "    _.-(6*  \\"<<endl; 
					cout << Red << "       |                     |        | /  ||" << "\t\t\t\t\t\t\t"<<Cyan<<         "   (=___._/; \\"<<endl; 
					cout << Red << "       /         /           |         (   ||" << "\t\t\t\t\t\t\t"<<Cyan<<         "        )  \\ |"<<endl; 
					cout << Red << "      /          .           /          )  ||" << "\t\t\t\t\t\t\t"<<Cyan<<         "       /   / |"<<endl; 
					cout << Red << "     |            \\         |      ________||" << "\t\t\t\t\t\t\t"<<Cyan<<       "      /    > /"<<endl; 
					cout << Red << "    /             |         /        ------||" << "\t\t\t\t\t\t\t"<<Cyan<<         "     j    < _\\"<<endl; 
					cout << Red << "   |\\           /          |               ||" << "\t\t\t\t\t\t\t"<<Cyan<<       " _.-; :      ;;."<<endl; 
					cout << Red << "   \\/`-._       |          /               ||" << "\t\t\t\t\t\t\t"<<Cyan<<       " \\ r=._\\        ;."<<endl; 
					cout << Red << "    //   `... /            |               ||" << "\t\t\t\t\t\t\t"<<Cyan<<         "<;\\_  \\         .;-."<<endl; 
					cout << Red << "   //`.      |             \\               ||" << "\t\t\t\t\t\t\t"<<Cyan<<         " \\ r-7  ;-. ._  , .  ;\\"<<endl; 
					cout << Red << "  ///\\ `-._  )/            |               ||" << "\t\t\t\t\t\t\t"<<Cyan<<         "  \\;,      ;-.;7  7)   )"<<endl; 
					cout << Red << " //// )   .(/               |              ||" << "\t\t\t\t\t\t\t"<<Cyan<<         "   \\/        \\| \\;  / ;-._"<<endl;              
					cout << Red << " ||||  /                    |" << "\t\t\t\t\t\t\t"<<Cyan<<           "                            ||    .;"<<endl;
					cout << Red << " `\\` /`                    |" << "\t\t\t\t\t\t\t"<<Cyan<<           "                            \\  ("<<endl; 
					cout << Red << "     |`                     \\" << "\t\t\t\t\t\t\t"<<Cyan<<         "                              >\\  >"<<endl;                                 
					cout << Red << "     |_,-.      .-.        _|" << "\t\t\t\t\t\t\t"<<Cyan<<           "                         ,.-; >.;"<<endl;
					cout << Red << "         `---'`   `'----'`" << "\t\t\t\t\t\t\t"<<Cyan<<           "                         <._.''"<<endl;
			
			
				}
				else if (badGuesses==4){
					cout<<Red << "                                         .""--..___" << "\t\t\t\t"<<       ""<<endl; 
					cout<<Red << "                     _                     []     ````-.._" << "\t\t\t\t"<<       ""<<endl; 
					cout<<Red << "                  .'` `'.                  ||__           `-._" << "\t\t\t\t"<<     ""<<endl; 
					cout<<Red << "                 /    ,-.\\                 ||_ ```---..__     `-." << "\t\t\t\t"<<   ""<<endl; 
					cout<<Red << "                /    /:::\\               /|//}          ``--._  `." << "\t\t\t\t"<<   ""<<endl; 
					cout<<Red << "                |    |:::||              |////}                `-. \\" << "\t\t\t\t"<<   ""<<endl; 
					cout<<Red << "                |    |:::||             //'///                    `.\\" << "\t\t\t\t"<< ""<<endl; 
					cout<<Red << "                |    |:::||            //  ||'                      `|" << "\t\t\t\t"<< ""<<endl; 
					cout<<Red << "                /    |:::|/      __,-//\\   ||" << "\t\t\t\t"<<       ""<<endl; 
					cout<<Red << "               /     |:::|-,__,-'   |/  \\  ||" << "\t\t\t\t"<<       ""<<endl; 
					cout<<Red << "             /;  |   |   ||          \\   | ||" << "\t\t\t\t"<<       ""<<endl; 
					cout<<Red << "           /    \\   |   ||            |  / ||" << "\t\t\t\t"<<White<<       "      \\"<<endl; 
					cout<<Red << "         |       |  |   |)            \\ |  ||" << "\t\t\t\t"<<White<<       "       \\"<<endl; 
					cout<<Red << "        |          \\ |   /      ,.__   \\|  ||" << "\t\t\t\t"<<White<<       "        \\"<<endl; 
					cout<<Red << "        /                    /`    \\   |   ||" << "\t\t\t\t"<<Cyan<<       "        >\\/7"<<endl; 
					cout<<Red << "       |                     /        \\  / ||" << "\t\t\t\t"<<Cyan<<       "    _.-(6*  \\"<<endl; 
					cout<<Red << "       |                     |        | /  ||" << "\t\t\t\t"<<Cyan<<         "   (=___._/; \\"<<endl; 
					cout<<Red << "       /         /           |         (   ||" << "\t\t\t\t"<<Cyan<<         "        )  \\ |"<<endl; 
					cout<<Red << "      /          .           /          )  ||" << "\t\t\t\t"<<Cyan<<         "       /   / |"<<endl; 
					cout<<Red << "     |            \\         |      ________||" << "\t\t\t\t"<<Cyan<<       "      /    > /"<<endl; 
					cout<<Red << "    /             |         /        ------||" << "\t\t\t\t"<<Cyan<<         "     j    < _\\"<<endl; 
					cout<<Red << "   |\\           /          |               ||" << "\t\t\t\t"<<Cyan<<       " _.-; :      ;;."<<endl; 
					cout<<Red << "   \\/`-._       |          /               ||" << "\t\t\t\t"<<Cyan<<       " \\ r=._\\        ;."<<endl; 
					cout<<Red << "    //   `... /            |               ||" << "\t\t\t\t"<<Cyan<<         "<;\\_  \\         .;-."<<endl; 
					cout<<Red << "   //`.      |             \\               ||" << "\t\t\t\t"<<Cyan<<         " \\ r-7  ;-. ._  , .  ;\\"<<endl; 
					cout<<Red << "  ///\\ `-._  )/            |               ||" << "\t\t\t\t"<<Cyan<<         "  \\;,      ;-.;7  7)   )"<<endl; 
					cout<<Red << " //// )   .(/               |              ||" << "\t\t\t\t"<<Cyan<<         "   \\/        \\| \\;  / ;-._"<<endl;              
					cout<<Red << " ||||  /                    |" << "\t\t\t\t"<<Cyan<<           "                            ||    .;"<<endl;
					cout<<Red << " `\\` /`                    |" << "\t\t\t\t"<<Cyan<<           "                            \\  ("<<endl; 
					cout<<Red << "     |`                     \\" << "\t\t\t\t"<<Cyan<<         "                              >\\  >"<<endl;                                 
					cout<<Red << "     |_,-.      .-.        _|" << "\t\t\t\t"<<Cyan<<           "                         ,.-; >.;"<<endl;
					cout<<Red << "         `---'`   `'----'`" << "\t\t\t\t"<<Cyan<<           "                         <._.''"<<endl;
			
			
				}
				else if (badGuesses==5){
					cout<<Red << "                                         .""--..___" << "\t\t"<<       ""<<endl; 
					cout<<Red << "                     _                     []     ````-.._" << "\t\t"<<       ""<<endl; 
					cout<<Red << "                  .'` `'.                  ||__           `-._" << "\t\t"<<     ""<<endl; 
					cout<<Red << "                 /    ,-.\\                 ||_ ```---..__     `-." << "\t\t"<<   ""<<endl; 
					cout<<Red << "                /    /:::\\               /|//}          ``--._  `." << "\t\t"<<   ""<<endl; 
					cout<<Red << "                |    |:::||              |////}                `-. \\" << "\t\t"<<   ""<<endl; 
					cout<<Red << "                |    |:::||             //'///                    `.\\" << "\t\t"<< ""<<endl; 
					cout<<Red << "                |    |:::||            //  ||'                      `|" << "\t\t"<< ""<<endl; 
					cout<<Red << "                /    |:::|/      __,-//\\   ||" << "\t\t"<<       ""<<endl; 
					cout<<Red << "               /     |:::|-,__,-'   |/  \\  ||" << "\t\t"<<       ""<<endl; 
					cout<<Red << "             /;  |   |   ||          \\   | ||" << "\t\t"<<       ""<<endl; 
					cout<<Red << "           /    \\   |   ||            |  / ||" << "\t\t"<<White<<       "      \\"<<endl; 
					cout<<Red << "         |       |  |   |)            \\ |  ||" << "\t\t"<<White<<       "       \\"<<endl; 
					cout<<Red << "        |          \\ |   /      ,.__   \\|  ||" << "\t\t"<<White<<       "        \\"<<endl; 
					cout<<Red << "        /                    /`    \\   |   ||" << "\t\t"<<Cyan<<       "        >\\/7"<<endl; 
					cout<<Red << "       |                     /        \\  / ||" << "\t\t"<<Cyan<<       "    _.-(6*  \\"<<endl; 
					cout<<Red << "       |                     |        | /  ||" << "\t\t"<<Cyan<<         "   (=___._/; \\"<<endl; 
					cout<<Red << "       /         /           |         (   ||" << "\t\t"<<Cyan<<         "        )  \\ |"<<endl; 
					cout<<Red << "      /          .           /          )  ||" << "\t\t"<<Cyan<<         "       /   / |"<<endl; 
					cout<<Red << "     |            \\         |      ________||" << "\t\t"<<Cyan<<       "      /    > /"<<endl; 
					cout<<Red << "    /             |         /        ------||" << "\t\t"<<Cyan<<         "     j    < _\\"<<endl; 
					cout<<Red << "   |\\           /          |               ||" << "\t\t"<<Cyan<<       " _.-; :      ;;."<<endl; 
					cout<<Red << "   \\/`-._       |          /               ||" << "\t\t"<<Cyan<<       " \\ r=._\\        ;."<<endl; 
					cout<<Red << "    //   `... /            |               ||" << "\t\t"<<Cyan<<         "<;\\_  \\         .;-."<<endl; 
					cout<<Red << "   //`.      |             \\               ||" << "\t\t"<<Cyan<<         " \\ r-7  ;-. ._  , .  ;\\"<<endl; 
					cout<<Red << "  ///\\ `-._  )/            |               ||" << "\t\t"<<Cyan<<         "  \\;,      ;-.;7  7)   )"<<endl; 
					cout<<Red << " //// )   .(/               |              ||" << "\t\t"<<Cyan<<         "   \\/        \\| \\;  / ;-._"<<endl;              
					cout<<Red << " ||||  /                    |" << "\t\t"<<Cyan<<           "                            ||    .;"<<endl;
					cout<<Red << " `\\` /`                    |" << "\t\t"<<Cyan<<           "                            \\  ("<<endl; 
					cout<<Red << "     |`                     \\" << "\t\t"<<Cyan<<         "                              >\\  >"<<endl;                                 
					cout<<Red << "     |_,-.      .-.        _|" << "\t\t"<<Cyan<<           "                         ,.-; >.;"<<endl;
					cout<<Red << "         `---'`   `'----'`" << "\t\t"<<Cyan<<           "                         <._.''"<<endl;
			
			
			
				}
		
	
				//step 7- letters remaining
				cout << Default;
				cout << endl;
				cout << endl;
				cout << Cyan << "Letters Remaining: " << Red << lettersRemaining << endl;
				cout << endl;
		
				//step 8- print out dot placeholder
				cout <<Cyan << "The phrase to guess: " <<White << guessPhrase<< endl;
				cout << endl;
		
				//step 9- get user to guess letter
				cout <<Cyan << "Enter letter: ";
				cout << White;
				cin >> letter;
				cout << endl;
				
				//step 10- remove guessed letter lowercase
				letter[0]=tolower(letter[0]);
					
				location= lettersRemaining.find(letter, 0); 
				if (location != -1){
					lettersRemaining.replace(location, 1, " ");
				}
		
				//step 11- put correct guess letter into guessPhrase
				location=secretPhrase.find(letter, 0);
		
				while (location != -1){
					guessPhrase.replace(location, 1, letter);
					location=secretPhrase.find(letter, location +1);
				}
				
				
				//step 10- remove guessed letter uppercase
				letter[0]=toupper(letter[0]);
					
				location= lettersRemaining.find(letter, 0); 
				if (location != -1){
					lettersRemaining.replace(location, 1, " ");
				}
		
				//step 11- put correct guess letter into guessPhrase
				location=secretPhrase.find(letter, 0);
				
		
				while (location != -1){
					guessPhrase.replace(location, 1, letter);
					location=secretPhrase.find(letter, location +1);
				}
				
				//bad guesses decrement
				//define strings
				string l="a";
				string u="A";
				
				//get letter in both cases
				l[0]=tolower(letter[0]);
				u[0]=toupper(letter[0]);
				
				//find location of letter
				int locationL = secretPhrase.find(l, 0);
				int locationU = secretPhrase.find(u, 0);
				
				//decrement check
				if (locationL==-1 && locationU==-1){
					badGuesses++;
				}
			
				
				
				
				
				
				
			}//game loop 
	
			//step 12- add the last rounds letters and show word
			cout << CLS;
			cout << Cyan<< "Letters Remaining: " <<Red<< lettersRemaining << endl;
			cout << endl;
			cout <<Cyan <<  "The phrase to guess: " << White << guessPhrase<< endl;
			cout << endl;
			cout << endl;
			cout <<endl;

	
	
			//step 13- winning or losing screens
			if (badGuesses==6){
				loss++; 
				cout << Red << "                                           .;;--.._"<< "\t\t\t" << "" <<endl;
				cout << "                                           []      `'--.._"<< "\t\t\t" << "" <<endl;
				cout << "                                           ||__           `'-,"<< "\t\t\t" << "" <<endl;
				cout << "                                         `)||_ ```'--..       \\"<< "\t\t\t" << "" <<endl;
				cout << "                     _                    /|//}        ``--._  |"<< "\t\t\t" << "" <<endl;
				cout << "                  .'` `'.                /////}              `\\/"<< "\t\t\t" << "" <<endl;
				cout << "                 /  .:::\\              //{///"<< "\t\t\t" << ""<<endl;
				cout << "                /  /_  _`\\            // ` ||"<< "\t\t\t" << "" <<endl;
				cout << "                | |(_)(_)||          _//   ||"<< "\t\t\t" << "" <<endl;
				cout << "                | |  /\\ )|        _///\\    ||"<< "\t\t\t" << "" <<endl;
				cout << "                | |L====J |       / |/ |   ||"<< "\t\t\t" << ""<< endl;
				cout << "               /  /'-..-' /    .'`  \\  |   ||"<< "\t\t\t" << "" <<endl;
				cout << "              /   |  :: | |_.-`      | \\   ||"<< "\t\t\t" << "" <<endl;
				cout << "             /|  `\\-::.| |         \\   |   ||"<< "\t\t\t" << "" <<endl;
				cout << "           /` `|   /    | |          | /   ||"<< "\t\t\t" << "   ▓██   ██▓ ▒█████   █    ██"<< endl;
				cout << "         |`    \\   |    / /         \\  |   ||"<< "\t\t\t" << "    ▒██  ██▒▒██▒  ██▒ ██  ▓██▒" <<endl;
				cout << "        |      `\\_|    |/      ,.__.\\ |    ||"<< "\t\t\t" << "     ▒██ ██░▒██░  ██▒▓██  ▒██░" <<endl;
				cout << "        /                     /`   `\\ ||   ||"<< "\t\t\t" << "     ░ ▐██▓░▒██   ██░▓▓█  ░██░"<< endl;
				cout << "       |           .         /       \\||   ||"<< "\t\t\t" << "     ░ ██▒▓░░ ████▓▒░▒▒█████▓ "<< endl;
				cout << "       |                     |         |/  ||"<< "\t\t\t" << "      ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒ "<< endl;
				cout << "       /         /           |         (   ||"<< "\t\t\t" << "    ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░" <<endl;
				cout << "      /          .           /          )  ||"<< "\t\t\t" << "    ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░ " <<endl;
				cout << "     |           \\          |              ||"<< "\t\t\t" << "    ░ ░         ░ ░     ░     "<< endl;
				cout << "    /             |          /             ||"<< "\t\t\t" << "    ░ ░                           " <<endl;
				cout << "   |\\            /          |              ||"<< "\t\t\t" << " ██▓     ▒█████    ██████ ▄▄▄█████▓" <<endl;
				cout << "   \\ `-._       |           /              ||"<< "\t\t\t" << "▓██▒    ▒██▒  ██▒▒██    ▒ ▓  ██▒ ▓▒" <<endl;
				cout << "    \\ ,//`\\    /`          |               ||"<< "\t\t\t" << "▒██░    ▒██░  ██▒░ ▓██▄   ▒ ▓██░ ▒░" <<endl;
				cout << "     ///\\ \\  |              \\              ||"<< "\t\t\t" << "▒██░    ▒██   ██░  ▒   ██▒░ ▓██▓ ░ " <<endl;
				cout << "    |||| ) |__/             |              ||"<< "\t\t\t" << "░██████▒░ ████▓▒░▒██████▒▒  ▒██▒ ░ " <<endl;
				cout << "    |||| `.(                |              ||"<< "\t\t\t" << "░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░  ▒ ░░ " <<endl;
				cout << "    `\\\\` /`                 /              ||"<< "\t\t\t" << "░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒  ░ ░    ░ "<< endl;
				cout << "       /`                   /              ||"<< "\t\t\t" << "  ░ ░   ░ ░ ░ ▒  ░  ░  ░    ░    "<< endl;
				cout << "      /                     |              ||"<< "\t\t\t" << "    ░  ░    ░ ░        ░         "<< endl;
				cout << "     |                      \\              ||"<< "\t\t\t" << "" <<endl;
				cout << "    /                        |             ||"<< "\t\t\t" << ""<< endl;
				cout << "  /`                          \\            ||"<< "\t\t\t" << ""<< endl;
				cout << "/`                            |            ||"<< "\t\t\t" << "" <<endl;
				cout << "`-.___,-.      .-.        ___,'            ||"<< "\t\t\t" << "" <<endl;
				cout << "         `---'`   `'----'`"<< endl;
				cout<< White << endl;
				cout << endl;

                               
				cout <<WhiteOnRed<< "Oh no! You lost!" << endl;
				cout << endl;
				cout << "The phrase to guess was: " << secretPhrase << endl;
				cout << Default;
				cout << endl;
		
			}
	
			else{
				wins++;
				cout<< Cyan << "                                                  /"<< "\t\t\t" << "" <<endl;
				cout << "                                                .7"<< "\t\t\t" << "" <<endl;
				cout << "                                     \\       , //"<< "\t\t\t" << "" <<endl;
				cout << "                                     |\\.--._/|//"<< "\t\t\t" << "" <<endl;
				cout << "                                    /\\ ) ) ).'/"<< "\t\t\t" << "" <<endl;
				cout << "                                   /(  \\  // /"<< "\t\t\t" << "" <<endl;
				cout << "                                  /(   J`((_/ \\"<< "\t\t\t" << "" <<endl;
				cout << "                                 / ) | _\\     /"<< "\t\t\t" << "" <<endl;
				cout << "                                /|)  \\  eJ    L"<< "\t\t\t" << "" <<endl;
				cout << "                               |  \\ L \\   L   L"<< "\t\t\t" << "" <<endl;
				cout << "                              /  \\  J  `. J   L"<< "\t\t\t" << "" <<endl;
				cout << "                              |  )   L   \\/   \\"<< "\t\t\t" << "" <<endl;
				cout << "                             /  \\    J   (\\   /"<< "\t\t\t" << "" <<endl;
				cout << "           _....___         |  \\      \\   \\```"<< "\t\t\t" << "		██╗   ██╗ ██████╗ ██╗   ██╗" <<endl;
				cout << "    ,.._.-'        '''--...-||\\     -. \\   \\"<< "\t\t\t" << "		╚██╗ ██╔╝██╔═══██╗██║   ██║" <<endl;
				cout << "  .'.=.'                    `         `.\\ [ Y"<< "\t\t\t" << "		 ╚████╔╝ ██║   ██║██║   ██║" <<endl;
				cout << " /   /                                  \\]  J"<< "\t\t\t" << "		  ╚██╔╝  ██║   ██║██║   ██║" <<endl;
				cout << "Y / Y                                    Y   L"<< "\t\t\t" << "		   ██║   ╚██████╔╝╚██████╔╝" <<endl;
				cout << "| | |          \\                         |   L"<< "\t\t\t" << "		   ╚═╝    ╚═════╝  ╚═════╝     " <<endl;
				cout << "| | |           Y                        A  J"<< "\t\t\t" << "                                    " <<endl;
				cout << "|   I           |                       /I\\ /"<< "\t\t\t" << "		██╗    ██╗ ██████╗ ███╗   ██╗" <<endl;
				cout << "|    \\          I             \\        ( |]/|"<< "\t\t\t" << "		██║    ██║██╔═══██╗████╗  ██║" <<endl;
				cout << "J     \\         /._           /        -tI/ |"<< "\t\t\t" << "		██║ █╗ ██║██║   ██║██╔██╗ ██║" <<endl;
				cout << " L     )       /   /'-------'J           `'-:."<< "\t\t\t" << "		██║███╗██║██║   ██║██║╚██╗██║" <<endl;
				cout << " J   .'      ,'  ,' ,     \\   `'-.__          \\"<< "\t\t\t" << "		╚███╔███╔╝╚██████╔╝██║ ╚████║" <<endl;
				cout << "  \\ T      ,'  ,'   )\\    /|        ';'---7   /"<< "\t\t\t" << "		 ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═══╝  " <<endl;
				cout << "   \\|    ,'L  Y...-' / _.' /         \\   /   /"<< "\t\t\t" << "" <<endl;
				cout << "    J   Y  |  J    .'-'   /         ,--.(   /"<< "\t\t\t" << "" <<endl;
				cout << "     L  |  J   L -'     .'         /  |    /\\"<< "\t\t\t" << "" <<endl;
				cout << "     |  J.  L  J     .-;.-/       |    \\ .' /"<< "\t\t\t" << "" <<endl;
				cout << "     J   L`-J   L____,.-'`        |  _.-'   |"<< "\t\t\t" << "" <<endl;
				cout << "      L  J   L  J                  ``  J    |"<< "\t\t\t" << "" <<endl;
				cout << "      J   L  |   L                     J    |"<< "\t\t\t" << "" <<endl;
				cout << "       L  J  L    \\                    L    \\"<< "\t\t\t" << "" <<endl;
				cout << "       |   L  ) _.'\\                    ) _.'\\"<< "\t\t\t" << "" <<endl;
				cout << "       L    \\('`    \\                  ('`    \\"<< "\t\t\t" << "" <<endl;
				cout << "        ) _.'\\`-....'                   `-....'"<< "\t\t\t" << "" <<endl;
				cout << "       ('`    \\"<< "\t\t\t" << "" <<endl;
				cout << "        `-.___/"<< "\t\t\t" << "" <<endl;   		
                               
		
				cout<< endl;
				cout <<endl;
				cout << "Congratulations! You won!" << endl;
				cout << endl;
				cout << "The phrase to guess was: " << secretPhrase << endl;
				cout << Default;
				cout << endl;
			}
		
		}
	
		//mythical objects
		if (choice ==2){
			//step 2- select secret phrase
			string phrases[15]= {"Helm of Darkness" , "The Holy Grail", "Excalibur The Sword in the Stone", "The Book of Thoth", "Mead of Poetry", "Mjolnir", "Ambrosia", "The Golden Fleece", "Seven League Boots", "Flying Carpet", "The Cup of Jamshid", "Chariot of the Sun", "The Trident of Neptune", "The Cintamani Stone", "The Argo" }; 
			string secretPhrase= phrases[rand()%15]; // 0 to 15 number
	
			//step 3- create guessPhrase and fill it with dots
			string guessPhrase=secretPhrase;
			for (int i=0; i < guessPhrase.size(); i++){
				if (guessPhrase[i] != ' '){
					guessPhrase[i]= '.';
				}
			}//dot loop
	
			cout << secretPhrase << endl;
			cout << guessPhrase << endl;
	
			//step 4- declare variables
			string letter;// user guesses
			string lettersRemaining= "abcdefghijklmnopqrstuvwxyz"; // the possible guesses
			int badGuesses=0; // counts the number of incorrect guesses
			int location;
	
			//step 5- game loop that runs as long secret phrase hasn't been guessed and is less than 6 incorrect tries
			while (guessPhrase != secretPhrase && badGuesses < 6){
				//step 6- graphics each bad guess unicorn gets closer!
	
				cout << CLS;
				if (badGuesses==0){
					cout << Red << "                                         .""--..___" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                     _                     []     ````-.._" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                  .'` `'.                  ||__           `-._" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<     ""<<endl; 
					cout << Red << "                 /    ,-.\\                 ||_ ```---..__     `-." << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                /    /:::\\               /|//}          ``--._  `." << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||              |////}                `-. \\" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||             //'///                    `.\\" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                |    |:::||            //  ||'                      `|" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                /    |:::|/      __,-//\\   ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "               /     |:::|-,__,-'   |/  \\  ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "             /;  |   |   ||          \\   | ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "           /    \\   |   ||            |  / ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< White <<       "      \\"<<endl; 
					cout << Red << "         |       |  |   |)            \\ |  ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<White <<       "       \\"<<endl; 
					cout << Red << "        |          \\ |   /      ,.__   \\|  ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<White <<       "        \\"<<endl; 
					cout << Red << "        /                    /`    \\   |   ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<       "        >\\/7"<<endl; 
					cout << Red << "       |                     /        \\  / ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<       "    _.-(6*  \\"<<endl; 
					cout << Red << "       |                     |        | /  ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "   (=___._/; \\"<<endl; 
					cout << Red << "       /         /           |         (   ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "        )  \\ |"<<endl; 
					cout << Red << "      /          .           /          )  ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "       /   / |"<<endl; 
					cout << Red << "     |            \\         |      ________||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<       "      /    > /"<<endl; 
					cout << Red << "    /             |         /        ------||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "     j    < _\\"<<endl; 
					cout << Red << "   |\\           /          |               ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<       " _.-; :      ;;."<<endl; 
					cout << Red << "   \\/`-._       |          /               ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<       " \\ r=._\\        ;."<<endl; 
					cout << Red << "    //   `... /            |               ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "<;\\_  \\         .;-."<<endl; 
					cout << Red << "   //`.      |             \\               ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         " \\ r-7  ;-. ._  , .  ;\\"<<endl; 
					cout << Red << "  ///\\ `-._  )/            |               ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "  \\;,      ;-.;7  7)   )"<<endl; 
					cout << Red << " //// )   .(/               |              ||" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "   \\/        \\| \\;  / ;-._"<<endl;              
					cout << Red << " ||||  /                    |" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<           "                            ||    .;"<<endl;
					cout << Red << " `\\` /`                    |" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<           "                            \\  ("<<endl; 
					cout << Red << "     |`                     \\" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<         "                              >\\  >"<<endl;                                 
					cout << Red << "     |_,-.      .-.        _|" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<           "                         ,.-; >.;"<<endl;
					cout << Red << "         `---'`   `'----'`" << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<< Cyan <<           "                         <._.''"<<endl;
			
				}
				else if (badGuesses==1){
					cout << Red << "                                         .""--..___" << "\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                     _                     []     ````-.._" << "\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                  .'` `'.                  ||__           `-._" << "\t\t\t\t\t\t\t\t\t\t\t"<<     ""<<endl; 
					cout << Red << "                 /    ,-.\\                 ||_ ```---..__     `-." << "\t\t\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                /    /:::\\               /|//}          ``--._  `." << "\t\t\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||              |////}                `-. \\" << "\t\t\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||             //'///                    `.\\" << "\t\t\t\t\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                |    |:::||            //  ||'                      `|" << "\t\t\t\t\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                /    |:::|/      __,-//\\   ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "               /     |:::|-,__,-'   |/  \\  ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "             /;  |   |   ||          \\   | ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "           /    \\   |   ||            |  / ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<White<<       "      \\"<<endl; 
					cout << Red << "         |       |  |   |)            \\ |  ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<White<<       "       \\"<<endl; 
					cout << Red << "        |          \\ |   /      ,.__   \\|  ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<White<<       "        \\"<<endl; 
					cout << Red << "        /                    /`    \\   |   ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<       "        >\\/7"<<endl; 
					cout << Red << "       |                     /        \\  / ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<       "    _.-(6*  \\"<<endl; 
					cout << Red << "       |                     |        | /  ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "   (=___._/; \\"<<endl; 
					cout << Red << "       /         /           |         (   ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "        )  \\ |"<<endl; 
					cout << Red << "      /          .           /          )  ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "       /   / |"<<endl; 
					cout << Red << "     |            \\         |      ________||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<       "      /    > /"<<endl; 
					cout << Red << "    /             |         /        ------||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "     j    < _\\"<<endl; 
					cout << Red << "   |\\           /          |               ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<       " _.-; :      ;;."<<endl; 
					cout << Red << "   \\/`-._       |          /               ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<       " \\ r=._\\        ;."<<endl; 
					cout << Red << "    //   `... /            |               ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "<;\\_  \\         .;-."<<endl; 
					cout << Red << "   //`.      |             \\               ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         " \\ r-7  ;-. ._  , .  ;\\"<<endl; 
					cout << Red << "  ///\\ `-._  )/            |               ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "  \\;,      ;-.;7  7)   )"<<endl; 
					cout << Red << " //// )   .(/               |              ||" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "   \\/        \\| \\;  / ;-._"<<endl;              
					cout << Red << " ||||  /                    |" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                            ||    .;"<<endl;
					cout << Red << " `\\` /`                    |" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                            \\  ("<<endl; 
					cout << Red << "     |`                     \\" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<         "                              >\\  >"<<endl;                                 
					cout << Red << "     |_,-.      .-.        _|" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                         ,.-; >.;"<<endl;
					cout << Red << "         `---'`   `'----'`" << "\t\t\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                         <._.''"<<endl;
			
			
				}
				else if (badGuesses==2){
					cout << Red << "                                         .""--..___" << "\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                     _                     []     ````-.._" << "\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                  .'` `'.                  ||__           `-._" << "\t\t\t\t\t\t\t\t\t"<<     ""<<endl; 
					cout << Red << "                 /    ,-.\\                 ||_ ```---..__     `-." << "\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                /    /:::\\               /|//}          ``--._  `." << "\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||              |////}                `-. \\" << "\t\t\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||             //'///                    `.\\" << "\t\t\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                |    |:::||            //  ||'                      `|" << "\t\t\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                /    |:::|/      __,-//\\   ||" << "\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "               /     |:::|-,__,-'   |/  \\  ||" << "\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "             /;  |   |   ||          \\   | ||" << "\t\t\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "           /    \\   |   ||            |  / ||" << "\t\t\t\t\t\t\t\t\t"<<White<<       "      \\"<<endl; 
					cout << Red << "         |       |  |   |)            \\ |  ||" << "\t\t\t\t\t\t\t\t\t"<<White<<       "       \\"<<endl; 
					cout << Red << "        |          \\ |   /      ,.__   \\|  ||" << "\t\t\t\t\t\t\t\t\t"<<White<<       "        \\"<<endl; 
					cout << Red << "        /                    /`    \\   |   ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<       "        >\\/7"<<endl; 
					cout << Red << "       |                     /        \\  / ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<       "    _.-(6*  \\"<<endl; 
					cout << Red << "       |                     |        | /  ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "   (=___._/; \\"<<endl; 
					cout << Red << "       /         /           |         (   ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "        )  \\ |"<<endl; 
					cout << Red << "      /          .           /          )  ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "       /   / |"<<endl; 
					cout << Red << "     |            \\         |      ________||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<       "      /    > /"<<endl; 
					cout << Red << "    /             |         /        ------||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "     j    < _\\"<<endl; 
					cout << Red << "   |\\           /          |               ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<       " _.-; :      ;;."<<endl; 
					cout << Red << "   \\/`-._       |          /               ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<       " \\ r=._\\        ;."<<endl; 
					cout << Red << "    //   `... /            |               ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "<;\\_  \\         .;-."<<endl; 
					cout << Red << "   //`.      |             \\               ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         " \\ r-7  ;-. ._  , .  ;\\"<<endl; 
					cout << Red << "  ///\\ `-._  )/            |               ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "  \\;,      ;-.;7  7)   )"<<endl; 
					cout << Red << " //// )   .(/               |              ||" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "   \\/        \\| \\;  / ;-._"<<endl;              
					cout << Red << " ||||  /                    |" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                            ||    .;"<<endl;
					cout << Red << " `\\` /`                    |" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                            \\  ("<<endl; 
					cout << Red << "     |`                     \\" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<         "                              >\\  >"<<endl;                                 
					cout << Red << "     |_,-.      .-.        _|" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                         ,.-; >.;"<<endl;
					cout << Red << "         `---'`   `'----'`" << "\t\t\t\t\t\t\t\t\t"<<Cyan<<           "                         <._.''"<<endl;
			
			
			
				}
				else if (badGuesses==3){
					cout << Red << "                                         .""--..___" << "\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                     _                     []     ````-.._" << "\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "                  .'` `'.                  ||__           `-._" << "\t\t\t\t\t\t\t"<<     ""<<endl; 
					cout << Red << "                 /    ,-.\\                 ||_ ```---..__     `-." << "\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                /    /:::\\               /|//}          ``--._  `." << "\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||              |////}                `-. \\" << "\t\t\t\t\t\t\t"<<   ""<<endl; 
					cout << Red << "                |    |:::||             //'///                    `.\\" << "\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                |    |:::||            //  ||'                      `|" << "\t\t\t\t\t\t\t"<< ""<<endl; 
					cout << Red << "                /    |:::|/      __,-//\\   ||" << "\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "               /     |:::|-,__,-'   |/  \\  ||" << "\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "             /;  |   |   ||          \\   | ||" << "\t\t\t\t\t\t\t"<<       ""<<endl; 
					cout << Red << "           /    \\   |   ||            |  / ||" << "\t\t\t\t\t\t\t"<<White<<       "      \\"<<endl; 
					cout << Red << "         |       |  |   |)            \\ |  ||" << "\t\t\t\t\t\t\t"<<White<<       "       \\"<<endl; 
					cout << Red << "        |          \\ |   /      ,.__   \\|  ||" << "\t\t\t\t\t\t\t"<<White<<       "        \\"<<endl; 
					cout << Red << "        /                    /`    \\   |   ||" << "\t\t\t\t\t\t\t"<<Cyan<<       "        >\\/7"<<endl; 
					cout << Red << "       |                     /        \\  / ||" << "\t\t\t\t\t\t\t"<<Cyan<<       "    _.-(6*  \\"<<endl; 
					cout << Red << "       |                     |        | /  ||" << "\t\t\t\t\t\t\t"<<Cyan<<         "   (=___._/; \\"<<endl; 
					cout << Red << "       /         /           |         (   ||" << "\t\t\t\t\t\t\t"<<Cyan<<         "        )  \\ |"<<endl; 
					cout << Red << "      /          .           /          )  ||" << "\t\t\t\t\t\t\t"<<Cyan<<         "       /   / |"<<endl; 
					cout << Red << "     |            \\         |      ________||" << "\t\t\t\t\t\t\t"<<Cyan<<       "      /    > /"<<endl; 
					cout << Red << "    /             |         /        ------||" << "\t\t\t\t\t\t\t"<<Cyan<<         "     j    < _\\"<<endl; 
					cout << Red << "   |\\           /          |               ||" << "\t\t\t\t\t\t\t"<<Cyan<<       " _.-; :      ;;."<<endl; 
					cout << Red << "   \\/`-._       |          /               ||" << "\t\t\t\t\t\t\t"<<Cyan<<       " \\ r=._\\        ;."<<endl; 
					cout << Red << "    //   `... /            |               ||" << "\t\t\t\t\t\t\t"<<Cyan<<         "<;\\_  \\         .;-."<<endl; 
					cout << Red << "   //`.      |             \\               ||" << "\t\t\t\t\t\t\t"<<Cyan<<         " \\ r-7  ;-. ._  , .  ;\\"<<endl; 
					cout << Red << "  ///\\ `-._  )/            |               ||" << "\t\t\t\t\t\t\t"<<Cyan<<         "  \\;,      ;-.;7  7)   )"<<endl; 
					cout << Red << " //// )   .(/               |              ||" << "\t\t\t\t\t\t\t"<<Cyan<<         "   \\/        \\| \\;  / ;-._"<<endl;              
					cout << Red << " ||||  /                    |" << "\t\t\t\t\t\t\t"<<Cyan<<           "                            ||    .;"<<endl;
					cout << Red << " `\\` /`                    |" << "\t\t\t\t\t\t\t"<<Cyan<<           "                            \\  ("<<endl; 
					cout << Red << "     |`                     \\" << "\t\t\t\t\t\t\t"<<Cyan<<         "                              >\\  >"<<endl;                                 
					cout << Red << "     |_,-.      .-.        _|" << "\t\t\t\t\t\t\t"<<Cyan<<           "                         ,.-; >.;"<<endl;
					cout << Red << "         `---'`   `'----'`" << "\t\t\t\t\t\t\t"<<Cyan<<           "                         <._.''"<<endl;
			
			
				}
				else if (badGuesses==4){
					cout<<Red << "                                         .""--..___" << "\t\t\t\t"<<       ""<<endl; 
					cout<<Red << "                     _                     []     ````-.._" << "\t\t\t\t"<<       ""<<endl; 
					cout<<Red << "                  .'` `'.                  ||__           `-._" << "\t\t\t\t"<<     ""<<endl; 
					cout<<Red << "                 /    ,-.\\                 ||_ ```---..__     `-." << "\t\t\t\t"<<   ""<<endl; 
					cout<<Red << "                /    /:::\\               /|//}          ``--._  `." << "\t\t\t\t"<<   ""<<endl; 
					cout<<Red << "                |    |:::||              |////}                `-. \\" << "\t\t\t\t"<<   ""<<endl; 
					cout<<Red << "                |    |:::||             //'///                    `.\\" << "\t\t\t\t"<< ""<<endl; 
					cout<<Red << "                |    |:::||            //  ||'                      `|" << "\t\t\t\t"<< ""<<endl; 
					cout<<Red << "                /    |:::|/      __,-//\\   ||" << "\t\t\t\t"<<       ""<<endl; 
					cout<<Red << "               /     |:::|-,__,-'   |/  \\  ||" << "\t\t\t\t"<<       ""<<endl; 
					cout<<Red << "             /;  |   |   ||          \\   | ||" << "\t\t\t\t"<<       ""<<endl; 
					cout<<Red << "           /    \\   |   ||            |  / ||" << "\t\t\t\t"<<White<<       "      \\"<<endl; 
					cout<<Red << "         |       |  |   |)            \\ |  ||" << "\t\t\t\t"<<White<<       "       \\"<<endl; 
					cout<<Red << "        |          \\ |   /      ,.__   \\|  ||" << "\t\t\t\t"<<White<<       "        \\"<<endl; 
					cout<<Red << "        /                    /`    \\   |   ||" << "\t\t\t\t"<<Cyan<<       "        >\\/7"<<endl; 
					cout<<Red << "       |                     /        \\  / ||" << "\t\t\t\t"<<Cyan<<       "    _.-(6*  \\"<<endl; 
					cout<<Red << "       |                     |        | /  ||" << "\t\t\t\t"<<Cyan<<         "   (=___._/; \\"<<endl; 
					cout<<Red << "       /         /           |         (   ||" << "\t\t\t\t"<<Cyan<<         "        )  \\ |"<<endl; 
					cout<<Red << "      /          .           /          )  ||" << "\t\t\t\t"<<Cyan<<         "       /   / |"<<endl; 
					cout<<Red << "     |            \\         |      ________||" << "\t\t\t\t"<<Cyan<<       "      /    > /"<<endl; 
					cout<<Red << "    /             |         /        ------||" << "\t\t\t\t"<<Cyan<<         "     j    < _\\"<<endl; 
					cout<<Red << "   |\\           /          |               ||" << "\t\t\t\t"<<Cyan<<       " _.-; :      ;;."<<endl; 
					cout<<Red << "   \\/`-._       |          /               ||" << "\t\t\t\t"<<Cyan<<       " \\ r=._\\        ;."<<endl; 
					cout<<Red << "    //   `... /            |               ||" << "\t\t\t\t"<<Cyan<<         "<;\\_  \\         .;-."<<endl; 
					cout<<Red << "   //`.      |             \\               ||" << "\t\t\t\t"<<Cyan<<         " \\ r-7  ;-. ._  , .  ;\\"<<endl; 
					cout<<Red << "  ///\\ `-._  )/            |               ||" << "\t\t\t\t"<<Cyan<<         "  \\;,      ;-.;7  7)   )"<<endl; 
					cout<<Red << " //// )   .(/               |              ||" << "\t\t\t\t"<<Cyan<<         "   \\/        \\| \\;  / ;-._"<<endl;              
					cout<<Red << " ||||  /                    |" << "\t\t\t\t"<<Cyan<<           "                            ||    .;"<<endl;
					cout<<Red << " `\\` /`                    |" << "\t\t\t\t"<<Cyan<<           "                            \\  ("<<endl; 
					cout<<Red << "     |`                     \\" << "\t\t\t\t"<<Cyan<<         "                              >\\  >"<<endl;                                 
					cout<<Red << "     |_,-.      .-.        _|" << "\t\t\t\t"<<Cyan<<           "                         ,.-; >.;"<<endl;
					cout<<Red << "         `---'`   `'----'`" << "\t\t\t\t"<<Cyan<<           "                         <._.''"<<endl;
			
			
				}
				else if (badGuesses==5){
					cout<<Red << "                                         .""--..___" << "\t\t"<<       ""<<endl; 
					cout<<Red << "                     _                     []     ````-.._" << "\t\t"<<       ""<<endl; 
					cout<<Red << "                  .'` `'.                  ||__           `-._" << "\t\t"<<     ""<<endl; 
					cout<<Red << "                 /    ,-.\\                 ||_ ```---..__     `-." << "\t\t"<<   ""<<endl; 
					cout<<Red << "                /    /:::\\               /|//}          ``--._  `." << "\t\t"<<   ""<<endl; 
					cout<<Red << "                |    |:::||              |////}                `-. \\" << "\t\t"<<   ""<<endl; 
					cout<<Red << "                |    |:::||             //'///                    `.\\" << "\t\t"<< ""<<endl; 
					cout<<Red << "                |    |:::||            //  ||'                      `|" << "\t\t"<< ""<<endl; 
					cout<<Red << "                /    |:::|/      __,-//\\   ||" << "\t\t"<<       ""<<endl; 
					cout<<Red << "               /     |:::|-,__,-'   |/  \\  ||" << "\t\t"<<       ""<<endl; 
					cout<<Red << "             /;  |   |   ||          \\   | ||" << "\t\t"<<       ""<<endl; 
					cout<<Red << "           /    \\   |   ||            |  / ||" << "\t\t"<<White<<       "      \\"<<endl; 
					cout<<Red << "         |       |  |   |)            \\ |  ||" << "\t\t"<<White<<       "       \\"<<endl; 
					cout<<Red << "        |          \\ |   /      ,.__   \\|  ||" << "\t\t"<<White<<       "        \\"<<endl; 
					cout<<Red << "        /                    /`    \\   |   ||" << "\t\t"<<Cyan<<       "        >\\/7"<<endl; 
					cout<<Red << "       |                     /        \\  / ||" << "\t\t"<<Cyan<<       "    _.-(6*  \\"<<endl; 
					cout<<Red << "       |                     |        | /  ||" << "\t\t"<<Cyan<<         "   (=___._/; \\"<<endl; 
					cout<<Red << "       /         /           |         (   ||" << "\t\t"<<Cyan<<         "        )  \\ |"<<endl; 
					cout<<Red << "      /          .           /          )  ||" << "\t\t"<<Cyan<<         "       /   / |"<<endl; 
					cout<<Red << "     |            \\         |      ________||" << "\t\t"<<Cyan<<       "      /    > /"<<endl; 
					cout<<Red << "    /             |         /        ------||" << "\t\t"<<Cyan<<         "     j    < _\\"<<endl; 
					cout<<Red << "   |\\           /          |               ||" << "\t\t"<<Cyan<<       " _.-; :      ;;."<<endl; 
					cout<<Red << "   \\/`-._       |          /               ||" << "\t\t"<<Cyan<<       " \\ r=._\\        ;."<<endl; 
					cout<<Red << "    //   `... /            |               ||" << "\t\t"<<Cyan<<         "<;\\_  \\         .;-."<<endl; 
					cout<<Red << "   //`.      |             \\               ||" << "\t\t"<<Cyan<<         " \\ r-7  ;-. ._  , .  ;\\"<<endl; 
					cout<<Red << "  ///\\ `-._  )/            |               ||" << "\t\t"<<Cyan<<         "  \\;,      ;-.;7  7)   )"<<endl; 
					cout<<Red << " //// )   .(/               |              ||" << "\t\t"<<Cyan<<         "   \\/        \\| \\;  / ;-._"<<endl;              
					cout<<Red << " ||||  /                    |" << "\t\t"<<Cyan<<           "                            ||    .;"<<endl;
					cout<<Red << " `\\` /`                    |" << "\t\t"<<Cyan<<           "                            \\  ("<<endl; 
					cout<<Red << "     |`                     \\" << "\t\t"<<Cyan<<         "                              >\\  >"<<endl;                                 
					cout<<Red << "     |_,-.      .-.        _|" << "\t\t"<<Cyan<<           "                         ,.-; >.;"<<endl;
					cout<<Red << "         `---'`   `'----'`" << "\t\t"<<Cyan<<           "                         <._.''"<<endl;
			
			
			
				}
		
	
				//step 7- letters remaining
				cout << Default;
				cout << endl;
				cout << endl;
				cout << Cyan << "Letters Remaining: " << Red << lettersRemaining << endl;
				cout << endl;
		
				//step 8- print out dot placeholder
				cout <<Cyan << "The phrase to guess: " <<White << guessPhrase<< endl;
				cout << endl;
		
				//step 9- get user to guess letter
				cout <<Cyan << "Enter letter: ";
				cout << White;
				cin >> letter;
				cout << endl;
				
		
				//step 10- remove guessed letter lowercase
				letter[0]=tolower(letter[0]);
					
				location= lettersRemaining.find(letter, 0); 
				if (location != -1){
					lettersRemaining.replace(location, 1, " ");
				}
		
				//step 11- put correct guess letter into guessPhrase
				location=secretPhrase.find(letter, 0);
		
				while (location != -1){
					guessPhrase.replace(location, 1, letter);
					location=secretPhrase.find(letter, location +1);
				}
				
				
				
				//step 10- remove guessed letter uppercase
				letter[0]=toupper(letter[0]);
					
				location= lettersRemaining.find(letter, 0); 
				if (location != -1){
					lettersRemaining.replace(location, 1, " ");
				}
		
				//step 11- put correct guess letter into guessPhrase
				location=secretPhrase.find(letter, 0);
				
		
				while (location != -1){
					guessPhrase.replace(location, 1, letter);
					location=secretPhrase.find(letter, location +1);
				}
				
				//bad guesses decrement
				//define strings
				string l="a";
				string u="A";
				
				//get letter in both cases
				l[0]=tolower(letter[0]);
				u[0]=toupper(letter[0]);
				
				//find location of letter
				int locationL = secretPhrase.find(l, 0);
				int locationU = secretPhrase.find(u, 0);
				
				//decrement check
				if (locationL==-1 && locationU==-1){
					badGuesses++;
				}
			
				
			}//game loop 
	
			//step 12- add the last rounds letters and show word
			cout << CLS;
			cout << Cyan<< "Letters Remaining: " <<Red<< lettersRemaining << endl;
			cout << endl;
			cout <<Cyan <<  "The phrase to guess: " << White << guessPhrase<< endl;
			cout << endl;
			cout << endl;
			cout <<endl;

	
	
			//step 13- winning or losing screens
			if (badGuesses==6){
				loss++;
				cout << Red << "                                           .;;--.._"<< "\t\t\t" << "" <<endl;
				cout << "                                           []      `'--.._"<< "\t\t\t" << "" <<endl;
				cout << "                                           ||__           `'-,"<< "\t\t\t" << "" <<endl;
				cout << "                                         `)||_ ```'--..       \\"<< "\t\t\t" << "" <<endl;
				cout << "                     _                    /|//}        ``--._  |"<< "\t\t\t" << "" <<endl;
				cout << "                  .'` `'.                /////}              `\\/"<< "\t\t\t" << "" <<endl;
				cout << "                 /  .:::\\              //{///"<< "\t\t\t" << ""<<endl;
				cout << "                /  /_  _`\\            // ` ||"<< "\t\t\t" << "" <<endl;
				cout << "                | |(_)(_)||          _//   ||"<< "\t\t\t" << "" <<endl;
				cout << "                | |  /\\ )|        _///\\    ||"<< "\t\t\t" << "" <<endl;
				cout << "                | |L====J |       / |/ |   ||"<< "\t\t\t" << ""<< endl;
				cout << "               /  /'-..-' /    .'`  \\  |   ||"<< "\t\t\t" << "" <<endl;
				cout << "              /   |  :: | |_.-`      | \\   ||"<< "\t\t\t" << "" <<endl;
				cout << "             /|  `\\-::.| |         \\   |   ||"<< "\t\t\t" << "" <<endl;
				cout << "           /` `|   /    | |          | /   ||"<< "\t\t\t" << "   ▓██   ██▓ ▒█████   █    ██"<< endl;
				cout << "         |`    \\   |    / /         \\  |   ||"<< "\t\t\t" << "    ▒██  ██▒▒██▒  ██▒ ██  ▓██▒" <<endl;
				cout << "        |      `\\_|    |/      ,.__.\\ |    ||"<< "\t\t\t" << "     ▒██ ██░▒██░  ██▒▓██  ▒██░" <<endl;
				cout << "        /                     /`   `\\ ||   ||"<< "\t\t\t" << "     ░ ▐██▓░▒██   ██░▓▓█  ░██░"<< endl;
				cout << "       |           .         /       \\||   ||"<< "\t\t\t" << "     ░ ██▒▓░░ ████▓▒░▒▒█████▓ "<< endl;
				cout << "       |                     |         |/  ||"<< "\t\t\t" << "      ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒ "<< endl;
				cout << "       /         /           |         (   ||"<< "\t\t\t" << "    ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░" <<endl;
				cout << "      /          .           /          )  ||"<< "\t\t\t" << "    ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░ " <<endl;
				cout << "     |           \\          |              ||"<< "\t\t\t" << "    ░ ░         ░ ░     ░     "<< endl;
				cout << "    /             |          /             ||"<< "\t\t\t" << "    ░ ░                           " <<endl;
				cout << "   |\\            /          |              ||"<< "\t\t\t" << " ██▓     ▒█████    ██████ ▄▄▄█████▓" <<endl;
				cout << "   \\ `-._       |           /              ||"<< "\t\t\t" << "▓██▒    ▒██▒  ██▒▒██    ▒ ▓  ██▒ ▓▒" <<endl;
				cout << "    \\ ,//`\\    /`          |               ||"<< "\t\t\t" << "▒██░    ▒██░  ██▒░ ▓██▄   ▒ ▓██░ ▒░" <<endl;
				cout << "     ///\\ \\  |              \\              ||"<< "\t\t\t" << "▒██░    ▒██   ██░  ▒   ██▒░ ▓██▓ ░ " <<endl;
				cout << "    |||| ) |__/             |              ||"<< "\t\t\t" << "░██████▒░ ████▓▒░▒██████▒▒  ▒██▒ ░ " <<endl;
				cout << "    |||| `.(                |              ||"<< "\t\t\t" << "░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░  ▒ ░░ " <<endl;
				cout << "    `\\\\` /`                 /              ||"<< "\t\t\t" << "░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒  ░ ░    ░ "<< endl;
				cout << "       /`                   /              ||"<< "\t\t\t" << "  ░ ░   ░ ░ ░ ▒  ░  ░  ░    ░    "<< endl;
				cout << "      /                     |              ||"<< "\t\t\t" << "    ░  ░    ░ ░        ░         "<< endl;
				cout << "     |                      \\              ||"<< "\t\t\t" << "" <<endl;
				cout << "    /                        |             ||"<< "\t\t\t" << ""<< endl;
				cout << "  /`                          \\            ||"<< "\t\t\t" << ""<< endl;
				cout << "/`                            |            ||"<< "\t\t\t" << "" <<endl;
				cout << "`-.___,-.      .-.        ___,'            ||"<< "\t\t\t" << "" <<endl;
				cout << "         `---'`   `'----'`"<< endl;
				cout<< White << endl;
				cout << endl;

                               
				cout <<WhiteOnRed<< "Oh no! You lost!" << endl;
				cout << endl;
				cout << "The phrase to guess was: " << secretPhrase << endl;
				cout << Default;
				cout << endl;
		
			}
	
			else{
				wins++;
		
				cout<< Cyan << "                                                  /"<< "\t\t\t" << "" <<endl;
				cout << "                                                .7"<< "\t\t\t" << "" <<endl;
				cout << "                                     \\       , //"<< "\t\t\t" << "" <<endl;
				cout << "                                     |\\.--._/|//"<< "\t\t\t" << "" <<endl;
				cout << "                                    /\\ ) ) ).'/"<< "\t\t\t" << "" <<endl;
				cout << "                                   /(  \\  // /"<< "\t\t\t" << "" <<endl;
				cout << "                                  /(   J`((_/ \\"<< "\t\t\t" << "" <<endl;
				cout << "                                 / ) | _\\     /"<< "\t\t\t" << "" <<endl;
				cout << "                                /|)  \\  eJ    L"<< "\t\t\t" << "" <<endl;
				cout << "                               |  \\ L \\   L   L"<< "\t\t\t" << "" <<endl;
				cout << "                              /  \\  J  `. J   L"<< "\t\t\t" << "" <<endl;
				cout << "                              |  )   L   \\/   \\"<< "\t\t\t" << "" <<endl;
				cout << "                             /  \\    J   (\\   /"<< "\t\t\t" << "" <<endl;
				cout << "           _....___         |  \\      \\   \\```"<< "\t\t\t" << "		██╗   ██╗ ██████╗ ██╗   ██╗" <<endl;
				cout << "    ,.._.-'        '''--...-||\\     -. \\   \\"<< "\t\t\t" << "		╚██╗ ██╔╝██╔═══██╗██║   ██║" <<endl;
				cout << "  .'.=.'                    `         `.\\ [ Y"<< "\t\t\t" << "		 ╚████╔╝ ██║   ██║██║   ██║" <<endl;
				cout << " /   /                                  \\]  J"<< "\t\t\t" << "		  ╚██╔╝  ██║   ██║██║   ██║" <<endl;
				cout << "Y / Y                                    Y   L"<< "\t\t\t" << "		   ██║   ╚██████╔╝╚██████╔╝" <<endl;
				cout << "| | |          \\                         |   L"<< "\t\t\t" << "		   ╚═╝    ╚═════╝  ╚═════╝     " <<endl;
				cout << "| | |           Y                        A  J"<< "\t\t\t" << "                                    " <<endl;
				cout << "|   I           |                       /I\\ /"<< "\t\t\t" << "		██╗    ██╗ ██████╗ ███╗   ██╗" <<endl;
				cout << "|    \\          I             \\        ( |]/|"<< "\t\t\t" << "		██║    ██║██╔═══██╗████╗  ██║" <<endl;
				cout << "J     \\         /._           /        -tI/ |"<< "\t\t\t" << "		██║ █╗ ██║██║   ██║██╔██╗ ██║" <<endl;
				cout << " L     )       /   /'-------'J           `'-:."<< "\t\t\t" << "		██║███╗██║██║   ██║██║╚██╗██║" <<endl;
				cout << " J   .'      ,'  ,' ,     \\   `'-.__          \\"<< "\t\t\t" << "		╚███╔███╔╝╚██████╔╝██║ ╚████║" <<endl;
				cout << "  \\ T      ,'  ,'   )\\    /|        ';'---7   /"<< "\t\t\t" << "		 ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═══╝  " <<endl;
				cout << "   \\|    ,'L  Y...-' / _.' /         \\   /   /"<< "\t\t\t" << "" <<endl;
				cout << "    J   Y  |  J    .'-'   /         ,--.(   /"<< "\t\t\t" << "" <<endl;
				cout << "     L  |  J   L -'     .'         /  |    /\\"<< "\t\t\t" << "" <<endl;
				cout << "     |  J.  L  J     .-;.-/       |    \\ .' /"<< "\t\t\t" << "" <<endl;
				cout << "     J   L`-J   L____,.-'`        |  _.-'   |"<< "\t\t\t" << "" <<endl;
				cout << "      L  J   L  J                  ``  J    |"<< "\t\t\t" << "" <<endl;
				cout << "      J   L  |   L                     J    |"<< "\t\t\t" << "" <<endl;
				cout << "       L  J  L    \\                    L    \\"<< "\t\t\t" << "" <<endl;
				cout << "       |   L  ) _.'\\                    ) _.'\\"<< "\t\t\t" << "" <<endl;
				cout << "       L    \\('`    \\                  ('`    \\"<< "\t\t\t" << "" <<endl;
				cout << "        ) _.'\\`-....'                   `-....'"<< "\t\t\t" << "" <<endl;
				cout << "       ('`    \\"<< "\t\t\t" << "" <<endl;
				cout << "        `-.___/"<< "\t\t\t" << "" <<endl;   		
                               
		
				cout<< endl;
				cout <<endl;
				cout << "Congratulations! You won!" << endl;
				cout << endl;
				cout << "The phrase to guess was: " << secretPhrase << endl;
				cout << Default;
				cout << endl;
			}
			
		}
		
		//display wins and losses
		cout << "Wins: " << wins << "\t" << "Losses: " << loss << endl;
		cout << endl;
		
		//ask if they want to play again
		cout << "If you would like to play the game again, please type 1 " << endl;
		cout << "If you would like to exit the game, press any key. " << endl;
		cin >> playAgain;
		
		cout << CLS;
		
		
		
		
	}// do while loop
	while (playAgain==1);
	
	//exitting game end screen
	cout << "Thank you for playing! Goodbye! " << endl;
	cout << endl;
	cout << endl;
		
	cout<< White << "\t\t\t   ██████╗ ██╗   ██╗███████╗██╗ " << endl;
	cout<< White << "\t\t\t   ██╔══██╗╚██╗ ██╔╝██╔════╝██║ " << endl;
	cout<< White << "\t\t\t   ██████╔╝ ╚████╔╝ █████╗  ██║ " << endl;
	cout<< White << "\t\t\t   ██╔══██╗  ╚██╔╝  ██╔══╝  ╚═╝ " << endl;
	cout<< White << "\t\t\t   ██████╔╝   ██║   ███████╗██╗ " << endl;
	cout<< White << "\t\t\t   ╚═════╝    ╚═╝   ╚══════╝╚═╝ " << endl;
                            
	
								
								
			           
	
	
	cout << White <<"	        _    .  ,   .           ." << endl;
	cout << White <<"	    *  / \\_ *  / \\_      _  *        *          /\\'__        *" << endl;
	cout << White <<"	      /    \\  /    \\,   ((        .           _/  /  \\  *'." << endl;
	cout << White <<"	 .   /\\/\\  /\\/ :' __ \\_  `              *   _^/  ^/    `--." << endl;
	cout << White <<"	    /    \\/  \\  _/  \\-'\\      *           /.' ^_   \\_   .'\\  *" << endl;
	cout << White <<"	  /\\  .-   `. \\/     \\ /~~~~~~~~~~~~~~~~~~;.  _/ \\ -. `_/   \\" << endl;
	cout << White <<"	 /  `-.__ ^   / .-'.--\\ ~~~~~~~~~~~~~~~~~/  _ `--./ .-'  `-" << endl;
	cout << White <<"	/        `.  / /       `.~~~~~~~~~~-~~~~~~~'      '-._ `._" << endl;
	

	           
	
	
	/*styuff to add
	
	upper and lower case
	

	*/
	
	
	


}