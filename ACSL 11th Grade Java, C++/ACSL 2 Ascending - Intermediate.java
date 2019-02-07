import java.util.Scanner;

public class IntAscending {
	public static char[] Reverse(String flipthis){

		char holder;
		char[] charFlip = flipthis.toCharArray();
		for(int i=1; i<=(flipthis.length()-1)/2; i++){
			holder = charFlip[i];
			charFlip[i] = charFlip[charFlip.length-i];
			charFlip[charFlip.length-i] = holder;
		}
		return charFlip;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 Scanner console = new Scanner(System.in);
		 //"1314159265"
		 String input = console.nextLine();		//.nextInt for ints etc.
		 String output = "";
		 int pivot, begin;
		 char[] digits = Reverse(input);
		 begin = digits[0];
		 digits[0] =

	}
}
