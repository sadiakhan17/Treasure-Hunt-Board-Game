//Author: Sadia Khan
//Purpose: Create a final game
import java.util.*;
public class finalGame{
	
	static String CLS = "\033[2J\033[1;1H";
	static String Red = "\033[31;1m";
	static String Green = "\033[32;1m";
	static String Yellow = "\033[33;1m";
	static String Blue = "\033[34;1m";
	static String Purple = "\033[35;1m";
	static String Cyan = "\033[36;1m";
	static String White = "\033[37;1m";
	static String Normal = "\033[0m"; // default gray color & reset background to black

	static String WhiteOnRed = "\033[41;1m";
	static String WhiteOnGreen = "\033[42;1m";
	static String WhiteOnYellow = "\033[43;1m";
	static String WhiteOnBlue = "\033[44;1m";
	static String WhiteOnPurple = "\033[45;1m";
	static String WhiteOnCyan = "\033[46;1m";
	
	public static void main (String[] args){
      Scanner in = new Scanner(System.in);
      char choice = ' ';

      // creating the player will initialize the world
      Player p = new Player("Player",'P');

      // create some enemies using array list
	  ArrayList<Enemy> Enemies = new ArrayList<Enemy>();
	  Enemies.add(new Enemy("Dragon"));
	  Enemies.add(new Enemy("Dragon"));
	  Enemies.add(new Enemy("Basilisk"));
	  Enemies.add(new Enemy("Basilisk"));
	  Enemies.add(new Enemy("Ghost"));
	  
	  //call intro screen
	  IntroScreen();
	  	  
      
      do{
		 System.out.print(CLS);
         p.PrintWorld();
		 
		 //player stats and instructions
		 System.out.println();
		 System.out.println(Green + p.name + "	Health: " + White + p.health + Green +"	Attack: " + White + p.attack + Green + "	Armor: " + White + p.armor +  Green+ "	Gold: " +White + p.gold);
		 System.out.println();
		 System.out.println(Green + "Commands:	Left: " +White + "A" + Green + "		Right: "+ White + "D" +	Green + "	Up: " + White + "W" + Green + "		Down: " + White + "S" + Green + "		Quit: " + White + "Q");
		 System.out.println();
		 
         System.out.println("Enter your command: ");
         choice = in.next().charAt(0);

         // call move methods - you can use the standard gaming directions - a,s,d,w
         if (choice=='A'){
            p.MoveLeft();
		}//if
		
        if (choice=='D'){
           p.MoveRight();
		}//if
		
        if (choice=='S'){
           p.MoveDown();
		}//if
		
        if (choice=='W'){
           p.MoveUp();
		}//if
		
		
		// step through Enemy ArrayList and attack if adjacent to player
		// this belongs in the gameloop after the player has moved
		for (int i=0; i<Enemies.size(); i++){
		   if ((Enemies.get(i).yPos == p.yPos && (Enemies.get(i).xPos == p.xPos+1)) || // player is to the left 
			  (Enemies.get(i).yPos == p.yPos && (Enemies.get(i).xPos == p.xPos-1)) ||  // player is to the right
		      (Enemies.get(i).xPos == p.xPos && (Enemies.get(i).yPos == p.yPos+1)) ||  // player is above
		      (Enemies.get(i).xPos == p.xPos && (Enemies.get(i).yPos == p.yPos-1)))    // player is below
		   {
		      //utilizes attack and armor values.
		      p.health -= (100 * Enemies.get(i).attack) / (100 + p.armor);//enemy attacks player
			  Enemies.get(i).health -=(100 * p.attack) / (100 + Enemies.get(i).armor);// Player attacks Enemy

		      // Enemy dies
			  if (Enemies.get(i).health <= 0){
		         p.World[Enemies.get(i).xPos][Enemies.get(i).yPos] = ' ';
		         Enemies.remove(i);
		      }//if
		   }//if 
		}//for
		
		
		// step through Enemy ArrayList and move towards the player
		// add a range variable so enemies only move towards player if within range 
		for (int i=0; i<Enemies.size(); i++){
			
			//check if enemy is within range of player
			if ((Math.abs(p.xPos-Enemies.get(i).xPos) < Enemies.get(i).range) && (Math.abs(p.yPos-Enemies.get(i).yPos) < Enemies.get(i).range)){
				if (Enemies.get(i).xPos > p.xPos){
					Enemies.get(i).MoveLeft();
			   	}// if move left
		   
				else{
					Enemies.get(i).MoveRight();
				}//else for move right
		   
				if (Enemies.get(i).yPos > p.yPos){
					Enemies.get(i).MoveUp();
				}//if move up
		   
				else{
					Enemies.get(i).MoveDown();
				}//else move down
				
			}//if range
			
			//if not in range so move randomly
			else{
				int r= (int) (Math.random() * 7)+1;
				if (r==1){
					Enemies.get(i).MoveLeft();
				}//if
				
				else if(r==2){
					Enemies.get(i).MoveRight();
				}//else if
				
				else if(r==3){
					Enemies.get(i).MoveUp();
				}//ekse if 
				
				else if(r==4){
					Enemies.get(i).MoveDown();
				}//else if
			}//else range
			
		}//for
		
		//winning or losing screen
		if (choice=='Q' || p.health <= 0){
			System.out.print(CLS);
			LoseScreen();
			
		}//if lose
		
		else if (p.gold>=500){
			System.out.print(CLS);
			WinScreen();
			
			
			
		}//else
		
		
		
		
		
	
	
      }while (choice!='Q' && p.health > 0 && p.gold<500);//while
   }//main
   
