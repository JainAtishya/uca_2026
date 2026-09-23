public class Intersection {
    static class Node{
        int val;
        Node next;

        public Node(int val){
            this.val = val;
            this.next = null;
        }
    }


    static Node intersection(Node head1, Node head2) {
        Node p1 = head1;
        Node p2 = head2;

        Node dummy = new Node(0);
        Node tail = dummy;

        while (p1 != null && p2 != null) {

            if (p1.val == p2.val) {
                tail.next = new Node(p1.val);
                tail = tail.next;

                p1 = p1.next;
                p2 = p2.next;
            }
            else if (p1.val < p2.val) {
                p1 = p1.next;
            }
            else {
                p2 = p2.next;
            }
        }

        return dummy.next;
    }

    public static void main(String[] args) {

        Node list1 = new Node(1);
        Node prev = list1;

        for(int i = 1; i < 6; i++){
            Node newNode = new Node(i + 1);
            prev.next = newNode;
            prev = newNode;
        }

        Node list2 = new Node(3);
        prev = list2;

        for(int i = 4; i < 9; i++){
            Node newNode = new Node(i + 1);
            prev.next = newNode;
            prev = newNode;
        }

        Node newList = intersection(list1, list2);


        Node temp = newList;
        
        while(temp != null){
            System.out.print(temp.val + " ");
            temp = temp.next;
        }

    }
}
