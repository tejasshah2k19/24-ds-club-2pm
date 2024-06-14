 
import java.util.Scanner;

public class GraphWithCost{
 
    public static void main(String[] args) {
        Graph g = new Graph();
        g.initGraph();
        g.scanEdges(); 
        g.printEdges();

    }
}

class Graph{
    int totalEdges;
    int totalVertex; 
    Edge edges[] ; //src dest 
    int visited[];


    void initGraph(){
        Scanner scr = new Scanner(System.in);

        System.out.println("How many Vertex and Edges you have? ");
        totalVertex = scr.nextInt(); 
        totalEdges = scr.nextInt() * 2; 
        visited = new int[totalVertex];

        edges = new Edge[totalEdges];
    }

    void scanEdges(){
        
        Scanner scr = new Scanner(System.in);

        for(int i=0;i<totalEdges;i++){
            System.out.println("Enter Source - Destination - Cost ");
            int s = scr.nextInt();
            int d = scr.nextInt();
            int c = scr.nextInt(); 

            Edge e = new Edge();
            e.src = s;
            e.dest = d; 
            e.cost = c; 
            edges[i] = e; 

            i++;
            Edge u = new Edge();
            u.src = e.dest ;
            u.dest = e.src;
            u.cost = c; 
            
            edges[i] = u; 

        } 
    }

    void printEdges(){
        for(int i=0;i<totalEdges;i++){
            System.out.println(edges[i].src+" => "+edges[i].dest+" :: "+edges[i].cost);
        }
    }
    
    
}

class Edge{
    int src;
    int dest;
    int cost; 
    
}