   //intro screen method
   static void IntroScreen(){
	   
	   
		System.out.println(Green+ "	   ███╗   ███╗███████╗██████╗ ██╗███████╗██╗   ██╗ █████╗ ██╗");         
		System.out.println("	   ████╗ ████║██╔════╝██╔══██╗██║██╔════╝██║   ██║██╔══██╗██║");         
		System.out.println("	   ██╔████╔██║█████╗  ██║  ██║██║█████╗  ██║   ██║███████║██║");         
		System.out.println("	   ██║╚██╔╝██║██╔══╝  ██║  ██║██║██╔══╝  ╚██╗ ██╔╝██╔══██║██║");         
		System.out.println("	   ██║ ╚═╝ ██║███████╗██████╔╝██║███████╗ ╚████╔╝ ██║  ██║███████╗");    
		System.out.println("	   ╚═╝     ╚═╝╚══════╝╚═════╝ ╚═╝╚══════╝  ╚═══╝  ╚═╝  ╚═╝╚══════╝");    
		System.out.println("");                                                                  
		System.out.println("	   ████████╗██████╗ ███████╗ █████╗ ███████╗██╗   ██╗██████╗ ███████╗"); 
		System.out.println("	   ╚══██╔══╝██╔══██╗██╔════╝██╔══██╗██╔════╝██║   ██║██╔══██╗██╔════╝"); 
		System.out.println("	      ██║   ██████╔╝█████╗  ███████║███████╗██║   ██║██████╔╝█████╗");   
		System.out.println("	      ██║   ██╔══██╗██╔══╝  ██╔══██║╚════██║██║   ██║██╔══██╗██╔══╝");
		System.out.println("	      ██║   ██║  ██║███████╗██║  ██║███████║╚██████╔╝██║  ██║███████╗");
		System.out.println("	      ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝"); 
		System.out.println("");                                                                  
		System.out.println("	               ██╗  ██╗██╗   ██╗███╗   ██╗████████╗");                   
		System.out.println("	               ██║  ██║██║   ██║████╗  ██║╚══██╔══╝");                   
		System.out.println("	               ███████║██║   ██║██╔██╗ ██║   ██║");                      
		System.out.println("	               ██╔══██║██║   ██║██║╚██╗██║   ██║");                      
		System.out.println("	               ██║  ██║╚██████╔╝██║ ╚████║   ██║");                      
		System.out.println("	               ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝");                      
                                                                   
	   
	   
		System.out.println();
		System.out.println();
		System.out.println(White+ "	   ,   A           {}" + "\t\t\t\t" + Green +"      Legend" + White);
		System.out.println("	  / \\, | ,        .--." + "\t\t\t\t" +  Green +"-------------------"+ White);
		System.out.println("	 |    =|= >      /.--.\\"+ "\t\t\t\t"+   "P Player");
		System.out.println("	  \\ /` | `       |====|" + "\t\t\t\t" + Red+ "D"+ White+ " Dragon");
		System.out.println("	   `   |         |`::`|  "+ "\t\t\t" + Purple + "B" + White+ " Basilisk");
		System.out.println("	       |     .-;`\\..../`;_.-^-._"+ "\t\t" +Blue + "G "+ White + "Ghost");
		System.out.println("	      /\\\\/  /  |...::..|`   :   `|"+ "\t\t" + Yellow + "$" + White +" Gold Each $ is $100");
		System.out.println("	      |:'\\ |   /'''::''|   .:.   |"+ "\t\t" + "+ Med pack (20 Points)");
		System.out.println("	       \\ /\\;-,/\\   ::  |..:::::..|"+"\t\t" +"% Armor Upgrade (20 Points)");
		System.out.println("	       |\\ <` >  >._::_.| ':::::' |");
		System.out.println("	       | `\"\"`  /   ^^  |   ':'   |");
		System.out.println("	       |       |       \\    :    /" + "\t\t" +Green +" Instructions" + White);
		System.out.println("	       |       |        \\   :   /"+ "\t\t" + Green+ "----------------"+ White) ; 
		System.out.println("	       |       |___/\\___|`-.:.-`" + "\t\t" +"You are a knight on a quest to find gold!");
		System.out.println("	       |        \\_ || _/    `" + "\t\t\t" +"You must find $500 worth of gold (5 $s) for your quest to be successful ");
		System.out.println("	       |        <_ >< _>"+ "\t\t\t" +"There will be all sorts of monsters you will have to fight!");
		System.out.println("	       |        |  ||  |"+ "\t\t\t" +"Good luck!");
		System.out.println("	       |        |  ||  |");
		System.out.println("	       |       _\\.:||:./_");
		System.out.println("	       |      /____/\\____\\");
		
		
		System.out.println();
		
		
		System.out.println("Press enter to begin: ");
		Scanner in = new Scanner(System.in);
		in.nextLine();
		 
		

	   
   	
	
   }//introscreen
   
