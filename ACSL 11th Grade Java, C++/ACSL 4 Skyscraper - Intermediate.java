import java.util.Scanner;

public class Skyscraper {
	
	public static boolean checkColumn(int[][] newBoard, int[][] clueNS, int column){	// TOP/BOT (NS)
		int totaltruecount = 0;
		int current = 0;
		int totalseen = 0;
		for(int a=0; a<4; a++){					//TOP -> DOWN
			if(newBoard[a][column] > current){
				current = newBoard[a][column];
				totalseen++;
			}
		}
		if(totalseen == clueNS[0][column])
			totaltruecount++;
		
		current = 0;
		totalseen = 0;
		for(int a=3; a>=0; a--){					//BOTTOM -> UP
			if(newBoard[a][column] > current){
				current = newBoard[a][column];
				totalseen++;
			}
		}
		if(totalseen == clueNS[1][column])
			totaltruecount++;
		
		if(totaltruecount == 2)
			return true;
		else
			return false;
	}
	
	public static boolean checkRow(int[][] newBoard, int[][] clueEW, int row){	// LEFT/RIGHT (EW)
		int totaltruecount = 0;
		int current = 0;
		int totalseen = 0;
		for(int a=0; a<4; a++){					//LEFT -> RIGHT
			if(newBoard[row][a] > current){
				current = newBoard[row][a];
				totalseen++;
			}
		}
		if(totalseen == clueEW[row][0])
			totaltruecount++;
		
		current = 0;
		totalseen = 0;
		for(int a=3; a>=0; a--){					//RIGHT -> LEFT
			if(newBoard[row][a] > current){
				current = newBoard[row][a];
				totalseen++;
			}
		}
		if(totalseen == clueEW[row][1])
			totaltruecount++;
		
		if(totaltruecount == 2)
			return true;
		else
			return false;
	}
	
	public static int[][] checkFours(int[][] ary, int[][] clueNS, int[][] clueEW){
		///LEFT  (EW)
		for(int a=0; a<4; a++){
			if(clueEW[a][0] == 4){
				for(int b=0; b<4; b++){
					ary[a][b] = b+1;
				}
			}
			else if(clueEW[a][0] == 1)
				ary[a][0] = 4;
		}
		///RIGHT (EW)
		for(int a=0; a<4; a++){
			if(clueEW[a][1] == 4){
				for(int b=0; b<4; b++){
					ary[a][b] = 4-b;
				}
			}
			else if(clueEW[a][1] == 1)
				ary[a][3] = 4;
		}
		
		///TOP (NS)
		for(int a=0; a<4; a++){
			if(clueNS[0][a] == 4){
				for(int b=0; b<4; b++){
					ary[b][a] = b+1;
				}
			}
			else if(clueNS[0][a] == 1)
				ary[0][a] = 4;
		}
		///BOTTOM (NS)
		for(int a=0; a<4; a++){
			if(clueNS[1][a] == 4){
				for(int b=0; b<4; b++){
					ary[b][a] = 4-b;
				}
			}
			else if(clueNS[1][a] == 1)
				ary[3][a] = 4;
		}
		return ary;
	}
	
