public class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root;
        TreeNode lastVisited = null;

        while (!stack.isEmpty() || node != null) {
            if (node != null) {
                stack.push(node);
                node = node.left; // go left as much as possible
            } else {
                TreeNode peek = stack.peek();
                if (peek.right != null && lastVisited != peek.right) {
                    node = peek.right; // go to right child
                } else {
                    result.add(peek.val); // visit node
                    lastVisited = stack.pop(); // mark as visited
                }
            }
        }

        return result;
    }
}