   //Losescreen
   
   static void LoseScreen(){
		System.out.println(Red+ "	   ██╗   ██╗ ██████╗ ██╗   ██╗");          
		System.out.println("	   ╚██╗ ██╔╝██╔═══██╗██║   ██║");          
		System.out.println("	    ╚████╔╝ ██║   ██║██║   ██║");          
		System.out.println("	     ╚██╔╝  ██║   ██║██║   ██║");          
		System.out.println("	      ██║   ╚██████╔╝╚██████╔╝");          
		System.out.println("	      ╚═╝    ╚═════╝  ╚═════╝");           
		System.out.println("");                                     
		System.out.println("	   ██╗      ██████╗ ███████╗████████╗██╗");
		System.out.println("	   ██║     ██╔═══██╗██╔════╝╚══██╔══╝██║");
		System.out.println("	   ██║     ██║   ██║███████╗   ██║   ██║");
		System.out.println("	   ██║     ██║   ██║╚════██║   ██║   ╚═╝");
		System.out.println("	   ███████╗╚██████╔╝███████║   ██║   ██╗");
		System.out.println("	   ╚══════╝ ╚═════╝ ╚══════╝   ╚═╝   ╚═╝");
		
		System.out.println();
		
		System.out.println("                                                 /===-_---~~~~~~~~~------____");
		System.out.println("                                                |===-~___                _,-'");
		System.out.println("                 -==\\\\                         `//~\\\\   ~~~~`---.___.-~~");
		System.out.println("             ______-==|                         | |  \\\\           _-~`");
		System.out.println("       __--~~~  ,-/-==\\\\                        | |   `\\        ,'");
		System.out.println("    _-~       /'    |  \\\\                      / /      \\      /");
		System.out.println("  .'        /       |   \\\\                   /' /        \\   /'");
		System.out.println(" /  ____  /         |    \\`\\.__/-~~ ~ \\ _ _/'  /          \\/'");
		System.out.println("/-'~    ~~~~~---__  |     ~-/~         ( )   /'        _--~`");
		System.out.println("                  \\_|      /        _)   ;  ),   __--~~");
		System.out.println("                    '~~--_/      _-~/-  / \\   '-~ \\");
		System.out.println("                   {\\__--_/}    / \\\\_>- )<__\\      \\");
		System.out.println("                   /'   (_/  _-~  | |__>--<__|      |");
		System.out.println("                  |0  0 _/) )-~     | |__>--<__|      |");
		System.out.println("                  / /~ ,_/       / /__>---<__/      |");
		System.out.println("                 o o _//        /-~_>---<__-~      /");
		System.out.println("                 (^(~          /~_>---<__-      _-~");
		System.out.println("                ,/|           /__>--<__/     _-~");
		System.out.println("             ,//('(          |__>--<__|     /                  .----_");
		System.out.println("            ( ( '))          |__>--<__|    |                 /' _---_~\\");
		System.out.println("         `-)) )) (           |__>--<__|    |               /'  /     ~\\`\\");
		System.out.println("        ,/,'//( (             \\__>--<__\\    \\            /'  //        ||");
		System.out.println("      ,( ( ((, ))              ~-__>--<_~-_  ~--____---~' _/'/        /'");
		System.out.println("    `~/  )` ) ,/|                 ~-_~>--<_/-__       __-~ _/");
		System.out.println("  ._-~//( )/ )) `                    ~~-'_/_/ /~~~~~~~__--~");
		System.out.println("   ;'( ')/ ,)(                              ~~~~~~~~~~");
		System.out.println("  ' ') '( (/");
		System.out.println("    '   '  `");

		
                                     
	   
   	
	
	
   }//Lose screen
   
   
   
