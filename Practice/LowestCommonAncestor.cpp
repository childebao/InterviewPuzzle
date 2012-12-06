
vector<Node> path;
vector<int> depth;
void inOrder(Node& node, int depth)
{
    if (node.left != NULL) inOrder(node.left, depth + 1);
    path.push_back(node);
    depth.push_back(depth);
    if (node.right != NULL) inOrder(node.right, depth + 1);
}

int LCA(Tree t, int a, int b)
{
    if (a == b) return a;

    path.clear();
    depth.clear();
    inOrder(t.node, 1);

    int lcaNodeIndex = -1;
    int minDepth = path.size();
    bool flag = false;
    for (int i = 0; i < path.size(); i ++)
    {
        if (path[i].val == a || path[i].val == b)
        {
            if (!flag) 
            {
                flag = true;
            }
            else
            {
                if (depth[i] < minDepth)
                {
                    minDepth = depth[i];
                    lcaNodeIndex = i;
                }
                flag = false;
                break;
            }
        }
        
        if (flag && minDepth > depth[i]) 
        {
            minDepth = depth[i];
            lcaNodeIndex = i;
        }
    }

    return path[lcaNodeIndex].val;
}
