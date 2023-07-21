import java.util.*;
public class CircularLinkedList {
  public int size = 0;
  public Node head = null;
  public Node tail = null;

   //print the list
 public void print(){
  System.out.print("The List So Far: ");
  Node temp = head;
 do {
  System.out.print(" " + temp.element);
  temp = temp.next;
 } while(temp != head);
 
  System.out.println();
 }
//add a new node at the start of the linked list
 public void addNodeToHead(int element){
  Node n = new Node(element);
  if(size==0){
   head = n;
   tail = n;
   n.next = head;
  }else{
   Node temp = head;
   n.next = temp;
   head = n;
   tail.next = head;
  }
 size++;
 }
 public void addNodeToTail(int element){
  if(size==0){
   addNodeToHead(element);
  }else{
   Node n = new Node(element);
   tail.next = n;
   tail = n;
   tail.next = head;
   size++;
  }
 }
 public void rotateElement() {
  System.out.println("Rotating!");
  tail = head;
  head = head.next;
 }
 public void deleteNodeFromTail() {
  System.out.println("\nDeleting Node " + 
  tail.element + " from Tail");
  if(tail.next == tail) {
    tail = null;
  }
  Node newTail = tail;
   
  while(newTail.next != tail) {
     newTail = newTail.next;
  }
    newTail.next = tail.next;
    tail = newTail;
  }
  public void deleteNodeFromHead(){
    head = head.next;
    tail.next = head;
    size--;
  }
}