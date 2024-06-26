import java.util.Scanner;

public class GraphDemo2 {
    public static void main(String[] args) {

        Scanner scr = new Scanner(System.in);
        int totalVertex;
        int totalEdges;

        System.out.println("Enter total Vertext");
        totalVertex = scr.nextInt(); // 4

        System.out.println("Enter Total Edges");
        totalEdges = scr.nextInt();

        int graph[][] = new int[totalVertex][totalVertex]; // 4*4

        int src;
        int dest;

        for (int i = 1; i <= totalEdges; i++) {

            System.out.println("Enter src and Dest");
            src = scr.nextInt();// 2
            dest = scr.nextInt();// 1
            System.out.println("Enter Cost");
            int cost = scr.nextInt();   
            graph[src][dest] = cost;
            graph[dest][src] = cost;
        }
 
        for (int i = 0; i < totalVertex; i++) {
            System.out.println(i + " is connected with : ");
            for (int c = 0; c < totalVertex; c++) {
                if (graph[i][c] != 0) {
                    System.out.println(" : " + c);
                }
            }
        }
    
        int find = 0; 
        int sum =0;
        for (int c = 0; c < totalVertex; c++) {
            if (graph[find][c] != 0) {
                sum = sum + graph[find][c]; 
            }
        }
        System.out.println("Total "+sum);
    
    }
}