   //Win screen
   
   static void WinScreen(){
		System.out.println(Green + "	   ██╗   ██╗ ██████╗ ██╗   ██╗");     
		System.out.println("	   ╚██╗ ██╔╝██╔═══██╗██║   ██║");     
		System.out.println("	    ╚████╔╝ ██║   ██║██║   ██║");     
		System.out.println("	     ╚██╔╝  ██║   ██║██║   ██║");     
		System.out.println("	      ██║   ╚██████╔╝╚██████╔╝");     
		System.out.println("	      ╚═╝    ╚═════╝  ╚═════╝");      
		System.out.println("");                               
		System.out.println("	   ██╗    ██╗ ██████╗ ███╗   ██╗██╗");
		System.out.println("	   ██║    ██║██╔═══██╗████╗  ██║██║");
		System.out.println("	   ██║ █╗ ██║██║   ██║██╔██╗ ██║██║");
		System.out.println("	   ██║███╗██║██║   ██║██║╚██╗██║╚═╝");
		System.out.println("	   ╚███╔███╔╝╚██████╔╝██║ ╚████║██╗");
		System.out.println("	    ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═══╝╚═╝");
		
		System.out.println();
		
		


		System.out.println(Yellow + "\t                 _.--.");
		System.out.println("\t             _.-'_:-'||");
		System.out.println("\t         _.-'_.-::::'||");
		System.out.println("\t    _.-:'_.-::::::'  ||");
		System.out.println("\t  .'`-.-:::::::'     ||");
		System.out.println("\t /.'`;|:::::::'      ||_");
		System.out.println("\t||   ||::::::'     _.;._'-._");
		System.out.println("\t||   ||:::::'  _.-!oo @.!-._'-.");
		System.out.println("\t\\'.  ||:::::.-!()oo @!()@.-'_.|");
		System.out.println("\t '.'-;|:.-'.&$@.& ()$%-'o.'\\U||");
		System.out.println("\t   `>'-.!@%()@'@_%-'_.-o _.|'||");
		System.out.println("\t    ||-._'-.@.-'_.-' _.-o  |'||");
		System.out.println("\t    ||=[ '-._.-\\U/.-'    o |'||");
		System.out.println("\t    || '-.]=|| |'|      o  |'||");
		System.out.println("\t    ||      || |'|        _| ';");
		System.out.println("\t    ||      || |'|    _.-'_.-'");
		System.out.println("\t    |'-._   || |'|_.-'_.-'");
		System.out.println("\t     '-._'-.|| |' `_.-'");
		System.out.println("\t         '-.||_/.-'");

		
		
		
                                
   
	
   }//win screen
   
   
}//game


class GameObject{ //superclass
	static String CLS = "\033[2J\033[1;1H";
	static String Red = "\033[31;1m";
	static String Green = "\033[32;1m";
	static String Yellow = "\033[33;1m";
	static String Blue = "\033[34;1m";
	static String Purple = "\033[35;1m";
	static String Cyan = "\033[36;1m";
	static String White = "\033[37;1m";
	static String Normal = "\033[0m"; // default gray color & reset background to black

	static String WhiteOnRed = "\033[41;1m";
	static String WhiteOnGreen = "\033[42;1m";
	static String WhiteOnYellow = "\033[43;1m";
	static String WhiteOnBlue = "\033[44;1m";
	static String WhiteOnPurple = "\033[45;1m";
	static String WhiteOnCyan = "\033[46;1m";
	
	
	//Variables
	int health, attack, xPos, yPos, armor;
	char avatar;
		
		
	
	//the world 40 by 20 (won't use 0,0)
	static char World[][] = new char[41][21];
	
