import java.util.Scanner;

public class GraphFinal {
    public static void main(String[] args) {
        
        Scanner scr = new Scanner(System.in);
        System.out.println("How many Edges you have?");
        int totalEdges = scr.nextInt();
        int s,d,c;
        //4 
      
        Edge ed[] = new Edge[totalEdges*2]; 
        for(int i=0;i<totalEdges*2;i++){ 
            System.out.println("Enter source and dest");
            s = scr.nextInt();//30
            d = scr.nextInt();//70
            System.out.println("Enter Cost");
            c= scr.nextInt();

            Edge e1 = new Edge();  
            e1.src = s;//30
            e1.dest =d;//70
            e1.cost = c; 
            ed[i] = e1; 


            Edge re1 = new Edge();  
            re1.src = e1.dest ; 
            re1.dest = e1.src;
            re1.cost = c;  
            i++;
            ed[i] = re1;   


        }

        for(int i=0;i<totalEdges*2;i++){
            System.err.println(ed[i].src+" => "+ed[i].dest+" :: "+ed[i].cost);
        }
        

        System.out.println("Enter source node : ");
        int search = scr.nextInt();

        
        for(int i=0;i<totalEdges*2;i++){
            if(ed[i].src == search){
                System.out.println(ed[i].dest);
            }
        }

    }
}

class Edge{
        int src;
        int dest; 
        int cost; 
}