	public static int[][] createBoard(int[][] ary, int[][] clueNS, int[][] clueEW, int counter){
		if(counter >= 16){//check to make sure all the rows and columns match the clues (2s and 3s)
			if(checkColumn(ary, clueNS, 0)==false);
			else if(checkColumn(ary, clueNS, 1)==false);
			else if(checkColumn(ary, clueNS, 2)==false);
			else if(checkColumn(ary, clueNS, 3)==false);
			else if(checkRow(ary, clueEW, 0)==false);
			else if(checkRow(ary, clueEW, 1)==false);
			else if(checkRow(ary, clueEW, 2)==false);
			else if(checkRow(ary, clueEW, 3)==false);
			else{
				return ary;
			}
		}
		else{
			if(ary[counter/4][counter%4]!=0){
				return createBoard(ary, clueNS, clueEW, counter+1);
			}
			for(int a=0; a<4; a++){					//checks for collisions
				if(ary[((counter/4)+1)%4][counter%4]==a+1);
				else if(ary[((counter/4)+2)%4][counter%4]==a+1);
				else if(ary[((counter/4)+3)%4][counter%4]==a+1);
				else if(ary[counter/4][((counter%4)+1)%4]==a+1);
				else if(ary[counter/4][((counter%4)+2)%4]==a+1);
				else if(ary[counter/4][((counter%4)+3)%4]==a+1);
				else{
					int[][] temp=new int[4][4];
					for(int i=0; i<4; i++){		//copying over into temp (to get around aliasing)
						for(int j=0; j<4; j++){
							temp[i][j]=ary[i][j];
						}
					}
					temp[counter/4][counter%4]=a+1;		//changing value of temp to 1-4
					temp=createBoard(temp, clueNS, clueEW, counter+1);	//runs at the next counter
					if(temp[0][0]!=-1){
						return temp;
					}
				}
			}
		}
		int[][] fail = new int[4][4];
		fail[0][0]=-1;
		return fail;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] board = new int[4][4];	//actual board
		int[][] clueNS = new int[2][4];	//clues on TOP and BOTTOM of the board (North and South)
		int[][] clueEW = new int[4][2];	//clues on LEFT and RIGHT of the board (East and West)
		int sholder;
		double iholder;
		
		//String input = "3221, 41, 22, 14, 22, 2313";		//CHANGE TO INPUT FROM CONSOLE
		Scanner scanner = new Scanner(System.in);
		String input = scanner.nextLine();
		
		String topclue = input.substring(0, input.indexOf(","));		//inputs and places TOP row of clues
		input = input.substring(input.indexOf(" ")+1, input.length());
		sholder = Integer.parseInt(topclue);	//3221
		iholder = (double)sholder/1000;			//3.221
		for(int i=0; i<=topclue.length()-1; i++){
			clueNS[0][i] = (int)iholder;
			iholder-=(int)iholder;
			iholder*=10;
		}
		
		String row1 = input.substring(0, input.indexOf(","));			// 0,0 / 0,1
		input = input.substring(input.indexOf(" ")+1, input.length());
		sholder = Integer.parseInt(row1);
		if(sholder > 100000){
			iholder = (double)sholder/100000;
			clueEW[0][0] = (int)iholder;
			iholder -= (int)iholder;
			iholder*=10;
			for(int a=0; a<4; a++){
				board[0][a] = (int)iholder;
				iholder -= (int)iholder;
				iholder*=10;
			}
			if((int)(iholder+.1) > (int)iholder)
				iholder+=1;
			clueEW[0][1] = (int)iholder;
		}
		else{
			iholder = (double)sholder/10;
			clueEW[0][0] = (int)iholder;
			iholder -= (int)iholder;
			iholder*=10;
			if((int)(iholder+.1) > (int)iholder)
				iholder+=1;
			clueEW[0][1] = (int)iholder;
		}
		
		String row2 = input.substring(0, input.indexOf(","));			// 1,0 / 1,1
		input = input.substring(input.indexOf(" ")+1, input.length());
		sholder = Integer.parseInt(row2);
		if(sholder > 100000){
			iholder = (double)sholder/100000;
			clueEW[1][0] = (int)iholder;
			iholder -= (int)iholder;
			iholder*=10;
			for(int a=0; a<4; a++){
				board[1][a] = (int)iholder;
				iholder -= (int)iholder;
				iholder*=10;
			}
			if((int)(iholder+.1) > (int)iholder)
				iholder+=1;
			clueEW[1][1] = (int)iholder;
		}
		else{
			iholder = (double)sholder/10;
			clueEW[1][0] = (int)iholder;
			iholder -= (int)iholder;
			iholder*=10;
			if((int)(iholder+.1) > (int)iholder)
				iholder+=1;
			clueEW[1][1] = (int)iholder;
		}
		
