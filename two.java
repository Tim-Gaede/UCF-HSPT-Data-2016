import java.util.Scanner;


public class two {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		while(T-->0){
			int input = scan.nextInt();
			
			boolean foundNext = false;
			
			int candidate = input+1;
			
			while (!foundNext) {
				String StrCan = Integer.toString(candidate);
				
				for(int i=1;i<=StrCan.length()-1;i++){
					
					//Check all the continuous substrings possible
					int start = Integer.parseInt(StrCan.substring(0, i));
					int end = Integer.parseInt(StrCan.substring(i, StrCan.length()));
					
					//You know a number is a power of two in binary if there are all zeros
					//and only a single 1. Therefore, we use "Integer.bitCount" to see how many
					//ones are in start and end. If they are both powers of two, we continue
					if (Integer.bitCount(start)==1&&Integer.bitCount(end)==1){
						
						//Now we cycle through all 2^k seeing if our candidate + 2^k is also
						//a power of 2.
						for(int k = 0; k < 25;k++){
							if(Integer.bitCount(candidate+(1<<k))==1){
								foundNext=true;
								System.out.println("The next hyper-even after "+input+" is "+candidate);
								break;
							}
						}
					}
					if(foundNext)break;
				}
				candidate++;
			}
		}
		scan.close();
	}
}
