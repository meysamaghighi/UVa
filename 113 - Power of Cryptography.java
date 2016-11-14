// Meysam Aghighi
// Comments: BigInteger + Binary Search
import java.math.*;
import java.util.Scanner;


public class Main {
	
	private static int nthRoot(BigInteger p, int n, int lo, int hi){
	    if (lo == hi) return lo;
	    int mi = (lo+hi)/2;
		BigInteger MI = new BigInteger(mi+"");
		BigInteger po = MI.pow(n);
		if (po.compareTo(p) == 0) return mi;
		if (po.compareTo(p) < 0) return nthRoot(p,n,mi+1,hi);
		return nthRoot(p,n,lo,mi-1);
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);		
		while (in.hasNext()){
			int n = in.nextInt();
			BigInteger p = in.nextBigInteger();
			int ans = nthRoot(p,n,1,1000000001);
			System.out.println(ans);
		}		
	}	
}