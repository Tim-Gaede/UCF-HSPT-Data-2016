import java.util.Scanner;


public class thirty {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();  	//scan in the number of integers to be processed
		
		for(int i=0;i<n;i++){		//loop for the specified number of times
			
			int num = scan.nextInt();	//scan in the number guaranteed to be in the format 2 * 3 * r
			num = num / 2;				//divide num by 2, the remaining integer is 3 * r
			num = num / 3;				//divide num by 3, the remaining integer is r
			
			System.out.println(num); 	//print out r on a line by itself
		}
		
	}

}