	//print world
	void PrintWorld(){
		for (int y=1; y<=20; y++){
			for (int x=1; x<=40; x++){
				if (World[x][y]=='$'){
					System.out.print(Yellow + "$"+ Normal + " ");
					
				}//if
				
				else if (World[x][y]=='D'){
					System.out.print(Red + "D"+ Normal + " ");
					
				}//if else
				
				else if (World[x][y]=='B'){
					System.out.print(Purple + "B"+ Normal + " ");
					
				}//if else
				
				else if (World[x][y]=='G'){
					System.out.print(Blue + "G"+ Normal + " ");
					
				}//if else
				
				else if (World[x][y]=='~'){
					System.out.print(Cyan+ "~"+ Normal + " ");
					
				}//if else
				
				else if (World[x][y]=='*'){
					System.out.print(Green+ "*"+ Normal + " ");
					
				}//if else
				
				else{
					System.out.print(World[x][y]+ " ");
				}
			}//x
			System.out.println();
		}//y
		
	}//print world
	
	
	

}//Game object


class Enemy extends GameObject{ //subclass
	
	//variables
	String type;
	int range;

	
	//create constructor
	Enemy (String theType){
		
		//make class variable to parameter
		type=theType;
	
		
		//set x and y position
		xPos=(int)((Math.random()*38)+2); //2 to 39 b/c 1 and 40 are border
		yPos=(int)((Math.random()*18)+2);//2 to 19 b/c 1 and 20 are border
		
		//assign things based on type
		if(type.equals("Dragon")){
			avatar='D';
			health=500;
			attack=75;
			range=15;
			armor=75;
			
		}//dragon
		
		World[xPos][yPos]=avatar; //put eneemy into world
		
		//assign things based on type
		if(type.equals("Basilisk")){
			avatar='B';
			health=300;
			range=10;
			attack=50;
			armor=45;
			
		}//Basilisk
		
		World[xPos][yPos]=avatar; //put enemy into world
		
		
		//assign things based on type
		if(type.equals("Ghost")){
			avatar='G';
			health=100;
			range=5;
			attack=20;
			armor=5;
		
			
		}//Ghost
		
		World[xPos][yPos]=avatar; //put enemy into world
		
		
		
	}//constructor
	
	//move right
	void MoveRight(){
		if (World[xPos+1][yPos] == ' '){
		   World[xPos][yPos] = ' ';
		   xPos++;
		   World[xPos][yPos] = avatar;
		}//if
		
	}//move right
	
	//move left
	void MoveLeft(){
		if (World[xPos-1][yPos] == ' '){
		   World[xPos][yPos] = ' ';
		   xPos--;
		   World[xPos][yPos] = avatar;
		}//if
		
	}//move left
	
	//move up
	void MoveUp(){
		if (World[xPos][yPos-1] == ' '){
		   World[xPos][yPos] = ' ';
		   yPos--;
		   World[xPos][yPos] = avatar;
		}//if
		
	}//move up
	
	//move down
	void MoveDown(){
		if (World[xPos][yPos+1] == ' '){
		   World[xPos][yPos] = ' ';
		   yPos++;
		   World[xPos][yPos] = avatar;
		}//if
		
	}//move down
	
	
	
	
}//Enemy


class Player extends GameObject{ //subclass
	//define variables
	String name;
	int gold;
	
