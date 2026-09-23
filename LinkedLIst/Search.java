public class Search {

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    static boolean search(Node list1, Node list2) {
        while (list2 != null) {
            Node p1 = list1;
            Node p2 = list2;

            while (p1 != null && p2 != null && p1.data == p2.data) {
                p1 = p1.next;
                p2 = p2.next;
            }

            if (p1 == null)
                return true;

            list2 = list2.next;
        }

        return false;
    }

    public static void main(String[] args) {

        Node list1 = new Node(1);
        list1.next = new Node(2);
        list1.next.next = new Node(3);

        Node list2 = new Node(5);
        list2.next = new Node(1);
        list2.next.next = new Node(2);
        list2.next.next.next = new Node(3);
        list2.next.next.next.next = new Node(4);

        System.out.println(search(list1, list2) ? "Yes" : "No");
    }
}