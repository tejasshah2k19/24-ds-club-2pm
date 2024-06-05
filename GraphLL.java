import java.util.Scanner;

public class GraphLL {
    public static void main(String[] args) {
        Scanner scr = new Scanner(System.in);
       
       
       System.out.println("How many Nodes(Vertex) you want to creaet?");
       int totalVertex = scr.nextInt(); 
       
        System.out.println("Enter Total Edges");//5000 1500 50 10 
        int totalEdge  = scr.nextInt();
    

        totalEdge = totalEdge *2;   
        
        Edge edges []  =new Edge[totalEdge];
        int vertices[]  = new int[totalVertex]; 


        for(int i=0;i<totalEdge;i++){

            Edge e1 = new Edge();
            System.out.println("Enter source and destination");
            e1.src=scr.nextInt();//20
            e1.dest=scr.nextInt();//30 
            edges[i] = e1; 

            Edge e2 = new Edge();
            e2.src = e1.dest;//30
            e2.dest = e1.src; //20 
            i++;
            edges[i]=e2; 
        }  


        int k=0;
        for(int i=0;i<totalEdge;i++){
              
            int v = edges[i].src;//20
            
            //search -> vertices[i] -> v
            boolean found = false; 
            for(int j=0;j<totalVertex;j++){
                if(vertices[j] == v){
                    found = true;
                    break;
                }
            }

            if(found == false){
                   vertices[k] = v; 
                    k++;
            }

        }

        System.out.println(" Vertices List ");
        for(int i=0;i<totalVertex;i++){
            System.out.println(vertices[i]);
        }

        
        System.out.println(" Edges List ");
        for(int i=0;i<totalEdge;i++){
            System.out.println(edges[i].src+ "   "+edges[i].dest);
        }


    }
}



class Edge{
    int src;
    int dest; 
}