		String row3 = input.substring(0, input.indexOf(","));			// 2,0 / 2,1
		input = input.substring(input.indexOf(" ")+1, input.length());
		sholder = Integer.parseInt(row3);
		if(sholder > 100000){
			iholder = (double)sholder/100000;
			clueEW[2][0] = (int)iholder;
			iholder -= (int)iholder;
			iholder*=10;
			for(int a=0; a<4; a++){
				board[2][a] = (int)iholder;
				iholder -= (int)iholder;
				iholder*=10;
			}
			if((int)(iholder+.1) > (int)iholder)
				iholder+=1;
			clueEW[2][1] = (int)iholder;
		}
		else{
			iholder = (double)sholder/10;
			clueEW[2][0] = (int)iholder;
			iholder -= (int)iholder;
			iholder*=10;
			if((int)(iholder+.1) > (int)iholder)
				iholder+=1;
			clueEW[2][1] = (int)iholder;
		}
		
		String row4 = input.substring(0, input.indexOf(","));			// 3,0 / 3,1
		input = input.substring(input.indexOf(" ")+1, input.length());
		sholder = Integer.parseInt(row4);
		if(sholder > 100000){
			iholder = (double)sholder/100000;
			clueEW[3][0] = (int)iholder;
			iholder -= (int)iholder;
			iholder*=10;
			for(int a=0; a<4; a++){
				board[3][a] = (int)iholder;
				iholder -= (int)iholder;
				iholder*=10;
			}
			if((int)(iholder+.1) > (int)iholder)
				iholder+=1;
			clueEW[3][1] = (int)iholder;
		}
		else{
			iholder = (double)sholder/10;
			clueEW[3][0] = (int)iholder;
			iholder -= (int)iholder;
			iholder*=10;
			if((int)(iholder+.1) > (int)iholder)
				iholder+=1;
			clueEW[3][1] = (int)iholder;
		}
		
		String botclue = input.substring(0, input.length());		//inputs and places BOTTOM row of clues
		sholder = Integer.parseInt(botclue);	//3221
		iholder = (double)sholder/1000;			//3.221
		for(int i=0; i<=botclue.length()-1; i++){
			clueNS[1][i] = (int)iholder;
			iholder-=(int)iholder;
			iholder*=10;
		}
		
		checkFours(board, clueNS, clueEW);		//done with making board
		board=createBoard(board, clueNS, clueEW, 0);
		
		/*for(int a=0; a<4; a++){						//BOARD output
			for(int b=0; b<4; b++){
				System.out.print(board[a][b]+" ");
			}
			System.out.println();
		}
		System.out.println();*/
		
		for(int i=0; i<5; i++){					//INPUT
			//Scanner scanner = new Scanner(System.in);
			input = scanner.nextLine();
			if(Integer.parseInt(input) == 11)
				System.out.println(board[0][0]);
			else if(Integer.parseInt(input) == 12)
				System.out.println(board[0][1]);
			else if(Integer.parseInt(input) == 13)
				System.out.println(board[0][2]);
			else if(Integer.parseInt(input) == 14)
				System.out.println(board[0][3]);
			else if(Integer.parseInt(input) == 21)
				System.out.println(board[1][0]);
			else if(Integer.parseInt(input) == 22)
				System.out.println(board[1][1]);
			else if(Integer.parseInt(input) == 23)
				System.out.println(board[1][2]);
			else if(Integer.parseInt(input) == 24)
				System.out.println(board[1][3]);
			else if(Integer.parseInt(input) == 31)
				System.out.println(board[2][0]);
			else if(Integer.parseInt(input) == 32)
				System.out.println(board[2][1]);
			else if(Integer.parseInt(input) == 33)
				System.out.println(board[2][2]);
			else if(Integer.parseInt(input) == 34)
				System.out.println(board[2][3]);
			else if(Integer.parseInt(input) == 41)
				System.out.println(board[3][0]);
			else if(Integer.parseInt(input) == 42)
				System.out.println(board[3][1]);
			else if(Integer.parseInt(input) == 43)
				System.out.println(board[3][2]);
			else if(Integer.parseInt(input) == 44)
				System.out.println(board[3][3]);
		}
		
		/*for(int a=0; a<2; a++){						//NS output
			for(int b=0; b<4; b++){
				System.out.print(clueNS[a][b]+" ");
			}
			System.out.println();
		}
		System.out.println();
		
		for(int a=0; a<4; a++){						//EW output
			for(int b=0; b<2; b++){
				System.out.print(clueEW[a][b]+" ");
			}
			System.out.println();
		}*/
		
		
	}

}