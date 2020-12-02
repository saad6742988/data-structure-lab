bool isAvl(node* n)
{
	if (n == NULL)
	{
		return true;
	}
	int L_height = height(n->left);
	int R_height = height(n->right);
	int balance = L_height - R_height;
	balance = abs(balance);
	if (balance <= 1 && isAvl(n->left) && isAvl(n->right))
		return true;
	return false;
}
