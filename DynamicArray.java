import java.util.Scanner;
import java.util.ArrayList;


public class DynamicArray {
    public static void main(String[] args) {
        Scanner scr = new Scanner(System.in);
        
        ArrayList<Integer> a = new ArrayList<>(); 


        System.out.println("Enter data");
        int data = scr.nextInt();//1     
        a.add(data);//1
        a.add(data+1);//2
        a.add(data+2);//3
        a.add(data+3);//4
        a.add(data+4);//5
        a.add(data+5);//6 


        System.out.println(a);
        a.add(data);//1
        a.add(data+1);//2
        a.add(data+2);//3
        a.add(data+3);//4
        a.add(data+4);//5
        a.add(data+5);//6 
        System.out.println(a);

        
        System.out.println(a.get(7));

        System.out.println(a.get(5));
        
        a.remove(0);
        System.out.println(a);
        



        //collection 
    }
}
