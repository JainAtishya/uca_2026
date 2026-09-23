class Reverse {

    static class Node{
        int val;
        Node next;

        public Node(int val){
            this.val = val;
            this.next = null;
        }
    }

    public static Node recursive(Node node){
        if(node.next == null) return node;

        Node newHead = recursive(node.next);

        node.next.next = node;
        node.next = null;

        return newHead;
    }

    public static void main(String[] args) {

       Node head = new Node(1);
       Node prev = head;

        for(int i = 1; i < 5; i++){
            Node newNode = new Node(i + 1);
            prev.next = newNode;
            prev = newNode;
        }

        Node reversedListHead = recursive(head);

        Node temp = reversedListHead;
        
        while(temp != null){
            System.out.print(temp.val + " ");
            temp = temp.next;
        }

    }
}