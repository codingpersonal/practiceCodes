/*You are given an input sorted array and a sum K
 * Find a pair from the array where in the sum is equal to K
 * Algo: Start two pointers- one from beginning and one from end
 * If the sum of the numbers is less than K, then move the front one
 * Else move the last pointer*/
public class FindSum {

	public static void main(String[] args) {
		int arr[]={0,2,3,7,10,13,20};
		int front = 0;
		int len = arr.length;
		int back = len - 1;
		int sum = 14;
		boolean flag = false;
		
		
		while(front < back) {
			int currSum = arr[front] + arr[back];
			if(currSum < sum){
				front++;
			}
			else if(currSum > sum) {
				back--;
			}
			else {
				System.out.println("Pair is:"+arr[front]+" "+arr[back]);
				flag = true;
				break;
			}
		}
		if(!flag) {
			System.out.println("No Pair exists!");
		}
	}
}
