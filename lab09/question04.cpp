//funtion to join trees
avl join(avlNode* tree1, avlNode* tree2)
{
	static avl temp_tree;
	if (tree1 != NULL)
	{
		temp_tree.root = temp_tree.insert(temp_tree.getRoot(), tree1->data);
		join(tree1->left, tree2);
		join(tree1->right, tree2);
	}
	if (tree2 != NULL)
	{
		temp_tree.root = temp_tree.insert(temp_tree.getRoot(), tree2->data);
		join(tree1, tree2->left);
		join(tree1, tree2->right);
	}
	return temp_tree;
}


