public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root;

        while (!stack.isEmpty() || node != null) {
            // Go as left as possible
            while (node != null) {
                stack.push(node);
                node = node.left;
            }

            // Visit node
            node = stack.pop();
            result.add(node.val);

            // Move to right
            node = node.right;
        }

        return result;
    }
}
