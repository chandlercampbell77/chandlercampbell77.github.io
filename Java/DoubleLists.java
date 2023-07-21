import java.util.*;
public class DoubleLists {
  //new Node to start the list
  public Node head;
  //The rest of the methods will go beneath this line
  public void addToHead(int element) {
    Node n = new Node(element);
    //the next of the one is now the head
    //make the previous node null
    n.next = head;
    n.prev = null;
    //previous of head is the new node
    if(head != null) {
     head.prev = n;
    }
    //move the head to point to new node
    head = n;
 }
  public void addToTail(int element) {
    // new node
    Node n = new Node(element);
    Node end = head;
    n.next = null;
    //if list is empty make new node the head
    if(head == null) {
     n.prev = null;
     head = n;
     return;
    }
    //go until you find the last
    while(end.next != null) {
     end = end.next;
    }
    //change next of the last node
    end.next = n;
    //make last node the previous of new node
    n.prev = end;
  }
  public void insertNode(Node prev, int element) {
   //is the given node null?
   if(prev == null) {
    System.out.println("Cannot have previous node of null");
    return;
   }
   //create new node and add data
   Node n = new Node(element);
   //make new node's next the next of the previous
   n.next = prev.next;
   //make next of prev the new node
   prev.next = n;
   //make previous node as previous of new node
   n.prev = prev;
   //change previous of new nodes next node
   if(n.next != null) {
   n.next.prev = n;
   }
  }
  public void printList(Node node) {
    System.out.println("Going forward --> ");
    Node end = null;
    while(node != null) {
     System.out.print(node.data + " " );
     end = node;
     node = node.next;
    }
    System.out.println();
    System.out.println("<-- Going backward " );
    while (end != null) {
     System.out.print(end.data + " ");
     end = end.prev;
    }
  }
}