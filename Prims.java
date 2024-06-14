import java.util.Scanner;

public class Prims {
    public static void main(String[] args) {
        Graph g = new Graph(); 
        g.initGraph();
        g.scanEdges();
        g.sortEdges();
        g.printEdges();
    
        g.prims();
    }
}

class Graph{
    int totalEdges;//7->14
    int totalVertex;//5
    Edge edges [];
    int visited[];
    void initGraph(){
        Scanner scr = new Scanner(System.in);
        System.out.println("How many Vertex and Edges you have");
        totalVertex = scr.nextInt();//4
        totalEdges = scr.nextInt()*2; //4
        edges = new Edge[totalEdges];//8 array 
        visited = new int[totalVertex]; 
    }

    void scanEdges(){
        Scanner scr = new Scanner(System.in);
        for(int i=0;i<totalEdges;i++){
            System.out.println("Enter source Dest and Cost");
            int s = scr.nextInt();
            int d = scr.nextInt();
            int c = scr.nextInt(); 

            Edge e = new Edge();
            e.src = s;
            e.dest = d;
            e.cost =c; 
            edges[i] = e; 
            i++; 

            Edge u  = new Edge();
            u.src = e.dest;
            u.dest = e.src; 
            u.cost = e.cost ;
            edges[i] = u; 


        }   
    }

    void printEdges(){
        System.out.println("Total Edges");
        for(int i=0;i<totalEdges;i++){
            System.out.println(edges[i].src +" => "+edges[i].dest+" : "+edges[i].cost);
        }
    }
    void sortEdges(){
        Edge tmp; 
        for(int i=0;i<totalEdges;i++){
            for(int j=0;j<totalEdges-1;j++){
                if(edges[j].cost > edges[j+1].cost){
                      tmp = edges[j];
                      edges[j] = edges[j+1];
                      edges[j+1] = tmp;   
                }
            }
        }
    }

    
    boolean isVisited(int x){
        for(int i=0;i<totalVertex;i++){
            if(visited[i] == x){
                return true; 
            }
        }
        return false; 
    }
    void prims(){
        int sum=0; 
        Scanner scr = new Scanner(System.in);  
        System.out.println("Enter initial vertex");
        int cur = scr.nextInt();//1
        int visitedIndex = 0; 
        int previousIndex = 0 ;
       // sortEdges();
        visited[visitedIndex]=cur;
        visitedIndex++;
        boolean flag = false; 
        System.out.println(cur);//1 

        while(visitedIndex < totalVertex){ 
            flag = false; 
            for(int i=0;i<totalEdges;i++){
                if(edges[i].src == cur  && isVisited(edges[i].dest) == false ){
                    cur = edges[i].dest; //3 
                    System.out.println(cur);//3 
                    previousIndex = visitedIndex - 1; //0
                    visited[visitedIndex]=cur;
                    visitedIndex++;//2
                    sum= sum+edges[i].cost;
                    flag=true; 
                    break;
                }
            }
            if(flag == false){
                cur = visited[previousIndex];// 2
                previousIndex--; 
            }

        }
        

    }
}
class Edge{
    int src;
    int dest;
    int cost; 
}
