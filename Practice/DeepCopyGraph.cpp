struct Node {
  list<Node *> neighbors;
};

void copyNode(Node* origin, Node* newNode)
{
    for (list<Node*>::iterator itr = origin->neighbors.begin(); itr != origin->neighbors.end(); ++itr)
    {
        Node* neighNode = *itr;
        newNode->neighbors.push(nodeMap[neighNode]);
    }
}

// then i'll build the neighbor nodes in the new nodes
void buildNeighNodes()
{
    for (map<Node*, Node*>::iterator itr = nodeMap.begin(); itr != nodeMap.end(); ++itr)
    {

        copyNode(itr.first, itr.second);
    }
}

map<Node*, Node*> nodeMap;

// firstly, i found all the nodes exist in the graph, and make a new node 
void findAllNodes(Node* node)
{
    if (nodeMap.find(node) == nodeMap.end())
    {
        nodeMap[node] = new Node();
    }
    else return;

    for (list<Node*>::iterator itr = node->neighbors.begin(); itr != node->neighbors.end(); ++itr)
        findAllNodes(*itr);
}

Node* copyGraph(Node *node)
{
    if (!node) return NULL;

    nodeMap.clear();
    findAllNodes(node);

    buildNeighNodes();

    return nodeMap[node];
}