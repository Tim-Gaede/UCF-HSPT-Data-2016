import java.util.*;

public class moes
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        // this HashMap stores the names inputted
        HashSet<String> names = new HashSet<String>();
        int C = in.nextInt();
        for(int c = 1; c <= C; c++)
        {
            String name = in.next();
            if(names.contains(name))
            {
                // names already contains name
                System.out.println("Customer #" + c + ": **continue working**");
            }
            else
            {
                // make sure this customer is added to the set of names
                names.add(name);
                System.out.println("Customer #" + c + ": Welcome to Moe's!!!");
            }
        }
    }
}