	Player(String theName, char theAvatar){
		
		//assign variables parameters
		name= theName;
		avatar= theAvatar;
		
		// set entire world to spaces
		for (int x=1; x<=40; x++)
		   for (int y=1; y<=20; y++)
		      World[x][y] = ' ';

		// put the player into the world after filling it with spaces
		//top left
		xPos=2;  
		yPos=2; 
		health=600;
		attack=100;
		armor=150;
		gold=0;
		World[2][2]=avatar;

		// line perimeter of world with stars *
		for (int x=1; x<=40; x++){
			World[x][1] = '*';
			World[x][20] = '*';  
		}// first and last row
		
		for (int y=1; y<=20; y++){
			World[1][y] = '*';
			World[40][y] = '*';
		}//first and last column
		
		//Put in gold and items
		World[(int)((Math.random()*38)+2)][(int)((Math.random()*18)+2)]='$';
		World[(int)((Math.random()*38)+2)][(int)((Math.random()*18)+2)]='$';
		World[(int)((Math.random()*38)+2)][(int)((Math.random()*18)+2)]='$';
		World[(int)((Math.random()*38)+2)][(int)((Math.random()*18)+2)]='$';
		World[(int)((Math.random()*38)+2)][(int)((Math.random()*18)+2)]='$';
		World[(int)((Math.random()*38)+2)][(int)((Math.random()*18)+2)]='$';
		
		World[(int)((Math.random()*38)+2)][(int)((Math.random()*18)+2)]='+';
		World[(int)((Math.random()*38)+2)][(int)((Math.random()*18)+2)]='+';
		
		World[(int)((Math.random()*38)+2)][(int)((Math.random()*18)+2)]='%';
		World[(int)((Math.random()*38)+2)][(int)((Math.random()*18)+2)]='%';
		
		
		
		
		// draw a lake at a random location 
		int a = (int)(Math.random()*30)+4;
		int b = (int)(Math.random()*10)+3;
		World[a][b] = '~';
		World[a+1][b] = '~';
		World[a+2][b] = '~';
		World[a+3][b] = '~';
		World[a+4][b] = '~';
		World[a][b+1] = '~'; 
		World[a+1][b+1] = '~'; 
		World[a+2][b+1] = '~';
		World[a+3][b+1] = '~';
		World[a+4][b+1] = '~';
		World[a][b+2] = '~'; 
		World[a+1][b+2] = '~'; 
		World[a+2][b+2] = '~';
		World[a+3][b+2] = '~';
		World[a+4][b+2] = '~';
		World[a][b+3] = '~'; 
		World[a+1][b+3] = '~'; 
		World[a+2][b+3] = '~';
		World[a+3][b+3] = '~';
		World[a+4][b+3] = '~';
		World[a][b+4] = '~'; 
		World[a+1][b+4] = '~'; 
		World[a+2][b+4] = '~';
		World[a+3][b+4] = '~';
		World[a+4][b+4] = '~';
		
		
	}//constructor
	
	//move right
	void MoveRight(){
		if (World[xPos+1][yPos] == ' ' || World[xPos+1][yPos] == '$' || World[xPos+1][yPos] == '+' || World[xPos+1][yPos] == '%'){
 		   if(World[xPos+1][yPos] == '$'){
 			   gold+=100;
 		   }//if $ 
		   
 		   if (World[xPos+1][yPos] == '+'){
 			   health+=20;
 		   }// if +
		   
 		   if (World[xPos+1][yPos] == '%'){
 			   armor+=20;
 		   }// if %
		   World[xPos][yPos] = ' ';
		   xPos++;
		   World[xPos][yPos] = avatar;
		}//if
		
	}//move right
	
	//move left
	void MoveLeft(){
		if (World[xPos-1][yPos] == ' ' || World[xPos-1][yPos] == '$' || World[xPos-1][yPos] == '+' || World[xPos-1][yPos] == '%'){
		   if(World[xPos-1][yPos] == '$'){
			   gold+=100;
		   }//if $ 
		   
		   if (World[xPos-1][yPos] == '+'){
			   health+=20;
		   }// if +
		   
		   if (World[xPos-1][yPos] == '%'){
			   armor+=20;
		   }// if %
		   
		   World[xPos][yPos] = ' ';
		   xPos--;
		   World[xPos][yPos] = avatar;
		}//if
		
	}//move left
	
	//move up
	void MoveUp(){
		if (World[xPos][yPos-1] == ' ' || World[xPos][yPos-1] == '$' || World[xPos][yPos-1] == '+' || World[xPos][yPos-1] == '%'){
 		   if(World[xPos][yPos-1] == '$'){
 			   gold+=100;
 		   }//if $ 
		   
 		   if (World[xPos][yPos-1] == '+'){
 			   health+=20;
 		   }// if +
		   
 		   if (World[xPos][yPos-1] == '%'){
 			   armor+=20;
 		   }// if %
		   World[xPos][yPos] = ' ';
		   yPos--;
		   World[xPos][yPos] = avatar;
		}//if
		
	}//move up
	
	//move down
	void MoveDown(){
		if (World[xPos][yPos+1] == ' ' || World[xPos][yPos+1] == '$' || World[xPos][yPos+1] == '+' || World[xPos][yPos+1] == '%'){
  		   if(World[xPos][yPos+1] == '$'){
  			   gold+=100;
  		   }//if $ 
		   
  		   if (World[xPos][yPos+1] == '+'){
  			   health+=20;
  		   }// if +
		   
  		   if (World[xPos][yPos+1] == '%'){
  			   armor+=20;
  		   }// if %
		   World[xPos][yPos] = ' ';
		   yPos++;
		   World[xPos][yPos] = avatar;
		}//if
		
	}//move down
	
	
	
	
}//Player

