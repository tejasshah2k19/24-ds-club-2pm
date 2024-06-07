import java.util.Scanner;

public class BFS{
 
    public static void main(String[] args) {
        Graph g = new Graph();
        g.initGraph();
        g.scanEdges(); 
        g.printEdges();

        g.bfs(); 


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
            System.out.println("Enter Source and Destination");
            int s = scr.nextInt();
            int d = scr.nextInt();

            Edge e = new Edge();
            e.src = s;
            e.dest = d; 
            edges[i] = e; 

            i++;
            Edge u = new Edge();
            u.src = e.dest ;
            u.dest = e.src; 
            edges[i] = u; 

        } 
    }

    void printEdges(){
        for(int i=0;i<totalEdges;i++){
            System.out.println(edges[i].src+" => "+edges[i].dest);
        }
    }
    boolean isVisited(int x){ //
        for(int j : visited){//0......SIZE-1 
            if( j  == x){
                return true;
            }
        }
        return false;
    }
    void bfs(){
        Scanner scr = new Scanner(System.in);
        System.out.println("Enter Starting Vertex:node");
        int visitedIndex = 0 ;
        int nextIndex = 0;
        int cur = scr.nextInt();//25
    
        visited[visitedIndex] = cur ; 

        while(visitedIndex < totalVertex){ 
            for(int i=0;i<totalEdges;i++){
                if(edges[i].src == cur && isVisited(edges[i].dest) == false){
                    visitedIndex++;
                    visited[visitedIndex] =  edges[i].dest;//25 35 1 2 
                        
                }
            }
            nextIndex++;//2
            cur = visited[nextIndex];
        }
    }
    
}

class Edge{
    int src;
    int dest;

    
}