import java.util.Scanner;

public class LightsOut {
	public static void place(int[][] foreground, int amtofpresses, String[] presspoints){
		int[][] background = new int[8][8];
		for(int i=0; i<amtofpresses; i++){
			char[] pivhold = presspoints[i].toCharArray();
			int pivotrow = pivhold[0]-48;
			int pivotcolumn = pivhold[1]-48;
			for(int a=0; a<8; a++){
				for(int b=0; b<8; b++){
					background[a][b] = 0;
				}
			}
			for(int n=0; n<5; n++){
				if(n==1)
					pivotrow+=1;
				if(n==2){
					pivotrow-=1;
					pivotcolumn+=1;
				}
				if(n==3){
					pivotrow-=1;
					pivotcolumn-=1;
				}
				if(n==4){
					pivotrow+=1;
					pivotcolumn-=1;
				}
				for(int a=-1; a<2; a++){	//checks row <->  (-1,0,1)
					if((pivotrow>0 && pivotrow<=8)&&(pivotcolumn+a>0 && pivotcolumn+a<=8)){
						if(background[pivotrow-1][pivotcolumn+a-1]==0){
							background[pivotrow-1][pivotcolumn+a-1] = flip(background[pivotrow-1][pivotcolumn+a-1]);
						}
					}
				}
				for(int a=-1; a<2; a++){	//checks columns <->  (-1,0,1)
					if((pivotrow+a>0 && pivotrow+a<=8)&&(pivotcolumn>0 && pivotcolumn<=8)){
						if(background[pivotrow+a-1][pivotcolumn-1]==0){
							background[pivotrow+a-1][pivotcolumn-1] = flip(background[pivotrow+a-1][pivotcolumn-1]);
						}
					}
				}
			}
			for(int a=0; a<8; a++){
				for(int b=0; b<8; b++){
					if(background[a][b] == 1){
						foreground[a][b] = flip(foreground[a][b]);
					}
				}
			}
		}
		
		
		int invertcounter = 0;
		for(int a=0; a<8; a++){
			for(int b=0; b<8; b++){
				if(foreground[a][b] == 1){
					invertcounter+=1;
				}
			}
		}
		System.out.println("Total on: "+invertcounter);
	}
	
	public static int flip(int x){
		if(x==0)
			x=1;
		else if(x==1)
			x=0;
		return x;
	}
	public static void output(int[][] outputary){
		for(int a=7; a>=0; a--){
			for(int b=0; b<8; b++){
				System.out.print(outputary[a][b] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//2 434 523 1 43
		//1 58 1 58
		//1 58 1 57
		//3 32 44 56 2 54 18
		//4 345 567 678 2 36 55
		for(int j=1; j<=5; j++){
			System.out.println(j+". ");
			int[][] ary = new int[8][8];
			for(int a=0; a<8; a++){
				for(int b=0; b<8; b++){
					ary[a][b] = 0;
				}
			}
			Scanner console = new Scanner(System.in);
			
			String changedrows = console.nextLine();
			int rowvar = Integer.parseInt(changedrows);	//variable is amount of rows affected
			String inputstarton = console.nextLine();		//string input of all start points
			String starton[] = new String[rowvar];		//contains separated substrings of each start point
			for(int i=0; i<rowvar; i++){
				if(inputstarton.contains(" "))
					starton[i] = inputstarton.substring(0, inputstarton.indexOf(" "));
				else
					starton[i] = inputstarton.substring(0, inputstarton.length());
				if(i<rowvar-1){
					StringBuilder deleter = new StringBuilder(inputstarton);
					deleter.delete(0, inputstarton.indexOf(" ")+1);
					//System.out.println(deleter);
					inputstarton = new String(deleter);
				}
			}
			
			String rowpressinput = console.nextLine();
			int rowpress = Integer.parseInt(rowpressinput);	//rowpress is amount of press points
			String inputpress = console.nextLine();		//String input of all press points
			String[] presspoints = new String[rowpress];	//Array of strings on each press point
			for(int i=0; i<rowpress; i++){
				presspoints[i] = inputpress.substring(0, 2);
				if(i<rowvar-1){
					StringBuilder deleter = new StringBuilder(inputpress);
					deleter.delete(0, inputpress.indexOf(" ")+1);
					inputpress = new String(deleter);
				}
			}
			for(int a=0; a<rowvar; a++){
				for(int b=0; b<starton[a].length()-1; b++){
					int initial = Integer.parseInt(starton[a]);
					int expdivide = 1;
					for(int x=0; x<starton[a].length()-1; x++){
						expdivide*=10;
					}
					initial = initial/expdivide;
					char[] hold = starton[a].toCharArray();
					int intholder = (hold[b+1]) - 48;
					ary[initial-1][intholder-1] = flip(ary[initial-1][intholder-1]);
				}
			}
			place(ary, rowpress, presspoints);
			//output(ary);		//outputs the board
		}
	}
}