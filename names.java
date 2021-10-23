import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class names {
	
	// declare our constant string of vowels for use in our program
	static String vowels = "AEIOU";

	public static void main(String[] args) {
		
		// make our Scanner and scan in the number of test cases (runs)
		Scanner scan = new Scanner(System.in);
		int runs = scan.nextInt();
		
		for(int i = 0; i < runs; i++){
			
			// this is where we will store every name we find to be valid
			ArrayList<String> valid_names = new ArrayList<String>();
			
			System.out.print("Couple #" + (i + 1) + ": ");
			
			// get in the parents' names from input
			String name1 = scan.next();
			String name2 = scan.next();
			
			// make all possible valid prefixes out of the first name, then
			// make all possible valid suffixes out of the second name
			for(int j = name1.length() - 1; j >= 1; j--){
				
				// the prefix
				String temp1 = name1.substring(0, j);
				
				for(int k = 1; k < name2.length(); k++){
					
					// the suffix
					String temp2 = name2.substring(k);
					
					// if the second half has the opposite (vowel/consonant) of the first
					// half's ending character, then we can safely combine the names
					if(vowels.contains("" + temp1.charAt(temp1.length() - 1))
							!= vowels.contains("" + temp2.charAt(0))){
						
						// make a name out of the prefix and suffix
						String baby_name = temp1 + temp2;
						
						// if we don't already have this name, then add it to our list
						if(!valid_names.contains(baby_name)){
							valid_names.add(temp1 + temp2);
						}
					}
				}
			}
			
			// now do the same process, but with the names switched
			for(int j = name2.length() - 1; j >= 1; j--){
				String temp1 = name2.substring(0, j);
				for(int k = 1; k < name1.length(); k++){
					String temp2 = name1.substring(k);
					if(vowels.contains("" + temp1.charAt(temp1.length() - 1))
							!= vowels.contains("" + temp2.charAt(0))){
						String baby_name = temp1 + temp2;
						if(!valid_names.contains(baby_name)){
							valid_names.add(temp1 + temp2);
						}
					}
				}
			}
			
			/// now that we have a list of all possible names, sort them alphabetically
			Collections.sort(valid_names);
			
			// and now just print them out!
			System.out.println(valid_names.size() + " possible names");
			for(int j = 0; j < valid_names.size(); j++){
				System.out.println(valid_names.get(j));
			}
			System.out.println();
		}
	}

}
