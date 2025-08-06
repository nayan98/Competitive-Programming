public class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            result.add(node.val); // Visit node

            if (node.right != null) stack.push(node.right); // Push right first
            if (node.left != null) stack.push(node.left);   // Push left after, so it's processed first
        }

        return result;
    }
}
