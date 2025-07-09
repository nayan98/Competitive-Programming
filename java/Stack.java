class Stack {
    private int top;
    private int size;
    private int[] data;

    public Stack(int size) {
        this.size = size;
        data = new int[size];
        top = -1;
    }
    public boolean push(int val) {
        if (top >= size-1) {
            return false;
        }
        top++;
        data[top] = val;
        return true;
    }
    public int pop() {
        if (top < 0) {
            return -99999;
        }
        int val = data[top];
        top--;
        return val;
    }
    public int peek() {
        if (top < 0) {
            return -99999;
        }
        return data[top];
        
    }
}
