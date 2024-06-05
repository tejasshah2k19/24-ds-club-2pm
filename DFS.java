import java.util.Scanner;

public class DFS {

    int visited[];
    int totalEdges;
    int totalVertex;
    int vertex[];
    Edge edges[];

    public void initGraph() {
        Scanner scr = new Scanner(System.in);
        System.out.println("How many vertex and Edges you have? ");
        totalVertex = scr.nextInt(); // 7
        totalEdges = scr.nextInt(); // 8
        totalEdges = totalEdges * 2;

        vertex = new int[totalVertex];
        edges = new Edge[totalEdges];

        for (int i = 0; i < totalVertex; i++) {
            System.out.println("Enter vertex value: ");
            vertex[i] = scr.nextInt();
        }

        for (int i = 0; i < totalEdges; i++) {
            Edge e = new Edge();
            System.out.println("Enter Source And Destination : ");
            e.src = scr.nextInt();// 1
            e.dest = scr.nextInt(); // 2
            edges[i] = e;
            i++;

            Edge e2 = new Edge();
            e2.src = e.dest;// 2
            e2.dest = e.src;// 1
            edges[i] = e2;
        }

    }

    public void printVertex() {
        System.out.println("All Vertex : ");

        for (int i = 0; i < totalVertex; i++) {
            System.out.println(vertex[i]);
        }
    }

    public void printEdges() {
        System.out.println("All Edges : ");
        for (int i = 0; i < totalEdges; i++) {
            System.out.println(edges[i].src + "  => " + edges[i].dest);
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
    public void findDFS(){
        Scanner scr = new Scanner(System.in); 
        int visitedIndex = 0;
        visited = new int[totalVertex];
        System.out.println("Enter initial vertex : ");
        int cur = scr.nextInt();//1 
        visited[visitedIndex] = cur; //1 
        visitedIndex++; //1 

        while(visitedIndex < totalVertex){ 
            for(int i=0;i<totalEdges;i++){ // 8 
                if(edges[i].src == cur  &&  isVisited(edges[i].dest) == false){
                    cur = edges[i].dest ; //2
                    System.out.println(edges[i].dest);
                    visited[visitedIndex] = cur ; 
                    visitedIndex++;
                }
            }
        }
    }
    public static void main(String[] args) {

        Scanner scr = new Scanner(System.in);

        DFS dfs = new DFS();
        dfs.initGraph();
        dfs.printVertex();
        dfs.printEdges(); 
        // DFS
        dfs.findDFS();
        
    }
}

class Edge {
    int src;
    int dest;
}
