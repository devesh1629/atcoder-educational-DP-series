import java.util.*;
class Pair {
    int cost;
    int profit;
    Pair(int x, int y) {
        this.cost=x;
        this.profit=y;
    }
}
class sortByCost implements Comparator<Pair> {
    @Override
    public int compare(Pair o1, Pair o2) {
        return o1.cost - o2.cost;
    }
}
class Solution {
    static Scanner in;
    public void solve() {
        int i, j;
        int n = in.nextInt(), sum=in.nextInt();
        ArrayList<Pair> crops = new ArrayList<>();
        for(i=0;i<n;i++) {
            int cost=in.nextInt(), profit=in.nextInt();
            crops.add(new Pair(cost, profit));
        }
        Collections.sort(crops, new sortByCost());
        for(i=0;i<n;i++) {
            if(sum < crops.get(i).cost)
                break;
            sum += crops.get(i).profit;
        }
        System.out.print(i + "\n");

    }
    public static void main(String args[]) {
        in = new Scanner(System.in);
        Solution solution = new Solution();
        int t = 1;
        // t = in.nextInt();
        while(t-->0) {
            solution.solve();
        }
    }
}