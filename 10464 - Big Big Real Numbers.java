// Meysam Aghighi
// Comments: Well, use BigDecimal and the trick to check if a BigDecimal value is actually an int.
import java.math.*;
import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		while (n > 0){
		    n = n-1;
			BigDecimal a = in.nextBigDecimal(), b = in.nextBigDecimal();
			a = a.add(b);
			if (a.signum() == 0 || a.scale() <= 0 || a.stripTrailingZeros().scale() <= 0) // trick!
			    System.out.println(a.stripTrailingZeros()+".0");
			else System.out.println(a.stripTrailingZeros());
		}		
	}	
}