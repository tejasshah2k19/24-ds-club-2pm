import java.util.Scanner;

public class GraphDemo{
    public static void main(String[] args) {
        

        Scanner scr = new Scanner(System.in);
        System.out.println("How many Vertex you have? ");
        int vertex = scr.nextInt();//4 3 

        int graph[][] = new int[vertex][vertex];
        
        
        System.out.println("how many edges you want to add?");//
        int edges = scr.nextInt();


        for(int i=1;i<=edges;i++){
            System.out.println("Enter Source and Destation");
            int src = scr.nextInt();//0 
            int dest  = scr.nextInt(); //1 

            graph[src][dest] = 1; 
            graph[dest][src] = 1;
        }

        //src -> dest 
        //0 : 1 ,2 
        //1 : 0,3 
        //2 : 0,1

        

    }
}